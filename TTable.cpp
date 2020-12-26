#include "TTable.h"

template<class T>
T TTable<T>::GetValue(const std::string& _Name)
{
    for (int i = 0; i < size; i++) {
      if (_Name == name[i])  return mas[i];
    }
    return mas[0];
}

template <class T>
TTable<T>::TTable(int _size) {
  if (_size <= 0)
    size = 20;
  else
    size = _size;
  length = 0;
  mas = new T[size];
  name = new string[size];
}

template <class T>
void TTable<T>::outputVarTable() {
  int i, i1;
  string a = "";
  if (length == 0) {
    cout << "no values available" << endl;
    return;
  }
  cout << " ________________" <<endl;
  cout << "|Name | Value    |" << endl;
  cout << "|_____|__________|" << endl;
  for (i = 0; i < length; ++i) {
    cout << "| " << name[i] << "   | ";
    a = to_string(mas[i]);
    if (a.size() > 5) {
      string a1 = "";
      for (int i = 0; i < 5; i++) {
        a1 = a1 + a[i];
      }
      a = a1;
    }
    i1 = 10 - (1 + a.size());
    cout << a;
    while (i1 != 0) {
      cout << " ";
      i1--;
    }
    cout << "|" << endl;
    cout << "|_____|__________|" << endl;
  }
}

template <class T>
void TTable<T>::inputVarValues() {
  int i, s;
  cout << "Imput size of variables " << endl;
  cin >> s;
  if (s > size)
    s = size;
  for (i = length; i < s; ++i){
    cout <<"Name - ";
    cin >> name[i];
    cout << "Value - ";
    cin >> mas[i];
  }
  length = length + s;
}

template class TTable<double>;
template class TTable<int>;