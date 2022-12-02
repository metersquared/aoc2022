#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#include <cassert>

int max_calories(std::string input)
{
    std::ifstream file(input);
    std::string line;
    int sum = 0;
    int max = 0;

    while (getline(file, line))
    {
        if (line.length() == 0)
        {
            if (sum > max)
            {
                max = sum;
            }
            sum = 0;
        }
        else
            sum += stoi(line);
    }

    return max;
}

int top3_max_calories(std::string input)
{
    std::ifstream file(input);
    std::string line;
    int sum = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;

    while (getline(file, line))
    {
        if (line.length() == 0)
        {
            if (sum > max1)
            {
                max2 = max1;
                max1 = sum;
            }
            else if (sum > max2)
            {
                max3 = max2;
                max2 = sum;
            }
            else if (sum > max3)
            {
                max3 = sum;
            }
            sum = 0;
        }
        else
            sum += stoi(line);
    }

    return max1 + max2 + max3;
}

int main(int argc, char **argv)
{
    std::cout << "Caloric value of elf with max calories: " << max_calories("input.txt") << std::endl;
    std::cout << "Caloric value of top 3 elves with max calories: " << top3_max_calories("input.txt") << std::endl;
}