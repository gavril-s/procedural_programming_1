#include <iostream>
#include <cmath>

const double PI = 3.1415926535;

double square(double x)
{
    return x * x;
}

struct Point
{
    double x = 0, y = 0;
};

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p)
{
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}

double distance(Point p1, Point p2)
{
    return sqrt(square(p1.x - p2.x) + square(p1.y - p2.y));
}

double rectangle_area(Point p1, Point p2)
{
    return std::abs(p2.x - p1.x) * std::abs(p2.y - p1.y);
}

double triangle_area(Point p1, Point p2, Point p3)
{
    double a = distance(p1, p2), b = distance(p2, p3), c = distance(p3, p1);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double circle_area(double radius)
{
    return PI * square(radius);
}

int main()
{
    int choice = 0;
    Point p1, p2, p3;
    double radius = 0;
    double result = -1;

    std::cout << "Выберите фигуру, площадь которой хотели бы вычислить" << std::endl
              << "1 - прямоугольник" << std::endl
              << "2 - треугольник" << std::endl
              << "3 - круг" << std::endl;
    std::cin >> choice;
    std::cout << std::endl;

    switch (choice)
    {
    case 1:
        std::cout << "Введите координаты левого нижнего и правого верхнего углов прямоугольника: ";
        if(!(std::cin >> p1 >> p2))
        {
            std::cout << "Некорректный ввод" << std::endl;
            return 0;
        }
        result = rectangle_area(p1, p2);
        break;
    case 2:
        std::cout << "Введите координаты вершин треугольника: ";
        if(!(std::cin >> p1 >> p2 >> p3))
        {
            std::cout << "Некорректный ввод" << std::endl;
            return 0;
        }
        result = triangle_area(p1, p2, p3);
        break;
    case 3:
        std::cout << "Введите радиус: ";
        if(!(std::cin >> radius))
        {
            std::cout << "Некорректный ввод" << std::endl;
            return 0;
        }
        result = circle_area(radius);
        break;
    default:
        std::cout << "Что-то ты перепутал" << std::endl;
        break;
    }

    if (result != -1)
        std::cout << "Площадь = " << result << std::endl;
    return 0;
}