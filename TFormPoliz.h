#pragma once

class TFormPoliz // Формирование польской обратной записи
{
private:
  char* orgExpr; // Исходное выражение
  char* pizExpr; // Обратная польская запись исходного выражения
public:
  TFormPoliz(char* _orgExpr); //Конструктор
  ~TFormPoliz();
  void formPizExpr(char* _orgExpr); // Формировать Обратная польская запись
  char* getPizPoliz();
private:
  int getOperationPriority(char opr); // запрос приоритета операции
  void addToPolish(char* operand);
  void addToPolish(char oper);

};