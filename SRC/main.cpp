
#include "operation.cpp"


int main ()
{

    RockPaperScissors game;
    std::string PlayerChoice;
    std::string OpponentChoice;

    for(int round = 0;round < 3 ; round ++)
    {
        PlayerChoice = game.MainChoice();
        OpponentChoice = game.Opponent_Choose();

        game.Process_Player_choosed(PlayerChoice);
        game.Process_Opponent_choosed(OpponentChoice);
    
        game.evulate_win(PlayerChoice,OpponentChoice,round);
    }
    return 0;   
}