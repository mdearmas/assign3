/*Source: http://www.cplusplus.com/doc/oldtutorial/templates/*/

#include <iostream>

using namespace std;

template <typename T>
class GenStack
{
public:
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  void push(T o);
  T pop();
  T peek();

  int getSize() { return (top + 1); }
  bool isFull() { return (top == size - 1); }
  bool isEmpty() { return (top < 0); }

  void resize();

  int size;
  int top;

  T* myArray;
};

class EmptyStackException
{
public:
  EmptyStackException(string message) : error_message(message) { }
  string getErrorMessage() { return error_message; }
private:
  string error_message;
};

template <typename T>
GenStack<T>::GenStack()
{
  size = 100;
  top = -1;

  myArray = new T[100];
}

template <typename T>
GenStack<T>::GenStack(int maxSize)
{
  size = maxSize;
  top = -1;

  myArray = new T[maxSize];
}

template <typename T>
GenStack<T>::~GenStack()
{
  delete[] myArray;
}

template <typename T>
void GenStack<T>::push(T o)
{
  if(isFull())
  {
    resize();
  }

  myArray[++top] = o;
}

template <typename T>
T GenStack<T>::pop()
{
  try
  {
    if(isEmpty())
      throw EmptyStackException("Stack is empty, so nothing can be popped.");
    else
    {
      --top;
      return myArray[top + 1];
    }
  }
  catch(EmptyStackException& e)
  {
    cout << e.getErrorMessage() << endl;
  }
}

template <typename T>
T GenStack<T>::peek()
{
  try
  {
    if(isEmpty())
      throw EmptyStackException("Stack is empty.");
    else
    {
      return myArray[top];
    }
  }
  catch(EmptyStackException& e)
  {
    cout << e.getErrorMessage() << endl;
  }
}

template <typename T>
void GenStack<T>::resize()
{
  size = size * 2;
  T* newArray = new T[size];

  for(int i = 0; i <= top; ++i)
  {
    newArray[i] = myArray[i];
  }

  delete[] myArray;
  myArray = newArray;
}
