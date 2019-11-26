#include <iostream>

int fibo(int i) {
	int result;

	if (i == 0) {
		return 0;
	}
	
	else if (i == 1) {
		return 1;
	}

	else {
		result = fibo(i-1) + fibo(i-2);
	}
}

int main(void) {
	int i;
	std::cin>>i;
	int val = fibo(i);

	std::cout << val << std::endl;
	return 0;
}
