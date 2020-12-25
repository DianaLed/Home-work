#include "TStack.h"
#include "TQueue.h"
#include "TRadixSort.h"
template <class T>
TQueue<T>::TQueue<T>(int n) : TStack<T>(n)
{
  start = 0;
  count = 0;
}


template <class T>
TQueue<T>::TQueue(TQueue<T>& q) : TStack<T>(q)
{
  start = q.start;
  count = q.count;
}

template <class T>
TQueue<T>::~TQueue()
{}

template<class T>
inline T TQueue<T>::Top()
{
  return TStack<T>::mas[start];
}

template<class T>
int TQueue<T>::maxDigCount()
{
  T max = TStack<T>::mas[0];
  for (int i = 1; i < TStack<T>::size; i++) {
    if (max < TStack<T>::mas[i]) max = TStack<T>::mas[i];
  }
  int res = 0;
  while (max > 0) {
    max = max / 10;
    res++;
  }
  return res;
}

template <class T>
void TQueue<T>::Put(T a)
{
  if (IsFull())
    throw 5;
  else
  {
    TStack<T>::Put(a);
    TStack<T>::top = TStack<T>::top % TStack<T>::size;
    count++;
  }
}

template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw 6;
  else
  {
    T dop = TStack<T>::mas[start];
    start = (start + 1) % TStack<T>::size;
    count--;
    return dop;
  }
}

template <class T>
bool TQueue<T>::IsFull()
{
  if (count == TStack<T>::size)
    return 1;
  return 0;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
  if (count == 0) return 1;
  return 0;
}



template<class T>
void TQueue<T>::Print()
{
  TRadixSort<T> psort(TStack<T>::mas, TStack<T>::size, maxDigCount());
  psort.doRadixSort();
  psort.Print();
  start = 0;
}

template class TQueue<int>;
template class TQueue<double>;