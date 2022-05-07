#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "mystack.h"

/*
 * Check if the input line is as prefix or postfix,
 * Calculate the operation based on being prefix or postfix
 */
class Calculator {

private:

    // Store the line which passed by Evaluator
    string str;

    // Store numbers
    Stack stack;

    /*
     * Check if every character of str is digit or not (from end of string to begin),
     * If it is digit convert it to integer and push it into stack,
     * And if it isn't digit based on it calculate the operation and get two operand
     * from top of stack
     */
    void prefix();

    /*
     * Check if every character of str is digit or not,
     * If it is digit convert it to integer and push it into stack,
     * And if it isn't digit based on it calculate the operation and get two operand
     * from top of stack
     */
    void postfix();

    /*
     * Determines that the given line is based on prefix or postfix
     */
    void calculate();

public:

    /*
     * Constructor,
     * With input parameter (the operation line)
     */
    explicit Calculator(string &);

    /*
     * Get result of calculating,
     * Return the top of stack that result is stored in it
     */
    int getResult();

};

Calculator::Calculator(string &s) :
        str(s) {

}

void Calculator::calculate() {

    if (isdigit(str.at(0)) || str.at(0) == '#') postfix();
    else prefix();
}

void Calculator::prefix() {

    // check if is there a number after this character
    bool nextNumber = true;

    for (int i = str.size() - 1; i >= 0; i--) {

        char c = str[i];
        int num1;
        int num2;

        if (!isdigit(c)) {

            switch (c) {

                case '-' :
                    num1 = stack.pop();
                    num2 = stack.pop();
                    stack.push(num2 - num1);
                    break;
                case '+':
                    stack.push(stack.pop() + stack.pop());
                    break;
                case '*':
                    stack.push(stack.pop() * stack.pop());
                    break;
                case '/':
                    num1 = stack.pop();
                    num2 = stack.pop();
                    stack.push(num2 / num1);
                    break;
                case '%':
                    num1 = stack.pop();
                    num2 = stack.pop();
                    stack.push(num2 % num1);
                    break;
                case '#':
                    stack.push(stack.pop() * -1);
                    break;
                case ' ':
                    nextNumber = true;
                    break;

                default:
                    continue;
            }


        } else {
            if (nextNumber) {

                stack.push((int) (c) - 48);
                nextNumber = false;

            } else {
                stack.push(stack.pop() + ((int) c - 48) * 10);
            }
        }


    }

}

void Calculator::postfix() {

    bool isNegative = false;

    // check if is there a number after this character
    bool nextNumber = true;

    for (char c : str) {

        int num1;
        int num2;

        if (!isdigit(c)) {

            switch (c) {

                case '-' :
                    num1 = stack.pop();
                    num2 = stack.pop();
                    stack.push(num2 - num1);
                    break;
                case '+':
                    stack.push(stack.pop() + stack.pop());
                    break;
                case '*':
                    stack.push(stack.pop() * stack.pop());
                    break;
                case '/':
                    num1 = stack.pop();
                    num2 = stack.pop();
                    stack.push(num2 / num1);
                    break;
                case '%':
                    num1 = stack.pop();
                    num2 = stack.pop();
                    stack.push(num2 % num1);
                    break;
                case '#':
                    isNegative = true;
                    break;
                case ' ':
                    nextNumber = true;
                    break;

                default:
                    continue;
            }


        } else {
            if (nextNumber) {
                if (isNegative) {
                    stack.push(((int) (c) - 48) * -1);
                    isNegative = false;
                } else {
                    stack.push((int) (c) - 48);
                }

                nextNumber = false;
            } else {
                stack.push(stack.pop() * 10 + (int) c - 48);
            }
        }


    }
}

int Calculator::getResult() {
    calculate();
    return stack.pop();
}

#endif
