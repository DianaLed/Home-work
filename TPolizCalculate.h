#pragma once
#include <string>
#include "TTable.h"
class TPolizCalculate // ¬ычисление выражени€ по польской обратной записи
{
private:
  char* pizExpr; // ќбратна€ польска€ запись исходного выражени€
public:
  TPolizCalculate(char* _pizExpr, TTable<double> a); // онструктор
  ~TPolizCalculate();
  double calculatePizExpr(); // ¬ычислить выражение по польской обратной записи
};