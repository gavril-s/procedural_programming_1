#include <iostream>
#include <fstream>
#include <string>

int main()
{
    double nums[10] = {10000,1000,100,10,10,1.6,-1.1,1,0,0};
    std::ofstream ofs("4.1.file.txt");
    for (int i = 0; i < 10; ++i)
        ofs << nums[i] << ' ';
    ofs.close();

    std::ifstream ifs("4.1.file.txt");
    double sum = 0, temp = 0;
    while (ifs >> temp)
        sum += temp;
    std::cout << sum << std::endl;
    return 0;
}