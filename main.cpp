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

  bool valid_file = true;

  int index = 1;

  GenStack<char> s(100);
  Delimiters d;

  cout << "Please enter your file: ";
  cin >> filepath;

  input_file.open(filepath);

  if( input_file.is_open() )
  {
    while( getline(input_file, line) )
    {
      for(int i = 0; i < line.length(); ++i)
      {
        if(d.isOpenDelimiter(line[i]))
        {
          s.push(line[i]);
        }

        if(d.isCloseDelimiter(line[i]))
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
      if(!valid_file)
      {
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
      }
      else
      {
        cout << "File has been processed. No delimiter errors have been found." << endl;
      }
    }
  }
  input_file.close();
}
