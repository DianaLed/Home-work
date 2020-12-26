#pragma once
#include "TTable.h"

class TPolizCalculate {
private:
  char *pizExpr; // �������� �������� ������ ��������� ���������
public:
  TPolizCalculate(char *_pizExpr); //�����������
  double calculatePizExpr(TTable<double> _varTable);  // ���������� � �����������
  double calculatePizExpr();  // ��������� ��������� �� �������� �������� 
};