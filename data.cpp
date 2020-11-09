#include "data.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

void Numbers::SetData(char**arrayVariable, int*valueVariable,const int num,const int width)
{
	itemNUM *tmp = Head;
	while (tmp != nullptr)
	{
		char name = tmp->variable;
		int  index = 0;
		for (size_t i = 0; i < width; i++)
		{
			if (name == arrayVariable[i][0]) {
				index = i;

				break;
			}
		}
		tmp->data = valueVariable[index];
		tmp = tmp->next;
	}
}

Numbers::~Numbers()
{
	delete Head;
}

void Numbers::ClearBuffer()
{
	while (HeadCopy != nullptr)
	{
		itemNUM *tmp = HeadCopy->next;
		delete HeadCopy;
		HeadCopy = tmp;
	}
	delete HeadCopy;
}

char** Numbers::ArrayUnique(const int width)
{
	set <char> mySet; // пустое множество
	char **arr = new char*[width]; // массив переменных на выходе
	for (size_t i = 0; i < width; i++)
	{
		arr[i] = new char[1];
		arr[i][0] = '-';
	}

	itemNUM *tmp = Head;
	while (tmp != nullptr) 
	{
		mySet.insert(tmp->variable);
		tmp = tmp->next;
	}

	int k = 0;
	for (int i = 'A'; i <= 'z'; i++)
	{
		if (mySet.count(i) != 0) {
			arr[k][0] = (char)i;
			k++;
		}
	}

	return arr;
}

int Numbers::CountVariable()
{
	int UniqueCount = 0;
	itemNUM *tmp = Head;

	int ALL = 0; // всего переменных
	while (tmp != nullptr) {
		++ALL;
		tmp = tmp->next;
	}
	
	char *arr = new char[ALL]; // массив всех переменных
	tmp = Head;
	for (size_t i = 0; i < ALL; i++) 
	{
		arr[i] = tmp->variable;
		tmp = tmp->next;
	}

	for (size_t i = 0; i < ALL; i++)
	{
		size_t j = 0;
		while (j < i && arr[j] != arr[i]) ++j;

		UniqueCount += j == i;
	}

	return UniqueCount;
}

void Numbers::InputFromBuffer()
{
	itemNUM *tmp = HeadCopy;
	Head = nullptr;
	Last = nullptr;
	while (tmp != nullptr)
	{
		char x = tmp->variable;
		
		if (Head == nullptr)
		{
			itemNUM *tmp = new itemNUM;
			tmp->variable = x;
			tmp->next = nullptr;
			Head = tmp;
			Last = tmp;
		}
		else {
			itemNUM *tmp = new itemNUM;
			Last->next = tmp;
			Last->next->variable = x;
			Last->next->next = nullptr;
			Last = Last->next;
		}

		tmp = tmp->next;
	}
}


void Numbers::Add(char x) 
{
	if (Head == nullptr)
	{
		itemNUM *tmp = new itemNUM;
		tmp->variable = x;
		tmp->next = nullptr;
		Head = tmp;
		Last = tmp;
	}
	else {
		itemNUM *tmp = new itemNUM;
		Last->next = tmp;
		Last->next->variable = x;
		Last->next->next = nullptr;
		Last = Last->next;
	}
}

void Numbers::CopyToBuffer()
{
	HeadCopy = nullptr;
	LastCopy = nullptr;
	itemNUM *tmp = Head;
	while (tmp != nullptr) {
		if (HeadCopy == nullptr)
		{
			itemNUM *newx = new itemNUM;
			newx->variable = tmp->variable;
			newx->next = nullptr;
			HeadCopy = newx;
			LastCopy = newx;
		}
		else {
			itemNUM *newx = new itemNUM;
			LastCopy->next = newx;
			LastCopy->next->variable = tmp->variable;
			LastCopy->next->next = nullptr;
			LastCopy = LastCopy->next;
		}
		tmp = tmp->next;
	}
}


void Numbers::Print()
{
	itemNUM *tmp = Head;
	std::cout << "List of nubmers: ";
	while (tmp != nullptr) {
		cout << tmp->variable << ' ';
		tmp = tmp->next;
	}
}

int Numbers::Count() // кол-во элементов
{
	itemNUM *tmp = Head;
	int k = 0;
	while (tmp != nullptr) {
		++k;
		tmp = tmp->next;
	}
	return k;
}

int Numbers::RequiredNumber(itemNUM *elem) // необходимый номер
{
	itemNUM *tmp = Head;
	int k = 1;
	while (tmp != elem) {
		++k;
		tmp = tmp->next;
	}
	return k;
}

void Numbers::Delete(itemNUM *&elem) // elem - указатель на удаляемый элемент.
{
	int num = RequiredNumber(elem); // получаем номер удаляемого элемента

	if (elem == Head) // если удаляемый элемент - голова
	{
		itemNUM *tmp = nullptr;
		tmp = Head->next;
		delete Head;
		Head = tmp;
	}
	else if (num == Count()) // если это последний элемент
	{
		itemNUM *tmp = Head;
		while (tmp->next != elem) {
			tmp = tmp->next;
		}
		tmp->next = nullptr;
		delete elem;
	}
	else
	{
		itemNUM *p = elem->next;
		int tmp;

		while (p->next != nullptr) {
			tmp = elem->data;
			elem->data = p->data;
			p->data = tmp;
			elem = elem->next;
			p = p->next;
		}
		tmp = elem->data;
		elem->data = p->data;
		p->data = tmp;
		elem->next = nullptr;
		delete p;
	}
}