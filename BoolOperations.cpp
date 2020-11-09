#include "BoolOperations.h"
#include <iostream>

bool Inversion(bool x) // !
{
	return !x;
}

bool Hatch(bool x, bool y) // |
{
	if (!x || !y) return 1;
	return 0;
}

bool ArrowPirs(bool x, bool y) // #
{
	if (!x && !y) return 1;
	return 0;
}

bool Ñonjunction(bool x, bool y) // *
{
	return (x && y);
}

bool Disjunction(bool x, bool y) // +
{
	return (x || y);
}

bool Module(bool x, bool y) // ^ 
{
	return x ^ y;
}

bool Implication(bool x, bool y) // @
{
	if (x == 1 && y == 0) return 0;
	return 1;
}

bool Equivalence(bool x, bool y) // =
{
	if (x == y) return 1;
	return 0;
}