#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// Function to copy a single file
void copyFile(const fs::path& srcFile, const fs::path& destPath) {
    fs::path destFile = destPath;

    // Check if the destination is a directory
    if (fs::is_directory(destPath)) {
        // Append the source file name to the destination directory
        destFile /= srcFile.filename();
    }

    std::ifstream src(srcFile, std::ios::binary);
    std::ofstream dest(destFile, std::ios::binary);

    if (!src) {
        std::cerr << "Error: Cannot open source file: " << srcFile << std::endl;
        return;
    }
    if (!dest) {
        std::cerr << "Error: Cannot open destination file: " << destFile << std::endl;
        return;
    }

    std::cout << "Copying " << srcFile << " to " << destFile << " .......... ";
    dest << src.rdbuf(); // Copy file content
    std::cout << "Done!" << std::endl;
}

// Function to copy the directory contents recursively
void copyDirectory(const fs::path& srcDir, const fs::path& destDir) {
    // Create the destination directory if it doesn't exist
    if (!fs::exists(destDir)) {
        fs::create_directories(destDir);
    }

    // Loop through each file/directory in the source directory
    for (const auto& entry : fs::directory_iterator(srcDir)) {
        const fs::path& srcPath = entry.path();
        fs::path destPath = destDir / srcPath.filename();

        if (fs::is_directory(srcPath)) {
            // Recursively copy directories
            std::cout << "Creating directory " << destPath << std::endl;
            copyDirectory(srcPath, destPath);
        } else if (fs::is_regular_file(srcPath)) {
            // Copy regular files
            copyFile(srcPath, destPath);
        }
    }
}

// Main function that prompts user for source and destination
int main() {
    std::string sourceInput, destinationInput;
    char choice;

    std::cout << "Do you want to copy a file or a directory? (f for file / d for directory): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any leftover characters in the input buffer

    // Convert choice to lowercase to ensure case-insensitive comparison
    choice = std::tolower(choice);

    if (choice == 'f') {
        // File copy mode
        std::cout << "Enter the source file path: ";
        std::getline(std::cin, sourceInput);
        fs::path sourcePath(sourceInput);

        std::cout << "Enter the destination file path or directory: ";
        std::getline(std::cin, destinationInput);
        fs::path destPath(destinationInput);

        if (!fs::exists(sourcePath) || !fs::is_regular_file(sourcePath)) {
            std::cerr << "Error: Source file does not exist or is not a valid file." << std::endl;
            return 1;
        }

        // Copy the file, appending the source file name if the destination is a directory
        copyFile(sourcePath, destPath);

    } else if (choice == 'd') {
        // Directory copy mode
        std::cout << "Enter the source directory path: ";
        std::getline(std::cin, sourceInput);
        fs::path sourcePath(sourceInput);

        std::cout << "Enter the destination directory path: ";
        std::getline(std::cin, destinationInput);
        fs::path destPath(destinationInput);

        if (!fs::exists(sourcePath) || !fs::is_directory(sourcePath)) {
            std::cerr << "Error: Source directory does not exist or is not a valid directory." << std::endl;
            return 1;
        }

        std::cout << "Copying directory..." << std::endl;
        copyDirectory(sourcePath, destPath);

    } else {
        std::cerr << "Invalid choice! Please enter 'f' for file or 'd' for directory." << std::endl;
        return 1;
    }

    std::cout << "Operation completed successfully!" << std::endl;
    return 0;
}
