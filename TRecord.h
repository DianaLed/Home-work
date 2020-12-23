#pragma once
#include <string>
template <class T>
class TRecord
{
private:
  std::string Name;
  T Value;
public:
  TRecord(std::string _Name = "", T _Value = T(1.7976931348623158e+308)); //Конструктор
  std::string GetName(); //Получить имя
  T GetValue() { return Value; } //Получить значение
  void SetValue(const T& temp) { Value = temp; } //Задать значение
  void SetName(std::string& n) { Name = n; } //Задать значение
  TRecord& operator=(const TRecord& rec);
};

