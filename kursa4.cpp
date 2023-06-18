#include <iostream>
#include <cmath>

// Базовый класс уравнения
class Equation {
public:
    virtual void solve() = 0; // Виртуальная функция для решения уравнения
};

// Производный класс для квадратного уравнения
class QuadraticEquation : public Equation {
private:
    double a, b, c; // Коэффициенты квадратного уравнения

public:
    QuadraticEquation(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void solve() override {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "Уравнение имеет два различных действительных корня:" << std::endl;
            std::cout << "Корень 1: " << root1 << std::endl;
            std::cout << "Корень 2: " << root2 << std::endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            std::cout << "Уравнение имеет один действительный корень:" << std::endl;
            std::cout << "Корень: " << root << std::endl;
        }
        else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            std::cout << "Уравнение имеет два комплексных корня:" << std::endl;
            std::cout << "Корень 1: " << realPart << " + " << imaginaryPart << "i" << std::endl;
            std::cout << "Корень 2: " << realPart << " - " << imaginaryPart << "i" << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c;

    std::cout << "Введите коэффициенты квадратного уравнения (ax^2 + bx + c = 0):" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;

    // Создание объекта квадратного уравнения и вызов метода solve()
    QuadraticEquation quadraticEquation(a, b, c);
    quadraticEquation.solve();

    return 0;
}
