#include <fstream>
#include <iostream>
#include <string>

int round_score_part1(std::string oppHand, std::string yourHand)
{
    int score = 0;
    if (yourHand == "X") // Rock
    {
        score += 1;
        if (oppHand == "A") // Rock - Draw
        {
            score += 3;
        }
        else if (oppHand == "C") // Scissor - Win
        {
            score += 6;
        }
    }
    else if (yourHand == "Y") // Paper
    {
        score += 2;
        if (oppHand == "B") // Paper - Draw
        {
            score += 3;
        }
        else if (oppHand == "A") // Rock - Win
        {
            score += 6;
        }
    }
    else if (yourHand == "Z") // Scizzor
    {
        score += 3;
        if (oppHand == "C") // Scizzor - Draw
        {
            score += 3;
        }
        else if (oppHand == "B") // Paper - Win
        {
            score += 6;
        }
    }
    return score;
}

int round_score_part2(std::string oppHand, std::string yourHand)
{
    int score = 0;
    if (yourHand == "X") // Lose
    {
        score += 0;
        if (oppHand == "A") // Rock - Scizzor
        {
            score += 3;
        }
        else if (oppHand == "C") // Scizzor - Paper
        {
            score += 2;
        }
        else if (oppHand == "B") // Paper - Rock
        {
            score += 1;
        }
    }
    else if (yourHand == "Y") // Draw
    {
        score += 3;
        if (oppHand == "A") // Rock - Rock
        {
            score += 1;
        }
        else if (oppHand == "B") // Paper - Paper
        {
            score += 2;
        }
        else if (oppHand == "C") // Scizzor - Scizzor
        {
            score += 3;
        }
    }
    else if (yourHand == "Z") // Win
    {
        score += 6;

        if (oppHand == "C") // Scizzor - Rock
        {
            score += 1;
        }
        else if (oppHand == "A") // Rock - Paper
        {
            score += 2;
        }
        else if (oppHand == "B") // Paper - Scizzor
        {
            score += 3;
        }
    }
    return score;
}

int game_score(std::string gamefile, std::string strategy)
{
    std::ifstream file(gamefile);

    int gamescore = 0;

    while (true)
    {
        std::string oppHand;
        std::string yourHand;

        file >> oppHand;
        file >> yourHand;

        if (strategy == "part1")
        {
            gamescore += round_score_part1(oppHand, yourHand);
        }
        else if (strategy == "part2")
        {
            gamescore += round_score_part2(oppHand, yourHand);
        }

        if (file.eof())
        {
            break;
        }
    }

    return gamescore;
}

int main(int argc, char const *argv[])
{
    std::cout << game_score("input.txt", "part1") << std::endl;
    std::cout << game_score("input.txt", "part2") << std::endl;
}