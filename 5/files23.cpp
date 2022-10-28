#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct team
{
    static const int GOLD_COST = 7;
    static const int SILVER_COST = 6;
    static const int BRONZE_COST = 5;

    std::string name;
    int gold = 0;
    int silver = 0;
    int bronze = 0; 
    int all_medals = 0;
    int score = 0;

    inline void calc_all()
    {
        all_medals = gold + silver + bronze;
    }

    inline void calc_score()
    {
        score = gold * GOLD_COST + 
                silver * SILVER_COST + 
                bronze * BRONZE_COST;
    }

    void write_to_csv(std::ofstream& of)
    {
        char delim = ';';
        of << name << delim;
        of << gold << delim;
        of << silver << delim;
        of << bronze << delim;
        of << all_medals << delim;
        of << score << delim;
    }

    friend std::ostream& operator<<(std::ostream& os, team& t)
    {
        os << t.name << " -> ";
        os << t.gold   << ", ";
        os << t.silver << ", ";
        os << t.bronze << ", ";
        os << t.all_medals << ", ";
        os << t.score;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, team& t)
    {
        t = team();
        is >> t.name >> t.gold >> t.silver >> t.bronze;
        if (t.gold < 0 || t.silver < 0 || t.bronze < 0)
        {
            std::cin.setstate(std::ios_base::failbit);
            t = team();
        }
        else
        {
            t.calc_all();
            t.calc_score();
        }

        return is;
    }
};

bool get_teams(std::vector<team>& teams, 
               std::string msg, std::string err)
{
    teams.clear();
    std::cout << msg << std::endl;

    char ch = ' ', prev_ch = ' ';
    team tmp_team;
    while (std::cin.get(ch))
    {
        if (ch == '\n')
        {
            if (prev_ch == '\n')
                return true;
            prev_ch = ch;
            continue;
        }
        prev_ch = ch;
        std::cin.putback(ch);

        if (std::cin >> tmp_team)
            teams.push_back(tmp_team);
        else
        {
            std::cout << err << std::endl;
            return false;
        }
    }

    return true;
}

void write_teams_to_file(std::vector<team>& teams, std::string file_name)
{
    std::ofstream out(file_name);
    out << "; Country ; Gold ; Silver ; Bronze ; Total ; Score\n";
    for (int i = 0; i < teams.size(); ++i)
    {
        out << (i + 1) << ';';
        teams[i].write_to_csv(out);
        out << '\n';
    }
}

void write_teams_to_console(std::vector<team>& teams, std::ostream& os)
{
    os << "Формат: (Страна) -> (Золото, Серебро, Бронза, Всего, Очков)" << std::endl;
    for (int i = 0; i < teams.size(); ++i)
    {
        os << (i + 1) << ") ";
        os << teams[i];
        os << std::endl;
    }
}

int cmp(const team& t1, const team& t2)
{
    return (t1.gold + t1.silver) > (t2.gold + t2.silver);
}

int main()
{
    std::string file_name = "result.csv";

    std::vector<team> teams;
    if (get_teams(teams, "Введите список команд и их медалей", 
              "Некорректный ввод!"))
    {
        std::sort(teams.begin(), teams.end(), cmp);
        write_teams_to_file(teams, file_name);
        write_teams_to_console(teams, std::cout);
        std::cout << "Реузльтаты также доступны в файле " 
                << file_name << std::endl;
    }
    
    return 0;
}