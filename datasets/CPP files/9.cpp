#include "Sub.h"

double Sub::eval()
{
	return pLeft->eval() - pRight->eval();
}

double Sub::eval(Assignment & assign)
{
	return pLeft->eval(assign) - pRight->eval(assign);
}

std::string Sub::toString() const
{
	string output = "";
	output += pLeft->toString();
	output += "-";
	output += pRight->toString();
	return output;
}

Expression * Sub::deepCopy()
{
	Sub* temp;
	temp = new Sub;
	temp->pLeft = this->pLeft->deepCopy();
	temp->pRight = this->pRight->deepCopy();
	return temp;
}

Expression* Sub::assign(char Symbol, Expression * expr)
{
	Sub* temp;
	temp = new Sub;
	temp->pLeft = this->pLeft->assign(Symbol, expr);
	temp->pRight = this->pRight->assign(Symbol, expr);
	return temp;
}

Sub::Sub()
{
}


Sub::~Sub()
{
}
