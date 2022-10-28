#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

bool check_brackets_balance(std::string in, char open_br, char close_br)
{
    std::stack<char> br_stack;

    for (char ch : in)
    {
        if (ch == open_br)
        {
            br_stack.push(ch);
        }
        else if (ch == close_br)
        {
            if (br_stack.size() > 0 && br_stack.top() == open_br)
                br_stack.pop();
            else
                br_stack.push(ch);
        }
        else
        {
            continue;
        }
    }

    return (br_stack.size() == 0);
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

    bool ok = check_brackets_balance(file_content, '(', ')') && 
              check_brackets_balance(file_content, '{', '}') &&
              check_brackets_balance(file_content, '[', ']');
    std::cout << ((ok) ? "OK" : "NOT OK") << std::endl;
    return 0;
}