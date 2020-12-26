#pragma once
#include "TTable.h"

class TPolizCalculate {
private:
  char *pizExpr; // ќбратна€ польска€ запись исходного выражени€
public:
  TPolizCalculate(char *_pizExpr); // онструктор
  double calculatePizExpr(TTable<double> _varTable);  // вычисление с переменными
  double calculatePizExpr();  // ¬ычислить выражение по польской обратной 
};