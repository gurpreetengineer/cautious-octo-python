#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

void create_file(const std::string& filename) {
    std::ofstream file(filename);
    if (file) {
        std::cout << "File created successfully: " << filename << std::endl;
    }
    else {
        std::cerr << "Failed to create file: " << filename << std::endl;
    }
}

void read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        std::cout << "Contents of " << filename << ":" << std::endl;
        std::cout << file.rdbuf() << std::endl;
    }
    else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

void update_file(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file) {
        file << content;
        std::cout << "File updated successfully: " << filename << std::endl;
    }
    else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

void delete_file(const std::string& filename) {
    if (fs::exists(filename)) {
        if (fs::remove(filename)) {
            std::cout << "File deleted successfully: " << filename << std::endl;
        }
        else {
            std::cerr << "Failed to delete file: " << filename << std::endl;
        }
    }
    else {
        std::cerr << "File not found: " << filename << std::endl;
    }
}

int main() {
    std::string filename = "test.txt";
    std::string content = "Hello, world!";

    create_file(filename);
    read_file(filename);
    update_file(filename, content);
    read_file(filename);
    delete_file(filename);

    return 0;
}
