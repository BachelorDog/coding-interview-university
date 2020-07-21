#include "array.h"

int main(){
	dynamicArray<int> testArray;
	bool empty = testArray.is_empty();
	std::cout << empty << std::endl;

	for (int i = 0; i < 10; ++i){
		testArray.push(i);
	}

	std::cout << testArray.get_size() << std::endl;
	std::cout << testArray.get_capacity() << std::endl;

	for (int i = 0; i < 10; ++i){
		testArray.push(i);
	}

	std::cout << testArray.get_size() << std::endl;
	std::cout << testArray.get_capacity() << std::endl;

	std::cout << testArray.at(10) << std::endl;

	testArray.prepend(10);
	std::cout << testArray.at(0) << std::endl;
	std::cout << testArray.pop() << std::endl;

	testArray.insert(10, 10);
	std::cout << testArray.at(10) << std::endl;

	testArray.del(10);
	testArray.remove(10);

	std::cout << testArray.find(10) << std::endl;
	return 0;
}


