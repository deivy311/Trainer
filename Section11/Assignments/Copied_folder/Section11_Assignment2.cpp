#include <iostream>
#include <filesystem>
#include <fstream>
#include <iomanip> // For progress bar formatting
#include <string>

namespace fs = std::filesystem;

// Function to display the copy progress as a percentage
void show_progress(uintmax_t bytes_copied, uintmax_t file_size) {
    int progress = static_cast<int>((static_cast<double>(bytes_copied) / file_size) * 100);
    std::cout << "\rProgress: [" << std::setw(3) << progress << "%]" << std::flush;
}

// Function to copy a single file with progress display
void copy_file_with_progress(const fs::path& source, const fs::path& target) {
    std::ifstream src(source, std::ios::binary);
    std::ofstream dst(target, std::ios::binary);

    if (!src.is_open() || !dst.is_open()) {
        std::cerr << "Failed to open file(s) for copying.\n";
        return;
    }

    // Get the file size
    uintmax_t file_size = fs::file_size(source);
    uintmax_t bytes_copied = 0;
    const size_t buffer_size = 4096;
    char buffer[buffer_size];

    // Copy the file in chunks and display progress
    while (src.read(buffer, buffer_size)) {
        dst.write(buffer, src.gcount());
        bytes_copied += src.gcount();
        show_progress(bytes_copied, file_size);
    }

    // Copy any remaining bytes
    dst.write(buffer, src.gcount());
    bytes_copied += src.gcount();
    show_progress(bytes_copied, file_size);

    std::cout << "\nFile copied: " << source << " -> " << target << std::endl;
}

// Function to copy the contents of a directory
void copy_directory(const fs::path& source, const fs::path& target) {
    if (!fs::exists(target)) {
        fs::create_directories(target);
    }

    for (const auto& entry : fs::recursive_directory_iterator(source)) {
        const auto& path = entry.path();
        auto relative_path = fs::relative(path, source);
        fs::path target_path = target / relative_path;

        if (fs::is_directory(path)) {
            fs::create_directories(target_path); // Create directories recursively
        } else if (fs::is_regular_file(path)) {
            copy_file_with_progress(path, target_path); // Copy files with progress
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <source_path> <target_path>\n";
        return 1;
    }

    fs::path source = argv[1];
    fs::path target = argv[2];

    if (!fs::exists(source)) {
        std::cerr << "Error: Source path does not exist.\n";
        return 1;
    }

    if (fs::is_directory(source)) {
        std::cout << "Copying directory...\n";
        copy_directory(source, target);
    } else if (fs::is_regular_file(source)) {
        if (!fs::exists(target.parent_path())) {
            fs::create_directories(target.parent_path());
        }
        copy_file_with_progress(source, target);
    } else {
        std::cerr << "Error: Invalid source path.\n";
        return 1;
    }

    std::cout << "Copy operation completed successfully.\n";
    return 0;
}
