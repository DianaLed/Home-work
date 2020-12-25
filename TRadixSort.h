#include"TQueue.h"
using namespace std;

template <class T>

class TRadixSort
{
private:
  T* arValue;
  int arCount;
  int digCount;
public:
  TRadixSort(T* _arValue, int _arCount, int _digCount); // Конструктор
  ~TRadixSort(); // Деструктор
  void doRadixSort();
  void Print();
private:
  int setDigCount(T* arValue, int _arCount);
  void countSort(T* _arValue, int _arCount, int _valCount);
};
