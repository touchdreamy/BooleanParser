#ifndef _HEADER_CLASS_OF_OPERATION__H_
#define _HEADER_CLASS_OF_OPERATION__H_

struct itemOP {
	char data;
	itemOP *next;
};

class Operations
{
	itemOP *Head; // ��������� �� ������
	itemOP *Last;  // ��������� �� ��������� �������
	itemOP *HeadCopy;															// ��������� �� ������ � ���������������
	itemOP *LastCopy;															// ...
	int x;
public:
	Operations() { Head = nullptr; };		// �����������
	~Operations();							// ����������
	void CopyToBuffer();
	void InputFromBuffer();
	int  Count();
	itemOP *head() { return Head; };
	void SetHead(itemOP *tmp) { Head = tmp; };
	void Add(char x); // ���������� � ������ ����� ��������
	void Print();		   // ����� �� ����� ������ ��������
	int RequiredNumber(itemOP *elem); // ����������� ����� � ������
	void Delete(itemOP *elem);
};


#endif