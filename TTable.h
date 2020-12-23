#pragma once
#include <string>

#include "TFormPoliz.h"
#include "TRecord.h"
template <class T>
class TTable
{
private:
  TRecord<T>* records; // Записи таблицы
  unsigned int tabSize; //Размер таблицы
  unsigned int recCount; //Количество записей в таблице
public:
  TTable(unsigned int _tabSize = 20); //Конструктор
  ~TTable(); //Деструктор
  T GetValue(const std::string& _Name); //Получить значение по имени строки
  void Add(TRecord<T> temp); //Добавить запись в таблицу
  void SetValue(std::string _Name, const T& _Value); //Установить значение записи
  std::string GetName(int ind); //Получить имя записи
  void inputVarValues(); // Ввод значений переменных
  void outputVarTable(); //Вывести всю таблицу на консоль
  void ImpTFormPoliz(TFormPoliz a);
  unsigned int GetSize();
private:
  unsigned int RowNumber(std::string _Name); //Запрос номера строки (записи) по имени
};

