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
		std::cout << "{" << std::endl;
		for (size_t row = 0; row < m_pData->size(); ++row)
		{
			std::cout << "    {";
			for (size_t col = 0; col < (*m_pData)[row].size(); ++col)
			{
				std::cout << (*m_pData)[row][col];
				if (col < (*m_pData)[row].size() - 1)
					std::cout << ", ";
			}
			std::cout << "}";
			if (row < m_pData->size() - 1)
				std::cout << ",";
			std::cout << std::endl;
		}
		std::cout << "}" << std::endl;
	}
};

int main()
{
	std::vector<std::vector<int>> vv{{1, 2, 3}, {4, 5, 6}};
	PrettyPrinter<std::vector<std::vector<int>>> pvv(&vv);
	pvv.Print();
	return 0;
}
