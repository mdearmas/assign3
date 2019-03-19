/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 3: Syntax Checker
  Purpose: This file, main.cpp, contains the main function for Assignment 3. The resulting program allows the user to
  check for mismatched delimiters in a program. If a mismatch if found, the program reports the error and exits; if no
  errors are found, the program allows the user to keep entering files to check.
*/
#include "GenStack.h" //allows access to the template GenStack class
#include "Delimiters.h" //allows access to the Delimiters Library class

#include <iostream> //allows access to input/output streams
#include <fstream> //allows access to file i/o

using namespace std; //allows access to standard library

int main(int argc, char** argv)
{
  ifstream input_file; //input file stream

  string filepath; //location of file
  string line; //initializes line for file reading

  char answer; //stores user's answer

  bool read_in = true; //allows file checking to be repeated
  bool valid_file = true; //sets up the necessary break clauses for nested loops

  int index = 1; //line count of the code

  GenStack<char> s(100); //initializes a char stack
  Delimiters d; //initializes a Delimiters object

  while(read_in)
  {
    cout << "Please enter your file: ";
    cin >> filepath;

    input_file.open(filepath);
    index = 1; //resets the line count for each file

    if( input_file.is_open() ) //ensures the file was successfully opened
    {
      while( getline(input_file, line) )
      {
        for(int i = 0; i < line.length(); ++i)
        {
          if(d.isOpenDelimiter(line[i])) //checks if the character is an open delimiter
          {
            s.push(line[i]); //pushes the latest open delimiter to the top of the stack
          }

          if(d.isCloseDelimiter(line[i])) //checks if the character is a close delimiter
          {
            if(d.isMatch(s.peek(), line[i])) //checks if the close delimiter matches the open delimiter at the top of the stack
            {
              s.pop(); //removes the top of the stack if the match is correct
            }
            else //if not a match, the location of the error is printed
            {
              cout << "Error, Line " << index << ": Expected " << d.getMatch(s.peek()) << " but found " << line[i] << " instead." << endl;
              valid_file = false; //sets up break out of while(getline) loop
              break; //breaks out of for loop
            }
          }
        }
        if(!valid_file)
        {
          read_in = false; //negates condition for while(read_in) loop
          break; //breaks out of while(getline)
        }
        else
        {
          ++index; //increments line count
        }
      }
      if(valid_file) //this clause only happens if there wasn't an early termination of the above loop
      {
        if(!s.isEmpty()) //checks if the stack still has delimiters in it
        {
          cout << "Error, end of file: Missing " << d.getMatch(s.peek()) << endl;
          read_in = false; //negates condition for while(read_in) loop
        }
        else
        {
          cout << "File has been processed. No delimiter errors have been found." << endl;
          cout << "Would you like to check another file? Enter 'Y' for yes and 'N' for no: ";
          cin >> answer;

          if(toupper(answer) == 'N') //if user input no
          {
            read_in = false; //negates condition for while(read_in) loop
            cout << "Exiting program. " << endl;
          }
          else if(toupper(answer) != 'Y') //if user did not enter a valid input
          {
            read_in = false; //negates condition for while(read_in) loop
            cout << "Invalid input. Exiting program. " << endl;
          }
        }
      }
      input_file.close();
    }
    else //if the file could not be opened
    {
      cout << "File could not be opened. Try again." << endl;
    }
  }
}
