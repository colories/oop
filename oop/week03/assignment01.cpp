#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 초기화되지 않은 전역변수, static변수를 저장하기 위한 bss변수 선언
int bss;

// 변경되지 않는 상수 값을 저장하기 위한 rodata 선언
char * rodata = "ABC";

// 전역변수 data 선언
int data = 1;

// 코드영역의 주소값을 출력하기 위한 code 선언 
int (*code)(void);

int main(void)
{
	// 지역변수 stack 선언
	int stack = 1;

	// heap 메모리 주소를 얻기 위한 동적 할당
	int* heap = new int[2];
	heap[0] = 0;
	heap[1] = 1;
	code = main;

	// 각 메모리 영역의 주소값 출력
	cout << "code\t" << (void*) code << endl;
	cout << "Rodata\t" << (void*) rodata << endl;
	cout << "data\t" << &data << endl;
	cout << "BSS\t" << &bss << endl;
	cout << "HEAP\t" << heap << endl;
	cout << "Stack\t" << &stack << endl;

	return 0;
}

	

	
