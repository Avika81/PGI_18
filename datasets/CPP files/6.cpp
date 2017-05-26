#include "Mul.h"

double Mul::eval()
{
	return pLeft->eval() * pRight->eval();
}

double Mul::eval(Assignment & assign)
{
	return pLeft->eval(assign) * pRight->eval(assign);
}

std::string Mul::toString() const
{
	string output = "";
	output += pLeft->toString();
	output += "*";
	output += pRight->toString();
	return output;
}

Expression * Mul::deepCopy()
{
	Mul* temp;
	temp = new Mul;
	temp->pLeft = this->pLeft->deepCopy();
	temp->pRight = this->pRight->deepCopy();
	return temp;
}

Expression* Mul::assign(char Symbol, Expression * expr)
{
	Mul* temp;
	temp = new Mul;
	temp->pLeft = this->pLeft->assign(Symbol, expr);
	temp->pRight = this->pRight->assign(Symbol, expr);
	return temp;
}

Mul::Mul()
{
}


Mul::~Mul()
{
}
