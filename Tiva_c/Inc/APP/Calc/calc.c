#include "Inc/LIB/BIT_MATH.h"
#include "Inc/LIB/STD_TYPES.h"
#include "Inc/LIB/DELAY.h"
#include <string.h>
#include <ctype.h>  // Include this header for isdigit() function

int flag = 0 ;
// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
// Function to get precedence of operators
int getPrecedence(char operator)
{
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0; // For '('
}

// Function to perform arithmetic operations
float performOperation(float operand1, float operand2, char operator)
{
    switch (operator)
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default:  return 0; // Invalid operator
    }
}

// Function to evaluate infix expression
float evaluateInfixExpression(char expression[])
{
    float operandStack[20]; // Array to store operands
    char operatorStack[20]; // Array to store operators
    int operandTop = -1;
    int operatorTop = -1;
    int i = 0 ;
    // check expression

    if (isOperator(expression[0]) || isOperator(expression[strlen (expression) - 1]))
    {
        flag = 1 ;
    }
    else
    {
        for (i = 0; expression[i] != '\0'; i++)
        {
            if (isOperator(expression[i]) && isOperator(expression[i+1]))
            {
                flag = 1 ;
                break ;
            }
            if (isdigit(expression[i]) && expression[i+1] == '/' && expression[i+2] == '0')
            {
                flag = 2 ;
                break ;
            }
        }
    }
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            float operand = 0.0;
            while (isdigit(expression[i]))
            {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Move back one step after the loop
            ++operandTop ;
            operandStack[operandTop] = operand;
        }
        else if (isOperator(expression[i]))
        {
            while (operatorTop != -1 &&
                   getPrecedence(expression[i]) <= getPrecedence(operatorStack[operatorTop]))
            {
                float operand2 = operandStack[operandTop--];
                float operand1 = operandStack[operandTop--];
                char operator = operatorStack[operatorTop--];
                float result = performOperation(operand1, operand2, operator);
                operandStack[++operandTop] = result;
            }
            operatorStack[++operatorTop] = expression[i];
        }
    }

    while (operatorTop != -1)
    {
        float operand2 = operandStack[operandTop--];
        float operand1 = operandStack[operandTop--];
        char operator = operatorStack[operatorTop--];
        float result = performOperation(operand1, operand2, operator);
        operandStack[++operandTop] = result;
    }

    return operandStack[operandTop];
}



