#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using comparisons = std::vector<std::string>;

/**
 * Maps a given character to priority index.
 */
int give_char_idx(char const &c)
{
    int cint = (int)c;

    if (cint < 97) // If A-Z
    {
        cint -= 38;
    }
    else // If a-z
    {
        cint -= 96;
    }
    return cint;
}

/**
 * Gives the priority index of the common character b/w 2 strings.
 */
int common_char(comparisons const &strings)
{
    int tracker[52] = {0};
    int charnum;
    int n = strings.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strings.at(i).length(); j++)
        {
            charnum = give_char_idx(strings.at(i)[j]);
            if (i == 0)
                tracker[charnum - 1] = i + 1;
            else if (n - 1 > i)
            {
                if (tracker[charnum - 1] == i)
                {
                    tracker[charnum - 1] = i + 1;
                }
            }
            else
            {
                if (tracker[charnum - 1] == i)
                {
                    std::cout << "Common char: " << charnum << std::endl;
                    return charnum;
                }
            }
        }
    }

    return charnum;
}

/**
 * Sum of priority index in a given file
 */
int sum_idx(std::string const &filename)
{
    std::ifstream file(filename);
    std::string rucksack;
    int sum = 0;
    comparisons items(2);

    while (true)
    {
        file >> rucksack;

        items[0] = rucksack.substr(0, rucksack.length() / 2);
        items[1] = rucksack.substr(rucksack.length() / 2, rucksack.length() / 2);
        sum += common_char(items);

        if (file.eof())
        {
            break;
        }
    }

    return sum;
}

int sum_group_idx(std::string const &filename)
{
    std::ifstream file(filename);
    std::string rucksack;
    int sum = 0;
    comparisons items(3);

    while (true)
    {
        file >> items[0];
        file >> items[1];
        file >> items[2];

        std::cout << items[0] << " - " << items[1] << " - " << items[2] << std::endl;

        sum += common_char(items);

        if (file.eof())
        {
            break;
        }
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    assert(1 == give_char_idx('a'));
    assert(26 == give_char_idx('z'));
    assert(27 == give_char_idx('A'));
    assert(28 == give_char_idx('B'));
    assert(52 == give_char_idx('Z'));

    std::cout << "Sum of item types: " << sum_idx("input.txt") << std::endl;
    std::cout << "Sum of item types groups: " << sum_group_idx("input.txt") << std::endl;
}