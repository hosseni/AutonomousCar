
#ifndef APP_CALC_H_
#define APP_CALC_H_

// Function to check if a character is an operator
int isOperator(char ch) ;

// Function to get precedence of operators
int getPrecedence(char operator) ;

// Function to perform arithmetic operations
float performOperation(float operand1, float operand2, char operator) ;

// Function to evaluate infix expression
float evaluateInfixExpression(char expression[]) ;

#endif /* APP_CALC_H_ */
