#pragma once
#include <string>
#include <iostream>
using namespace std;

template <class T>
class  TTable{
public:
  T *mas;
  string *name;
  int length;
  int size;
  T GetValue(const std::string& _Name); //�������� �������� �� ����� ������
public:
  TTable(int kvo);
  void outputVarTable();
  void inputVarValues();
};