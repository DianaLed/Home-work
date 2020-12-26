#pragma once

class TScaner {
private:
  char *expr; // Сканируемое выражение
  int ind; // Текущий индекс сканирования

public:
  TScaner(char *_expr);
  ~TScaner();
  int getNextElem(char &oper, char *operand); // Запрос следующего элемента выражения
  // Возврат
  // 1 - операция
  // 2 - операнд
  // 3 - переменная
  // 0 - конец сканирования

private:
  void delBlank(); // удаление пробелов
  bool isOperation(char c); // это операция?
  bool isNumber(char c); // это цифра?
};