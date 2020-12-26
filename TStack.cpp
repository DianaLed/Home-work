#include "TStack.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
TStack<T>::TStack(int size) {
  if (size == 0)
    throw logic_error("size can't be 0");
  if (size > maxMemSize) size = maxMemSize;
  memSize = size;
  dataCount = 0;
  Hi = -1;
  pMem = new T[size];
}

template <class T>
TStack<T>::~TStack() {
  /*delete[] pMem;*/
}

template <class T>
bool TStack<T>::IsEmpty(void) const {
  return (dataCount <= 0);
}

template <class T>
bool TStack<T>::IsFull(void) const {
  return (dataCount == memSize);
}

template <class T>
void TStack<T>::Put(const T &val) {
  Hi = dataCount;
  dataCount++;
  pMem[Hi] = val;
}

template <class T>
int TStack<T>::GetNextIndex(int index) {
  return ++index;
}

template <class T>
T TStack<T>::Get(void) {
  dataCount--;
  return pMem[Hi--];
}

int doSkbControl(char *expr) {
  TStack<int> stack(25);
  int error = 0, i, j = i = 0;
  char ch;
  while (expr[i] != '\0')
    cout << i++;
  cout << endl << expr << endl;
  i = 0;
  while (expr[i] != '\0') {
    ch = expr[i];
    if (ch == '(')
      stack.Put(i);
    if (ch == ')') {
      if (!stack.IsEmpty()) {
        j = stack.Get();
        cout << j << " - " << i << endl;
      } else {
        cout << "?" << " - " << i << endl;
        error++;
      }
    }
    ++i;
  }
  while (!stack.IsEmpty()) {
    j = stack.Get();
    cout << j << " - " << "?" << endl;
    error++;
  }
  return error;
}

template class TStack<int>;
template class TStack<double>;