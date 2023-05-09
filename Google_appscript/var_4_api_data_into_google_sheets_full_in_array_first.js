const SPREADSHEET_ID = 'YOUR_SPREADSHEET_ID_HERE';


function doGet(request) {
  let rowsMissed = 0;
  const endpoint = request?.path;
  let sheetName;
  if (endpoint == '/endpoint1') {
    sheetName = 'Endpoint1';
  } else if (endpoint == '/endpoint2') {
    sheetName = 'Endpoint2';
  } else if (endpoint == '/endpoint3') {
    sheetName = 'Endpoint3';
  } else {
    return ContentService.createTextOutput('Invalid endpoint');
  }
  const sheet = SpreadsheetApp.openById(SPREADSHEET_ID).getSheetByName(sheetName) || SpreadsheetApp.openById(SPREADSHEET_ID).insertSheet(sheetName).activate();

  let page = 1;
  let keysForFirstRow;
  const baseUrl = `https://example.com/v1${endpoint}`;
  const values = [];
  do {
    var url = baseUrl + "?page=" + page;
    const options = {
      headers: {
        Authorization: 'Basic ' + Utilities.base64Encode('YOUR_USERNAME_:_PASSWORD'),
        Accept: 'application/json',
      },
    };
    const response = UrlFetchApp.fetch(url, options);
    const data = JSON.parse(response.getContentText());
    if (page === 1) {
      keysForFirstRow = Object.keys(data[endpoint.slice(1)][0])
      sheet.appendRow(keysForFirstRow);
    }
    if (data[endpoint.slice(1)].length === 0) {
      break;
    }
    for (const row of data[endpoint.slice(1)]) {
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
      } else {
        rowsMissed ++;
      }
    }
    console.log('values: ', values.length);
    page++;
  } while (true);

  if (values.length > 0) {
    sheet.getRange(sheet.getLastRow() + 1, 1, values.length, values[0].length).setValues(values);
  }
  
  console.log('Total number of rows missed in ', endpoint, ' are ', rowsMissed);
  return ContentService.createTextOutput(`Data uploaded to ${sheetName}`);
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

doGet({ path: '/endpoint1' });
doGet({ path: '/endpoint2' });
doGet({ path: '/endpoint3' });
