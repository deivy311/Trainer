#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

void Write() {
    std::ofstream out("data.txt", std::ios::binary);
    out << "Hello world" << std::endl;
    int number = 10;
    out.write(reinterpret_cast<char*>(&number), sizeof(number));
    out.close();
}

void Read() {
    std::ifstream input("data.txt", std::ios::binary);
    if (input.fail()) {
        std::cout << "Could not open the file" << std::endl;
        return;
    }
    // Read the contents (optional, can be implemented as needed)
    std::string line;
    while (std::getline(input, line)) {
        std::cout << line << std::endl;
    }
    input.close();
}

void CopyFile(const std::filesystem::path& source, const std::filesystem::path& destination) {
    if (!std::filesystem::exists(source)) {
        std::cerr << "Source file does not exist: " << source << std::endl;
        return;
    }

    if (std::filesystem::exists(destination)) {
        std::cerr << "Destination file already exists: " << destination << std::endl;
        return;
    }

    std::ifstream src(source, std::ios::binary);
    if (!src) {
        std::cerr << "Error opening source file for reading: " << source << std::endl;
        return;
    }

    std::ofstream dst(destination, std::ios::binary);
    if (!dst) {
        std::cerr << "Error opening destination file for writing: " << destination << std::endl;
        return;
    }

    // Get the size of the source file
    src.seekg(0, std::ios::end);
    std::streamsize size = src.tellg();
    src.seekg(0, std::ios::beg);

    // Read from source and write to destination
    char* buffer = new char[size]; // Dynamic buffer allocation
    if (src.read(buffer, size)) {
        dst.write(buffer, size);
    } else {
        std::cerr << "Error reading from source file" << std::endl;
    }

    delete[] buffer; // Free allocated memory
    src.close();
    dst.close();
    std::cout << "File copied from " << source << " to " << destination << std::endl;
}

void CopyDirectory(const std::filesystem::path& sourceDir, const std::filesystem::path& destinationDir) {
    if (!std::filesystem::exists(sourceDir) || !std::filesystem::is_directory(sourceDir)) {
        std::cerr << "Source directory does not exist or is not a directory: " << sourceDir << std::endl;
        return;
    }

    // Create destination directory if it does not exist
    std::filesystem::create_directories(destinationDir);

    std::vector<std::filesystem::path> files; // To keep track of files for progress display

    // Iterate through the source directory and copy each file
    for (const auto& entry : std::filesystem::directory_iterator(sourceDir)) {
        if (std::filesystem::is_regular_file(entry.status())) {
            files.push_back(entry.path());
        }
    }

    // Copy files and show progress
    for (size_t i = 0; i < files.size(); ++i) {
        const auto& file = files[i];
        std::filesystem::path destFile = destinationDir / file.filename();
        CopyFile(file, destFile);
        std::cout << "Progress: " << (i + 1) << "/" << files.size() << " files copied." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source> <destination>" << std::endl;
        return 1;
    }

    std::filesystem::path sourcePath = argv[1];
    std::filesystem::path destinationPath = argv[2];

    // Check if the source is a file or a directory
    if (std::filesystem::is_directory(sourcePath)) {
        CopyDirectory(sourcePath, destinationPath);
    } else if (std::filesystem::is_regular_file(sourcePath)) {
        CopyFile(sourcePath, destinationPath);
    } else {
        std::cerr << "Source is neither a file nor a directory." << std::endl;
        return 1;
    }

    return 0;
}
