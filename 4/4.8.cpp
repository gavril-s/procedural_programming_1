#include <iostream>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<double>> matrix;
    int n_rows, n_columns;

public:
    Matrix() : n_rows{0}, n_columns{0} {}

    Matrix operator*(Matrix other);
    friend std::istream& operator>>(std::istream& is, Matrix A);
    friend std::ostream& operator<<(std::ostream& os, Matrix A);
};

int main()
{
    Matrix A;
    std::cin >> A;
    std::cout << A;
    return 0;
}

Matrix Matrix::operator*(Matrix other)
{
    return Matrix();
}

std::istream& operator>>(std::istream& is, Matrix A)
{
    char c;
    double temp;
    A.matrix.push_back(std::vector<double>());
    while (is.get(c))
    {
        if (c == '\n')
        {
            A.matrix.push_back(std::vector<double>());
        }
        else
        {
            is.putback(c);
            is >> temp;
            A.matrix[A.matrix.size() - 1].push_back(temp);
        }
    }
}

std::ostream& operator<<(std::ostream& os, Matrix A)
{
    for (auto i : A.matrix)
    {
        for (double j : i)
        {
            os << j << ' ';
        }
        os << '\n';
    }

    return os;
}