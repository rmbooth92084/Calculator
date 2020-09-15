// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "headers.h"

using namespace std;

void solve(char op, double firstNum, double secondNum) {
    
    Op* first = new Op(firstNum);
    Op* second = new Op(secondNum);

    Base* result;
    switch (op){
        case '+':
            result = new Add(first,second);
            break;
        case '-':
            result = new Sub(first, second);
            break;
        case '*':
            result = new Mult(first, second);
            break;
        case '/':
            result = new Div(first, second);
            break;
        case '^':
            result = new Pow(first, second);
            break;
        default:
            cout << "should not have gotten here" << endl;
            result = new Op();
             break;
    }
    cout << result->stringify() << " = " << result->evaluate();
}

void numberInputMenu(char operation) {
    
    double firstInput, secondInput;

    cout << "Now please enter the first number" << endl;
    cin >> firstInput;

    cout << "Now please enter the second number" << endl;
    cin >> secondInput;

    solve(operation, firstInput, secondInput);

}

void operationMenu() {
    
    cout << "please input what opperation of what you want to do:" << endl
        << "(+,-,*,/, ^)" << endl;
    char input;
    while(1){
        input = ' '; //default input
        cin >> input;

        bool valid = false;
        //This switch statment plus the fallowing if statemnet  checks if the input was valid
        switch (input) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                valid = true;
                break;
            default:
                valid = false;

        }
        if (valid)
            break;
    }
    numberInputMenu(input);
    
}

int main(){
    operationMenu();
}

