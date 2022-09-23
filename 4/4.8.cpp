#include <iostream>
#include <vector>
#include <string>
#include <float.h>

class Matrix
{
private:
    std::vector<std::vector<double>> matrix;
    int n_rows, n_columns;

    bool matrix_check();
public:
    Matrix() : n_rows{0}, n_columns{0} {}

    double get(int i, int j);
    void set(int i, int j, double val);

    std::pair<int, int> get_size();

    Matrix operator*(Matrix& other);
    friend std::istream& operator>>(std::istream& is, Matrix& A);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& A);
};

void ask_for_matrix(std::string q, Matrix& A, int row_num=-1, int column_num=-1)
{
    std::cout << q;
    if (row_num != -1 || column_num != -1)
    {
        std::cout << " (матрица должна быть размером  ";
        if (row_num == -1) std::cout << '_';
        else               std::cout << row_num;

        std::cout << " x ";

        if (column_num == -1) std::cout << '_';
        else                  std::cout << column_num;

        std::cout << ')';
    }
    std::cout << std::endl;

    try 
    {
        std::cin >> A;
        std::pair<int, int> A_size = A.get_size();
        if ((row_num != -1 && A_size.first != row_num) || (column_num != -1 && A_size.second != column_num))
        {
            throw std::string{"Не тот размер матрицы"};
        }
    }
    catch (std::string e)
    {
        std::cout << e << std::endl;
        ask_for_matrix(q, A);
    }
}

int main()
{
    Matrix A, B;
    ask_for_matrix("Введите таблицу A", A);
    ask_for_matrix("Введите таблицу B", B, -1, 2);

    try
    {
        Matrix C = A * B;
        std::pair<int, int> C_size = C.get_size();

        double max_income = 0, max_commission = 0;
        int max_income_num = 0, max_commission_num = 0;
        double min_income = DBL_MAX, min_commission = DBL_MAX;
        int min_income_num = 0, min_commission_num = 0;
        double income_sum = 0, commission_sum = 0;

        std::cout << "\t\t\t" << "Прибыль" << '\t' << "Комиссионные" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        for (int i = 1; i <= C_size.first; ++i)
        {
            std::cout << "Продавец №" << i << "\t|\t";
            std::cout << C.get(i, 1) << '\t' << C.get(i, 2) << std::endl;

            income_sum += C.get(i, 1);
            commission_sum += C.get(i, 2);

            if (C.get(i, 1) > max_income)
            {
                max_income = C.get(i, 1);
                max_income_num = i;
            }
            if (C.get(i, 1) < min_income)
            {
                min_income = C.get(i, 1);
                min_income_num = i;
            }
            
            if (C.get(i, 2) > max_commission)
            {
                max_commission = C.get(i, 2);
                max_commission_num = i;
            }
            if (C.get(i, 2) < min_commission)
            {
                min_commission = C.get(i, 2);
                min_commission_num = i;
            }
        }
        std::cout << std::endl;
        std::cout << "Максимальная выручка у продавца №" << max_income_num << "\t:\t" << max_income << std::endl;
        std::cout << "Минимальная выручка у продавца №" << min_income_num << "\t:\t" << min_income << std::endl;
        std::cout << "Максимальные комиссионные у продавца №" << max_commission_num << "\t:\t" << max_commission << std::endl;
        std::cout << "Минимальные комиссионные у продавца №" << min_commission_num << "\t:\t" << min_commission << std::endl;
        std::cout << "Общая прибыль: " << income_sum << std::endl;
        std::cout << "Всего комиссионных: " << commission_sum << std::endl;
        std::cout << "Общая сумма денег, прошедших через продавцов: " << income_sum + commission_sum << std::endl;
    }
    catch (std::string e)
    {
        std::cout << e << std::endl;
    }

    return 0;
}

double Matrix::get(int i, int j)
{
    if (i < 1 || i > n_rows || j < 1 || j > n_columns)
    {
        throw std::string{"Matrix out of range"};
    }

    return matrix[i - 1][j - 1];
}

void Matrix::set(int i, int j, double val)
{
    if (i < 1 || i > n_rows || j < 1 || j <= n_columns)
    {
        throw std::string{"Matrix out of range"};
    }

    matrix[i - 1][j - 1] = val;
}

bool Matrix::matrix_check()
{
    n_rows = 0;
    n_columns = -1;

    for (int i = 0; i < matrix.size(); ++i)
    {
        n_rows++;
        if (n_columns == -1)
        {
            n_columns = matrix[i].size();
        }
        else
        {
            if (n_columns != matrix[i].size())
            {
                n_rows = 0;
                n_columns = 0;
                matrix.clear();
                return false;
            }
        }
    }

    if (n_columns == -1)
        n_columns = 0;
    return true;
}

std::pair<int, int> Matrix::get_size()
{
    return std::make_pair(n_rows, n_columns);
}

Matrix Matrix::operator*(Matrix& other)
{
    std::pair<int, int> lh_size = this->get_size();
    std::pair<int, int> rh_size = other.get_size();

    if (lh_size.second != rh_size.first)
    {
        throw std::string{"Количество столбцов первой матрицы не соответствует количеству строк второй матрицы"};
    }

    Matrix res;
    for (int i = 0; i < lh_size.first; ++i)
    {
        res.matrix.push_back(std::vector<double>());
        for (int j = 0; j < rh_size.second; ++j)
        {
            res.matrix[i].push_back(0);
            for (int k = 0; k < lh_size.second && k < rh_size.first; ++k)
            {
                res.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    res.matrix_check();
    return res;
}

std::istream& operator>>(std::istream& is, Matrix& A)
{
    A.matrix.clear();
    char c, prev_c;
    double temp;
    bool create_new_row = true;

    while (is.get(c))
    {
        if (c == ' ')
        {
            continue;
        }
        else if (c == '\n')
        {
            if (prev_c == '\n')
            {
                break;
            }
            create_new_row = true;
        }
        else
        {
            is.putback(c);
            if (is >> temp)
            {
                if (create_new_row)
                {
                    A.matrix.push_back(std::vector<double>());
                    create_new_row = false;
                }
                A.matrix[A.matrix.size() - 1].push_back(temp);
            }
        }
        prev_c = c;
    }

    if (!A.matrix_check())
    {
        throw std::string{"Некорректная матрица"};
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& A)
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