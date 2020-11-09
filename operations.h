#ifndef _HEADER_CLASS_OF_OPERATION__H_
#define _HEADER_CLASS_OF_OPERATION__H_

struct itemOP {
	char data;
	itemOP *next;
};

class Operations
{
	itemOP *Head; // УКАЗАТЕЛЬ НА ГОЛОВУ
	itemOP *Last;  // указатель на последний элемент
	itemOP *HeadCopy;															// указатель на голову у скоропированной
	itemOP *LastCopy;															// ...
	int x;
public:
	Operations() { Head = nullptr; };		// конструктор
	~Operations();							// деструктор
	void CopyToBuffer();
	void InputFromBuffer();
	int  Count();
	itemOP *head() { return Head; };
	void SetHead(itemOP *tmp) { Head = tmp; };
	void Add(char x); // добавление в список знака операции
	void Print();		   // вывод на экран список операций
	int RequiredNumber(itemOP *elem); // необходимый номер в список
	void Delete(itemOP *elem);
};


#endif