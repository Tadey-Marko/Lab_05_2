#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Опис функції A, яку ми тестуємо
double A(const double x, const int n, double a) {
    double R = (x * x) / n; // Коефіцієнт рекурентності для exp(x^2)
    return a * R;
}

namespace UnitTestLab52
{
    TEST_CLASS(UnitTestLab52)
    {
    public:

        TEST_METHOD(TestMethod_A_Calculation)
        {
            // Початкові дані: x = 2.0, n = 1, попередній доданок a = 1.0
            // Очікуваний результат: R = (2^2)/1 = 4.0; a_new = 1.0 * 4.0 = 4.0
            double x = 2.0;
            int n = 1;
            double a = 1.0;
            double expected = 4.0;

            double actual = A(x, n, a);

            // Перевіряємо з допустимою похибкою 0.00001
            Assert::AreEqual(expected, actual, 0.00001);
        }
    };
}