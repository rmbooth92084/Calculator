// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "headers.h"
#include <vector>

using namespace std;
void numberInputMenu(Base*);
void operationMenu(Base*);
/*
* This function puts all the information the user inputed to solve and display
* the problem
*/
void solve(char op, Base* first, Base* second) {
    Base* result;
    //This if else checks if it's a one input problem or two
    if (second == nullptr) {
        switch (op){
            case 'q':
            case 'Q':
                result = new SquRoot(first);
                break;
            case 's':
            case 'S':
                result = new Sin(first);
                break;
            case 'c':
            case 'C':
                result = new Cos(first);
                break;
            case 't':
            case 'T':
                result = new Tan(first);
                break;
            case '2':
                result = new TwoPow(first);
                break;
            default:
                cout << "Should not have gotten here" << endl;
                result = nullptr;
                break;
        }
    }
    else {
        switch (op) {
        case '+':
            result = new Add(first, second);
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
        case 'v':
        case 'V':
            result = new VarRoot(first, second);
            break;
        default:
            cout << "Should not have gotten here" << endl;
            result = nullptr;
            break;
        }
    }
    cout << result->stringify() << " = " << result->evaluate() << endl
        << "If you want to add to the problem input y" << endl;
    char input;
    cin >> input;
    if (input == 'y' || input == 'Y') {
        operationMenu(result);
    }
    else
        exit(0);

}
/*
* This fucntion is like the other one named similarly but takes in
* a Base object so you can make a problem as long as you want
*/
void numberInputMenu(char operation, Base* firstPart) {

    double firstInput;
    Op* secondNum;

    switch (operation) {
        case 'q':
        case 's':
        case 'c':
        case 't':
        case 'Q':
        case 'S':
        case 'C':
        case 'T':
        case '2':
            solve(operation, firstPart, nullptr);
            break;
        default:
            cout << "Please input a number" << endl;
            cin >> firstInput;
            secondNum = new Op(firstInput);
            //place holder for the third paramiter to be able to reuse solve function
            solve(operation, firstPart, secondNum);
            break;
            break;
    }

}
/*
* This prompts the user to input the 2 numbers to but used to make the problem
* but this currently doesn't take care of if the user inputs an invalid
*/
void numberInputMenu(char operation) {
    double firstInput, secondInput;
    Op* firstNum;
    switch (operation) {
        case 'q':
        case 's':
        case 'c':
        case 't':
        case 'Q':
        case 'S':
        case 'C':
        case 'T':
        case '2':
            cout << "Please input a number" << endl;
            cin >> firstInput;
            firstNum = new Op(firstInput);
            solve(operation, firstNum, nullptr); 
            break;
        default:
            cout << "Please enter the first number" << endl;
            cin >> firstInput;
            Op* firstNum1 = new Op(firstInput);

            cout << "Now please enter the second number" << endl;
            cin >> secondInput;
            Op* secondNum = new Op(secondInput);

            solve(operation, firstNum1, secondNum);
            break;
    }

}
/*
* Just like funciton with similar name but is able to take in a Base type of object
* to be able to make an operation of variable length
*/
void operationMenu(Base* firstPart) {

    cout << "Please input what opperation of what you want to do:" << endl
        << "(+,-,*,/, ^,q - square Root, s - sin, c - cos, t - tan, 2 - 2^(), v - varRoot)" << endl;
    char input;
    while (1) {
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
        case 'e':
        case '!':
        case '%':
        case 'q':
        case 's':
        case 'S':
        case 'c':
        case 'C':
        case 't':
        case 'T':
        case '2':
        case 'v':
        case 'V':
            valid = true;
            break;
        default:
            valid = false;

        }
        if (valid)
            break;
    }

    numberInputMenu(input, firstPart);

}
/*
* This funciton promps the user to input the operation they want to use
* and varifies that it's a valid input and then calls numberInputMenu
* to deal with the user input numbers
*/
void operationMenu() {
    
    cout << "Please input what opperation of what you want to do:" << endl
        << "(+,-,*,/, ^,q - square Root, s - sin, c - cos, t - tan, 2 - 2^(), v - varRoot)" << endl;
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
            case 'e':
            case '!':
            case '%':
            case 'q':
            case 's':
            case 'S':
            case 'c':
            case 'C':
            case 't':
            case 'T':
            case '2':
            case 'v':
            case 'V':
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


/*
* This deals with getting the sorting methods called properly that were from a 
* previous project and outputs the sorted list
*/
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

    cout << "Please input 1 for calculator and 2 for sorting a list" << endl;

    char input;
    cin >> input;
    while (true)
    {
        if (input == '1') {
            operationMenu();
            break;
        }
        else if (input == '2') {
            sortingUI;
            break;
        }

        else {
            cout << "Invalid input, please try again." << endl;
            cin >> input;
        }

    }
    
    return 0;
}

