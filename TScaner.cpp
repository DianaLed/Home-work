#include "TScaner.h"
#include <string>
TScaner::TScaner(char* _expr)
{
  std::string a = _expr;
  size_of_expr = a.size();
  char c = '\0';
  expr = NULL;
  if (size_of_expr != 0) {
    expr = new  char[size_of_expr+1];
    for (int i = 0; i < size_of_expr; i++) {
      expr[i] = a[i];
    }
    expr[size_of_expr] = c;
  }
  ind = 0;
  delBlank();
}

TScaner::~TScaner()
{
  delete[] expr;
}

int TScaner::getNextElem(char& oper, char* operand)
{
  if (expr == NULL) return 0;
  /*if (operand != NULL)delete[] operand;*/
  if (ind >= size_of_expr) {  //если последний символ
   /* operand = new char[1];*/
    operand[0] = '\0';
    oper = '\0';
    return 0; 
  }
  if ((isOperation(expr[ind])) && (size_of_expr >= ind)) { //если операция
    if ((expr[ind] == '-') && (ind == 0)) ind++;
    else {
      oper = expr[ind];
      operand = expr;
      ind++; //след индекс
      return 1;
    }
  }
  if ((isNumber(expr[ind])) && (size_of_expr > ind)) { //если число
    //проводим работу над операндом
    int dopi=0;
    if ((ind == 1) && (expr[0] == '-')) {
      operand[0] = expr[0];
      dopi = 1;
    }
    while ((isNumber(expr[ind])) && (size_of_expr > ind)) {
      operand[dopi] = expr[ind];
      dopi++;
      ind++;
    }
    operand[dopi] = '\0';
    //вбили операнд
    return 2;
  }
  return -1;
}

void TScaner::delBlank()
{

  if (size_of_expr != 0) {
    std::string a = expr;
    char* expr_c = new char[100];
    int i1 = 0;
    for(int i=0; i< size_of_expr; i++){
        while((a[i] == ' ')&&(i< size_of_expr)) {
          i++;
        }
    expr_c[i1] = a[i];
    i1++;
    }
    expr_c[i1] = '\0';
    delete[] expr;
    expr= new char[i1+1];
    for (int i = 0; i < i1; i++) {
      expr[i] = expr_c[i];
    }
    expr[i1] = '\0';
  }
}

bool TScaner::isOperation(char c)
{
  if((c=='*')||(c=='/') || (c == '-') || (c == '+') || (c == ')') || (c == '(')) return true;
  return false;
}

bool TScaner::isNumber(char c)
{
  if((c-'0'<10)&&(c - '0'>-1)) return true;
  if ((c >= 'a') && (c <= 'z')) return true;
  if ((c >= 'а') && (c <= 'я')) return true;
  if ((c == '.') || (c == ',')) return true;
  return 0;
}
