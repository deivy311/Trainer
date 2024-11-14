//Step 1: Import Required Libraries
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;   // Use `fs` as a shorthand for std::filesystem

//########################################################################


//Step 2: Define the Copy Function and Validate the Source File
bool copy_binary_file(const fs::path& src, const fs::path& dest) {
    // Check if the source file exists and is a regular file
    if (!fs::exists(src) || !fs::is_regular_file(src)) {
        std::cerr << "Source file does not exist or is not a regular file.\n";
        return false;
    }


    //Step 3: Check if the Destination File Exists to Prevent Overwriting
    if (fs::exists(dest)) {
        std::cerr << "Destination file already exists. Copy operation aborted to prevent overwriting.\n";
        return false;
    }

    //Step 4: Open the source file in binary mode for "" reading ""
    std::ifstream inFile(src, std::ios::binary);
    if (!inFile) {
        std::cerr << "Failed to open source file for reading.\n";
        return false;
    }

    //Step 5: Open the destination file in binary mode for "" writing ""
    std::ofstream outFile(dest, std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to open destination file for writing.\n";
        return false;
    }


    //Step 5: Determine File Size
    // Get the size of the source file
    std::size_t fileSize = fs::file_size(src);


//########################################################################

    //Step 6: Copy the file data in chunks
    const std::size_t bufferSize = 4096;  // Set buffer size for copying in chunks
    char buffer[bufferSize];
    
    while (fileSize > 0) {
        std::size_t bytesToRead = std::min(bufferSize, fileSize);
        inFile.read(buffer, bytesToRead);

        if (inFile.fail()) {
            std::cerr << "Error reading from source file.\n";
            return false;
        }

        outFile.write(buffer, bytesToRead);
        if (outFile.fail()) {
            std::cerr << "Error writing to destination file.\n";
            return false;
        }

        fileSize -= bytesToRead;
    }

    std::cout << "File copied successfully.\n";
    return true;
}

//#######################################################################################################################33

int main() {
    fs::path source = "source.bin";
    fs::path destination = "destination.bin";

    // Start copy operation and handle errors
    if (!copy_binary_file(source, destination)) {
        std::cerr << "Copy operation failed.\n";
    }

    return 0;
}
