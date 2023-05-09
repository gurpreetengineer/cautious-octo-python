const SPREADSHEET_ID = 'YOUR_SPREADSHEET_ID_HERE';

function doGet(request) {
  var page = 1;
  var endpoint = request?.path;
  var sheetName = '';
  if (endpoint == '/endpoint1') {
    sheetName = 'Sheet1';
  } else if (endpoint == '/endpoint2') {
    sheetName = 'Sheet2';
  } else if (endpoint == '/endpoint3') {
    sheetName = 'Sheet3';
  } else {
    return ContentService.createTextOutput('Invalid endpoint');
  }
  var spreadsheet = SpreadsheetApp.openById(SPREADSHEET_ID);
  var sheet = spreadsheet.getSheetByName(sheetName) || spreadsheet.insertSheet(sheetName);
  var options = {
    'headers': {
      'Authorization': 'Basic ' + Utilities.base64Encode('YOUR BASIC AUTH USERNAME HERE'),
      'Accept': 'application/json'
    }
  };
  var data, keys, rows, selfKey, url, response;
  do {
    url = 'https://YOUR_WEBSITE_URL_HERE.com/' + endpoint + '?page=' + page;
    response = UrlFetchApp.fetch(url, options);
    data = JSON.parse(response.getContentText());
    keys = Object.keys(data)[0];
    rows = data[keys];
    for (var i = 0; i < rows.length; i++) {
      var row = rows[i];
      var values = [];
      if (i === 0 && page === 1) {
        var keysForFirstRow = Object.keys(rows[0])
        sheet.appendRow(keysForFirstRow);
      }
      for (var property in row) {
        if (row.hasOwnProperty(property)) {
          if (row[property] instanceof Object) {
            selfKey = findSelfKey(row[property])
            values.push(selfKey);
            continue;
          }
          values.push(row[property]);
        }
      }
      sheet.appendRow(values);
    }
    page++;
  } while (rows.length > 0);
  return ContentService.createTextOutput('Data uploaded to ' + sheetName);
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

doGet({ path: '/endpoint1' })
doGet({ path: '/endpoint2' })
doGet({ path: '/endpoint3' })
