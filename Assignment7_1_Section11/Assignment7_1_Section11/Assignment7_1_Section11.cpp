#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

void Write()
{
    std::ofstream out("data.txt", std::ios::binary);
    out << "Hello world" << std::endl;
    int number = 10;
    out.write(reinterpret_cast<char *>(&number), sizeof(number));
    out.close();
}
void Read()
{
    std::ifstream input("data.txt", std::ios::binary);
    if (input.fail())
    {
        std::cout << "could not open the file" << std::endl;
        return;
    }
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

int main() {
    Write();
    Read();
    
    // Example of using the CopyFile function
    std::filesystem::path sourcePath = "data.txt";
    std::filesystem::path destinationPath = "data_copy.txt";
    
    CopyFile(sourcePath, destinationPath);

    return 0;
}