#pragma once
class TScanerPoliz {
private:
  char *poliz; // ����������� �������� 
  int ind; // ������� ������ ������������
public:
  TScanerPoliz(char *_poliz); //�����������
  int getNextElemPoliz(char &oper, double &operand, char *varible);
  int getNextElemPoliz(char &oper, double &operand); // ������ ���������� �������� ������� ������
  // �������:
  // 1 - ��������
  // 2 - �������
  // 3 - ������
  // 4 - ����������
  // 0 - ����� ������������
private:
  bool isOperation(char c); // ��� ��������?
  bool isNumber(char c); // ��� �����?
  bool isVarible(char c); // ��� ����������?
};