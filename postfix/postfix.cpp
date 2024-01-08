/*
 This is the main code for the evaluation of the postfix expression
 Operands in postfix expression shou;d be integers and 
 there must be space between two operands.
 Only '+'  ,  '-'  , '*' and '/' these four operators are expected.
 */

#include "postfix.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

Postfix::Postfix() 
{

}

// This function initialize the postfix expression in console using a while loop
void Postfix::init()
{
    while (true)
    {
        string expression;
        cout<<"Enter Postfix Array: \n";
        getline(cin, expression);
        int result = EvaluatePostfix(expression);
        cout<< "The output of the postfix expression is " << result << "\n";
    }
    
}

// This function examines whether the number in expression is numeric number from 0 to 9
bool Postfix::IsNumericNumber(char C)
{
    if(C >= '0' && C <= '9') 
    {
        return true;
    }
    else return false;
}


// This function examines whether the operator input in postfix expression is valid for peration 
bool Postfix::IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
    {
        return true;
    }

    else return false;
}

// This function perform numerical operation between operand 1 and operand 2
int Postfix::ExecuteOperation(char operation, int operand1, int operand2)
{
    // If the operator is "+", execute addition
    if(operation == '+') 
    {
        return operand1 + operand2;
    }
    // If the operator is "-", execute subtraction
    else if(operation == '-') 
    {
        return operand1 - operand2;
    }
    // If the operator is "*", execute multiplication
    else if(operation == '*') 
    {
        return operand1 * operand2;
    }
    // If the operator is "/", execute division
    else if(operation == '/') 
    {
        return operand1 / operand2;
    }

    else cout<<"Error of operational execution \n";
    return -1;
}

// This function evaluate the postfix expression
int Postfix::EvaluatePostfix(string expression)
{
    // Declare a stack to store the values of postfix expression.
    stack<int> Stack;

    // Look over the expression, if the character is a space, continue.
    for(int i = 0; i< expression.length(); ++i) 
    {
        if(expression[i] == ' ') continue;

    // If the character currently look up is operator, pop two elements from stack and perform operation.
        else if(IsOperator(expression[i])) 
        {
            int operand2 = Stack.top(); 
            Stack.pop();
            int operand1 = Stack.top(); 
            Stack.pop();
            // Execute operation
            int result = ExecuteOperation(expression[i], operand1, operand2);
            //Push the result (the value after operation) back to stack.
            Stack.push(result);
        }

        // If the character currently look up is an operand, keep scan through the expression till the end.
        else if(IsNumericNumber(expression[i])) 
        {
            int operand = 0;
            while(i < expression.length() && IsNumericNumber(expression[i])) 
            {
                // if the numeric number in expression has more than 1 digit (eg. 11, 345, 5323), process following convention
                operand = (operand * 10) + (expression[i] - '0');				             
                ++i;   
            }

            --i;

            // Push operand on stack.
            Stack.push(operand);
        }
    }

    return Stack.top();
}

