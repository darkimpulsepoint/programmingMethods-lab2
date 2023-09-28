#include <iostream>
#include <string>
#include <clocale>
#include <cmath>
/*
  !!! Вариант 5 задачи: 14 !!!
*/


using namespace std;

void printMsgIncorrectInput() {
    const string incorrectInputMsg = "Incorrect input!";
    cout << incorrectInputMsg << endl;
}

void task1() {
    double sum;
    int term;

    cout << "Enter deposit value: " << endl;
    cin >> sum;

    cout << "Enter term (in months): " << endl;
    cin >> term;

    if (sum < 0 || term < 0) {
        printMsgIncorrectInput();
        return;
    }

    double profit;

    if (sum < 5000) {
        profit = sum * 0.1 * term / 12;
    }
    else {
        profit = sum * 0.13 * term / 12;
    }

    cout << "Income: " << floor(profit) << " rub. " << round((profit - static_cast<int>(profit)) * 100) << " kop." << endl;
}


void task2() {
    int blackPaperAmount, colorPaperAmount;
    double blackPaperCost, colorPaperCost;

    cout << "Number of lists of black-white paper:" << endl;
    cin >> blackPaperAmount;

    cout << "Cost of one list of white-black paper:" << endl;
    cin >> blackPaperCost;

    cout << "Number of lists of color paper:" << endl;
    cin >> colorPaperAmount;

    cout << "Cost of one list of color paper:" << endl;
    cin >> colorPaperCost;

    if (blackPaperAmount < 0 || blackPaperCost < 0 || colorPaperAmount < 0 || colorPaperCost < 0) {
        printMsgIncorrectInput();
        return;
    }

    double cost = blackPaperAmount * blackPaperCost + colorPaperAmount * colorPaperCost;

    if (blackPaperAmount > 50 || colorPaperAmount > 25)
        cost *= 0.95;

    cout << "All cost: " << floor(cost) << " rub. " << ceil((cost - static_cast<int>(cost)) * 100) << " kop." << endl;
}


void task3() {

    double a, b, c;

    cout << "Quadratic equation is ax^2 + bx + c = 0" << endl;

    cout << "Enter a, b and c" << endl;
    cin >> a >> b >> c;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        cout << "No solutions!" << endl;
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << "Solution is: " << x << endl;
    }
    else {
        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);

        cout << "Solutions: " << x1 << " and " << x2 << endl;
    }
}


void task4() {
    cout << "Cost of product: " << endl;
    double price;
    cin >> price;

    if (price < 0) {
        printMsgIncorrectInput();
        return;
    }

    double cahbackPersent = 0;

    if (price > 2000) {
        cahbackPersent = 0.2;
    }
    else if (price > 1000) {
        cahbackPersent = 0.15;
    }

    double cashbackSum = price * cahbackPersent;

    cout << "Cashback: " << floor(cashbackSum) << " rub. " << round((cashbackSum - static_cast<int>(cashbackSum)) * 100) << " kop." << endl;
}



/*
  !!! Вариант 5 задачи: 14 !!!
*/

void task5() {
    double x;
    cout << "Enter x:" << endl;
    cin >> x;

    int parametrChoice;
    double a, b, z;
    bool isParametrChoiceMade = false;

    while (!isParametrChoiceMade) {
        cout << "Choose parametr:\n1 - a=0.5, b=4.5, z=e^(ax)\n2 - a=0.5, b=3.7, z=e^(2ax)\n3 - a=0.5, b=2.7, z=e^(2.5ax)" << endl;
        cin >> parametrChoice;

        switch (parametrChoice) {
        case 1:
            a = 0.5;
            b = 4.5;
            z = exp(a * x);
            isParametrChoiceMade = true;
            break;

        case 2:
            a = 0.5;
            b = 3.7;
            z = exp(2 * a * x);
            isParametrChoiceMade = true;
            break;

        case 3:
            a = 0.5;
            b = 2.7;
            z = exp(2.5 * a * x);
            isParametrChoiceMade = true;
            break;

        default:
            cout << "Incorrect number of parametr!" << endl;
        }
    }
    long double function;

    if (x <= 5 * a) {
        cout << "Function value is: " << 2.5 * b * b + a * x - 4.5 * cos(x * z) << endl;
    }
    else if (x > b) {
        if (a < x * x * x * z) {
            cout << "Can't solve sqrt from negative number!" << endl;
        }
        else {
            cout << "Function value is: " << sqrt(6.5 * b * b + (a - x * x * x * z)) << endl;
        }
    }
    else {
        if (x * z <= 0) {
            cout << "Cant solve log(p) if p <= 0" << endl;
        }
        else {
            cout << "Function value is: " << pow(a * a - 5.4 * x, 3) + log(x * z) << endl;
        }
    }
}


int main() {

    int taskNumber;

    void (*tasks[])() = { task1, task2, task3, task4, task5 };

    while (true) {
        system("cls");


        cout << "Enter task number (1-5)" << endl;
        cout << "1 - task about money deposit\n2 - task about cost of printing\n3 - solve quadratic equation\n4 - task about cashback\n5 - calculate the value of a function\n\n0 - exit" << endl;
        cin >> taskNumber;

        if (taskNumber == 0) {
            exit(0);
        }
        else if (taskNumber > 0 && taskNumber < 6) {
            tasks[taskNumber - 1]();
        }
        else {
            printMsgIncorrectInput();
        }
        system("pause");
    }


}
