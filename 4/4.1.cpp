#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int nums[10] = {1, 4, 6, 1, 6, 2, 7, 9, 10, 5};
    std::ofstream ofs("4.1.file.txt");
    for (int i = 0; i < 10; ++i)
        ofs << nums[i] << ' ';
    ofs.close();

    std::ifstream ifs("4.1.file.txt");
    int sum = 0, temp = 0;
    while (ifs >> temp)
        sum += temp;
    std::cout << sum << std::endl;
    return 0;
}