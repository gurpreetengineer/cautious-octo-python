import React, { useState } from 'react';

function TextEditor() {
  const [fontSize, setFontSize] = useState('');
  const [fontFamily, setFontFamily] = useState('');
  const [alignment, setAlignment] = useState('');

  const bold = () => {
    document.execCommand('bold', false, null);
  };

  const italic = () => {
    document.execCommand('italic', false, null);
  };

  const underline = () => {
    document.execCommand('underline', false, null);
  };

  const handleFontSizeChange = (e) => {
    setFontSize(e.target.value);
    document.execCommand('fontSize', false, e.target.value);
  };

  const handleFontFamilyChange = (e) => {
    setFontFamily(e.target.value);
    document.execCommand('fontName', false, e.target.value);
  };

  const handleAlignmentChange = (e) => {
    setAlignment(e.target.value);
    document.execCommand(`justify${e.target.value}`, false, null);
  };

  return (
    <div id="editor">
      <div className="toolbar">
        <button onClick={bold}>
          <b>B</b>
        </button>
        <button onClick={italic}>
          <i>I</i>
        </button>
        <button onClick={underline}>
          <u>U</u>
        </button>
        <select value={fontSize} onChange={handleFontSizeChange}>
          <option value="">Size</option>
          <option value="1">Size 1</option>
          <option value="2">Size 2</option>
          <option value="3">Size 3</option>
          <option value="4">Size 4</option>
          <option value="5">Size 5</option>
          <option value="6">Size 6</option>
          <option value="7">Size 7</option>
        </select>
        <select value={fontFamily} onChange={handleFontFamilyChange}>
          <option value="">Font</option>
          <option value="Arial">Arial</option>
          <option value="Helvetica">Helvetica</option>
          <option value="Times New Roman">Times New Roman</option>
          <option value="Courier">Courier</option>
          <option value="Verdana">Verdana</option>
          <option value="Georgia">Georgia</option>
        </select>
        <button onClick={(e) => handleAlignmentChange(e)} value="left">
          <i className="fa fa-align-left"></i>
        </button>
        <button onClick={(e) => handleAlignmentChange(e)} value="center">
          <i className="fa fa-align-center"></i>
        </button>
        <button onClick={(e) => handleAlignmentChange(e)} value="right">
          <i className="fa fa-align-right"></i>
        </button>
      </div>
      <div contentEditable="true"></div>
    </div>
  );
}

export default TextEditor;
