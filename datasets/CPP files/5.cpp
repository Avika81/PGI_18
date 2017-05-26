#include "Abs.h"

double Abs::eval()
{
	return abs(m_expr->eval());
}

double Abs::eval(Assignment & assign)
{
	return abs((m_expr->eval(assign)));
}

std::string Abs::toString() const
{
	string output = "";
	output += "|";
	output += m_expr->toString();
	output += "|";
	return output;
}

Expression * Abs::deepCopy()
{
	Abs* temp;
	temp = new Abs;
	temp->m_expr = this->m_expr;
	return temp;
}

Expression * Abs::assign(char Symbol, Expression * expr)
{
	Abs* temp;
	temp = new Abs;
	temp->m_expr = m_expr->assign(Symbol, expr);
	return temp;
}

Abs::Abs()
{
}


Abs::~Abs()
{
}
