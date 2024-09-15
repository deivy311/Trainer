import os
import sys

def convert_name(name):
    """Convert a name by removing spaces and capitalizing the first letter of each word."""
    return ''.join(word.capitalize() for word in name.split())

def is_in_excluded_directory(path, base_dir, excluded_dirs):
    """Check if a given path is inside any of the excluded directories."""
    relative_path = os.path.relpath(path, base_dir)
    return any(part.lower() in excluded_dirs for part in relative_path.split(os.sep))

def rename_files_and_directories(base_dir):
    """Recursively rename files and directories, skipping excluded directories and files."""
    # Directories to exclude
    excluded_dirs = {'.git', 'cmakefiles', '.vscode'}

    # Collect all items to rename
    items_to_rename = []

    # Walk the directory tree
    for root, dirs, files in os.walk(base_dir, topdown=False):
        print(f"Processing directory: {root}")  # Debug statement

        # Filter out excluded directories
        dirs[:] = [d for d in dirs if d.lower() not in excluded_dirs]

        # Process files
        cpp_files = []
        for filename in files:
            old_file_path = os.path.join(root, filename)
            if is_in_excluded_directory(old_file_path, base_dir, excluded_dirs):
                continue  # Skip files inside excluded directories

            # Delete .sln files
            if filename.endswith('.sln'):
                print(f"Deleting .sln file: {old_file_path}")
                os.remove(old_file_path)
                continue

            # Collect .cpp files
            if filename.endswith('.cpp'):
                cpp_files.append(filename)

            # Rename files (remove spaces and capitalize)
            new_filename = convert_name(filename)
            if new_filename != filename:
                new_file_path = os.path.join(root, new_filename)
                items_to_rename.append((old_file_path, new_file_path))

        # Rename main .cpp file to match folder name
        if cpp_files:
            main_cpp_file = None
            if 'main.cpp' in cpp_files:
                main_cpp_file = 'main.cpp'
            elif len(cpp_files) == 1:
                main_cpp_file = cpp_files[0]
            else:
                # If multiple .cpp files, you may specify which one is the main file
                print(f"Multiple .cpp files in '{root}', cannot determine main file.")
                main_cpp_file = None

            if main_cpp_file:
                old_main_cpp_path = os.path.join(root, main_cpp_file)
                folder_name = os.path.basename(root)
                # Remove spaces and capitalize folder name
                new_main_cpp_name = convert_name(folder_name) + '.cpp'
                new_main_cpp_path = os.path.join(root, new_main_cpp_name)
                if old_main_cpp_path != new_main_cpp_path:
                    items_to_rename.append((old_main_cpp_path, new_main_cpp_path))
                    print(f"Renaming main .cpp file: '{old_main_cpp_path}' -> '{new_main_cpp_path}'")

        # Process directories
        for dirname in dirs:
            old_dir_path = os.path.join(root, dirname)
            if is_in_excluded_directory(old_dir_path, base_dir, excluded_dirs):
                continue  # Skip excluded directories
            new_dirname = convert_name(dirname)
            if new_dirname != dirname:
                new_dir_path = os.path.join(root, new_dirname)
                items_to_rename.append((old_dir_path, new_dir_path))

    if not items_to_rename:
        print("No files or directories to rename.")
    else:
        # Sort items to ensure correct renaming order
        items_to_rename.sort(key=lambda x: (-x[0].count(os.sep), x[0]))

        # Rename collected items
        for old_path, new_path in items_to_rename:
            if not os.path.exists(old_path):
                continue  # Skip if the old path doesn't exist
            if os.path.exists(new_path):
                print(f"Cannot rename '{old_path}' to '{new_path}': Target already exists.")
                continue
            print(f"Renaming '{old_path}' to '{new_path}'")
            os.rename(old_path, new_path)

    # Rename the base directory if necessary
    base_dir_name = os.path.basename(base_dir)
    new_base_dir_name = convert_name(base_dir_name)
    if new_base_dir_name != base_dir_name:
        new_base_dir_path = os.path.join(os.path.dirname(base_dir), new_base_dir_name)
        if os.path.exists(new_base_dir_path):
            print(f"Cannot rename base directory '{base_dir}' to '{new_base_dir_path}': Target already exists.")
        else:
            print(f"Renaming base directory '{base_dir}' to '{new_base_dir_path}'")
            os.rename(base_dir, new_base_dir_path)

if __name__ == "__main__":
    base_directory = os.getcwd()  # Use the current working directory
    if not os.path.isdir(base_directory):
        print(f"Error: The directory '{base_directory}' does not exist or cannot be accessed.")
        sys.exit(1)
    rename_files_and_directories(base_directory)
