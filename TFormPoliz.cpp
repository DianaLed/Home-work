#include "TFormPoliz.h"
#include "TScaner.h"
#include "TStack.h"
#include <string>

int size_zn(char* _orgExpr) {
  int i = 0, res=0;
  char a = '\0';
  while (_orgExpr[i] != a) {
    if ((_orgExpr[i] == '+') || (_orgExpr[i] == '-') || (_orgExpr[i] == '/') || (_orgExpr[i] == '*') || (_orgExpr[i] == ')') || (_orgExpr[i] == '(')) res++;
    i++;
  }
  return res;
}

int size_per(char* _orgExpr) {
  int i = 0, res = 0;
  char a = '\0';
  while (_orgExpr[i] != a) {
    if ((_orgExpr[i] >= 'a') && (_orgExpr[i] <= 'z')) res++;
    i++;
  }
  return res;
}




TFormPoliz::TFormPoliz(char* _orgExpr)
{
  int size = 0;
  char c = '\0';
  while (_orgExpr[size] != c) {
    size++;
  }
  orgExpr = new char[size+1];
  orgExpr = _orgExpr;
  orgExpr[size + 1] = c;
  pizExpr =new char[size + 1];
}

TFormPoliz::~TFormPoliz()
{
  //if(orgExpr) delete[]orgExpr;
  //if (pizExpr) delete[]pizExpr;
}

void TFormPoliz::formPizExpr(char* _orgExpr)
{
  orgExpr = _orgExpr;
  int s_zn = size_zn(orgExpr);
  int s_per = size_per(orgExpr);
  char *mass_zn=new char [s_zn];
  int* prior_zn = new int[s_zn];
  for (int i = 0; i < s_zn; i++) {
    prior_zn = 0;
  }
  char* mass_per = new char[s_per];
  TScaner scan(orgExpr);
  int idop = 0, d1 = 0, d2=0;
  char ch=' ', * ch1=new char[1];
  ch1[0] = '\0';
  /*for (int i = 0; i < s_zn + s_per; i++) {
    idop = scan.getNextElem(ch, ch1);
    if (idop == 1) {
      mass_zn[d1] = ch;
      d1++;
    }
    if (idop == 2) {
      mass_per[d2] = ch;
      d2++;
    }

  }*/
  _orgExpr = orgExpr;
  delete[]mass_zn;
}

bool isOperation(char c)
{
  if ((c == '*') || (c == '/') || (c == '-') || (c == '+') || (c == ')') || (c == '(')) return true;
  return false;
}
void plus_el_stack(TStack* a, char el) {
  TStack b;
  while (!(a->IsEmpty())) b.Put(a->Get());
  b.Put(el);
  while (!(b.IsEmpty())) a->Put(b.Get());
  //?
}

void dob_stack(TStack* a, TStack b) {
  while (!(b.IsEmpty())) a->Put(b.Get());
  //?
}

void rawno_stack(TStack* a, TStack b) {
  TStack c;
  char d;
  while (!(b.IsEmpty())) {
    c.Put(b.Get());
  }
  while (!(a[0].IsEmpty())) {
    d=a[0].Get();
  }
  while (!(c.IsEmpty())) {
    a[0].Put(c.Get());
  }
}

int getOperationPriority(char opr)
{
  if ((opr == '+') || (opr == '-')) return 1;
  if ((opr == '*') || (opr == '/')) return 2;
  return 0;
}

std::string perenos_zn_left_one(std::string a, char zn) {
  std::string res="";
  int klvo = 0;
  int s = a.size();
  for (int i = 0; i < s; i++) {
    if(a[i]==' ')klvo++;
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

void yravnen(std::string isx_vqr, std::string *let, TStack *st_zn) {
  std::string res_letters = "";
  std::string dop_vqr = ""; std::string * dop_let = new std::string[1];
  TStack stack_zn, *dop_stack_zn=new TStack[1];
  //перебиваем string в char
  int aw = isx_vqr.size();
  char* c_isx_v = new char[isx_vqr.size()+1];
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
  while (i1 != -1) {
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
                dop_vqr= dop_vqr + " ";
              }
          }
        }
          //заполнили строку с выражениями
          yravnen(dop_vqr, dop_let, dop_stack_zn); //произошло чудо и оно обработалось
          //если стек пустой, то перекачиваем в него наш стек и числа
          if (stack_zn.IsEmpty()) {
            if (!(dop_stack_zn->IsEmpty())) dob_stack(&stack_zn, dop_stack_zn[0]);//?
            res_letters = res_letters + dop_let[0]; //?
          }
          //если стек не пустой, то нужно ставить в начало последний знак перед скобкой 
          else {
            //добавили буквы
            res_letters = res_letters + dop_let[0]; //?
            res_letters = res_letters + ' ';           
            //добавляем знаки
            while (!(dop_stack_zn->IsEmpty())) {
              a= dop_stack_zn->Get();
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
          } else {
            /*res_letters = res_letters + b;
            res_letters = res_letters + ' ';
            stack_zn.Put(a);*/
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


char* TFormPoliz::getPizPoliz()
{
  std::string a = "", b="", c="";
  TStack z;
  char* res;
  char ch;
  int i1 = 0;
  while (orgExpr[i1] != '\0') {
    a = a + orgExpr[i1];
    i1++;
  }
  yravnen(a, &b, &z);
  while (!(z.IsEmpty())) {
    ch= z.Get();
    c = c + ch;
    c = c + ' ';
  }
  b = b + c;
  i1 = b.size();
  res = new char[i1+1];
  for (int i = 0; i < i1; i++) {
    res[i] = b[i];
  }
  res[i1] = '\0';
  return res;
}

int TFormPoliz::getOperationPriority(char opr)
{
  if ((opr == '+') || (opr == '-')) return 1;
  if ((opr == '*') || (opr == '/')) return 2;
  return 0;
}

