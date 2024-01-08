#pragma once
#include<iostream>
#include<string>
using namespace std;

class Postfix
{
    public:
        Postfix();
        void init();

    private:
        bool IsNumericNumber(char C);
        bool IsOperator(char C);
        int ExecuteOperation(char operation, int operand1, int operand2);
        int EvaluatePostfix(string expression);
};