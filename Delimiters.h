/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 3: Syntax Checker
  Purpose: This file, Delimiters.h, contains the definition for the Delimiters class, which serves as a pseudo-library of possible delimiters.
  This class contains functions, to check if a character is a open or close delimiter, to find the close pair of an open delimiter, and to check
  if two passed characters are matching delimiters.
*/

#include <iostream> //allows access to input/output

using namespace std; //allows access to standard library

class Delimiters {
public:
  Delimiters() {}; //default constructor, left empty because there are no member variables to initalize

  char getMatch(char c); //finds the close delimiter match to a passed character

  bool isOpenDelimiter(char c); //checks if the passed character is a valid open delimiter
  bool isCloseDelimiter(char c); //checks if the passed character is a valid close delimiter
  bool isMatch(char top, char pair); //checks if the two passed characters are a pair of delimiters
};
