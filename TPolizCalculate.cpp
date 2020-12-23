#include "TPolizCalculate.h"
#include "TFormPoliz.h"
#include "TScaner.h"
#include "TStack.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>


bool isLetter(char c)
{
  if ((c >= 'a') && (c <= 'z')) return true;
  if ((c >= 'à') && (c <= 'ÿ')) return true;
  return 0;
}
bool isNumb(char c)
{
  if ((c - '0' < 10) && (c - '0' > -1)) return true;
  if ((c == '.') || (c == ',')) return true;
  return 0;
}
bool isZn(char c) {
  if ((c == '+') || (c == '-')) return 1;
  if ((c == '*') || (c == '/')) return 1;
  return 0;
}

int prob_back(std::string e, int symbol) {
  while (symbol > 0) {
    symbol--;
    if (e[symbol] == ' ') {
      while (symbol > 0) {
        symbol--;
        if (e[symbol] == ' ') {
          symbol++;
          return symbol;
        }
        if (symbol==0) {
          return symbol;
        }
      }
    }
    return -1;
  }
}
int nom_ferst_zn(std::string e) {
  int s = e.size();
  for (int i = 0; i < s; i++) {
    if (isZn(e[i])) return i;
  }
  return -1;
}
double para_do1(std::string e, int nom) {
  int r2 = prob_back(e, nom);
  int r1 = prob_back(e, r2);
  std::string rash = "";
  while ((isNumb(e[r1]) && (r1 < e.size()))) {
    rash = rash + e[r1];
    r1++;
  }
  double res = atof(rash.c_str());
  return res;
}
double para_do2(std::string e, int nom) {
  int r2 = prob_back(e, nom);
  std::string rash = "";
  while ((isNumb(e[r2])&&(r2<e.size()))) {
    rash = rash + e[r2];
    r2++;
  }
  double res = atof(rash.c_str());
  return res;

}

double do_it(std::string e, int nom) {
  double a1 = para_do1(e, nom);
  double a2 = para_do2(e, nom);
  if (e[nom] == '+') return a1 + a2;
  if (e[nom] == '-') return a1 - a2;
  if (e[nom] == '*') return a1 * a2;
  if (e[nom] == '/') return a1 / a2;
  return (-1);
}

std::string posle(std::string e, int nom_zn) {
  std::string res = "";
  for (int i = nom_zn+2; i < e.size(); i++) {
    res = res + e[i];
  }
  return res;
}

std::string start(std::string e, int nom_zn) {
  std::string res = "";
  int s = prob_back(e, (prob_back(e, nom_zn)))-1;
  if (s > 0) {
   for (int i = 0; i < s; i++) {
    res = res + e[i];
   }
  }
  return res;
}



TPolizCalculate::TPolizCalculate(char* _pizExpr, TTable<double> a)
{
  pizExpr = _pizExpr;
  int i1 = 0, d;
  std::string name = "", a1="", all="";
  double re;
  while (pizExpr[i1] != '\0') {
    if (isLetter(pizExpr[i1])) {
      name = "";
      name = name + pizExpr[i1];
      re = a.GetValue(name);
      all = all + std::to_string(re);
    }
    else {
      all = all + pizExpr[i1];
    }
    i1++;
  }
   /*delete[]pizExpr;*/
   pizExpr = new char[all.size() + 1];
   for (int i = 0; i < all.size(); i++) {
     pizExpr[i] = all[i];
   }
   pizExpr[all.size()] = '\0';
}

TPolizCalculate::~TPolizCalculate()
{
  delete[]pizExpr;
}

double TPolizCalculate::calculatePizExpr()
{
  std::string all = "", rash = "";
  std::string c1 = "", c4 = "";
  double sum;
  for (int i = 0; pizExpr[i] != '\0'; i++) {
    all = all + pizExpr[i];
  }
  int nom_zn = nom_ferst_zn(all);
  while (nom_zn != -1) {
    sum = do_it(all, nom_zn);
    c1 = start(all, nom_zn);
    c4 = posle(all, nom_zn);
    all = c1;
    all = all + std::to_string(sum);
    all = all + c4;
    nom_zn = nom_ferst_zn(all);
  }
  return atof(all.c_str());
}
