#include <iostream>
#include <fstream>
#include <string>

const std::string VOWELS = "aeiou";
const std::string FORBIDDEN_STRINGS[] = {
    "ab", "cd", "pq", "xy"
};

bool is_nice_a(const std::string& str)
{
    if (str.size() < 3) 
    {
        return false;
    }
    
    size_t num_vowels = 0;
    bool contains_double = false;
    char letter1 = ' ';
    char letter2 = ' ';
    for (const auto& c : str)
    {
        for (const auto& vowel : VOWELS)
        {
            if (c == vowel)
            {
                num_vowels++;
            }
        }

        letter1 = letter2;
        letter2 = c;
        if (letter1 == letter2)
        {
            contains_double = true;
        }

        std::string joined = "";
        joined += letter1;
        joined += letter2;
        for (const auto& forbidden_string : FORBIDDEN_STRINGS)
        {
            if (joined == forbidden_string)
            {
                return false;
            }
        }
    }

    const int minimum_vowels = 3;
    return num_vowels >= minimum_vowels && contains_double;
}

void part_a(const std::string& input_file)
{
    std::ifstream input(input_file);
    if (!input)
    {
        std::cerr << "Could not load " << input_file << "\n";
        return;
    }
    std::string str;
    size_t nice_strings = 0;

    while (std::getline(input, str))
    {
        if (is_nice_a(str))
        {
            nice_strings++;
        }
    }

    std::cout << "Number of nice strings: " << nice_strings << "\n";
}

bool is_nice_b(const std::string& str)
{
    if (str.length() < 3)
    {
        return false;
    }

    size_t current_index = 0;
    bool contains_double = false;
    while (current_index < str.length() - 3 && !contains_double)
    {
        std::string substr = str.substr(current_index, 2);
        for (size_t i = current_index + 2; i < str.length() - 1; i++)
        {
            std::string other_substr = str.substr(i, 2);
            if (substr == other_substr)
            {
                contains_double = true;
                break;
            }
        }

        current_index++;
    }
    if (!contains_double)
    {
        return false;
    }
    
    bool contains_symmetric_split = false;
    for (size_t i = 0; i < str.length() - 2; i++)
    {
        if (str[i] == str[i + 2])
        {
            contains_symmetric_split = true;
            break;
        }
    }
    if (!contains_symmetric_split)
    {
        return false;
    }

    return true;
}

void part_b(const std::string& input_file)
{
    std::ifstream input(input_file);
    if (!input)
    {
        std::cerr << "Could not load " << input_file << "\n";
        return;
    }
    std::string str;
    size_t nice_strings = 0;

    while (std::getline(input, str))
    {
        if (is_nice_b(str))
        {
            nice_strings++;
        }
    }

    std::cout << "Number of nice strings: " << nice_strings << "\n";
}

int main()
{
    part_a("inputs/d5.txt");
    part_b("inputs/d5.txt");

    return 0;
}
