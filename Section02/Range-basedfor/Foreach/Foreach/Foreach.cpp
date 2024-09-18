#include <iostream>
int main() {
	// using namespace std;
	// int arr[] = { 1,2,3,4,5 };
	// for (int i = 0; i < 5; i++) {
	// 	cout << arr[i] << " ";
	// }
	// for (const auto & x : arr) {
		
	// 	cout << x << " ";
	// }
	// for (auto x : { 1,2,3,4 }) {
	// 	cout << x;
	// }
	// return 0;

	using namespace std;
	int arr[]= {1,2,3,4,5};

	for(int i=0;i<5;i++){
		cout << arr[i] << " ";
	}

	for( const auto &x: arr){
		cout << x << " ";
	}

	// int *beg = &arr[0]; //arr
	// int *end = &arr[5];
    // int *beg = std::begin(arr); //arr
	// // int *end = std::end(arr);
	// while(beg != end){
	// 	std::cout << *beg << ' ';
	// 	++beg;
	// }

	auto &&range =arr;
	auto begin = std::begin(range);
	auto end = std::end(range);
	for(;begin !=end;++begin){
		auto v =*begin;
	}

	return 0;
}