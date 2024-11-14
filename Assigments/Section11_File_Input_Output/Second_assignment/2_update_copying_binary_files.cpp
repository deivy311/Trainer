//1. Importing Required Libraries and Setting Up Namespace Alias
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;  // Alias for easier reference to std::filesystem

//########################################################################

//2. Function to Display Progress Bar

void show_progress(std::size_t bytesCopied, std::size_t totalBytes) {
    int barWidth = 50;  // Width of the progress bar
    float progress = static_cast<float>(bytesCopied) / totalBytes;
    int pos = barWidth * progress;

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();  // Ensures immediate output
}

//########################################################################

//3. Function to Copy a Single File with Progress

bool copy_file_with_progress(const fs::path& src, const fs::path& dest) {

    std::ifstream inFile(src, std::ios::binary);
    std::ofstream outFile(dest, std::ios::binary);

//handle exceptions
    if (!inFile) {
        std::cerr << "Error: Could not open source file " << src << '\n';
        return false;
    }
    if (!outFile) {
        std::cerr << "Error: Could not create destination file " << dest << '\n';
        return false;
    }



    std::size_t fileSize = fs::file_size(src);
    const std::size_t bufferSize = 4096;
    char buffer[bufferSize];
    std::size_t bytesCopied = 0;

    while (inFile) {
        inFile.read(buffer, bufferSize);
        std::size_t bytesRead = inFile.gcount();
        outFile.write(buffer, bytesRead);
        bytesCopied += bytesRead;
        show_progress(bytesCopied, fileSize);
    }

    std::cout << std::endl;  // Move to the next line after progress is complete
    return true;

}


//########################################################################

//4. Function to Copy an Entire Directory

void copy_directory(const fs::path& srcDir, const fs::path& destDir) {
    if (!fs::exists(destDir)) {
        fs::create_directories(destDir);
    }

    for (const auto& entry : fs::directory_iterator(srcDir)) {
        if (entry.is_regular_file()) {
            fs::path destPath = destDir / entry.path().filename();
            std::cout << "Copying " << entry.path().filename() << "...\n";
            if (!copy_file_with_progress(entry.path(), destPath)) {
                std::cerr << "Failed to copy file: " << entry.path() << "\n";
            }
        }
    }
}



//5. Main Function for Command-Line Handling and Execution
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source> <destination>\n";
        return 1;
    }

    fs::path source = argv[1];
    fs::path destination = argv[2];

    try {
        if (fs::exists(source)) {
            if (fs::is_directory(source)) {
                std::cout << "Copying directory: " << source << " to " << destination << "\n";
                copy_directory(source, destination);
            } else if (fs::is_regular_file(source)) {
                if (!fs::exists(destination.parent_path())) {
                    fs::create_directories(destination.parent_path());
                }
                std::cout << "Copying file: " << source << " to " << destination << "\n";
                if (!copy_file_with_progress(source, destination)) {
                    std::cerr << "Failed to copy file: " << source << "\n";
                    return 1;
                }
            } else {
                std::cerr << "Error: Source is neither a file nor a directory.\n";
                return 1;
            }
        } else {
            std::cerr << "Error: Source path does not exist.\n";
            return 1;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << "\n";
        return 1;
    }

    std::cout << "Copy operation completed successfully.\n";
    return 0;
}
