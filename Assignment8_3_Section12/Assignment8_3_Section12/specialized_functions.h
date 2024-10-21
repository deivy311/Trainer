#include <vector>
#include <cstring> // For strcmp

// Specialized function for const char*
template <size_t N>
int ArraySum(const char* const (&arr)[N]){
    return 0; // no sum for an array of C-style strings
} 
// Specialized function for std::string
template <size_t N>
int ArraySum(const std::string (&arr)[N]){
    return 0; // no sum for an array 
} 
// Specialized function to find the maximum string for const char*
template <size_t N>
const char* Max(const char* const (&arr)[N]) {
    const char* max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (strcmp(arr[i], max) > 0) {
            max = arr[i];
        }
    }
    return max;
}

// Specialized function to find min and max for const char*
template <size_t N>
std::pair<const char*, const char*> MinMax(const char* const (&arr)[N]) {
    const char* minVal = arr[0];
    const char* maxVal = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (strcmp(arr[i], minVal) < 0) {
            minVal = arr[i];
        }
        if (strcmp(arr[i], maxVal) > 0) {
            maxVal = arr[i];
        }
    }
    return std::make_pair(minVal, maxVal);
}

// Specialization for Max (std::string)
template <size_t N>
std::string Max(const std::string(&arr)[N]) {
    std::string maxVal = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Specialized function to find min and max for std::string array
template <size_t N>
std::pair<std::string, std::string> MinMax(const std::string (&arr)[N]) {
    std::string minVal = arr[0];
    std::string maxVal = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return std::make_pair(minVal, maxVal);
}

