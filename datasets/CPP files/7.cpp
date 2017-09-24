#include "Neg.h"



double Neg::eval()
{
	return -(m_expr->eval());
}

double Neg::eval(Assignment & assign)
{
	return -(m_expr->eval(assign));
}

std::string Neg::toString() const
{
	string output = "";
	output += "-";
	output += m_expr->toString();
	return output;
}

Expression * Neg::deepCopy()
{
	Neg* temp;
	temp = new Neg;
	temp->m_expr = this->m_expr;
	return temp;
}

Expression * Neg::assign(char Symbol, Expression * expr)
{
	Neg* temp;
	temp = new Neg;
	temp->m_expr = m_expr->assign(Symbol, expr);
	return temp;
}

Neg::Neg()
{
}


Neg::~Neg()
{
}
