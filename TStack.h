#pragma once
#include <iostream>
#include <string>
#include <locale.h>
//#include "Exception.h"
using namespace std;
template <class T>
class TStack
{
protected:
  int size;
  int top;
  T* mas;
  TStack(int n = 0);
  TStack(TStack<T>& S); 
  virtual ~TStack();   
  int GetSize();  
  T Get();   
  void Put(T A);
  bool IsFull();
  bool IsEmpty();
  void PrintStack();
  T Top();
  int operator!=(const TStack<T>& stack) const;
  int operator==(const TStack<T>& stack) const;
  TStack& operator=(const TStack<T>& stack);
};

