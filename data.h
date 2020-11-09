#ifndef _HEADER_CLASS_OF_DATE__H_
#define _HEADER_CLASS_OF_DATE__H_

#include <string>

struct itemNUM
{
	char variable;
	bool  data;
	itemNUM *next;
};

class Numbers
{
	itemNUM *Head;																// ��������� �� ������
	itemNUM *Last;																// ��������� �� ��������� �������
	itemNUM *HeadCopy;															// ��������� �� ������ � ���������������
	itemNUM *LastCopy;															// ...
	int x;
public:
	Numbers() { Head = nullptr; Last = nullptr; };								// �����������
	~Numbers();																	// ����������
	void CopyToBuffer();														// �������� � ������
	void InputFromBuffer();														// ����� ������� �� �������
	void ClearBuffer();															// ������� ������
	itemNUM *head() { return Head; };					
	void SetHead(itemNUM *tmp) { Head = tmp; };
	char** ArrayUnique(const int width);										// ������� ������ ���������� ����������
	void SetData(char**arrayVariable, int*valueVariable,const int num,const int width);
	int  Count();																// ��������� ������ ���-�� ���������� � ������
	int  CountVariable();														// ���-�� ���������� ����������
	void Add(char x);															// ���������� � ������ ����������
	void Print();																// ����� �� ����� ������ �����
	int  RequiredNumber(itemNUM *elem);											// ����������� ����� � ������
	void Delete(itemNUM *&elem);												// �������� �������
};


#endif