// Лабораторна робота № 5.2
// Завдання 5.2. Варіант 3: Обчислення суми ряду Тейлора для exp(x^2)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h> // Потрібно для SetConsoleCP та SetConsoleOutputCP

using namespace std;

// Прототипи функцій
double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
    // Встановлення кодування UTF-8 (65001) для консолі Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "Введіть xp: "; cin >> xp;
    cout << "Введіть xk: "; cin >> xk;
    cout << "Введіть dx: "; cin >> dx;
    cout << "Введіть eps: "; cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << "   |"
        << setw(12) << "exp(x^2)" << "   |"
        << setw(12) << "S" << "   |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "---------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + dx / 2.0)
    {
        s = S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(12) << setprecision(5) << exp(x * x) << "   |"
            << setw(12) << setprecision(5) << s << "   |"
            << setw(5) << n << "   |"
            << endl;
        x += dx;
    }
    cout << "---------------------------------------------------------" << endl;

    return 0;
}

// Функція обчислення суми ряду Тейлора
double S(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = 1.0; // Перший доданок a0 = 1
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

// Функція обчислення наступного доданку за рекурентним співвідношенням
double A(const double x, const int n, double a)
{
    double R = (x * x) / n; // Коефіцієнт R = x^2 / n
    a *= R;
    return a;
}