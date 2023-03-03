#include "fn.hpp"
#include <iostream>

bool end_con = false;
int player_turn = 0;
int position;

int main()
{
    greet();

    while (!end_con)
    {
        show_board();
        if (check_if_tie())
        {
            std::cout << "It was a tie!!\n";
            return 0;
        }

        if (check_win_cons() == 0)
        {
            std::cout << "Player 1 wins!\n";
            return 0;
        }

        if (check_win_cons() == 1)
        {
            std::cout << "Player 2 wins!\n";
            return 0;
        }

        switch (player_turn)
        {
        case 0:
            std::cout << "Player 1, enter your move:";
            std::cin >> position;
            if(!insert_move(player_turn, position))
            {
                std::cout << "ILLEGAL MOVE, TRY AGAIN!";
                break;
            }
            player_turn = 1;
            break;
        case 1:
            std::cout << "Player 2, enter your move:";
            std::cin >> position;
            if(!insert_move(player_turn, position))
            {
                std::cout << "ILLEGAL MOVE, TRY AGAIN!";
                break;
            }
            player_turn = 0;
            break;
        }
    }
    return 0;
}