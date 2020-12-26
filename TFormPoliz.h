#pragma once

class TFormPoliz{
private:
  char *orgExpr; // �������� ���������
  char *pizExpr; // �������� �������� ������ ��������� ���������
public:
  TFormPoliz(char *_orgExpr);
  void formPizExpr(); // ����������� �������� �������� ������
  char* getPizPoliz();
private:
  int getOperationPriority(char opr); // ������ ���������� 
  void addToPolish(char *operand);
  void addToPolish(char oper);
};