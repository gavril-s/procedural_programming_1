#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream ofs;
    ofs.open("3.3.file.txt");
    ofs << "sadfdghffdf";
    ofs.close();

    std::ifstream ifs;
    ifs.open("3.3.file.txt");
    std::string line;
    while (getline(ifs, line))
        std::cout << line << std::endl;

    return 0;
}
