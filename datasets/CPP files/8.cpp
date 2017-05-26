#include "Pow.h"

double Pow::eval()
{
	return pow(this->pRight->eval(), this->pLeft->eval());
}

double Pow::eval(Assignment & assign)
{
	return pow(this->pRight->eval(assign),this->pLeft->eval(assign));
}

std::string Pow::toString() const
{
	string output = "";
	output += pLeft->toString();
	output += "^";
	output += pRight->toString();
	return output;
}

Expression * Pow::deepCopy()
{
	Pow* temp;
	temp = new Pow;
	temp->pLeft = this->pLeft->deepCopy();
	temp->pRight = this->pRight->deepCopy();
	return temp;
}

Expression* Pow::assign(char Symbol, Expression * expr)
{
	Pow* temp;
	temp = new Pow;
	temp->pLeft = this->pLeft->assign(Symbol, expr);
	temp->pRight = this->pRight->assign(Symbol, expr);
	return temp;
}

Pow::Pow()
{
}


Pow::~Pow()
{
}
