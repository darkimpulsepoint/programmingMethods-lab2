#include <iostream>
#include <string>
#include <clocale>
#include <cmath>
/*
  !!! Вариант 5 задачи: 14 !!!
*/


using namespace std;

void printMsgIncorrectInput() {
    const string incorrectInputMsg = "Ошибка ввода!";
    cout << incorrectInputMsg << endl;
}

void task1() {
    double sum;
    int term;

    cout << "Введите сумму вклада: " << endl;
    cin >> sum;

    cout << "Введите срок (в месяцах): " << endl;
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

    cout << "Доход: " << floor(profit) << " р. " << round((profit - static_cast<int>(profit))*100) << " коп." << endl;
}


void task2() {
    int blackPaperAmount, colorPaperAmount;
    double blackPaperCost, colorPaperCost;

    cout << "Кол-во листов черной-белой бумаги:" << endl;
    cin >> blackPaperAmount;

    cout << "Стоимость листа черно-белой бумаги" << endl;
    cin >> blackPaperCost;

    cout << "Кол-во листов цветной бумаги:" << endl;
    cin >> colorPaperAmount;

    cout << "Стоимость листа цветной бумаги" << endl;
    cin >> colorPaperCost;

    if (blackPaperAmount < 0 || blackPaperCost < 0 || colorPaperAmount < 0 || colorPaperCost < 0) {
        printMsgIncorrectInput();
        return;
    }

    double cost = blackPaperAmount * blackPaperCost + colorPaperAmount * colorPaperCost;

    if (blackPaperAmount > 50 || colorPaperAmount > 25)
        cost *= 0.95;

    cout << "Стоимость: " << floor(cost) << " р. " << ceil((cost - static_cast<int>(cost)) * 100) << " коп." << endl;
}


void task3() {

    double a, b, c;

    cout << "Квадратное уравнение вида ax^2 + bx + c = 0" << endl;

    cout << "Введите a, b и c" << endl;
    cin >> a >> b >> c;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        cout << "Нет решений!" << endl;
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << "Корень уравнения: " << x << endl;
    }
    else {
        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);

        cout << "Корни: (" << x1 << ", " << x2 << ")" << endl;
    }
}


void task4() {
    cout << "Стоимость товара: " << endl;
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

    cout << "Кэшбек: " << floor(cashbackSum) << " р. " << round((cashbackSum - static_cast<int>(cashbackSum)) * 100) << " коп." << endl;
}



/*
  !!! Вариант 5 задачи: 14 !!!
*/

void task5() {
    double x;
    cout << "Введите x:" << endl;
    cin >> x;

    int parametrChoice;
    double a, b, z;
    bool isParametrChoiceMade = false;

    while (!isParametrChoiceMade) {
        cout << "Выберите параметр:\n1 - a=0.5, b=4.5, z=e^(ax)\n2 - a=0.5, b=3.7, z=e^(2ax)\n3 - a=0.5, b=2.7, z=e^(2.5ax)" << endl;
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
            cout << "Неправильный номер параметра!" << endl;
        }
    }
    double function;

    if (x <= 5 * a) {
        function = 2.5 * b * b + a * x - 4.5 * cos(x * z);
    }
    else if (x > b) {
        function = sqrt(6.5 * b * b + (a - x * x * x * z));
    }
    else {
        function = pow(a * a - 5.4 * x, 3) + log(x * z);
    }
    
    cout << "Значение функции: " << function << endl;
}


int main() {
    setlocale(LC_ALL, "rus");

    int taskNumber;

    while (true) {
        system("cls");

        void (*tasks[])() = {task1, task2, task3, task4, task5};

        cout << "Введите номер задания (1-5)" << endl;
        cout << "1 - задача про доход\n2 - задача про стоимость печати\n3 - решение квадратного уравнения\n4 - задача про кэшбек\n5 - вычислить значение функции\n\n0 - выход" << endl;
        cin >> taskNumber;

        if (taskNumber == 0) {
            exit(0);
        }
        else if (taskNumber > 0 && taskNumber < 6) {
            tasks[taskNumber - 1]();
        }
        else {
            cout << "Некорректный ввод!" << endl;
        }
        system("pause");
    }


}
