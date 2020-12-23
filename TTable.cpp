#include <iostream>
#include <iomanip>
#include <conio.h>
#include "TRecord.h"
#include "TTable.h"
#include "TFormPoliz.h"
using namespace std;

template<class T>
TTable<T>::TTable(unsigned int _tabSize)
{
  if (_tabSize > 50) _tabSize = 20;
  tabSize = _tabSize;
  records = new TRecord<T>[tabSize];
  recCount = _tabSize;
}

template<class T>
TTable<T>::~TTable()
{
  
  delete[]records;
  recCount = 0;
}

template<class T>
T TTable<T>::GetValue(const std::string& _Name)
{
  for (int i = 0; i < recCount; i++) {
  if(_Name== records[i].GetName())  return records[i].GetValue();
  }
  /*catch () {
    cout << "Exeption(GetValue), not found element" << endl;
  }*/
}

template<class T>
void TTable<T>::Add(TRecord<T> temp)
{ 
  if (tabSize == recCount) {
    cout << "Exeption(Add), the table is filled" << endl;
  }
  else {
    records[recCount] = temp;
    recCount++;
  }
}

template<class T>
void TTable<T>::SetValue(std::string _Name, const T& _Value)
{

}

template<class T>
std::string TTable<T>::GetName(int ind)
{
  if (ind > recCount) { 
    cout << "Exeption(GetName), not found element " << ind << " > " << recCount << endl; 
    return "Error";
  }
  std::string a = records[ind].GetName();
  return a;
}

bool isLetter1(char c)
{
  if ((c >= 'a') && (c <= 'z')) return true;
  if ((c >= 'а') && (c <= 'я')) return true;
  return 0;
}

bool isNumb1(char c)
{
  if ((c - '0' < 10) && (c - '0' > -1)) return true;
  if ((c == '.') || (c == ',')) return true;
  return 0;
}

template<class T>
void TTable<T>::inputVarValues()
{
  double a = 0;
  for (int i = 0; i < recCount; i++) {
    if(isLetter1(records[i].GetName()[0])) 
      if (records[i].GetValue() == 1.7976931348623158e+308) {
        cout << "Input chislo " << records[i].GetName() << " -";
        cin >> a; 
        records[i].SetValue(a);
      }
  }
}

void prob_nichego() {
  int k = 9;
  while (k > 0) {
    cout << " ";
    k--;
  }
}

void size_pr(std::string chislo) {
  int s = chislo.size();

  if (s == 0) prob_nichego();
  /// ставим пробелы
  else {
    int d = 9 - s;
    while (d > 0) {
      cout << " ";
      d--;
    }
  }
  ///
  cout << "|";
}

template<class T>
void TTable<T>::outputVarTable()
{
  std::string a = "", a1="";
  if (recCount > 0) {
    cout << " ________________________________" << endl;
    cout << "|ID        |Name      |Value     |" << endl;
    cout << "|__________|__________|__________|" << endl; //10 пробелов -1 на начало
    for (int i = 0; i < recCount; i++) {
      cout << "| " << i;
      a = to_string(i);
      size_pr(a);
      //ID ready
      a = records[i].GetName();
      cout << " " << a;
      size_pr(a);
      a = to_string(records[i].GetValue());
      if (a.size() > 5) {
        a1 = "";
        for (int i = 0; i < 5; i++) {
          a1 = a1 + a[i];
        }
        a = a1;
      }
      cout <<" "<< a;
      size_pr(a);
      cout << endl;
      cout << "|__________|__________|__________|" << endl;
    }
  }
}

int kvo_chisel(char* b) {
  int res = 0;
  for (int i = 0; b[i]!='\0'; i++) {
    if (b[i] == ' ') res++;
    if (!((isNumb1(b[i]))||(isLetter1(b[i])|| (b[i] == ' ')))) res--;
  }
  return res;
}

template<class T>
void TTable<T>::ImpTFormPoliz(TFormPoliz a)
{
  if (recCount != 0) delete[]records;
  recCount = kvo_chisel(a.getPizPoliz());
  records = new TRecord<T>[recCount];
  string dop = "";
  int i1 = 0;
  for (int i = 0; i < recCount; i++) {
    dop = "";
    while (a.getPizPoliz()[i1] != ' ') {
      dop = dop + a.getPizPoliz()[i1];
      i1++;
    }
    i1++;
    if (isNumb1(dop[0])) {
      double dou = atof(dop.c_str());
      records[i].SetValue(dou);
    }
    if (isLetter1(dop[0])) {
      records[i].SetName(dop);
    }
  }
}

template<class T>
unsigned int TTable<T>::GetSize()
{
  return tabSize;
}

template<class T>
unsigned int TTable<T>::RowNumber(std::string _Name)
{
  for (int i = 0; i < tabSize; i++) {
    if (records[i].GetName() == _Name) return i;
  }
  return 0;
}


template class TTable<double>;

