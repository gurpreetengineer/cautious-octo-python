import os
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QFileDialog, QLabel, QLineEdit
from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive

class DriveBackup(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()
        self.authenticate()

    def initUI(self):
        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('Drive Backup')

        self.label1 = QLabel(self)
        self.label1.setText('Source Folder Path:')
        self.label1.move(20, 30)

        self.textbox1 = QLineEdit(self)
        self.textbox1.move(140, 30)
        self.textbox1.resize(180, 25)

        self.browseButton1 = QPushButton('Browse', self)
        self.browseButton1.move(320, 30)
        self.browseButton1.clicked.connect(self.openFolderDialog1)

        self.label2 = QLabel(self)
        self.label2.setText('Destination Folder Name:')
        self.label2.move(20, 80)

        self.textbox2 = QLineEdit(self)
        self.textbox2.move(140, 80)
        self.textbox2.resize(180, 25)

        self.browseButton2 = QPushButton('Backup', self)
        self.browseButton2.move(140, 140)
        self.browseButton2.clicked.connect(self.backup)

        self.statusLabel = QLabel(self)
        self.statusLabel.setText('Status: Ready')
        self.statusLabel.move(20, 200)

    def openFolderDialog1(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        folder_path = QFileDialog.getExistingDirectory(self, 'Select Source Folder', options=options)
        self.textbox1.setText(folder_path)

    def authenticate(self):
        gauth = GoogleAuth()
        gauth.LocalWebserverAuth()
        self.drive = GoogleDrive(gauth)

    def backup(self):
        source_folder = self.textbox1.text()
        dest_folder_name = self.textbox2.text()

        folder_metadata = {'title': dest_folder_name, 'mimeType': 'application/vnd.google-apps.folder'}
        folder = self.drive.CreateFile(folder_metadata)
        folder.Upload()
        print('Created folder: %s' % folder['title'])

        for file_name in os.listdir(source_folder):
            if os.path.isfile(os.path.join(source_folder, file_name)):
                file_metadata = {'title': file_name, 'parents': [{'id': folder['id']}]}

                file = self.drive.CreateFile(file_metadata)
                file.SetContentFile(os.path.join(source_folder, file_name))
                file.Upload()
                print('Uploaded file: %s' % file['title'])

        self.statusLabel.setText('Status: Backup completed successfully.')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = DriveBackup()
    ex.show()
    sys.exit(app.exec_())

# You'll need to install the necessary modules like pydrive and PyQt5 for this code to work. Also, make sure to follow the authentication process to connect the code to your Google Drive account.
