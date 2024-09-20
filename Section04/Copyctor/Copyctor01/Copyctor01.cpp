#include "Integer.h"
#include <iostream>
#include <memory>
class IntPtr {
	Integer *m_p;
public:
	IntPtr(Integer *p) :m_p(p) {

	}
	~IntPtr() {
		delete m_p;
	}
	Integer *operator ->() {
		return m_p;
	}
	Integer & operator *() {
		return *m_p;
	}
};
void CreateInteger() {
	std::unique_ptr<Integer> p(new Integer);
	//auto p2(p);
	(*p).SetValue(3);
	//std::cout << p->GetValue() << std::endl; 
}
void Process(Integer val) {

}


int main() {
	Integer a(3);
	/*auto b(std::move(a));
	std::cout << a << std::endl;*/
	Process(std::move(a));
	return 0;

	Integer i(5);
	Integer i2(i);
	//shallow copy
	i =i2;
	int *p1 = new int(5);
	// shallow copy
	int *p2 = p1;
	// Deep Copy
    int *p3 = new int(*p1);

	std::cout << i.GetValue() << std::endl;
	return 0;
}

