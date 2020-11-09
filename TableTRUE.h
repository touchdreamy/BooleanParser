#ifndef _HEADER_CLASS_TABLE_TRUE_H_
#define _HEADER_CLASS_TABLE_TRUE_H_

class Table
{
private:
	int width; // ������
	int height;// ������
	int ** matrix; // ����������� �������
	int ** T;	   // ������� ����������
public:
	void SetWidth(const int x) { width = x; };
	void SetHeight(const int x) { height = x; };
	void CreateTable();
	int  **Transpose();
	void ReturnLine(const int num, int *arr); // �������� ������ ������ �� ������� ���������� - 0 0 0 - ��������
	void Print();
};

#endif