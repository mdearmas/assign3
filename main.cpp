#include "GenStack.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  GenStack<int> myStack(5);

  for(int i = 0; i < 10; ++i)
  {
    myStack.push(i);
  }

  for(int i = 0; i < 10; ++i)
  {
    cout << myStack.pop() << endl;
  }
}
