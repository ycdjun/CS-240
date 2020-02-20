#include "expr.hh"

#include <string>
#include <sstream>

std::string
IntExpr::toString() const
{
  std::stringstream s;
  s << value;
  return s.str();
}

static std::string
binaryExprToString(std::string op, ExprPtr left, ExprPtr right)
{
  std::stringstream s;
  s << "(" << *left << ") " << op << " (" << *right << ")";
  return s.str();
}

std::string
AddExpr::toString() const
{
  return binaryExprToString("+", left, right);
}

std::string
SubExpr::toString() const
{
  return binaryExprToString("-", left, right);
}

std::string
MulExpr::toString() const
{
  return binaryExprToString("*", left, right);
}

std::string
DivExpr::toString() const
{
  return binaryExprToString("/", left, right);
}

int 
IntExpr::eval() const
{
  return value;
}

int 
AddExpr::eval() const
{
  return (left.get()->eval() + right.get()->eval());
}

int 
SubExpr::eval() const
{
  return (left.get()->eval() - right.get()->eval());
}
int 
MulExpr::eval() const
{
  return (left.get()->eval() * right.get()->eval());
}
int 
DivExpr::eval() const
{
  return (left.get()->eval() / right.get()->eval());
}
