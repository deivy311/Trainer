import os

def print_all_directories(base_dir):
    """Recursively print all directories relative to base_dir, excluding the .git directory."""
    for root, dirs, files in os.walk(base_dir):
        # Exclude the .git directory
        if '.git' in dirs:
            dirs.remove('.git')  # Don't visit .git subdirectories
        if 'build' in dirs:
            dirs.remove('build')  # Don't visit .git subdirectories
        for dir_name in dirs:
            dir_path = os.path.join(root, dir_name)
            relative_path = os.path.relpath(dir_path, base_dir)
            print(relative_path)

if __name__ == "__main__":
    base_directory = os.getcwd()  # Use the current working directory
    print_all_directories(base_directory)
