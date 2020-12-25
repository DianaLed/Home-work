#include"TQueue.h"
#include"TRadixSort.h"

template<class T>
TRadixSort<T>::TRadixSort(T* _arValue, int _arCount, int _digCount)
{

  arCount = _arCount;
  digCount = _digCount;
  arValue = _arValue;
}

template<class T>
TRadixSort<T>::~TRadixSort()
{

}



template<class T>
int TRadixSort<T>::setDigCount(T* arValue, int _arCount)
{
  int mx = arValue[0];
  for (int i = 1; i < _arCount; i++)
    if (arValue[i] > mx)
      mx = arValue[i];
  return mx;
}

template<class T>
void TRadixSort<T>::countSort(T* _arValue, int _arCount, int _digCount)
{
  int* out = new int[_arCount];
  int i;
  int c[10];
  int a;
  for (int i = 0; i < 10; i++) {
    c[i] = 0;
  }
  for (i = 0; i < _arCount; i++)
  {
    a = _arValue[i];
    c[(a / _digCount) % 10]++;
  }
  for (i = 1; i < 10; i++)
    c[i] += c[i - 1];
  // Создаем выходной массив
  for (i = _arCount - 1; i >= 0; i--) {
    a = _arValue[i];
    out[c[(a / _digCount) % 10] - 1] = _arValue[i];
    c[(a / _digCount) % 10]--;
  }
  for (i = 0; i < _arCount; i++) _arValue[i] = out[i];
  delete[] out;
}
template<class T>
void TRadixSort<T>::doRadixSort()
{
  int m = setDigCount(arValue, arCount);
  for (int i = 1; m / i > 0; i =i* 10) countSort(arValue, arCount, i);
}

template<class T>
void TRadixSort<T>::Print()
{
  for (int i = 0; i < arCount; i++) cout << arValue[i] << " ";
  cout << endl;
}

template class TRadixSort<int>;
template class TRadixSort<double>;