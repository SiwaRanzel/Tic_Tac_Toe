#include <iostream>
#include <ctime>
void lines(char *spaces);
void user1Move(char *spaces, char user1);
void user2Move(char *spaces, char user2);
void computerMove(char *spaces, char computer);
bool checkWinnerP1vP2(char *spaces, char user1, char user2);
bool checkWinnerPC(char *spaces, char user1, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char user1;
    char user2;
    char computer;
    std::string option;
    int opt;
    bool running = true;
    std::string repeat;

    std::cout << "Choose from the options: \n";
    std::cout << "1. Player1 vs Player2\n";
    std::cout << "2. Player1 vs PC\n";
    std::cout << "Option :";
    std::cin >> opt;
    if (opt == 1)
    {
        std::cout << "Player1 choose to play with X or O: ";
        std::cin >> option;

        if (option == "X" || option == "x")
        {
            user1 = 'X';
            user2 = 'O';
        }
        else if (option == "O" || option == "o")
        {
            user1 = 'O';
            user2 = 'X';
        }

        lines(spaces);

        while (running)
        {
            user1Move(spaces, user1);
            lines(spaces);
            if (checkWinnerP1vP2(spaces, user1, user2))
            {
                running = false;
                break;
            }
            else if (checkTie(spaces))
            {
                running = false;
                break;
            }
            user2Move(spaces, user2);
            lines(spaces);
            if (checkWinnerP1vP2(spaces, user1, user2))
            {
                running = false;
                break;
            }
            else if (checkTie(spaces))
            {
                running = false;
                break;
            }
        }
    }
    else if (opt == 2)
    {

        std::cout << "Player1 choose to play with X or O: ";
        std::cin >> option;
        if (option == "X" || option == "x")
        {
            user1 = 'X';
            computer = 'O';
        }
        else if (option == "O" || option == "o")
        {
            user1 = 'O';
            computer = 'X';
        }

        lines(spaces);

        while (running)
        {
            user1Move(spaces, user1);
            lines(spaces);
            if (checkWinnerPC(spaces, user1, computer))
            {
                running = false;
                break;
            }
            else if (checkTie(spaces))
            {
                running = false;
                break;
            }
            computerMove(spaces, computer);
            lines(spaces);
            if (checkWinnerPC(spaces, user1, computer))
            {
                running = false;
                break;
            }
            else if (checkTie(spaces))
            {
                running = false;
                break;
            }
        }
    }
    return 0;
}
void lines(char *spaces)
{
    std::cout << "     |     |     "
              << "\n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   "
              << "\n";
    std::cout << "_____|_____|_____"
              << "\n";
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   "
              << "\n";
    std::cout << "_____|_____|_____"
              << "\n";
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   "
              << "\n";
    std::cout << "     |     |     "
              << "\n";
    std::cout << "\n";
}
void user1Move(char *spaces, char user1)
{
    int num;
    do
    {
        std::cout << "Enter a spot to place a maker (1-9)";
        std::cin >> num;
        num--;
        if (spaces[num] == ' ')
        {
            spaces[num] = user1;
            break;
        }

    } while (!num > 0 || !num < 8);
}
void user2Move(char *spaces, char user2)
{
    int num;
    do
    {
        std::cout << "Enter a spot to place a maker (1-9)";
        std::cin >> num;
        num--;
        if (spaces[num] == ' ')
        {
            spaces[num] = user2;
            break;
        }

    } while (!num > 0 || !num < 8);
}
void computerMove(char *spaces, char computer)
{
    int num;
    srand(time(0));

    while (true)
    {
        num = rand() % 9;
        if (spaces[num] == ' ')
        {
            spaces[num] = computer;
            break;
        }
    }
}
bool checkWinnerPC(char *spaces, char user1, char computer)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2]))
    {
        spaces[0] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5]))
    {
        spaces[3] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8]))
    {
        spaces[6] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6]))
    {
        spaces[0] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7]))
    {
        spaces[1] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8]))
    {
        spaces[2] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8]))
    {
        spaces[0] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6]))
    {
        spaces[2] == user1 ? std::cout << "You won! :-D" : std::cout << "You lost :-(";
    }
    else
    {
        return false;
    }

    return true;
}
bool checkWinnerP1vP2(char *spaces, char user1, char user2)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2]))
    {
        spaces[0] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5]))
    {
        spaces[3] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8]))
    {
        spaces[6] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6]))
    {
        spaces[0] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7]))
    {
        spaces[1] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8]))
    {
        spaces[2] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8]))
    {
        spaces[0] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6]))
    {
        spaces[2] == user1 ? std::cout << "player1 won" : std::cout << "Player 2 won";
    }
    else
    {
        return false;
    }

    return true;
}
bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "It's a tie :-|";
    return true;
}
