from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
import os

# Authenticate and create PyDrive client
gauth = GoogleAuth()
gauth.LocalWebserverAuth() # Starts local webserver and prompts for authentication
drive = GoogleDrive(gauth)

# Define file path to backup and name of file in Google Drive
file_path = '/path/to/backup/file.txt'
file_name = 'backup_file.txt'

# Create file on Google Drive and set the file content
file = drive.CreateFile({'title': file_name})
file.Upload()

# Set the file content to the local file's content
with open(file_path, 'r') as f:
    file.SetContentString(f.read())

# Print success message
print('Backup to Google Drive successful.')
