#include <iostream>
#include <fstream>
#include <string>

void part_a(const std::string &input) 
{
    std::ifstream input_a(input);
    std::string line;

    if (!input_a)
    {
        std::cout << "Could not open input_a\n";
        return;
    }

    getline(input_a, line);
    int32_t floor = 0; 

    for (char& instruction : line) 
    {
        if (instruction == '(')
        {
            floor++;
        }
        if (instruction == ')')
        {
            floor--;
        }
    }

    std::cout << "Final floor: " << floor << "\n";
}

void part_b(const std::string &input) 
{
    std::ifstream input_a(input);
    std::string line;

    if (!input_a)
    {
        std::cout << "Could not open input_a\n";
        return;
    }

    getline(input_a, line);
    int32_t floor = 0; 
    size_t instruction_num = 0;

    for (char& instruction : line) 
    {
        if (instruction == '(')
        {
            floor++;
        }
        if (instruction == ')')
        {
            floor--;
        }
        instruction_num++;
        
        if (floor < 0) 
        {
            break;
        }
    }

    std::cout << "Instruction that enters basement: " << instruction_num << "\n";
}

int main() 
{
    part_a("inputs/d1a.txt");
    part_b("inputs/d1a.txt");
    
    std::cout << "Hello world!\n";
    return 0;
}
