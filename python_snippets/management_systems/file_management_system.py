import os
import shutil

def create_file(file_path):
    with open(file_path, 'w') as f:
        pass

def read_file(file_path):
    with open(file_path, 'r') as f:
        content = f.read()
        print(content)

def update_file(file_path, new_content):
    with open(file_path, 'w') as f:
        f.write(new_content)

def delete_file(file_path):
    os.remove(file_path)

def navigate_directory(directory_path):
    os.chdir(directory_path)

def list_directory_contents(directory_path):
    for item in os.listdir(directory_path):
        print(item)

def copy_file(source_path, dest_path):
    shutil.copy2(source_path, dest_path)

def rename_file(file_path, new_name):
    os.rename(file_path, new_name)

def create_symbolic_link(file_path, link_path):
    os.symlink(file_path, link_path)

# Example usage
file_path = 'example.txt'
create_file(file_path)
read_file(file_path)
update_file(file_path, 'Hello, world!')
read_file(file_path)
delete_file(file_path)

directory_path = '.'
list_directory_contents(directory_path)

source_path = 'example.txt'
dest_path = 'example_copy.txt'
copy_file(source_path, dest_path)

new_name = 'example_renamed.txt'
rename_file(dest_path, new_name)

link_path = 'example_link.txt'
create_symbolic_link(new_name, link_path)
read_file(link_path)


# In this program, we define several functions to perform various file management operations. The create_file, read_file, update_file, and delete_file functions respectively create, read, update, and delete a file at the specified path using Python's built-in open and os modules.

# The navigate_directory function changes the current working directory to the specified path using the os.chdir function. The list_directory_contents function lists the contents of the specified directory using the os.listdir function.

# The copy_file function copies a file from the source path to the destination path using the shutil.copy2 function. The rename_file function renames a file at the specified path using the os.rename function.

# The create_symbolic_link function creates a symbolic link at the specified path using the os.symlink function.

# Finally, the program demonstrates the usage of these functions by creating, reading, updating, and deleting a file, navigating a directory, listing directory contents, copying and renaming a file, and creating a symbolic link.
