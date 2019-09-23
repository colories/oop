#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	char target[] = "Kim JungHyun";
	long b[983];	// 자신의 학번 마지막 세자리
	int a = 17;
	int i = 7892;	
	int *c = new int[601];
	char * copy = "is no no";
	char name = 'a';	// 자신의 학번 4, 5, 6번째 자리 

	cout << "in rodata - copy의 참조주소 : \t" << copy << endl;
	cout << "in heap - c[0]의 참조주소 : \t" << &c[0] << endl;
	cout << "in heap - c[600]의 참조주소 : \t" << &c[600] << endl;
	cout << "in Stack - target의 주소 : \t" << &target << endl;
	cout << "in Stack - b[982]의 주소 : \t" << &b[982] << endl;
	cout << "in Stack - b[0]의 주소 : \t" << &b[0] << endl;
       	cout << "in Stack - a의 주소 : \t\t" << &a << endl;	
	cout << "in Stack - i의 주소 : \t\t" << &i << endl;
	cout << "in Stack - c의 주소 : \t\t" << &c << endl;
	cout << "in Stack - copy의 주소 : \t" << &copy << endl;
	cout << "in Stack - name의 주소 : \t" << (int*)&name << endl;
	cout << "&name + i : " << &name+i << endl;

	return 0;
}
