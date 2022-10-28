#include <iostream>
#include <vector>

class Permutation
{
private:
    std::vector<int> current;
public:
    Permutation(int size) :
        current{size, 0}
    {
        for (int i = 0; i < current.size(); ++i)
            current[i] = i + 1;
    }
};

int main()
{
    int balls_amount = 0;
    std::cin >> balls_amount;

    std::vector<int> balls(balls_amount, 0);
    for (int i = 0; i < balls.size(); ++i)
        balls[i] = i + 1;



    return 0;
}