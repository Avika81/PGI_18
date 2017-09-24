#include "Div.h"

double Div::eval()
{
	return pLeft->eval() / pRight->eval();
}

double Div::eval(Assignment & assign)
{
	return pLeft->eval(assign) - pRight->eval(assign);
}

std::string Div::toString() const
{
	string output = "";
	output += pLeft->toString();
	output += "/";
	output += pRight->toString();
	return output;
}

Expression * Div::deepCopy()
{
	Div* temp;
	temp = new Div;
	temp->pLeft = this->pLeft->deepCopy();
	temp->pRight = this->pRight->deepCopy();
	return temp;
}

Expression* Div::assign(char Symbol, Expression * expr)
{
	Div* temp;
	temp = new Div;
	temp->pLeft = this->pLeft->assign(Symbol, expr);
	temp->pRight = this->pRight->assign(Symbol, expr);
	return temp;
}


Div::Div()
{
}


Div::~Div()
{
}
