#include "TStack.h"

template <class T>
TStack<T>::TStack(int n)
{
  if (n < 0) throw 1;
  if (n == 0) size = 1;
  else size = n;
  top = 0;
  mas = new T[size];
  for (int i = 0; i < size; i++) mas[i] = 0;
}

template <class T>
TStack<T>::TStack(TStack<T>& s)
{
  size = s.size;
  top = s.top;
  if (size == 0) mas = NULL;
  else {
    mas = new T[size];
    for (int i = 0; i < size; i++) mas[i] = s.mas[i];
  }
}

template<class T>
TStack <T>::~TStack()
{
  top = 0;
  size=0;
  delete[] mas;
}

template <class T>
int TStack<T>::GetSize()
{
  return size;
}

template <class T>
T TStack<T>::Get()
{
  if (IsEmpty()) throw 2;
  top--;
  return mas[top];
}

template <class T>
void TStack<T>::Put(T a)
{
  if (IsFull()) throw 3;
  else
  {
    mas[top] = a;
    top++;
  }
}

template <class T>
bool TStack<T>::IsFull()
{
  if (top >= size) return 1;
  return 0;
}

template <class T>
bool TStack<T>::IsEmpty()
{
  if (top == 0) return 1;
  return 0;
}

template <class T>
void TStack<T>::PrintStack()
{
  for (int i = top - 1; i >= 0; i--)
    cout << " " << mas[i];
}

template<class T>
T TStack<T>::Top()
{
  if (IsEmpty()) throw 4;
  else return mas[top - 1];
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& s)
{
  if (this != &s)
  {
    delete[] mas;
    top = s.top;
    size = s.size;
    mas = new T[size];
    for (int i = 0; i < size; i++) mas[i] = s.mas[i];
  }
  return *this;
}

template <class T>
int TStack<T>::operator==(const TStack<T>& s) const
{
  if (top != s.top) return 0;
  if (size != s.size) return 0;
  for (int i = 0; i < top; i++) if (mas[i] != s.mas[i]) return 0;
  return 1;
}

template <class T>
int TStack<T>::operator!=(const TStack<T>& s) const
{
  if (*this == s) return 0;
  else return 1;
}

template class TStack<int>;
template class TStack<double>;