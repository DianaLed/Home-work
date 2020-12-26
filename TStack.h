#pragma once

const int maxMemSize = 25; // ������������ ������ ������ ��� �����

template <class T>
class TStack {
protected: // ����
  T *pMem; // ��������� �� ������ ���������
  int memSize; // ������ ������ ��� ��
  int dataCount; // ���������� ��������� � ��
  int Hi; // ������ ������� �����
  virtual int GetNextIndex(int index);
public:
  TStack(int size);//�����������
  ~TStack();
  bool IsEmpty(void) const; // �������� �������
  bool IsFull(void) const; // �������� ������������
  void Put(const T &val);// �������� ��������
  virtual T Get(void); // ������� ��������
};

int doSkbControl(char *expr);
