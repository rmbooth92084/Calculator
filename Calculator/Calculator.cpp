// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "headers.h"
#include <vector>

using namespace std;
void numberInputMenu(Base*);
/*
* This function puts all the information the user inputed to solve and display
* the problem
*/
void solve(char op, Base* first, Base* second) {
    

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
    cout << result->stringify() << " = " << result->evaluate() << endl
        << "If you want to add to the problem input y" << endl;
    char input;
    cin >> input;
    if (input == 'y' || input == 'Y') {
        numberInputMenu(result);
    }
    else
        exit(0);

}
/*
* This funciton promps the user to input the operation they want to use
* and varifies that it's a valid input and then calls numberInputMenu
* to deal with the user input numbers
*/
void operationMenu(Base* first, Base* second) {
    
    cout << "Please input what opperation of what you want to do:" << endl
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

    solve(input,first,second);
    
}
/*
* This fucntion is like the other one named similarly but takes in
* a Base object so you can make a problem as long as you want
*/
void numberInputMenu(Base* firstPart) {

    double  secondInput;

    cout << "Please input the next number" << endl;
    cin >> secondInput;
    Op* secondNum = new Op(secondInput);

    operationMenu(firstPart, secondNum);
}
/*
* This prompts the user to input the 2 numbers to but used to make the problem
* but this currently doesn't take care of if the user inputs an invalid
*/
void numberInputMenu() {

    double firstInput, secondInput;

    cout << "Please enter the first number" << endl;
    cin >> firstInput;
    Op* firstNum = new Op(firstInput);

    cout << "Now please enter the second number" << endl;
    cin >> secondInput;
    Op* secondNum = new Op(secondInput);

    operationMenu(firstNum, secondNum);
}
void sortingUI() {
    getUserListInput();
    selectSort();
    cout << "Sorted List: " << endl;
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.at(i) << " ";
    }
    cout << endl;
}
int main(){
   // numberInputMenu();

    cout << "Please input 1 for calculator and 2 for sorting a list" << endl;

    char input;
    cin >> input;

    if (input == '1')
        numberInputMenu();
    else
        sortingUI;
    
    return 0;
}

