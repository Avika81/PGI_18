#include "Max.h"

double Max::eval()
{
	if (pLeft->eval() > pRight->eval())
		return pLeft->eval();
	else
		return pRight->eval();

}

double Max::eval(Assignment & assign)
{
	if (this->pRight->eval(assign) > this->pLeft->eval(assign))
		return pRight->eval(assign);
	else
		return pLeft->eval(assign);
}

std::string Max::toString() const
{
	string output = "Max(";
	output += pLeft->toString();
	output += ",";
	output += pRight->toString();
	output += ")";
	return output;
}

Expression * Max::deepCopy()
{
	Max* temp;
	temp = new Max;
	temp->pLeft = this->pLeft->deepCopy();
	temp->pRight = this->pRight->deepCopy();
	return temp;
}

Expression* Max::assign(char Symbol, Expression * expr)
{
	Max* temp;
	temp = new Max;
	temp->pLeft = this->pLeft->assign(Symbol, expr);
	temp->pRight = this->pRight->assign(Symbol, expr);
	return temp;
}

Max::Max()
{
}


Max::~Max()
{
}
