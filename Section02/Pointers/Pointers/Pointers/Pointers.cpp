#include <iostream>

void testReference( int &a)
{
	a++;
}
int main() {
	using namespace std;
	int x = 10;
	cout << &x << "\n";
	int *ptr = &x;
	//cout << *ptr << "\n";
	testReference(x);

	*ptr = 10 ;
	return 0; 
}