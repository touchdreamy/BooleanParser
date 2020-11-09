#include "operations.h"
#include <iostream>

Operations::~Operations()
{
	/*while (Head != nullptr)
	{
		itemOP *tmp = Head->next;
		delete Head;
		Head = tmp;
	}*/
	delete Head;
}

void Operations::InputFromBuffer()
{
	itemOP *tmp = HeadCopy;
	Head = nullptr;
	Last = nullptr;

	while (tmp != nullptr)
	{
		char x = tmp->data;

		if (Head == nullptr)
		{
			itemOP *tmp = new itemOP;
			tmp->data = x;
			tmp->next = nullptr;
			Head = tmp;
			Last = tmp;
		}
		else {
			itemOP *tmp = new itemOP;
			Last->next = tmp;
			Last->next->data = x;
			Last->next->next = nullptr;
			Last = Last->next;
		}

		tmp = tmp->next;
	}
}

void Operations::CopyToBuffer()
{
	HeadCopy = nullptr;
	LastCopy = nullptr;
	itemOP *tmp = Head;
	while (tmp != nullptr) {
		if (HeadCopy == nullptr)
		{
			itemOP *newx = new itemOP;
			newx->data = tmp->data;
			newx->next = nullptr;
			HeadCopy = newx;
			LastCopy = newx;
		}
		else {
			itemOP *newx = new itemOP;
			LastCopy->next = newx;
			LastCopy->next->data = tmp->data;
			LastCopy->next->next = nullptr;
			LastCopy = LastCopy->next;
		}
		tmp = tmp->next;
	}
}

void Operations::Add(char x)
{
	if (Head == nullptr)
	{
		itemOP *tmp = new itemOP;
		tmp->data = x;
		tmp->next = nullptr;
		Head = tmp;
		Last = tmp;
	}
	else {
		itemOP *tmp = new itemOP;
		Last->next = tmp;
		Last->next->data = x;
		Last->next->next = nullptr;
		Last = Last->next;
	}
}

void Operations::Print()
{
	itemOP *tmp = Head;
	std::cout << "List of operations: ";
	while (tmp != nullptr) {
		std::cout << tmp->data << ' ';
		tmp = tmp->next;
	}
}

int Operations::Count() // кол-во элементов
{
	itemOP *tmp = Head;
	int k = 0;
	while (tmp != nullptr) {
		++k;
		tmp = tmp->next;
	}
	return k;
}


int Operations::RequiredNumber(itemOP *elem) // необходимый номер в cписке
{
	itemOP *tmp = Head;
	int k = 1;
	while (tmp != elem) {
		++k;
		tmp = tmp->next;
	}
	return k;
}

void Operations::Delete(itemOP *elem) // elem - указатель на удаляемый элемент.
{
	int num = RequiredNumber(elem);

	if (elem == Head) // если удаляемый элемент - голова
	{
		itemOP *tmp = nullptr;
		tmp = Head->next;
		delete Head;
		Head = tmp;
	}
	else if (num == Count()) // если это последний элемент
	{
		itemOP *tmp = Head;
		while (tmp->next != elem) {
			tmp = tmp->next;
		}
		tmp->next = nullptr;
		delete elem;
	}
	else
	{
		itemOP *p = elem->next;
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