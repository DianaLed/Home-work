#include "TFormPoliz.h"
#include "TStack.h"
#include "TScaner.h"
#include <iostream>
using namespace std;

TFormPoliz::TFormPoliz(char *_orgExpr) {
  int i = 0;
  orgExpr = new char[200];
  pizExpr = new char[200];
  while (_orgExpr[i - 1] != '\0')
    orgExpr[i] = _orgExpr[i++];
  pizExpr[0] = '\0';
}


std::string perenos_zn_left_one(std::string a, char zn) {
  std::string res = "";
  int klvo = 0;
  int s = a.size();
  for (int i = 0; i < s; i++) {
    if (a[i] == ' ')klvo++;
  }
  //посчитали общее количество пробелов
  if (klvo <= 2) {
    res = a + zn;
    res = res + " ";
    return res;
  }
  std::string part1 = "", part2 = "";
  int dkl = klvo - 3, d = 0;
  for (int i = 0; i < s; i++) {
    if (a[i] == ' ')d++;
    if (d <= dkl) part1 = part1 + a[i];
    if (d > dkl) part2 = part2 + a[i];
  }
  res = part1 + zn;
  res = part1 + part2;
  return res;
}
void dob_stack(TStack<double>* a, TStack<double> b) {
  while (!(b.IsEmpty())) a->Put(b.Get());
}
int getOperationPriority(char opr)
{
  if ((opr == '+') || (opr == '-')) return 1;
  if ((opr == '*') || (opr == '/')) return 2;
  return 0;
}
void rawno_stack(TStack<double>* a, TStack<double> b) {
  TStack<double> c(200);
  char d;
  while (!(b.IsEmpty())) {
    c.Put(b.Get());
  }
  while (!(a[0].IsEmpty())) {
    d = a[0].Get();
  }
  while (!(c.IsEmpty())) {
    a[0].Put(c.Get());
  }
}

void yravnen(std::string isx_vqr, std::string* let, TStack<double>* st_zn) {
  std::string res_letters = "";
  std::string dop_vqr = ""; std::string* dop_let = new std::string[1];
  TStack<double> stack_zn(200);
  TStack<double> dop_stack_zn(200);
  //перебиваем string в char
  int aw = isx_vqr.size();
  char* c_isx_v = new char[isx_vqr.size() + 1];
  for (int i = 0; i < aw; i++) {
    c_isx_v[i] = isx_vqr[i];
  }
  c_isx_v[aw] = '\0';
  TScaner scan(c_isx_v);
  //создали скан
  char znak;
  char* letter = new char[1];
  int i1 = scan.getNextElem(znak, letter);
  int dop = 0;
  char a, b;
  //забиваем выражение
  while (i1 != 0) {
    //если буква
    if (i1 == 2) {
      res_letters = res_letters + letter;
      res_letters = res_letters + ' ';
    }
    //если знак
    if (i1 == 1) {
      //обрабатываем выражение в скобках
      if (znak == '(') {
        dop_vqr = "";
        dop = 1;
        //будет переписан пример до закрывающей скобочки (причем не первой, а именно к этой)
        while (dop != 0) {
          i1 = scan.getNextElem(znak, letter);
          //добавляем в строку букву
          if (i1 == 2) {
            dop_vqr = dop_vqr + letter;
            dop_vqr = dop_vqr + " ";
          }
          //добавляем в строку знак
          if (i1 == 1) {
            //если еще (
            if (znak == '(') {
              dop++;
              dop_vqr = dop_vqr + znak;
              dop_vqr = dop_vqr + " ";
            }
            else
              //если )
              if (znak == ')') {
                dop--;
                if (dop != 0) {
                  dop_vqr = dop_vqr + znak;
                  dop_vqr = dop_vqr + " ";
                }
              }
              else
                //если просто знак добавили 
              {
                dop_vqr = dop_vqr + znak;
                dop_vqr = dop_vqr + " ";
              }
          }
        }
        //заполнили строку с выражениями
        yravnen(dop_vqr, dop_let, &dop_stack_zn); //произошло чудо и оно обработалось
        //если стек пустой, то перекачиваем в него наш стек и числа
        if (stack_zn.IsEmpty()) {
          if (!(dop_stack_zn.IsEmpty())) dob_stack(&stack_zn, dop_stack_zn);
          res_letters = res_letters + dop_let[0];
        }
        //если стек не пустой, то нужно ставить в начало последний знак перед скобкой 
        else {
          //добавили буквы
          res_letters = res_letters + dop_let[0]; //?
          res_letters = res_letters + ' ';
          //добавляем знаки
          while (!(dop_stack_zn.IsEmpty())) {
            a = dop_stack_zn.Get();
            res_letters = res_letters + a;
            res_letters = res_letters + ' ';
          }
          //добавили занки и буквы
        }
        //готово
      //}
      //закончили обрабатывать содержимое скобок
      }
      //если это просто знак
      else {
        //если стек пуст
        if (stack_zn.IsEmpty()) {
          stack_zn.Put(znak);
        }
        //если стек не пуст
        else {
          a = znak;
          b = stack_zn.Get();
          if (getOperationPriority(a) >= getOperationPriority(b)) {
            if (getOperationPriority(a) == getOperationPriority(b)) res_letters = perenos_zn_left_one(res_letters, b);
            else stack_zn.Put(b);
            stack_zn.Put(a);
          }
          else {
            res_letters = perenos_zn_left_one(res_letters, b);
            stack_zn.Put(a);
          }
        }
      }
      //добавили знак
    }
    i1 = scan.getNextElem(znak, letter);
  }
  let[0] = res_letters;
  while (!(stack_zn.IsEmpty())) {
    a = stack_zn.Get();
    let[0] = let[0] + a;
    let[0] = let[0] + " ";
  }
  rawno_stack(st_zn, stack_zn);
}

void TFormPoliz::formPizExpr() {
  std::string a = "", b = "", c = "";
  TStack<double> z(200);
  char* res;
  char ch;
  int i1 = 0;
  while (orgExpr[i1] != '\0') {
    a = a + orgExpr[i1];
    i1++;
  }
  yravnen(a, &b, &z);
  i1 = 0;
  while (b[i1] != '\0') {
    pizExpr[i1] = b[i1];
    i1++;
  }
  pizExpr[i1] = '\0';
}

char* TFormPoliz::getPizPoliz() {
  if (pizExpr[0] != '\0')
    return pizExpr;
  else
    throw logic_error("ERROR getPizPoliz");
}

int TFormPoliz::getOperationPriority(char opr) {
  int res = -1;
  if (res == '(') res = 0;
  else if (opr == '+' || opr == '-') res = 1;
  else if (opr == '*' || opr == '/') res = 2;
  return res;
}

void TFormPoliz::addToPolish(char *operand) {
  int j = 0, i=0;
  while (pizExpr[j] != '\0') j++;
  j = 0;
  i = 0;
  while (operand[i] != '\0') pizExpr[j++] = operand[i++];
  pizExpr[j++] = '\0';
}

void TFormPoliz::addToPolish(char oper) {
  int j = 0;
  while (pizExpr[j] != '\0')j++;
  --j;
  pizExpr[j] = oper;
  pizExpr[++j] = ' ';
  pizExpr[++j] = '\0';
}