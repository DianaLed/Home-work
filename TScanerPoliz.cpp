#include "TScanerPoliz.h"
#include <string>

TScanerPoliz::TScanerPoliz(char *_poliz) {
  poliz = new char[200];
  ind = 0;
  int i = 0;
  while (_poliz[i - 1] != '\0')
    poliz[i] = _poliz[i++];
}

int TScanerPoliz::getNextElemPoliz(char &oper, double &operand, char *varible) {
  int res, i;
  char doubleNum[30];
  // без пробела
  if (isVarible(poliz[ind])) {
    res = 4;
    i = 0;
    varible[i++] = poliz[ind++];
    while (isVarible(poliz[ind]))
      varible[i++] = poliz[ind++];
    varible[i] = '\0';
  } else if (poliz[ind] == 45 && isNumber(poliz[ind + 1]) || isNumber(poliz[ind])) {
    res = 2;
    i = 0;
    doubleNum[i++] = poliz[ind++];
    while (isNumber(poliz[ind]))
      doubleNum[i++] = poliz[ind++];
    doubleNum[i] = '\0';
    operand = strtod(doubleNum, NULL);
  }
  else if (isOperation(poliz[ind])) {
    res = 1;
    oper = poliz[ind++];
  }
  else if (poliz[ind] == '\0') {
    res = 0;
  }
  else {
    ind++;
    res = 3;
  }
  return res;
 }

int TScanerPoliz::getNextElemPoliz(char &oper, double &operand) {
  int res, i;
  char doubleNum[30];
  // без пробела
  if (poliz[ind] == 45 && isNumber(poliz[ind + 1]) || isNumber(poliz[ind])) {
    res = 2;
    i = 0;
    doubleNum[i++] = poliz[ind++];
    while (isNumber(poliz[ind]))
      doubleNum[i++] = poliz[ind++];
    doubleNum[i] = '\0';
    operand = strtod(doubleNum, NULL);
  }
  else if (isOperation(poliz[ind])) {
    res = 1;
    oper = poliz[ind++];
  }
  else if (poliz[ind] == '\0') {
    res = 0;
  }
  else {
    ind++;
    res = 3;
  }
  return res;
}

bool TScanerPoliz::isOperation(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

bool TScanerPoliz::isNumber(char c) {
  return (c > 47 && c < 58 || c == 46);
}

bool TScanerPoliz::isVarible(char c) {
  return (c > 96 && c < 123);
}