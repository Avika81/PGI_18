#include "Min.h"

double Min::eval()
{
	if (pLeft->eval() < pRight->eval())
		return pLeft->eval();
	else
		return pRight->eval();

}

double Min::eval(Assignment & assign)
{
	if (this->pRight->eval(assign) < this->pLeft->eval(assign))
		return pRight->eval(assign);
	else
		return pLeft->eval(assign);
}

std::string Min::toString() const
{
	string output = "Min(";
	output += pLeft->toString();
	output += ",";
	output += pRight->toString();
	output += ")";
	return output;
}

Expression * Min::deepCopy()
{
	Min* temp;
	temp = new Min;
	temp->pLeft = this->pLeft->deepCopy();
	temp->pRight = this->pRight->deepCopy();
	return temp;
}

Expression* Min::assign(char Symbol, Expression * expr)
{
	Min* temp;
	temp = new Min;
	temp->pLeft = this->pLeft->assign(Symbol, expr);
	temp->pRight = this->pRight->assign(Symbol, expr);
	return temp;
}


Min::Min()
{
}


Min::~Min()
{
}
