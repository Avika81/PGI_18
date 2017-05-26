#include "Sum.h"



double Sum::eval()
{
	return pLeft->eval()+pRight->eval();
}

double Sum::eval(Assignment & assign)
{
	return pLeft->eval(assign) + pRight->eval(assign);
}

std::string Sum::toString() const
{
	string output = "";
	output += pLeft->toString();
	output += "+";
	output += pRight->toString();
	return output;
}

Expression * Sum::deepCopy()
{
	Sum* temp;
	temp = new Sum;
	temp->pLeft = this->pLeft->deepCopy();
	temp->pRight = this->pRight->deepCopy();
	return temp;
}

Expression* Sum::assign(char Symbol, Expression * expr)
{
	Sum* temp;
	temp = new Sum;
	temp->pLeft = this->pLeft->assign(Symbol, expr);
	temp->pRight = this->pRight->assign(Symbol, expr);
	return temp;
}

Sum::Sum()
{
}


Sum::~Sum()
{
}
