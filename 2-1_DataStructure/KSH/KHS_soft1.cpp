#include <iostream>

using namespace std;

void divide(int a, int b, int* c, int* d);
int main() {
	int num1;
	int num2;
	int q;
	int r;
	int* pq = &q;
	int* pr = &r;

	std::cout << "ù��° �ǿ����� �Է�" << std::endl;
	std::cin >> num1;
	std::cout << "�ι�° �ǿ����� �Է�" << std::endl;
	std::cin >> num2;
	try{
		if (num1 == 0 or num2 == 0)
		{
			throw 0;
		}
		if (num1 != 0 and num2 != 0)
		{
			divide(num1, num2, pq, pr);
			cout << num1 << " / " << num2 << " = " << *pq << endl;
			cout << num1 << " % " << num2 << " = " << *pr << endl;
		}
	}
	catch(int expn){
		cout << "�ǿ����ڿ� 0�� ���� �� �����ϴ�" << endl;
		cout << "���α׷��� �ٽ� �����ϼ���" << endl;


	}
	
	


	return 0;
}
void divide(int a,int b,int* c,int*d) {
	*c = a / b;
	*d = a % b;


	return;
}