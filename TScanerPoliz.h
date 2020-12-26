#pragma once
class TScanerPoliz {
private:
  char *poliz; // Сканируемая польская 
  int ind; // Текущий индекс сканирования
public:
  TScanerPoliz(char *_poliz); //Конструктор
  int getNextElemPoliz(char &oper, double &operand, char *varible);
  int getNextElemPoliz(char &oper, double &operand); // Запрос следующего элемента полькой записи
  // Возврат:
  // 1 - операция
  // 2 - операнд
  // 3 - пробел
  // 4 - переменная
  // 0 - конец сканирования
private:
  bool isOperation(char c); // это операция?
  bool isNumber(char c); // это цифра?
  bool isVarible(char c); // это переменная?
};