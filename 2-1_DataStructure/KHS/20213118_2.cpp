#include <algorithm>
#include <iostream>
#include <cstring>
#include <random>
#include <cstdlib>
class Bizcard//����ī�� 
{
public:
	Bizcard(const char* nameF, const char* addressF, long office, long mobile) : office_phone(office), mobile_phone(mobile) {
		int lenName = strlen(nameF) + 1;
		int lenAddress = strlen(addressF) + 1;
		name = new char[lenName];
		address = new char[lenAddress];
		strcpy(name, nameF);
		strcpy(address, addressF);
	}
	Bizcard(){

	}
	Bizcard(const Bizcard& copy) :office_phone(copy.office_phone), mobile_phone(copy.mobile_phone) {
		name = new char[strlen(copy.name) + 1];
		address = new char[strlen(copy.address) + 1];
		strcpy(name, copy.name);
		strcpy(address, copy.address);
	}

	~Bizcard() {
		delete [] name;
		delete [] address;
	};
	void Showinfo() {
		std::cout << "�̸�: " << name << std::endl;
		std::cout << "�ּ�: " << address << std::endl;
		std::cout << "ȸ�� ��ȭ��ȣ: " << office_phone << std::endl;
		std::cout << "�ڵ��� ��ȣ: " << mobile_phone << std::endl;
	};
private:
	char* name=NULL;// 1.1 ��������� name, address, office_phone, mobile_phone�̴�. name�� address�� ���ڿ� ������ �����̸�, office_phone�� mobile_phone�� 11�ڸ� ������ �����ϴ� ���� �����̴�.
	char* address=NULL;
	long office_phone=0;
	long mobile_phone=0;
};

void ChangeSize1D(Bizcard*& a, const int b, const int c);

class Bag
{
public:
	Bag(int bagCapacity = 3):capacity(bagCapacity) {
		if (capacity < 1) std::cout << "Capacity must be > 0" << std::endl;
		else {
			array = new Bizcard[capacity];
			top = -1;
		}
	};
	~Bag() {
		delete[] array;
	};

	int Size() const {

		return top + 1;//top�� -1 �ּ� 0
	};
	bool IsEmpty() const {
		return Size() == 0;
	};
	
	Bizcard& Element() const {
		if (IsEmpty()) std::cout << "Bag is empty" << std::endl; 
			
		return array[rand()%(Size()+1)];
	};
	
		//std::cout << "Bag is empty" << std::endl;
	
	

	void Push(const Bizcard& x) {
		if (capacity == top + 1) {
			ChangeSize1D(array, capacity, 2 * capacity);
			capacity = 2*capacity;
		}
		array[++top] = x;
	};

	void Pop() {
		if (IsEmpty()) throw "Bag is empty, cannot delete";
		int deletePos = rand() % (Size() + 1);
		std::copy(array + deletePos + 1, array + top + 1, array + deletePos);
		top--;
	};

private:
	Bizcard* array;
	int capacity;
	int top=-1;
};//������� ���Ǻ�

void ChangeSize1D(Bizcard*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	Bizcard* temp = new Bizcard[newSize];                                  // new array
	int number = oldSize;  // number to copy
	std::copy(a, a + number, temp);
	delete[] a;                             // deallocate old memory
	a = temp;
};


int main() {
	Bizcard a("a", "a", 1, 1);
	Bizcard b("b", "b", 2, 2);
	Bizcard c("c", "c", 3, 3);
	Bizcard d("d", "d", 4, 4);
	Bizcard e("e", "e", 5, 5);
	Bizcard f("f", "f", 6, 6);
	Bizcard g("g", "g", 7, 7);


	Bag bag(3);

	


	std::cout << bag.Size() << std::endl;
	bag.IsEmpty();
	bag.Element();
	bag.Push(a);
	bag.Push(b);
	bag.Push(c);
	std::cout << bag.Size() << std::endl;
	bag.IsEmpty();
	bag.Element().Showinfo();
	
	bag.Push(d);
	bag.Push(e);
	bag.Push(f);
	bag.Push(g);
	std::cout << bag.Size() << std::endl;
	bag.IsEmpty();
	bag.Element().Showinfo();

	bag.Pop();
	bag.Pop();
	std::cout << bag.Size() << std::endl;
	bag.IsEmpty();
	bag.Element().Showinfo();

	

	return 0;
}