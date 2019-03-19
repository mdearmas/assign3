/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 3: Syntax Checker
  Purpose: This file, main.cpp, contains the main function for Assignment 2. The resulting program will first ask what mode the user wants to run their game in,
  (defaulting to a 10x!0 board with 0.5 population density in case of erroneous input). If file input is selected, the user will be prompted to enter the name of
  their file; if random is selected, the user will be prompted to enter the number of rows and columns and the population density. Then, the user will be asked
  what mode they would like (defaulting to Classic if erroneous input). Finally, the user will be prompeted with a choice regarding how their output will
  be formatted (defaulting to Pauses if erroneous input).
*/
#include "GenStack.h"
#include "Delimiters.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  ifstream input_file;

  string filepath;
  string line;

  char answer;

  bool read_in = true;
  bool valid_file = true;

  int index = 1;
  int is_string = -1;

  GenStack<char> s(100);
  Delimiters d;

  while(read_in)
  {
    cout << "Please enter your file: ";
    cin >> filepath;

    input_file.open(filepath);

    if( input_file.is_open() )
    {
      while( getline(input_file, line) )
      {
        for(int i = 0; i < line.length(); ++i)
        {
          if(line[i] == '"' && line[i+1] != '\'')
          {
            is_string = is_string * -1;
          }

          if(d.isOpenDelimiter(line[i]) && line[i+1] != '\'')
          {
            if(is_string < 0)
            {
              s.push(line[i]);
            }
          }

          if(d.isCloseDelimiter(line[i]) && line[i+1] != '\'')
          {
            if(is_string < 0)
            {
              if(d.isMatch(s.peek(), line[i]))
              {
                s.pop();
              }
              else
              {
                cout << "Error, Line " << index << ": Expected " << d.getMatch(s.peek()) << " but found " << line[i] << " instead." << endl;
                valid_file = false;
                break;
              }
            }
          }
        }
        if(!valid_file)
        {
          read_in = false;
          break;
        }
        else
        {
          ++index;
        }
      }
      if(valid_file)
      {
        if(!s.isEmpty())
        {
          cout << "Error, Line " << index << ": Expected '}' at end of file. " << endl;
          read_in = false;
        }
        else
        {
          cout << "File has been processed. No delimiter errors have been found." << endl;
          cout << "Would you like to check another file? Enter 'Y' for yes and 'N' for no: ";
          cin >> answer;

          if(toupper(answer) == 'N')
          {
            read_in = false;
            cout << "Exiting program. " << endl;
          }
          else if(toupper(answer) != 'Y')
          {
            read_in = false;
            cout << "Invalid input. Exiting program. " << endl;
          }
        }
      }
    }
    input_file.close();
  }

}
