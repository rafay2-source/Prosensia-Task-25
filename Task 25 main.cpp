#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class CalculatorException {
    string message;
public:
    CalculatorException(const string& msg) : message(msg) {}
    string what() const { return message; }
};

double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw CalculatorException("Division by zero");
            return a / b;
        default:
            throw CalculatorException("Invalid operator");
    }
}

void logError(const string& msg) {
    ofstream log("error_log.txt", ios::app);
    log << msg << "\n";
    log.close();
}

int main() {
    double a, b;
    char op;

    try {
        cout << "Enter first number: ";
        if (!(cin >> a)) throw CalculatorException("Invalid input type for first number");

        cout << "Enter operator (+ - * /): ";
        cin >> op;

        cout << "Enter second number: ";
        if (!(cin >> b)) throw CalculatorException("Invalid input type for second number");

        double result = calculate(a, b, op);
        cout << "Result: " << result << "\n";
    }
    catch (const CalculatorException& e) {
        cout << "Error: " << e.what() << "\n";
        logError(e.what());
    }

    return 0;
}
