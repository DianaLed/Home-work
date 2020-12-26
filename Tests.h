#define TESTS
#ifdef TESTS
#include <iostream>
#include "TStack.h"
#include "TFormPoliz.h"
#include "TScaner.h"
#include "TScanerPoliz.h"
#include "TPolizCalculate.h"
using namespace std;
static void test1() {
  cout << "Paired brackets tests:" << endl << endl;
  {
    char s[200] = "())(()";
    cout << "Test 1. Expr = " << s << "." << endl;
    cout << "Expected output:" << endl
      << "012345" << endl
      << s << endl
      << "0 - 1" << endl
      << "? - 2" << endl
      << "4 - 5" << endl
      << "3 - ?" << endl;
    cout << "Actual output:" << endl;
    int erCount = doSkbControl(s);
    cout << "ErCount. Expected: 2, axtual: " << erCount << endl << endl;
  }
  {
    char s[200] = "(()())";
    cout << "Test 2. Expr = " << s << "." << endl;
    cout << "Expected output:" << endl
      << "012345" << endl
      << s << endl
      << "1 - 2" << endl
      << "3 - 4" << endl
      << "0 - 5" << endl;
    cout << "Actual output:" << endl;
    int erCount = doSkbControl(s);
    cout << "ErCount. Expected: 0, axtual: " << erCount << endl << endl;
  }
  {
    char s[200] = "(()))(";
    cout << "Test 3. Expr = " << s << "." << endl;
    cout << "Expected output:" << endl
      << "012345" << endl
      << s << endl
      << "1 - 2" << endl
      << "0 - 3" << endl
      << "? - 4" << endl
      << "5 - ?" << endl;
    cout << "Actual output:" << endl;
    int erCount = doSkbControl(s);
    cout << "ErCount. Expected: 2, axtual: " << erCount << endl << endl;
  }
  {
    char s[200] = "(((";
    cout << "Test 4. Expr = " << s << "." << endl;
    cout << "Expected output:" << endl
      << "012" << endl
      << s << endl
      << "2 - ?" << endl
      << "1 - ?" << endl
      << "0 - ?" << endl;
    cout << "Actual output:" << endl;
    int erCount = doSkbControl(s);
    cout << "ErCount. Expected: 3, axtual: " << erCount << endl << endl;
  }
  {
    char s[200] = ")))";
    cout << "Test 5. Expr = " << s << "." << endl;
    cout << "Expected output:" << endl
      << "012" << endl
      << s << endl
      << "? - 0" << endl
      << "? - 1" << endl
      << "? - 2" << endl;
    cout << "Actual output:" << endl;
    int erCount = doSkbControl(s);
    cout << "ErCount. Expected: 3, axtual: " << erCount << endl << endl;
  }

  {
    char s[200] = " ( ) ) ( ( ) ";
    cout << "Test 6. Expr = " << s << "." << endl;
    cout << "Expected output:" << endl
      << "0123456789012" << endl
      << s << endl
      << "1 - 3" << endl
      << "? - 5" << endl
      << "9 - 11" << endl
      << "7 - ?" << endl;
    cout << "Actual output:" << endl;
    int erCount = doSkbControl(s);
    cout << "ErCount. Expected: 2, axtual: " << erCount << endl << endl;
  }
}
static void test2() {
  cout << "TScaner tests:" << endl;
  char oper = ' ';
  char operand[20];
  {
    char s[200] = "";
    TScaner scaner(s);
    cout << "Test 1. Expr = " << s << endl;
    cout << "Expected output: 0, actual output: " << scaner.getNextElem(oper, operand) << endl;
    cout << endl;
  }
  {
    char s[200] = "0";
    TScaner scaner(s);
    cout << "Test 2. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElem(oper, operand) << endl;
    cout << "Expected operand: 0, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = " 1 ";
    TScaner scaner(s);
    cout << "Test 3. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElem(oper, operand) << endl;
    cout << "Expected operand: 1, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "10";
    TScaner scaner(s);
    cout << "Test 4. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElem(oper, operand) << endl;
    cout << "Expected operand: 10, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "10.";
    TScaner scaner(s);
    cout << "Test 5. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElem(oper, operand) << endl;
    cout << "Expected operand: 10., actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "10.5";
    TScaner scaner(s);
    cout << "Test 6. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElem(oper, operand) << endl;
    cout << "Expected operand: 10.5, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "+-*/()";
    TScaner scaner(s);
    cout << "Test 7. Expr = " << s << endl;
    std::string actOut, actOpers;
    for (int i = 0; i < 6; i++) {
      actOut += to_string(scaner.getNextElem(oper, operand));
      actOpers += oper;
    }
    cout << "Expected output: 111111, actual output: " << actOut << endl;
    cout << "Expected opers: " << s << ", actual opers: " << actOpers << endl;
    cout << endl;
  }
  {
    char s[200] = "-1";
    TScaner scaner(s);
    cout << "Test 8. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElem(oper, operand) << endl;
    cout << "Expected operand: -1, actual operand: " << operand << endl;
    cout << endl;
  }
  cout << endl;

  // TFormPoliz tests:
  cout << "TFormPoliz tests:" << endl;
  {
    char s[200] = "8.5 + 7.5";
    cout << "Test 1. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 +" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 - 7.5 - 8.0";
    cout << "Test 2. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 - 8.0 -" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 + 7.5 * 2";
    cout << "Test 3. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 2 * +" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "(8.5 / 2)";
    cout << "Test 4. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 2 /" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 - (7.5 + 8.0)";
    cout << "Test 5. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 8.0 + -" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "2 * (7.5 + 8.0)";
    cout << "Test 6. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 2 7.5 8.0 + *" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "3 / ((1 + 2) * (3 - 4))";
    cout << "Test 7. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 3 1 2 + 3 4 - * /" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "-3 / (-3)";
    cout << "Test 8. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: -3 -3 /" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 - (91 - 78./4) * 7.";
    cout << "Test 9. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 91 78. 4 / - 7. * -" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;
    cout << endl;
  }
}
static void test3() {
  cout << "TScanerPoliz tests:" << endl;
  char oper = ' ';
  double operand;
  {
    char s[200] = "";
    TScanerPoliz scaner(s);
    cout << "Test 1. Expr = " << s << endl;
    cout << "Expected output: 0, actual output: " << scaner.getNextElemPoliz(oper, operand) << endl;
    cout << endl;
  }
  {
    char s[200] = "0";
    TScanerPoliz scaner(s);
    cout << "Test 2. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElemPoliz(oper, operand) << endl;
    cout << "Expected operand: 0, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "10";
    TScanerPoliz scaner(s);
    cout << "Test 3. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElemPoliz(oper, operand) << endl;
    cout << "Expected operand: 10, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "10.";
    TScanerPoliz scaner(s);
    cout << "Test 4. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElemPoliz(oper, operand) << endl;
    cout << "Expected operand: 10, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "10.5";
    TScanerPoliz scaner(s);
    cout << "Test 5. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElemPoliz(oper, operand) << endl;
    cout << "Expected operand: 10.5, actual operand: " << operand << endl;
    cout << endl;
  }
  {
    char s[200] = "+-*/";
    TScanerPoliz scaner(s);
    cout << "Test 6. Expr = " << s << endl;
    std::string actOut, actOpers;
    for (int i = 0; i < 4; i++) {
      actOut += to_string(scaner.getNextElemPoliz(oper, operand));
      actOpers += oper;
    }
    cout << "Expected output: 1111, actual output: " << actOut << endl;
    cout << "Expected opers: " << s << ", actual opers: " << actOpers << endl;
    cout << endl;
  }
  {
    char s[200] = "-1";
    TScanerPoliz scaner(s);
    cout << "Test 7. Expr = " << s << endl;
    cout << "Expected output: 2, actual output: " << scaner.getNextElemPoliz(oper, operand) << endl;
    cout << "Expected operand: -1, actual operand: " << operand << endl;
    cout << endl;
  }
  cout << endl;

  // TFormPoliz tests:
  cout << "TFormPoliz tests:" << endl;
  {
    char s[200] = "8.5 + 7.5";
    cout << "Test 1. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 +" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: 16" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 - 7.5 - 8.0";
    cout << "Test 2. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 - 8.0 -" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: -7" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 + 7.5 * 2";
    cout << "Test 3. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 2 * +" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: 23.5" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "(8.5 / 2)";
    cout << "Test 4. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 2 /" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: 4.25" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 - (7.5 + 8.0)";
    cout << "Test 5. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 7.5 8.0 + -" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: -7" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "2 * (7.5 + 8.0)";
    cout << "Test 6. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 2 7.5 8.0 + *" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: 31" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "3 / ((1 + 2) * (3 - 4))";
    cout << "Test 7. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 3 1 2 + 3 4 - * /" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: -1" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "-3 / (-3)";
    cout << "Test 8. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: -3 -3 /" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: 1" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
  {
    char s[200] = "8.5 - (91 - 78./4)  * 7.";
    cout << "Test 9. orgExpr = " << s << endl;
    TFormPoliz poliz(s);
    poliz.formPizExpr();
    cout << "Expected pizExpr: 8.5 91 78. 4 / - 7. * -" << endl;
    cout << "Actual pizExpr:   " << poliz.getPizPoliz() << endl;

    TPolizCalculate polizCalculate(poliz.getPizPoliz());
    double res = polizCalculate.calculatePizExpr();
    cout << "Expected res: -492" << endl;
    cout << "Actual res:   " << res << endl;
    cout << endl;
  }
}
static void test4() {
  cout << "Tests:" << endl;
  {
    TTable<double> varTable(20);
    char expr[200] = "x + 5.5";
    cout << "Test 1. Expr = " << expr << endl;
    // 1. x = 4.5 -> res = 10
    // 2. x = -4.5 -> res = 1

    TFormPoliz poliz(expr);
    poliz.formPizExpr();
    char* pizExpr = poliz.getPizPoliz();

    cout << "1. pizExpr:" << endl;
    cout << "Expected pizExpr: x 5.5 +" << endl;
    cout << "Actual pizExpr:   " << pizExpr << endl;

    cout << "2. Print table before:" << endl;
    varTable.outputVarTable();
    cout << "3. Enter variables:" << endl;
    varTable.inputVarValues();
    cout << "4. Print table after:" << endl;
    varTable.outputVarTable();

    TPolizCalculate polizCalculate(pizExpr);
    double res = polizCalculate.calculatePizExpr(varTable);

    cout << "5. res = " << res << endl;
    cout << endl;
  }
  {
    TTable<double> varTable(20);
    char expr[200] = "5.5 - x";
    cout << "Test 2. Expr = " << expr << endl;
    // 1. x = 4.5 -> res = 1
    // 2. x = -4.5 -> res = 10

    TFormPoliz poliz(expr);
    poliz.formPizExpr();
    char* pizExpr = poliz.getPizPoliz();

    cout << "1. pizExpr:" << endl;
    cout << "Expected pizExpr: 5.5 x -" << endl;
    cout << "Actual pizExpr:   " << pizExpr << endl;

    cout << "2. Print table before:" << endl;
    varTable.outputVarTable();
    cout << "3. Enter variables:" << endl;
    varTable.inputVarValues();
    cout << "4. Print table after:" << endl;
    varTable.outputVarTable();

    TPolizCalculate polizCalculate(pizExpr);
    double res = polizCalculate.calculatePizExpr(varTable);

    cout << "5. res = " << res << endl;
    cout << endl;
  }
  {
    TTable<double> varTable(20);
    char expr[200] = "x * x + x";
    cout << "Test 3. Expr = " << expr << endl;
    // 1. x = 2 -> res = 6
    // 2. x = -2 -> res = 2

    TFormPoliz poliz(expr);
    poliz.formPizExpr();
    char* pizExpr = poliz.getPizPoliz();

    cout << "1. pizExpr:" << endl;
    cout << "Expected pizExpr: x x * x +" << endl;
    cout << "Actual pizExpr:   " << pizExpr << endl;

    cout << "2. Print table before:" << endl;
    varTable.outputVarTable();
    cout << "3. Enter variables:" << endl;
    varTable.inputVarValues();
    cout << "4. Print table after:" << endl;
    varTable.outputVarTable();

    TPolizCalculate polizCalculate(pizExpr);
    double res = polizCalculate.calculatePizExpr(varTable);

    cout << "5. res = " << res << endl;
    cout << endl;
  }
  {
    TTable<double> varTable(20);
    char expr[200] = "x / y - z";
    cout << "Test 4. Expr = " << expr << endl;
    // 1. x = 8, y = 4, z = 2 -> res = 0

    TFormPoliz poliz(expr);
    poliz.formPizExpr();
    char* pizExpr = poliz.getPizPoliz();

    cout << "1. pizExpr:" << endl;
    cout << "Expected pizExpr: x y / z -" << endl;
    cout << "Actual pizExpr:   " << pizExpr << endl;

    cout << "2. Print table before:" << endl;
    varTable.outputVarTable();
    cout << "3. Enter variables:" << endl;
    varTable.inputVarValues();
    cout << "4. Print table after:" << endl;
    varTable.outputVarTable();

    TPolizCalculate polizCalculate(pizExpr);
    double res = polizCalculate.calculatePizExpr(varTable);

    cout << "5. res = " << res << endl;
    cout << endl;
  }
  {
    TTable<double> varTable(20);
    char expr[200] = "alpha + beta";
    cout << "Test 5. Expr = " << expr << endl;
    // 1. alpha = 1, beta = -1 -> res = 0

    TFormPoliz poliz(expr);
    poliz.formPizExpr();
    char* pizExpr = poliz.getPizPoliz();

    cout << "1. pizExpr:" << endl;
    cout << "Expected pizExpr: alpha beta +" << endl;
    cout << "Actual pizExpr:   " << pizExpr << endl;

    cout << "2. Print table before:" << endl;
    varTable.outputVarTable();
    cout << "3. Enter variables:" << endl;
    varTable.inputVarValues();
    cout << "4. Print table after:" << endl;
    varTable.outputVarTable();

    TPolizCalculate polizCalculate(pizExpr);
    double res = polizCalculate.calculatePizExpr(varTable);

    cout << "5. res = " << res << endl;
    cout << endl;
  }
}
//что бы вызывалс€ без создани€ экземпл€ра класса
#else
#endif