#pragma once
#include <string>

#include "TFormPoliz.h"
#include "TRecord.h"
template <class T>
class TTable
{
private:
  TRecord<T>* records; // ������ �������
  unsigned int tabSize; //������ �������
  unsigned int recCount; //���������� ������� � �������
public:
  TTable(unsigned int _tabSize = 20); //�����������
  ~TTable(); //����������
  T GetValue(const std::string& _Name); //�������� �������� �� ����� ������
  void Add(TRecord<T> temp); //�������� ������ � �������
  void SetValue(std::string _Name, const T& _Value); //���������� �������� ������
  std::string GetName(int ind); //�������� ��� ������
  void inputVarValues(); // ���� �������� ����������
  void outputVarTable(); //������� ��� ������� �� �������
  void ImpTFormPoliz(TFormPoliz a);
  unsigned int GetSize();
private:
  unsigned int RowNumber(std::string _Name); //������ ������ ������ (������) �� �����
};

