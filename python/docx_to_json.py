import docx
import json

# Open the Word file
doc = docx.Document('path/to/word/file.docx')

# Loop through each chapter in the document
chapters = []
for chapter in doc.chapters:
    # Extract the text of the chapter
    text = chapter.text
    
    # Add the text to the list of chapters
    chapters.append(text)

# Create a dictionary with each chapter as a value and the index as the key
data = {}
for i, chapter in enumerate(chapters):
    data[str(i+1)] = chapter

# Generate the JSON object
json_data = json.dumps(data)
