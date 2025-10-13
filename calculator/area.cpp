#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

double calculateTriangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void printHelp() {
    cout << "Калькулятор площади. Поддерживаемые операции:\n"
         << "  circle (радиус)\n"
         << "  triangle (стороны a, b, c)\n\n"
         << "Использование:\n"
         << "  ./area_calculator -o <операция> <операнды>\n"
         << "Примеры:\n"
         << "  ./area_calculator -o circle 5\n"
         << "  ./area_calculator -o triangle 3 4 5\n";
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printHelp();
        return 0;
    }
    string operation;
    vector<double> operands;
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-o" || arg == "--operation") {
            if (i + 1 >= argc) {
                cerr << "Ошибка: не указана операция.\n";
                printHelp();
                return 1;
            }
            operation = argv[++i];
        } else {
            try {
                operands.push_back(stod(arg));
            } catch (...) {
                cerr << "Ошибка: некорректный операнд.\n";
                printHelp();
                return 1;
            }
        }
    }
    if (operation.empty()) {
        cerr << "Ошибка: не указана операция.\n";
        printHelp();
        return 1;
    }
    if (operation == "circle") {
        if (operands.size() != 1) {
            cerr << "Ошибка: для операции circle требуется 1 операнд (радиус).\n";
            printHelp();
            return 1;
        }
        double radius = operands[0];
        if (radius <= 0) {
            cerr << "Ошибка: радиус должен быть положительным числом.\n";
            printHelp();
            return 1;
        }
        double area = calculateCircleArea(radius);
        int area_int = (int)(area * 100 + 0.5);
        cout << "Площадь круга с радиусом " << radius << ": " << area_int / 100.0 << endl;
    }
    else if (operation == "triangle") {
        if (operands.size() != 3) {
            cerr << "Ошибка: для операции triangle требуется 3 операнда (стороны a, b, c).\n";
            printHelp();
            return 1;
        }
        double a = operands[0], b = operands[1], c = operands[2];
        if (a <= 0 || b <= 0 || c <= 0) {
            cerr << "Ошибка: длины сторон должны быть положительными числами.\n";
            printHelp();
            return 1;
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            cerr << "Ошибка: треугольник с такими сторонами не существует.\n";
            printHelp();
            return 1;
        }
        double area = calculateTriangleArea(a, b, c);
        int area_int = (int)(area * 100 + 0.5);
        cout << "Площадь треугольника со сторонами " << a << ", " << b << ", " << c << ": " << area_int / 100.0 << endl;
    }
    else {
        cerr << "Ошибка: неизвестная операция.\n";
        printHelp();
        return 1;
    }
    return 0;
}
