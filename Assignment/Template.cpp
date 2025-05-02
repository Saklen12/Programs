#include <iostream>
using namespace std;

// Template Function to find the maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template Class for Calculator
template <typename T>
class Calculator {
private:
    T num1, num2;

public:
    // Constructor
    Calculator(T a, T b) {
        num1 = a;
        num2 = b;
    }

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }

    T multiply() {
        return num1 * num2;
    }

    T divide() {
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

// Driver code to demonstrate
int main() {
    // Using template function
    cout << "Max of 5 and 10 is: " << findMax(5, 10) << endl;
    cout << "Max of 3.5 and 2.8 is: " << findMax(3.5, 2.8) << endl;

    // Integer Calculator
    Calculator<int> intCalc(5, 10);
    cout << "\nInteger Operations:\n";
    cout << "5 + 10 = " << intCalc.add() << endl;
    cout << "5 - 10 = " << intCalc.subtract() << endl;
    cout << "5 * 10 = " << intCalc.multiply() << endl;
    cout << "5 / 10 = " << intCalc.divide() << endl;

    // Float Calculator
    Calculator<float> floatCalc(3.5f, 2.0f);
    cout << "\nFloat Operations:\n";
    cout << "3.5 + 2.0 = " << floatCalc.add() << endl;
    cout << "3.5 - 2.0 = " << floatCalc.subtract() << endl;
    cout << "3.5 * 2.0 = " << floatCalc.multiply() << endl;
    cout << "3.5 / 2.0 = " << floatCalc.divide() << endl;

    // Double Calculator
    Calculator<double> doubleCalc(4.8, 1.2);
    cout << "\nDouble Operations:\n";
    cout << "4.8 + 1.2 = " << doubleCalc.add() << endl;
    cout << "4.8 - 1.2 = " << doubleCalc.subtract() << endl;
    cout << "4.8 * 1.2 = " << doubleCalc.multiply() << endl;
    cout << "4.8 / 1.2 = " << doubleCalc.divide() << endl;

    return 0;
}
