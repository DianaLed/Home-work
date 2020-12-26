#pragma once

class TScaner {
private:
  char *expr; // ����������� ���������
  int ind; // ������� ������ ������������

public:
  TScaner(char *_expr);
  ~TScaner();
  int getNextElem(char &oper, char *operand); // ������ ���������� �������� ���������
  // �������
  // 1 - ��������
  // 2 - �������
  // 3 - ����������
  // 0 - ����� ������������

private:
  void delBlank(); // �������� ��������
  bool isOperation(char c); // ��� ��������?
  bool isNumber(char c); // ��� �����?
};