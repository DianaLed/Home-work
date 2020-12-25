#include"TStack.h"
#include"TRadixSort.h"
#include "TQueue.h"
#include <iterator>
#include <iostream>
using namespace std;

void printArray(int ar[], int arCount)
{
  for (int i = 0; i < arCount; ++i)
  cout << ar[i] << " ";
  cout << endl;
}



int main()
{
  setlocale(LC_ALL, "Russian");
  // 3. TCBQueue tests
  cout << "3. TCBQueue tests:" << endl;
  {
    TQueue<int> queue(3);
    cout << "Test 1. queue.isEmpty(). Expected: " << true << " , actual: " << queue.IsEmpty() << endl;
    queue.Put(10);
    cout << "Test 2. queue.isEmpty(). Expected: " << false << " , actual: " << queue.IsEmpty() << endl;
    cout << "Test 3. queue.Get(). Expected: " << 10 << " , actual: " << queue.Get() << endl;
    cout << "Test 4. queue.isEmpty(). Expected: " << true << " , actual: " << queue.IsEmpty() << endl;
    queue.Put(10);
    queue.Put(20);
    queue.Put(30);
    cout << "Test 5. queue.printQue()." << endl;
    cout << "\tExpected: 10 20 30" << endl;
    cout << "\tActual: ";
    queue.Print();
    cout << "Test 6. queue.isFull(). Expected: " << true << " , actual: " << queue.IsFull() << endl;
    cout << "Test 7. queue.Get(). Expected: " << 10 << " , actual: " << queue.Get() << endl;

    TQueue<double> queue2;
    queue2.Put(10.5);
    cout << "Test 8. queue2.Get(). Expected: " << 10.5 << " , actual: " << queue2.Get() << endl;
    cout << endl;
  }

  // 4. TRadixSort tests
  cout << "3. TRadixSort tests:" << endl;
  {
    int arSRT[7] = { 301, 102, 127, 453, 874, 472, 311 };
    int arCNT = 7;

    cout << "Исходный массив: ";
    printArray(arSRT, arCNT);

    TRadixSort<int> radixSort(arSRT, arCNT, 9);
    radixSort.doRadixSort();

    cout << "Сортированный массив: ";
    printArray(arSRT, arCNT);
    cout << endl;
  }
  {
    int arSRT[7] = { 1, 10, 7, 53, 8, 47, 311 };
    int arCNT = 7;

    cout << "Исходный массив: ";
    printArray(arSRT, arCNT);

    TRadixSort<int> radixSort(arSRT, arCNT, 9);
    radixSort.doRadixSort();

    cout << "Сортированный массив: ";
    printArray(arSRT, arCNT);
    cout << endl;
  }
  system("pause");
  return 0;
}
