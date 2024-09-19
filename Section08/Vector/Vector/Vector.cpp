#include <iostream>
#include <vector>
int main() {

	// old fashion methods
	int arr[10];
	int *ptr = new int[10];
	for (int i = 0; i < 10; ++i) {
		ptr[i] = i * 10;
	}


//dynamic memory
	std::vector<int> data{ 1,2,3 };
	for (int i = 0; i < 5; ++i) {
		data.push_back(i * 10);  //push back allows me to add values as many as I want ( at the end)
	}


	//Access
	data[0] = 100;
//(1)
	// for (int i = 0; i <data.size(); ++i){
	// 	std::cout << data[i] << " ";
	// }
	
//(2)
	// for (auto x : data) {
	// 	std::cout << x << " ";
	// }

//(3) iterator

	auto it = data.begin();
	//std::cout << *it;
	++it;

	//--it;
	it = it + 5;





	// //Delete
	// it = data.begin();
	// data.erase(it);
	// std::cout << std::endl;
	// for (auto x : data) {
	// 	std::cout << x << " ";
	// }




	// //Insert
	it = data.begin() + 5;
	data.insert(it, 500);
	std::cout << std::endl;
	for (auto x : data) {
		std::cout << x << " ";
	}
	return 0;
}