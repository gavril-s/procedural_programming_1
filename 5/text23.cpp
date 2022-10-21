#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int index(char ch, const std::string& s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ch)
            return i;
    }
    return -1;
}

std::pair<char, int> get_top_consonant(const std::string& in)
{
    std::string consonants = "qwrtpsdfghjklzxcvbnm";
    std::vector<int> cons_count(consonants.length(), 0);

    int max = 0;
    char max_ch = ' ';
    for (char ch : in)
    {
        int ch_ind = index(ch, consonants);
        if (ch_ind == -1)
            continue;
        int new_val = ++cons_count[ch_ind];
        if (new_val > max)
        {
            max = new_val;
            max_ch = ch;
        }
    }
    return std::make_pair(max_ch, max);
}

int main()
{
    const std::string DEFAULT_FILE_NAME = "text.txt";
    std::string file_name;
    char tmp = ' ';
    
    std::cout << "Введите имя файла для анализа: ";
    std::cin.get(tmp);
    if (tmp == '\n')
        file_name = DEFAULT_FILE_NAME;
    else
    {
        std::cin.putback(tmp);
        std::cin >> file_name;
    }

    std::ifstream ifs(file_name);
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string file_content = buffer.str();
    ifs.close();

    std::pair<char, int> result = get_top_consonant(file_content);
    std::cout << result.first << ' ' << result.second << std::endl;

    return 0; 
}