#include <iostream>

// extern "C" void Print(int *x) {

// }
// void Print(const int* x) {

// }

int Add(int a,int b){
	return a+b;
}

double AddDouble(double a,double b){
	return a+b;
}

extern "C" void Print(int *x){
	
}

//  void Print(const int* x){

//  }
int main() {
	// using namespace std;
	// int result = Add(3, 5);
	// cout << result << endl;
	// Add(3.1, 6.2);
	// const int x = 1;
	// Print(&x);
	// return 0;

	using namespace std;
	int result = Add(3,5);
	cout << result << endl;
	cout << Add(5.6,8.2) << endl;
	int x = 4;
	double y =6.7;
	Print(&x);
    return 0;
}