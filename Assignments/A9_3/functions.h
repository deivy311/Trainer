#include <utility>
#include <string>
#include <cstring>

// Sum in array
template <typename T, size_t N>
T ArraySum(const T (&pArr)[N])
{
    T sum = 0;
    for (size_t i = 0; i < N; ++i)
    {
        sum += pArr[i];
    }
    return sum;
}

// Max in array
template <typename T, size_t N>
T Max(const T (&pArr)[N])
{
    T max = pArr[0];
    for (size_t i = 1; i < N; ++i)
    {
        if (pArr[i] > max)
        {
            max = pArr[i];
        }
    }
    return max;
}

// MinMax in array
template <typename T, size_t N>
std::pair<T, T> MinMax(const T (&pArr)[N])
{
    T min = pArr[0];
    T max = pArr[0];
    for (size_t i = 1; i < N; ++i)
    {
        if (pArr[i] < min)
        {
            min = pArr[i];
        }
        if (pArr[i] > max)
        {
            max = pArr[i];
        }
    }
    return std::make_pair(min, max);
}

// Max in const char* array
template <>
const char *Max<const char *, 3>(const char *const (&pArr)[3])
{
    const char *max = pArr[0];
    for (size_t i = 1; i < 3; ++i)
    {
        if (strcmp(pArr[i], max) > 0)
        {
            max = pArr[i];
        }
    }
    return max;
}

// MinMax in const char* array
template <>
std::pair<const char *, const char *> MinMax<const char *, 3>(const char *const (&pArr)[3])
{
    const char *min = pArr[0];
    const char *max = pArr[0];
    for (size_t i = 1; i < 3; ++i)
    {
        if (strcmp(pArr[i], min) < 0)
        {
            min = pArr[i];
        }
        if (strcmp(pArr[i], max) > 0)
        {
            max = pArr[i];
        }
    }
    return std::make_pair(min, max);
}

// Max in std::string array
template <>
std::string Max<std::string, 3>(const std::string (&pArr)[3])
{
    std::string max = pArr[0];
    for (size_t i = 1; i < 3; ++i)
    {
        if (pArr[i] > max)
        {
            max = pArr[i];
        }
    }
    return max;
}

// MinMax in std::string array
template <>
std::pair<std::string, std::string> MinMax<std::string, 3>(const std::string (&pArr)[3])
{
    std::string min = pArr[0];
    std::string max = pArr[0];
    for (size_t i = 1; i < 3; ++i)
    {
        if (pArr[i] < min)
        {
            min = pArr[i];
        }
        if (pArr[i] > max)
        {
            max = pArr[i];
        }
    }
    return std::make_pair(min, max);
}
