#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "data.h"
#include "operations.h"
#include "TableTRUE.h"
#include "BoolOperations.h"
#include <math.h>
#include <string>

#define LENGTH 100

int PriorityOperation(char data)
{
	//if ((data == '(') || (data == ')')) return 9;
	if (data == '!') return 4;
	else if ((data == '*') || (data == '|')) return 3;
	else if ((data == '+') || (data == '#')) return 2;
	else return 1;

	/*if (data == '!') return 8;
	else if (data == '|') return 7;
	else if (data == '#') return 6;
	else if (data == '*') return 5;
	else if (data == '+') return 4;
	else if (data == '^') return 3;
	else if (data == '@') return 2;
	else if (data == '=') return 1;*/
}

bool Operation(bool x, bool y, char op)
{
	if (op == '!') return Inversion(x);
	if (op == '|') return Hatch(x,y);
	if (op == '#') return ArrowPirs(x,y);
	if (op == '*') return Сonjunction(x,y);
	if (op == '+') return Disjunction(x,y);
	if (op == '^') return Module(x, y);
	if (op == '@') return Implication(x, y);
	if (op == '=') return Equivalence(x, y);
}

void TreatmentInput(char data[LENGTH], Numbers &numbers, Operations &operations); // обработка входной строки !ДОПИСАТЬ ЗАЩИТКИ!

void Calculations(Numbers &numbers, Operations &operations, itemNUM *headNUM, itemOP *headOP, int *result, int & counter) 
// передаем заголовки на списки и массив для записи туда результата
// headNum и HeadOp - откуда начинать считать
{
	itemNUM *numberLEFT = headNUM;			 // "левое" значение - основное -
	itemNUM *numberRIGHT = numberLEFT->next; // "правое" значение
	itemOP  *operation = headOP;			 // верхняя операция - ходовая операция -
		
	int maxPriority = 1;
	int minPriority = 4;
	int countOperations = 0;

	// Поиск максимального приоритета в строке
	do {															
		if (PriorityOperation(operation->data) > maxPriority) {
			maxPriority = PriorityOperation(operation->data);
		}
		if (PriorityOperation(operation->data) < minPriority) {
			minPriority = PriorityOperation(operation->data);
		}
		countOperations++;
		operation = operation->next;
	} while (operation != nullptr);

	for (int priority = maxPriority; priority > minPriority - 1; priority--)	// цикл по приоритетам операций, с высшего к низшему
	{
		//cout << "pri = " << priority << endl;

		operation = headOP; // начинаем проверять с головы.
		numberLEFT = headNUM;       // числа гоним также с головы.
		int countThisPrior = 0;

		// Поиск кол-во операций с данным приоритетом в строке
		do {							
			if (PriorityOperation(operation->data) == priority) {
				countThisPrior++;
			}
			operation = operation->next;
		} while (operation != nullptr);

		operation = headOP; // начинаем проверять с головы.
		bool error = true;				 // ошибка, если в строке есть остались операции с данным приоритетом

		for (int i = 0; i < countThisPrior; i++)
		{
			operation = headOP;
			numberLEFT = headNUM;

			while (PriorityOperation(operation->data) != priority) {
				operation = operation->next;
				numberLEFT = numberLEFT->next;
			}
			if (PriorityOperation(operation->data) == priority)
			{
				if (operation->data != '!') {
					numberRIGHT = numberLEFT->next; // получили указатель на второе число
					numberLEFT->data = Operation(numberLEFT->data, numberRIGHT->data, operation->data); // операция выполняется, ответ записывается в "левое число", правое удаляется
					numbers.Delete(numberRIGHT);  // удалили второе значение
				}
				else {
					numberLEFT->data = Operation(numberLEFT->data, 0, operation->data);
				}
				
				operations.Delete(operation); // удалили выполнившуюся операцию
			}

		}

	}

	result[counter] = (int)numberLEFT->data;
	counter++;
	std::cout << "res = " << numberLEFT->data;
}

