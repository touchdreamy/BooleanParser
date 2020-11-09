#ifndef _HEADER_CLASS_TABLE_TRUE_H_
#define _HEADER_CLASS_TABLE_TRUE_H_

class Table
{
private:
	int width; // ширина
	int height;// высота
	int ** matrix; // изначальная матрица
	int ** T;	   // таблица истинности
public:
	void SetWidth(const int x) { width = x; };
	void SetHeight(const int x) { height = x; };
	void CreateTable();
	int  **Transpose();
	void ReturnLine(const int num, int *arr); // получаем единую строку из таблицы истинности - 0 0 0 - допустим
	void Print();
};

#endif