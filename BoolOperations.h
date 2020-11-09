#ifndef _HEADER_BOOL_OPERATIONS_H_
#define _HEADER_BOOL_OPERATIONS_H_

bool Inversion(bool x);			  // ��������� " ! "
bool Hatch(bool x, bool y);		  // ����� ������� " | "
bool ArrowPirs(bool x, bool y);   // ������� ����� " # "
bool �onjunction(bool x, bool y); // ���������� (���������) " * "
bool Disjunction(bool x, bool y); // ���������� (��������) " + "
bool Module(bool x, bool y);	  // �������� �� ������ 2 " ^ "
bool Implication(bool x, bool y); // ���������� " @ "
bool Equivalence(bool x, bool y); // ��������������� " = "

#endif