int main()
{
	Numbers numbers;
	Operations operations;

	char data[LENGTH];
	char tmp[LENGTH];
	int k = 0; // счетчик по массиву tmp
	int Fillcount = 0; // кол-во занесенных чисел в список
	int IndexOp1 = 0; // индекс операции операции (найдена после первого числа)

	std::cin.getline(data, LENGTH); // ввод изначальной строки

	TreatmentInput(data, numbers, operations);
	std::cout << std::endl;
	numbers.Print();
	std::cout << std::endl;
	operations.Print();
	std::cout << std::endl;

	int width = numbers.CountVariable() ;    // ширина
	int height = pow(2, width) ;			 // высота

	Table TableTrue;

	TableTrue.SetHeight(height);
	TableTrue.SetWidth(width);
	TableTrue.CreateTable();
	int **table = TableTrue.Transpose();
	TableTrue.Print();

	std::cout << std::endl;

	char **arrayVariable;						// массив название переменных				x y z
	int *valueVariable = new int [width];		// массив значений этих переменных			0 0 0
	int *result = new int[height];				// массив, хранящий результаты выполнения функции.
	int counter = 0;							// счетик для работы с массивом результатов

	for (size_t i = 0; i < height; i++)
	{
		result[i] = 0;
	}

	arrayVariable = numbers.ArrayUnique(width);

	numbers.CopyToBuffer();										// скопировали в буффер изначальные списки
	operations.CopyToBuffer();									// также закинули туда операции
	for (size_t i = 0; i < 1; i++)
	{
		TableTrue.ReturnLine(i, valueVariable);					 // номер строки в таблице передается
		itemNUM *headVar = numbers.head();
		itemOP  *headOp =  operations.head();
		numbers.SetData(arrayVariable, valueVariable, i, width); // номер строки в таблице передается
		Calculations(numbers, operations, headVar, headOp, result, counter);	     // произвели все операции. Осталось только головы
		std::cout << std::endl;

		itemNUM *head = numbers.head();							 // удалили голову.
		numbers.Delete(head);
		operations.~Operations();

		if (i != height-1) {
			numbers.InputFromBuffer();
			operations.InputFromBuffer();
		}

	}

	numbers.ClearBuffer(); 	// освободить память буфера

	int countSDNF = 0;
	int countSKNF = 0;

	for (size_t i = 0; i < height; i++)
	{
		if (result[i] == 0) countSKNF++;
		else countSDNF++;
	}


	for (int i = 0; i < height; i++) // по всем результатам функции 
	{
		// можно заранее узнать кол-во 0 и кол-во 1
		if (result[i] == 0) { // скнф
			std::cout << '(';
			for (int j = 0; j < width; j++) // по ширине
			{
				if (table[i][j] == 1) { std::cout << '!' << arrayVariable[j][0]; }
				else { std::cout << arrayVariable[j][0]; }
				if (j != width - 1) { std::cout << '+'; }
			}
			std::cout << ')';
			std::cout << '*';
			
		}

	}

	std::cout << std::endl;

	for (int i = 0; i < height; i++) // по всем результатам функции 
	{
		// можно заранее узнать кол-во 0 и кол-во 1
		if (result[i] == 1) { // сднф
			std::cout << '(';
			for (int j = 0; j < width; j++) // по ширине
			{
				if (table[i][j] == 0) { std::cout << '!' << arrayVariable[j][0]; }
				else { std::cout << arrayVariable[j][0]; }
				if (j != width - 1) { std::cout << '*'; }
			}
			std::cout << ')';
			std::cout << '+';
		}


	}

	



	itemOP *re = operations.head();
	itemNUM *ops = numbers.head();
	
	std::cout << std::endl;

	for (size_t i = 0; i < height; i++)
	{
		std::cout << result[i];
	}

	std::cout << std::endl;

	std::cout << std::endl << re << std::endl << ops;


	_getch();
	return 0;
}

void TreatmentInput(char data[LENGTH], Numbers &numbers, Operations &operations) 
{
	for (int i = 0; i <= strlen(data); ++i)  // закидываем все числа в список
	{
		if (i != strlen(data))
		{
			if (data[i] == '!' || data[i] == '|' || data[i] == '#' || data[i] == '*' || data[i] == '+' || data[i] == '^' || data[i] == '@' || data[i] == '=' || data[i] == '(' || data[i] == ')') {
				char x = data[i];
				operations.Add(x); // добавляем операцию
			}
		}
		if ((i != strlen(data)) && (data[i] != '!' && data[i] != '|' && data[i] != '#' && data[i] != '*' && data[i] != '+' && data[i] != '^' && data[i] != '@' && data[i] != '=' && data[i] != '(' && data[i] != ')'))
		{
			numbers.Add(data[i]);
		}
	}
}
