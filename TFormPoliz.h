#pragma once

class TFormPoliz{
private:
  char *orgExpr; // Исходное выражение
  char *pizExpr; // Обратная польская запись исходного выражения
public:
  TFormPoliz(char *_orgExpr);
  void formPizExpr(); // Формировать обратную польскую запись
  char* getPizPoliz();
private:
  int getOperationPriority(char opr); // запрос приоритета 
  void addToPolish(char *operand);
  void addToPolish(char oper);
};