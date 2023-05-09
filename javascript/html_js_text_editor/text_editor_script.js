function bold() {
  document.execCommand('bold', false, null);
}

function italic() {
  document.execCommand('italic', false, null);
}

function underline() {
  document.execCommand('underline', false, null);
}

function fontSize(size) {
  document.execCommand('fontSize', false, size.value);
}

function fontFamily(font) {
  document.execCommand('fontName', false, font.value);
}

function align(position) {
  document.execCommand('justify' + position, false, null);
}
