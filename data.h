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
	itemNUM *Head;																// указатель на голову
	itemNUM *Last;																// указатель на последний элемент
	itemNUM *HeadCopy;															// указатель на голову у скоропированной
	itemNUM *LastCopy;															// ...
	int x;
public:
	Numbers() { Head = nullptr; Last = nullptr; };								// конструктор
	~Numbers();																	// деструктор
	void CopyToBuffer();														// копируем в буффер
	void InputFromBuffer();														// берем обратно из буффера
	void ClearBuffer();															// очищаем буффер
	itemNUM *head() { return Head; };					
	void SetHead(itemNUM *tmp) { Head = tmp; };
	char** ArrayUnique(const int width);										// создаем массив уникальных переменных
	void SetData(char**arrayVariable, int*valueVariable,const int num,const int width);
	int  Count();																// получение общего кол-ва переменных в списке
	int  CountVariable();														// кол-во уникальных переменных
	void Add(char x);															// добавление в список переменной
	void Print();																// вывод на экран список чисел
	int  RequiredNumber(itemNUM *elem);											// необходимый номер в список
	void Delete(itemNUM *&elem);												// удаление лишнего
};


#endif