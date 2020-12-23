#pragma once
const int MaxMemSize = 25; // максимальный размер памяти для стека
typedef int TElem; // тип элемента СД
typedef TElem* PTElem; // тип указателя на СД

class TStack {
protected: // поля
  PTElem pMem; // указатель на массив элементов
  int MemSize; // размер памяти для СД
  int DataCount; // количество элементов в СД
  int Hi; // индекс вершины стека
  virtual int GetNextIndex(int index); // получить следующий индекс
public:
  TStack(int Size = MaxMemSize);//конструктор
  ~TStack(); //деструктор
  int IsEmpty(void) const; // контроль пустоты
  
  int IsFull(void) const; // контроль переполнения
  void Put(const TElem& Val);// добавить значение
  virtual TElem Get(void); // извлечь значение
};
