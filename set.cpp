d#include<iostream>
#include "set.h"
using namespace std;

Set::Set(int a, int b)
{
	l = a;
	r = b;
	n = (r - l) / 8 + (bool)(r - l) % 8;//����� ������
	ptr = new char[n];
	for (int i = 0; i < n; ++i)
		ptr[i] = 0;

}

Set::~Set()
{
	delete[]ptr;	
}

Set::Set(const Set& obj)
{
	l = obj.l;
	r = obj.r;
	n = obj.n;
	ptr = new char[n];
	for (int i = 0; i < n; ++i)
	{
		ptr[i] = obj.ptr[i];
	}
}

bool Set::poisk(int a)
{
    setlocale(LC_ALL, "rus");
	if (a >= l && a <= r)
	{
		int byte = (a - l) / 8;//����� �����
		int bit = (a - l) % 8;//����� ����
		char mask = 1 << bit;
		if ((ptr[byte] & mask) != 0)
		{

			
			return 1;
		}
		else {
			
			return 0;
		}
	}
	else {
		cout << "�����" << " " << a << " " << " �� ����������� ��������� ���������" << endl;
		return 0;
	}
}

void Set::add(int b)
{
    setlocale(LC_ALL, "rus");
	if (b >= l && b <= r)
	{
		int byte = (b - l) / 8;
		int bit = (b - l) % 8;
		char mask = 1 << bit;//������ �����
		ptr[byte] |= mask;//��������� ��� �� �����
	}
	else
		cout << "�����" << " " << b << " " << "�� ����������� ��������� ���������" << endl;

}

void Set::del(int c)
{
	int byte, bit;
	char maska;
	//��������� ������ ����� � ����, ���������� �� k
	byte = (c - l) / 8;
	bit = (c - l) % 8;
	//������ �����
	maska = ~(1 << bit);//��������
	//������� ��� �� �����
	ptr[byte] &= maska;
}

bool Set::search(int a)
{
    setlocale(LC_ALL, "rus");
	if (a >= l && a <= r)
	{
		int byte = (a - l) / 8;//����� �����
		int bit = (a - l) % 8;//����� ����
		char mask = 1 << bit;
		if ((ptr[byte] & mask) != 0)
		{

			cout << "����� " << dec << a << " ���� � ���������\n" << endl;
			return 1;
		}
		else {
			cout << "����� " << dec << a << " �� �������"<<endl;
			return 0;
		}
	}
	else {
		cout << "�����" << " " << a << " " << " �� ����������� ��������� ���������" << endl;
		return 0;
	}
}





ostream& operator<<(ostream& potok, Set& C)
{
    
	potok << "{";
	int byte = 0;
	int bit = 0;
	char maska = 1;
	int count = 0;
	for (int i = 0; i <= (C.r - C.l); i++)
	{
		if (C.poisk(C.l + i)) count++;
	}
	for (int it = 0; byte <= C.n - 1; )
	{
		if (((C.ptr[byte] & maska) != 0) && ((C.r - C.l) >= bit + byte * 8))
		{
			potok << dec << C.l + 8 * byte + bit;
			it++;
			if (it < count) potok << ",";
		}
		if (bit == 7)
		{
			bit = 0;
			byte++;
			maska = 1;
		}
		else
		{
			bit++;
			maska = 1 << bit;
		}

	}
	potok << "}    ";
	for (int i = 0; i < C.n; ++i)
		cout << i << "-� ����:" << bitset < sizeof(C.ptr[i]) * 8>(C.ptr[i]) << " ";
	cout << endl;
	return potok;
}

Set operator+(Set A, Set B)
{
	Set C(A.l, A.r);
	for (int i = 0; i < C.n; ++i)
	{
		C.ptr[i] = A.ptr[i] | B.ptr[i];
	}

	return C;
}

Set operator*(Set A, Set B)
{

	Set C(A.l, A.r);
	for (int i = 0; i < C.n; ++i)
	{
		C.ptr[i] = A.ptr[i] & B.ptr[i];
	}

	return C;
}

Set operator-(Set A, Set B)
{
	Set C(A.l, A.r);
	for (int i = 0; i < C.n; ++i)
	{
		C.ptr[i] = A.ptr[i] & (~(B.ptr[i]));
	}

	return C;
}

Set operator~(Set A)
{
	Set C(A.l, A.r);
	for (int i = 0; i < C.n; ++i)
	{
		C.ptr[i] = ~(A.ptr[i]);
	}

	return C;
}