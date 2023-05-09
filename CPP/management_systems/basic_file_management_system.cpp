#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// refer to this file basic_cpp_file_management_system.txt for more elaboration.

int main() {
    int choice;
    string filename;
    ofstream outfile;
    ifstream infile;
    string line;

    do {
        cout << "1. Create a file\n";
        cout << "2. Read a file\n";
        cout << "3. Update a file\n";
        cout << "4. Delete a file\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the filename: ";
                cin >> filename;
                outfile.open(filename.c_str());
                if (outfile.is_open()) {
                    cout << "File created successfully.\n";
                    outfile.close();
                } else {
                    cout << "Error creating file.\n";
                }
                break;
            case 2:
                cout << "Enter the filename: ";
                cin >> filename;
                infile.open(filename.c_str());
                if (infile.is_open()) {
                    while (getline(infile, line)) {
                        cout << line << endl;
                    }
                    infile.close();
                } else {
                    cout << "Error opening file.\n";
                }
                break;
            case 3:
                cout << "Enter the filename: ";
                cin >> filename;
                outfile.open(filename.c_str(), ios::app);
                if (outfile.is_open()) {
                    cout << "Enter the text to add to the file (press Enter to stop):\n";
                    cin.ignore();
                    while (getline(cin, line) && line != "") {
                        outfile << line << endl;
                    }
                    outfile.close();
                } else {
                    cout << "Error opening file.\n";
                }
                break;
            case 4:
                cout << "Enter the filename: ";
                cin >> filename;
                if (remove(filename.c_str()) == 0) {
                    cout << "File deleted successfully.\n";
                } else {
                    cout << "Error deleting file.\n";
                }
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
