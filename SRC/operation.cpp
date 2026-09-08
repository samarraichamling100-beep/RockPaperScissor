#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <cctype>
#include <thread>
#include <chrono>


class RockPaperScissors
{

    private:
    std::string Player_Choice;
    std::string Opponent_Choice;
    unsigned int win = 0;
    unsigned int loss = 0;
    //Copied these strings from google
    std::string you_win_sign = 
    "[*]  YOU WIN !!!  [*]\n"
    "======================\n"
    "  o/   o/   o/   o/\n"
    " /|   /|   /|   /|\n"
    " / \\  / \\  / \\  / \\\n"
    "======================\n";
    //Copied these strings from google
    std::string you_lose_sign = 
    "[X]  YOU LOSE !!  [X]\n"
    "======================\n"
    "  _\\|/_   _\\|/_   _\\|/_\n"
    "   (.)     (.)     (.)\n"
    "  / | \\   / | \\   / | \\\n"
    "======================\n";
    public:
    std::string PlayerLeftChoice[3] = {
    //Copied these strings from google
        R"(   
        _______
    ---'   ____)
          (_____)
          (_____)
          (____)
    ---.__(___))",
        R"(   
        _______
    ---'   ____)____
              ______)
              _______)
             _______)
    ---.__________))",

        R"(   
        _______
    ---'   ____)____
              ______)
           __________)
          (____)
    ---.__(___))"
    };
    //Copied these strings from google
    std::string OpponentRightChoice[3] = {
        R"(   
     _______
    (____   '---
    (_____)
    (_____)
    (____)
        (___)__.---)",
        R"(      
         _______
     ____(____   '---
    (______
    (_______
    (_______
    (___________.---)",
        R"(     
         _______
    ____(____   '---
    (______
    (__________
        (____)
        (___)__.---)"
};

    //All made without AI
    std::vector<std::string> GameChoices = 
    {
        "scissor",
        "rock",
        "paper"
    };


    std::random_device random_seed;
    std::mt19937 gen{random_seed()};

    void StartDown()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Rock" << std::endl;
        std::cout << PlayerLeftChoice[0] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Paper" << std::endl;
        std::cout << OpponentRightChoice[1] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Scissors" << std::endl;
        std::cout << PlayerLeftChoice[2] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::string MainChoice()
    {
        std::cout << "Choose an option from {scissor,rock,paper}: ";
        std::cin >> Player_Choice;
        //std::transform to convert the string into lower
        //Cool lambda function to to lower every string
        std::transform
        (
            Player_Choice.begin(),
            Player_Choice.end(),
            Player_Choice.begin(),
            [](unsigned char letter)
            {
                return std::tolower(letter);
            }
    );
        return Player_Choice;
    }

    std::string Opponent_Choose()
    {
        //MAke the random index generator
        std::uniform_int_distribution <std::size_t> OpponentChoiceIndexGen(0,GameChoices.size() - 1);
        //Uses the index generator to get the index
        std::size_t OpponentChoiceIndex = OpponentChoiceIndexGen(gen);
        //Uses the index from the list to get random 
        Opponent_Choice = GameChoices[OpponentChoiceIndex];
        return Opponent_Choice;
    }

    void Process_Player_choosed(std::string playerchoice)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        bool valid = false;

        for (auto &Choice : GameChoices)
        {
            if (playerchoice == Choice)
            {
                valid = true;
                break;
            }
        }

        if (!valid)
        {
            std::cout << "Invalid choice!\n";
        }
        else
        {
            if (playerchoice == "rock")
            {
                std::cout << "Player Chose:\n";
                std::cout << PlayerLeftChoice[0] << std::endl;
            }
            else if (playerchoice == "paper")
            {
                std::cout << "Player Chose:\n";
                std::cout << PlayerLeftChoice[1] << std::endl;
            }
            else if (playerchoice == "scissor")
            {
                std::cout << "Player Chose:\n";
                std::cout << PlayerLeftChoice[2] << std::endl;
            }
        }
    }
    void Process_Opponent_choosed(std::string opponentchoice)

    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(opponentchoice == "rock")
        {
            std::cout << "Opponent Chose" << std::endl;
            std::cout << OpponentRightChoice[0] << std::endl;
        }
                
        else if(opponentchoice == "paper")
        {
            std::cout << "Opponent Chose" << std::endl;
            std::cout << OpponentRightChoice[1] << std::endl;
        }
        else if(opponentchoice == "scissor")
        {
            std::cout << "Opponent Chose" << std::endl;
            std::cout << OpponentRightChoice[2] << std::endl;
        }
            
    }
    void evulate_win (std::string playerchoice,std::string opponentchoice,int rounds)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (playerchoice == opponentchoice)
        {
            std::cout << "It's a draw\n";
        }
        else if (
            (playerchoice == "rock" && opponentchoice == "scissor") ||
            (playerchoice == "paper" && opponentchoice == "rock") ||
            (playerchoice == "scissor" && opponentchoice == "paper")
            )
            {
                std::cout << you_win_sign << '\n';
                win += 1;
            }
        else
        {

            std::cout << you_lose_sign << '\n';
            loss += 1;
        }
        CheckWin(& rounds);
    }
    void CheckWin(int *rounds)
    {
        if (*rounds == 2)
        {
            std::cout << "It is being checked" << std::endl;

            std::cout << "You have won "
                  << win << " times" << std::endl;

            std::cout << "You have lost "
                  << loss << " times" << std::endl;

            if (win == loss)
            {
                std::cout << "Overall Draw!" << std::endl;
            }
            else if (win > loss)
            {
                std::cout << "You have won the game!" << std::endl;
            }
            else
            {
            std::cout << "You have lost the game!" << std::endl;
            }
        }
    }
};