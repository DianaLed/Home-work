#pragma once
#include <string>
#include "TTable.h"
class TPolizCalculate // ���������� ��������� �� �������� �������� ������
{
private:
  char* pizExpr; // �������� �������� ������ ��������� ���������
public:
  TPolizCalculate(char* _pizExpr, TTable<double> a); //�����������
  ~TPolizCalculate();
  double calculatePizExpr(); // ��������� ��������� �� �������� �������� ������
};