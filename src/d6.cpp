#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

enum Command
{
    turn_on,
    toggle,
    turn_off
};

typedef struct Instruction 
{
    Command command;
    int32_t x0, y0, x1, y1;
} Instruction;

static const int32_t width = 1000;
static const int32_t height = 1000;
class LightGridA
{
public:
    bool grid[width][height] = {0};

    LightGridA() {}

    void process(const Instruction& instruction)
    {
        int32_t x0 = instruction.x0;
        int32_t y0 = instruction.y0;
        int32_t x1 = instruction.x1;
        int32_t y1 = instruction.y1;
        Command command = instruction.command;

        for (int32_t row = x0; row <= x1; row++)
        {
            for (int32_t col = y0; col <= y1; col++) 
            {
                if (command == turn_on)
                {
                    grid[row][col] = 1;
                }
                else if (command == toggle)
                {
                    grid[row][col] = !grid[row][col];
                }
                else if (command == turn_off)
                {
                    grid[row][col] = 0;
                }
            }
        }
    }

    size_t num_lights_lit() const
    {
        size_t num_lit = 0;
        for (int32_t row = 0; row < width; row++)
        {
            for (int32_t col = 0; col < height; col++) 
            {
                if (grid[row][col])
                {
                    num_lit++;
                }
            }
        }

        return num_lit;
    }
};

class LightGridB
{
public:
    int32_t grid[width][height] = {0};

    LightGridB() {}

    void process(const Instruction& instruction)
    {
        int32_t x0 = instruction.x0;
        int32_t y0 = instruction.y0;
        int32_t x1 = instruction.x1;
        int32_t y1 = instruction.y1;
        Command command = instruction.command;

        for (int32_t row = x0; row <= x1; row++)
        {
            for (int32_t col = y0; col <= y1; col++) 
            {
                if (command == turn_on)
                {
                    grid[row][col] += 1;
                }
                else if (command == toggle)
                {
                    grid[row][col] += 2;
                }
                else if (command == turn_off && grid[row][col] > 0)
                {
                    grid[row][col] -= 1;
                }
            }
        }
    }

    size_t total_brightness() const
    {
        size_t num_lit = 0;
        for (int32_t row = 0; row < width; row++)
        {
            for (int32_t col = 0; col < height; col++) 
            {
                num_lit += grid[row][col];
            }
        }

        return num_lit;
    }
};


Instruction parse_instruction(const std::string& instruction_string)
{
    std::istringstream instruction_stream(instruction_string);
    std::string word;

    Command command;
    int32_t x0, y0, x1, y1;

    instruction_stream >> word;
    if (word == "toggle")
    {
        command = toggle;
    }
    else 
    {
        instruction_stream >> word;
        if (word == "on")
        {
            command = turn_on;
        }
        else if (word == "off")
        {
            command = turn_off;
        }
    }

    instruction_stream >> word;
    size_t comma_location = word.find(',');
    x0 = std::stoi(word.substr(0, comma_location));
    y0 = std::stoi(word.substr(comma_location + 1));

    instruction_stream >> word; // ignore "through"
    instruction_stream >> word;
    comma_location = word.find(',');
    x1 = std::stoi(word.substr(0, comma_location));
    y1 = std::stoi(word.substr(comma_location + 1));

    return Instruction{command, x0, y0, x1, y1};
}

void part_a(const std::string& input_file)
{
    std::ifstream input(input_file);
    if (!input)
    {
        std::cerr << "Could not find " << input_file << "\n";
    }
    std::string instruction_string;
    LightGridA grid;

    while (std::getline(input, instruction_string))
    {
        Instruction instruction = parse_instruction(instruction_string);
        grid.process(instruction);
    }

    std::cout << grid.num_lights_lit() << "\n";
}

void part_b(const std::string& input_file)
{
    std::ifstream input(input_file);
    if (!input)
    {
        std::cerr << "Could not find " << input_file << "\n";
    }
    std::string instruction_string;
    LightGridB grid;

    while (std::getline(input, instruction_string))
    {
        Instruction instruction = parse_instruction(instruction_string);
        grid.process(instruction);
    }

    std::cout << grid.total_brightness() << "\n";
}

int main()
{
    part_a("inputs/d6.txt");
    part_b("inputs/d6.txt");

    return 0;
}
