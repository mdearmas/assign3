#include "Delimiters.h"

char Delimiters::getMatch(char c)
{
  if(c == '(')
  {
    return ')';
  }
  else if (c == '[')
  {
    return ']';
  }
  else if (c == '{')
  {
    return '}';
  }
  else
  {
    return c;
  }
}

bool Delimiters::isOpenDelimiter(char c)
{
  if(c == '(' || c == '[' || c == '{')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Delimiters::isCloseDelimiter(char c)
{
  if(c == ')' || c == ']' || c == '}')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Delimiters::isMatch(char top, char pair)
{
  if((top == '(' && pair == ')') || (top == '[' && pair == ']') || (top == '{' && pair == '}'))
  {
    return true;
  }
  else
  {
    return false;
  }
}
