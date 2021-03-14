﻿
#include "TDatValue.h"
#include "TItemValue.h"

#include "TDatLink.h"
#include "TDatList.h"

#include "Monom.h"
#include "Polinom.h"

#include <iostream>

void printList(TDatList& st)
{
  cout << st << " ";
  cout << endl;
}

using namespace std;

//int main()
//{
//  setlocale(LC_ALL, "Russian");
//  cout << "Тестирование списка" << endl;
//  // Конструктор --------------------------------------------
//  cout << "\nКонструктор --------------------------------------------" << endl;
//  int elemsCount = 5;
//  PTDatValue* listElems = new PTDatValue[elemsCount];
//  PTItemValue pVal;
//  for (int i = 0; i < elemsCount; i++)
//  {
//    pVal = new TItemValue(10 * i);
//    listElems[i] = pVal;
//  }
//  TDatList st(listElems, elemsCount);
//
//  // печать списка
//  printList(st);
//  // Вставить элементы списка
//  cout << "\nВставить элементы списка: 11 - в начало, 12 - в конец, 13 - перед текущим ----" << endl;
//  st.Reset();
//  PTItemValue iVal1 = new TItemValue(11);
//  PTItemValue iVal2 = new TItemValue(12);
//  PTItemValue iVal3 = new TItemValue(13);
//  int cur2 = st.GetCurrentPos();
//  cout << "Текущий элемент: " << cur2 << endl;
//  st.GoNext();
//  st.GoNext();
//  int cur1 = st.GetCurrentPos();
//  cout << "Текущий элемент: " << cur1 << endl;
//  st.InsCurrent(iVal3);
//  st.InsFirst(iVal1);
//  st.InsLast(iVal2);
//  printList(st);
//  // Взять текущий элемент списка
//  cout << "\nВзять текущий элемент списка ------------------------------------------" << endl;
//  st.Reset();
//  st.GoNext();
//  st.GoNext();
//  int cur4 = st.GetCurrentPos();
//  cout << "Текущий элемент: " << cur4 << endl;
//  PTItemValue iVal4 = (PTItemValue)(st.GetDatValue(CURRENT));
//  cout << "Элемент = " << iVal4->GetValue() << endl;
//  printList(st);
//  // Удалить элемент списка
//  cout << "\nУдалить элементы списка: текущий, первый ----------------------------" << endl;
//  st.Reset();
//  st.GoNext();
//  st.GoNext();
//  int cur5 = st.GetCurrentPos();
//  cout << "Текущий элемент: " << cur5 << endl;
//  st.DelCurrent();
//  printList(st);
//  st.DelFirst();
//  printList(st);
//}

void main()
{
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование полиномов" << endl;
  int ms1[][2] = { {1, 543}, {3, 432}, {5, 321}, {7, 210}, {9, 100} };
  int mn1 = sizeof(ms1) / (2 * sizeof(int));
  TPolinom p(ms1, mn1);
  cout << "1 полином" << endl << p<<endl;
  int ms2[][2] = { {2, 643}, {4, 432}, {-5, 321}, {8, 110}, {10, 50} };
  int mn2 = sizeof(ms2) / (2 * sizeof(int));
  TPolinom q(ms2, mn2);
  cout << "2 полином" << endl << q << endl;
  TPolinom r;
  //r = p + q;
  cout << "Полином-результат + " << endl << p + q;
  TPolinom r1 = r;
  cout << "Полином-результат = " << endl << r1;
  TPolinom c(r);
  cout << "Полином-копия = " << endl << c;
}

