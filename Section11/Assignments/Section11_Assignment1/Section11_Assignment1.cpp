#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

void CopyBinaryFile(const fs::path& sourcePath, const fs::path& destinationPath) {
    // Check if the source file exists
	std::cout << "Current path: " << fs::current_path() << std::endl;
    if (!fs::exists(sourcePath)) {
        std::cerr << "Error: Source file " << sourcePath << " does not exist." << std::endl;
        return;
    }

    // Prevent overwriting the destination file
    if (fs::exists(destinationPath)) {
        std::cerr << "Error: Destination file " << destinationPath << " already exists." << std::endl;
        return;
    }

    // Open the source file in binary mode for reading
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    if (!sourceFile) {
        std::cerr << "Error: Could not open source file." << std::endl;
        return;
    }

    // Open the destination file in binary mode for writing
    std::ofstream destinationFile(destinationPath, std::ios::binary);
    if (!destinationFile) {
        std::cerr << "Error: Could not open destination file." << std::endl;
        return;
    }

    // Get the size of the source file
    auto fileSize = fs::file_size(sourcePath);

    // Allocate a buffer to hold file contents
    char* buffer = new char[fileSize];

    // Read from the source file into the buffer
    sourceFile.read(buffer, fileSize);
    if (!sourceFile) {
        std::cerr << "Error: Could not read source file." << std::endl;
        delete[] buffer;
        return;
    }

    // Write the buffer contents to the destination file
    destinationFile.write(buffer, fileSize);
    if (!destinationFile) {
        std::cerr << "Error: Could not write to destination file." << std::endl;
    }

    // Clean up
    delete[] buffer;
    sourceFile.close();
    destinationFile.close();

    std::cout << "File copied successfully from " << sourcePath << " to " << destinationPath << "." << std::endl;
}

int main() {
    fs::path source = "/home/adasi/development/C++_Course/CPP_Course/Trainer/Section11/Assignments/Section11_Assignment1/Binary.bin"; // Source Path
    fs::path destination = "/home/adasi/development/C++_Course/CPP_Course/Trainer/Section11/Assignments/Section11_Assignment1/destination.bin";  // Example destination path

    // Copy binary file from source to destination
    CopyBinaryFile(source, destination);

    return 0;
}
