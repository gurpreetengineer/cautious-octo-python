const SPREADSHEET_ID = 'YOUR_SPREAD_SHEET_ID_HERE';

function fetchData(endpoint, page) {
  const url = `https://EXAMPLE.com/v1${endpoint}?page=${page}`;
  const options = {
    headers: {
      Authorization: 'Basic ' + Utilities.base64Encode('YOUR_API_KEY_HERE'),
      Accept: 'application/json',
    },
  };
  const response = UrlFetchApp.fetch(url, options);
  const data = JSON.parse(response.getContentText());
  return data[endpoint.slice(1)];
}

function writeDataToSheet(sheet, data) {
  const values = [];
  const keysForFirstRow = Object.keys(data[0]);
  for (const row of data) {
    const rowValues = [];
    for (const property in row) {
      if (row.hasOwnProperty(property)) {
        if (row[property] instanceof Object) {
          const selfKey = findSelfKey(row[property]);
          rowValues.push(selfKey);
        } else {
          rowValues.push(row[property]);
        }
      }
    }
    if (rowValues.length === keysForFirstRow.length) {
      values.push(rowValues);
    }
  }
  sheet.getRange(sheet.getLastRow() + 1, 1, values.length, values[0].length).setValues(values);
}

function findSelfKey(obj) {
  for (const key in obj) {
    if (key === "self") {
      return obj[key];
    } else if (typeof obj[key] === "object") {
      const selfKey = findSelfKey(obj[key]);
      if (selfKey) {
        return selfKey;
      }
    }
  }
}

function fetchAndWriteData(endpoint) {
  const sheetName = endpoint.slice(1).charAt(0).toUpperCase() + endpoint.slice(2);
  const spreadsheet = SpreadsheetApp.openById(SPREADSHEET_ID);
  const sheet = spreadsheet.getSheetByName(sheetName) || spreadsheet.insertSheet(sheetName);
  let page = 1;
  let data = fetchData(endpoint, page);
  const threadCount = 5;
  let threads = [];
  while (data.length > 0) {
    while (threads.length < threadCount) {
      const threadData = data.shift();
      if (threadData) {
        threads.push({
          data: threadData,
          thread: sheet.getName()
        });
      } else {
        break;
      }
    }
    threads = threads.map(thread => {
      writeDataToSheet(sheet, [thread.data]);
      return null;
    }).filter(thread => thread !== null);
    page++;
    data = fetchData(endpoint, page);
  }
  if (threads.length > 0) {
    threads = threads.map(thread => {
      writeDataToSheet(sheet, [thread.data]);
      return null;
    }).filter(thread => thread !== null);
  }
}

function doGet(request) {
  const endpoint = request?.path;
  if (endpoint == '/endpoint1' || endpoint == '/endpoint2' || endpoint == '/endpoint3') {
    fetchAndWriteData(endpoint);
    return ContentService.createTextOutput(`Data uploaded to ${endpoint.slice(1).charAt(0).toUpperCase() + endpoint.slice(2).toLowerCase()}`);
  } else {
    console.log('Invalid endpoint')
  }
}

doGet({ path: '/endpoint1' });
doGet({ path: '/endpoint2' });
doGet({ path: '/endpoint3' });
