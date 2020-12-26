#include "TScaner.h"
#include <iostream>

using namespace std;

TScaner::TScaner(char *_expr) {
  int i = 0;
  expr = new char[200];
  while (_expr[i] != '\0') {
    expr[i] = _expr[i];
    i++;
  }
  expr[i] = '\0';
  ind = 0;
}

TScaner::~TScaner()
{
  ind = 0;
  delete[]expr;
}

int TScaner::getNextElem(char &oper, char *operand) {
 int res, i;
 char d= expr[ind];
     if ((d == '-') && (isNumber(expr[ind + 1])) || (isNumber(expr[ind]))) {
      res = 2;
      i = 0;
      operand[i++] = expr[ind++];
      while (isNumber(expr[ind]))
        operand[i++] = expr[ind++];
      operand[i] = '\0';
    } else if (isOperation(expr[ind])) {
      res = 1;
      oper = expr[ind++];
    } else if (expr[ind] == '\0'){
      res = 0;
    } else {
      ind++;
      res = 3;
    }
  return res;
}

void TScaner::delBlank() {
  int i = 0, j=0;
  while (expr[i] != '\0') {
    if (expr[i] == ' ') {
      j = i;
      while (expr[j] != '\0') {
        expr[j] = expr[j + 1];
        j++;
      }
    }
    i++;
  }
}

bool TScaner::isOperation(char c) {
  return ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')'));
}

bool TScaner::isNumber(char c) {
  if ((c - '0' < 10) && (c - '0' > -1)) return true;
  if ((c >= 'a') && (c <= 'z')) return true;
  if ((c >= 'à') && (c <= 'ÿ')) return true;
  if ((c == '.') || (c == ',')) return true;
  return 0;
}


