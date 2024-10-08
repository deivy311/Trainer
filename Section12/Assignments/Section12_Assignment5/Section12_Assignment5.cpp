#include <iostream>
#include <vector>

// Primary template
template<typename T>
class PrettyPrinter {
	T *m_pData;
public:
	PrettyPrinter(T *data) : m_pData(data) {}

	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T* GetData() {
		return m_pData;
	}
};

// Explicit specialization of a member function for std::vector<int>
template<>
void PrettyPrinter<std::vector<int>>::Print() {
	std::cout << "{";
	for (const auto &x : *m_pData) {
		std::cout << x << " ";
	}
	std::cout << "}" << std::endl;
}

// Explicit specialization of PrettyPrinter for char*
template<>
class PrettyPrinter<char*> {
	char *m_pData;
public:
	PrettyPrinter(char *data) : m_pData(data) {}

	void Print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}

	char* GetData() {
		return m_pData;
	}
};

// Explicit specialization of the Print function for std::vector<std::vector<int>>
template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print() {
	std::cout << "{\n";
	for (const auto &innerVec : *m_pData) {
		std::cout << "    {";
		for (const auto &x : innerVec) {
			std::cout << x << " ";
		}
		std::cout << "},\n";
	}
	std::cout << "}" << std::endl;
}

int main() {
	// Example 1: PrettyPrinter for char*
	char *p{ "Hello world" };
	PrettyPrinter<char*> p3(p);
	p3.Print();

	// Example 2: PrettyPrinter for std::vector<int>
	std::vector<int> v{ 1, 2, 3, 4, 5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	pv.Print();

	// Example 3: PrettyPrinter for std::vector<std::vector<int>>
	std::vector<std::vector<int>> vv{ {1, 2, 3}, {4, 5, 6} };
	PrettyPrinter<std::vector<std::vector<int>>> ppv(&vv);
	ppv.Print();

	return 0;
}
