#pragma once

class TFormPoliz // ������������ �������� �������� ������
{
private:
  char* orgExpr; // �������� ���������
  char* pizExpr; // �������� �������� ������ ��������� ���������
public:
  TFormPoliz(char* _orgExpr); //�����������
  ~TFormPoliz();
  void formPizExpr(char* _orgExpr); // ����������� �������� �������� ������
  char* getPizPoliz();
private:
  int getOperationPriority(char opr); // ������ ���������� ��������
  void addToPolish(char* operand);
  void addToPolish(char oper);

};