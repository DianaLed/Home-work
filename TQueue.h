#pragma once
#pragma once
#include "TStack.h"
#include <algorithm>
template <class T>
class TQueue : public TStack<T>
{
protected:
  int start;
  int count;
public:
  TQueue(int n = 1);
  TQueue(TQueue <T>& q);
  virtual ~TQueue();
  T Top();
  int maxDigCount();
  void Put(T a);
  T Get();
  bool IsFull();
  bool IsEmpty();
  void Print();
};