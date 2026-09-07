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
    //Not these
    int PlayerFalseChoice = 0;
    int OpponentFalseChoice = 0;
    int PlayerIritableChecker = 0;
    int OpponentIritableChecker = 0;


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
            [](auto & letter)
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
        int OpponentChoiceIndex = OpponentChoiceIndexGen(gen);
        //Uses the index from the list to get random 
        Opponent_Choice = GameChoices[OpponentChoiceIndex];
        return Opponent_Choice;
    }

    void Process_Player_choosed(std::string playerchoice)
    {
        for (auto &Choice : GameChoices)
        {
            //If choice is not equal to all each of the choices
            if (playerchoice != Choice)
            {
                PlayerFalseChoice ++;
                //we add it gets to 2 if 3 then its invalid options
            }
            if(PlayerFalseChoice == 3)
            {
                //Three means invalid options
                std::cout << "Please choose from the options {scissor,rock,paper} " << std::endl;
                PlayerFalseChoice = 0;
            }
            else 
            {
                if(playerchoice == "rock")
                {
                    PlayerIritableChecker ++;
                    if (PlayerIritableChecker == 3)
                    {
                        std::cout << "Player Chose" << std::endl;
                        std::cout << OpponentRightChoice[0] << std::endl;
                        PlayerIritableChecker = 0;
                    }
                }
                if(playerchoice == "paper")
                {
                    PlayerIritableChecker ++;
                    if (PlayerIritableChecker == 3)
                    {
                        std::cout << "Player Chose" << std::endl;
                        std::cout << OpponentRightChoice[1] << std::endl;
                        PlayerIritableChecker = 0;
                    }
                }
                if(playerchoice == "scissor")
                {
                    PlayerIritableChecker ++;
                    if (PlayerIritableChecker == 3)
                    {
                        std::cout << "Player Chose" << std::endl;
                        std::cout << OpponentRightChoice[2] << std::endl;
                        PlayerIritableChecker = 0;
                    }
                }
            }
        }
    }

    void Process_Opponent_choosed(std::string opponentchoice)

    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (auto &Choice : GameChoices)
        {

            if (opponentchoice != Choice)
            {
                OpponentFalseChoice ++;
            }
            if(OpponentFalseChoice == 3)
            {
                std::cout << "Please choose from the options {scissor,rock,paper} " << std::endl;
            }

            else 
            {
                if(opponentchoice == "rock")
                {
                    OpponentIritableChecker ++;
                    if (OpponentIritableChecker == 3)
                    {
                        std::cout << "Opponent Chose" << std::endl;
                        std::cout << PlayerLeftChoice[0] << std::endl;
                        OpponentIritableChecker = 0;
                    }
                }
                if(opponentchoice == "paper")
                {
                    OpponentIritableChecker ++;
                    if (OpponentIritableChecker == 3)
                    {
                        std::cout << "Opponent Chose" << std::endl;
                        std::cout << PlayerLeftChoice[1] << std::endl;
                        OpponentIritableChecker = 0;
                    }
                }
                if(opponentchoice == "scissor")
                {
                    OpponentIritableChecker ++;
                    if (OpponentIritableChecker == 3)
                    {
                        std::cout << "Opponent Chose" << std::endl;
                        std::cout << PlayerLeftChoice[2] << std::endl;
                        OpponentIritableChecker = 0;
                    }
                }
            }
        }
    }
    void evulate_win (std::string playerchoice,std::string opponentchoice)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        if (playerchoice == opponentchoice)
        {
            std::cout << "Its a draw" << std::endl;
        }
        else
        {
            if (playerchoice == "rock" && opponentchoice == "paper")
            {
                std::cout << you_lose_sign << std::endl;
                OpponentIritableChecker = 0;
                PlayerIritableChecker = 0;
            }
            if (playerchoice == "paper" && opponentchoice == "scissor")
            {
                std::cout << you_lose_sign << std::endl;
                OpponentIritableChecker = 0;
                PlayerIritableChecker = 0;
            }
            if (playerchoice == "scissor" && opponentchoice == "rock")
            {
                std::cout << you_lose_sign << std::endl;
                OpponentIritableChecker = 0;
                PlayerIritableChecker = 0;
            }
            //Didnt use else to not cause weird things
            if (opponentchoice == "rock" && playerchoice == "paper")
            {
                std::cout << you_win_sign << std::endl;
                OpponentIritableChecker = 0;
                PlayerIritableChecker = 0;
            }
            if (opponentchoice == "paper" && playerchoice == "scissor")
            {
                std::cout << you_win_sign << std::endl;
                OpponentIritableChecker = 0;
                PlayerIritableChecker = 0;
            }
            if (opponentchoice == "scissor" && playerchoice == "rock")
            {
                std::cout << you_win_sign << std::endl;
                OpponentIritableChecker = 0;
                PlayerIritableChecker = 0;
            }
        }
    }
};