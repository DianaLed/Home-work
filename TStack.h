#pragma once

const int maxMemSize = 25; // максимальный размер пам€ти дл€ стека

template <class T>
class TStack {
protected: // пол€
  T *pMem; // указатель на массив элементов
  int memSize; // размер пам€ти дл€ —ƒ
  int dataCount; // количество элементов в —ƒ
  int Hi; // индекс вершины стека
  virtual int GetNextIndex(int index);
public:
  TStack(int size);//конструктор
  ~TStack();
  bool IsEmpty(void) const; // контроль пустоты
  bool IsFull(void) const; // контроль переполнени€
  void Put(const T &val);// добавить значение
  virtual T Get(void); // извлечь значение
};

int doSkbControl(char *expr);
