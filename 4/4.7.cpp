#include <iostream>

class Random
{
private:
    int m, b, c, last_result;

public:
    Random(int _m, int _b, int _c, int _c_0) 
          : m{_m}, b{_b}, c{_c}, last_result{_c_0} {}

    int random()
    {
        last_result = (m * last_result + b) % c;
        return last_result;
    }

    void test(int amount)
    {
        for (int i = 0; i < amount; ++i)
            std::cout << random() << ' ';
    }
};

int main()
{
    Random r1(37, 3, 64, 0);
    Random r2(25173, 13849, 65537, 0);

    std::cout << "r1: "; r1.test(15); std::cout << std::endl;
    std::cout << "r2: "; r2.test(15); std::cout << std::endl;

    return 0;
}