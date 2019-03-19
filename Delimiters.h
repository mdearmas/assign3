#include <iostream>

using namespace std;

class Delimiters {
public:
  Delimiters() {};

  char getMatch(char c);

  bool isOpenDelimiter(char c);
  bool isCloseDelimiter(char c);
  bool isMatch(char top, char pair);
};
