#pragma once
#include "TStack.h"
const int MaxLength = 255; // ������������ ������ ������� ������
class TFormula {
private:
  char Formula[MaxLength]; // ������� ������
  char PostfixForm[MaxLength]; // ����������� ������
public:
 /* TFTrans(char form[]);*/   // ��� ��� � �����
  int FormulaChecker(int Brackets[], int size);// �������� ������������
  int FormulaConverter(void); // ������� � ����������� �����
  double FormulaCalculator(void); // ���������� ����������
};

