#pragma once
#include <string>
template <class T>
class TRecord
{
private:
  std::string Name;
  T Value;
public:
  TRecord(std::string _Name = "", T _Value = T(1.7976931348623158e+308)); //�����������
  std::string GetName(); //�������� ���
  T GetValue() { return Value; } //�������� ��������
  void SetValue(const T& temp) { Value = temp; } //������ ��������
  void SetName(std::string& n) { Name = n; } //������ ��������
  TRecord& operator=(const TRecord& rec);
};

