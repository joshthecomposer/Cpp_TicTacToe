#include <iostream>
#include <vector>

char board[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

void show_board()
{
    std::cout << "   |   |   \n";
    std::cout << " "<<board[0]<<" | " <<board[1]<<" | " <<board[2]<< "\n";
    std::cout << "___|___|___\n";
    std::cout << "   |   |   \n";
    std::cout << " "<<board[3]<<" | " <<board[4]<<" | " <<board[5]<< "\n";
    std::cout << "___|___|___\n";
    std::cout << "   |   |   \n";
    std::cout << " "<<board[6]<<" | " <<board[7]<<" | " <<board[8]<< "\n";
    std::cout << "   |   |   \n";
    std::cout << "\n";
}

void greet()
{
    std::cout << "Welcome to Tic Tac Toe.\n";
}

bool insert_move(int player, int position)
{
    if (board[position] == 'X' || board[position] == 'O')
    {
        return false;
    }
    if (player == 0)
    {
        board[position] = 'X';
    }
    else
    {
        board[position] = 'O';
    }
    return true;
}

int check_win_cons()
{
    //player 0 win cons
    if (
        (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
        (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
        (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
        (board[0] == 'X' && board[3] == 'X' && board[4] == 'X') ||
        (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
        (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
        (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') ||
        (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
        )
    {
        return 0;
    }
    //player 1 win cons
    else if (
                (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
        (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
        (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
        (board[0] == 'O' && board[3] == 'O' && board[4] == 'O') ||
        (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
        (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
        (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') ||
        (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
        )
    {
        return 1;
    }
    return -1;
}

bool check_if_tie()
{
    for (int i = 0; i < 8; i++)
    {
        if (board[i] != 'X' || board[i] != 'O')
        {
            return false;
        }
    }
    return true;
}