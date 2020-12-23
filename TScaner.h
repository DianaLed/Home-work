#pragma once

class TScaner // Сканирование выражения
{
private:
  int size_of_expr;
  char* expr; // Сканируемое выражение
  int ind; // Текущий индекс сканирования
public:
  TScaner(char* _expr); //Конструктор
  ~TScaner();
  int getNextElem(char& oper, char* operand); // Запрос следующего элемента выражения
  // Возврат:
  // 1 - операция
  // 2 - операнд
  // 0 - конец сканирования
private:
  void delBlank(); // удаление пробелов
  bool isOperation(char c); // это операция?
  bool isNumber(char c); // это цифра?

};
