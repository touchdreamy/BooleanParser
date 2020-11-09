#ifndef _HEADER_BOOL_OPERATIONS_H_
#define _HEADER_BOOL_OPERATIONS_H_

bool Inversion(bool x);			  // Отрицание " ! "
bool Hatch(bool x, bool y);		  // Штрих Шеффера " | "
bool ArrowPirs(bool x, bool y);   // Стрелка Пирса " # "
bool Сonjunction(bool x, bool y); // Конъюнкция (умножение) " * "
bool Disjunction(bool x, bool y); // Дизъюнкция (сложение) " + "
bool Module(bool x, bool y);	  // Сложение по модулю 2 " ^ "
bool Implication(bool x, bool y); // Импликация " @ "
bool Equivalence(bool x, bool y); // Эквивалентность " = "

#endif