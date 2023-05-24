#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

class Location 
{
public:
    int32_t x = 0;
    int32_t y = 0;

    Location() : x(0), y(0) {}
    Location(int32_t x, int32_t y) : x(x), y(y) {}

    std::string as_string() const
    {
        std::string str = "";
        str += std::to_string(x) + ", " + std::to_string(y);
        return str;
    }

    void move(const char direction)
    {
        if (direction == '^')
        {
            y++;
        }
        else if (direction == 'v')
        {
            y--;
        }
        else if (direction == '>')
        {
            x++;
        }
        else if (direction == '<')
        {
            x--;
        }
    }
};

void part_a(const std::string &input_file)
{
    std::ifstream input(input_file);
    if (!input)
    {
        std::cerr << "Failed to load input file\n";
        return;
    }
    std::string moves;
    std::getline(input, moves); // only 1 line
    
    std::unordered_map<std::string, int32_t> houses_visited;

    Location current_location;
    houses_visited[current_location.as_string()]++;

    for (char& move : moves)
    {
        current_location.move(move);
        houses_visited[current_location.as_string()]++;
    }

    std::cout << "Unique houses visited: " << houses_visited.size() << "\n";
}

void part_b(const std::string &input_file)
{
    std::ifstream input(input_file);
    if (!input)
    {
        std::cerr << "Failed to load input file\n";
        return;
    }
    std::string moves;
    std::getline(input, moves); // only 1 line
    
    std::unordered_map<std::string, int32_t> houses_visited;

    Location santa_location;
    houses_visited[santa_location.as_string()]++;
    Location robos_location;
    houses_visited[robos_location.as_string()]++;

    bool is_santas_move = true;
    for (char& move : moves)
    {
        if (is_santas_move)
        {
            santa_location.move(move);
            houses_visited[santa_location.as_string()]++;
        }
        else if (!is_santas_move)
        {
            robos_location.move(move);
            houses_visited[robos_location.as_string()]++;
        }
        is_santas_move = !is_santas_move;
    }
    
    std::cout << "Unique houses visited: " << houses_visited.size() << "\n";
}

int main()
{
    part_a("inputs/d3.txt");
    part_b("inputs/d3.txt");

    return 0;
}
