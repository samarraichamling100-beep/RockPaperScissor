
#include "operation.cpp"


int main ()
{

    RockPaperScissors game;
    std::string PlayerChoice;
    std::string OpponentChoice;

    game.StartDown();
    PlayerChoice = game.MainChoice();
    OpponentChoice = game.Opponent_Choose();

    game.Process_Player_choosed(PlayerChoice);
    game.Process_Opponent_choosed(OpponentChoice);
    
    game.evulate_win(PlayerChoice,OpponentChoice);
    return 0;   
}