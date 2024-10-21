#include <iostream>
#include <vector>
template <typename T>
class PrettyPrinter
{
    T *m_pData;

public:
    PrettyPrinter(T *data) : m_pData(data) {}

    void Print()
    {
        std::cout << "{" << *m_pData << "}" << std::endl;
    }

    T *GetData()
    {
        return m_pData;
    }
};


// Specialization of the Print function for std::vector<std::vector<int>>
template <>
void PrettyPrinter<std::vector<std::vector<int>>>::Print(){
    std::cout << "{" << std::endl;
    for (const auto &innerVec : *m_pData)
    {
        std::cout << "    {";
        for (const auto &x : innerVec)
        {
            std::cout << x << ",";
        }
        std::cout << "\b}"; // Remove the last comma
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}

int main()
{

    std::vector<std::vector<int>> vv{{1, 2, 3}, {4, 5, 6}};
    PrettyPrinter<std::vector<std::vector<int>>> pvv(&vv);
    pvv.Print();
    return 0;
}