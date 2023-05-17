#include <iostream>

void lines();
void blackMove();
void whiteMove();
bool checkWinnerWvB();
bool checkTie();

char spaces[][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};
int num;
int row;
int column;
char white = 'w';
char black = 'b';
bool ongoing = true;
int main()
{
    lines();
    while (ongoing != false)
    {
        blackMove();
        lines();
        if (checkWinnerWvB())
        {
            ongoing = false;
            break;
        }
        else if (checkTie())
        {
            ongoing = false;
            break;
        }

        whiteMove();
        lines();
        if (checkWinnerWvB())
        {
            ongoing = false;
            break;
        }
        else if (checkTie())
        {
            ongoing = false;
            break;
        }
    }
    return 0;
}
void lines()
{
    std::cout << "     |     |     "
              << "\n";
    std::cout << "  " << spaces[0][0] << "  |  " << spaces[0][1] << "  |  " << spaces[0][2] << "   "
              << "\n";
    std::cout << "_____|_____|_____"
              << "\n";
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[1][0] << "  |  " << spaces[1][1] << "  |  " << spaces[1][2] << "   "
              << "\n";
    std::cout << "_____|_____|_____"
              << "\n";
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[2][0] << "  |  " << spaces[2][1] << "  |  " << spaces[2][2] << "   "
              << "\n";
    std::cout << "     |     |     "
              << "\n";
    std::cout << "\n";
}
void whiteMove()
{
    do
    {
        std::cout << "White choose empty field!";
        std::cin >> num;
        switch (num)
        {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
        default:
            break;
        }
        if (spaces[row][column] == ' ')
        {
            spaces[row][column] = white;
            break;
        }
    } while (!num > 1 || !num < 9);
}
void blackMove()
{
    do
    {
        std::cout << "Black choose empty field!";
        std::cin >> num;
        switch (num)
        {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
        default:
            break;
        }
        if (spaces[row][column] == ' ')
        {
            spaces[row][column] = black;
            break;
        }

    } while (!num > 1 || !num < 9);
}
bool checkWinnerWvB()
{
    if ((spaces[0][0] != ' ') && (spaces[0][0] == spaces[0][1] && spaces[0][1] == spaces[0][2]))
    {
        spaces[0][0] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else if ((spaces[1][0] != ' ') && (spaces[1][0] == spaces[1][1] && spaces[1][1] == spaces[1][2]))
    {
        spaces[1][0] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else if ((spaces[2][0] != ' ') && (spaces[2][0] == spaces[2][1] && spaces[2][1] == spaces[2][2]))
    {
        spaces[2][0] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else if ((spaces[0][0] != ' ') && (spaces[0][0] == spaces[1][0] && spaces[1][0] == spaces[2][0]))
    {
        spaces[0][0] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else if ((spaces[0][1] != ' ') && (spaces[0][1] == spaces[1][1] && spaces[1][1] == spaces[2][1]))
    {
        spaces[0][1] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else if ((spaces[0][2] != ' ') && (spaces[0][2] == spaces[1][2] && spaces[1][2] == spaces[2][2]))
    {
        spaces[0][2] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else if ((spaces[0][0] != ' ') && (spaces[0][0] == spaces[1][1] && spaces[1][1] == spaces[2][2]))
    {
        spaces[0][0] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else if ((spaces[0][2] != ' ') && (spaces[0][2] == spaces[1][1] && spaces[1][1] == spaces[2][0]))
    {
        spaces[0][2] == white ? std::cout << "Vitory to White" : std::cout << "Victory to Black";
    }
    else
    {
        return false;
    }

    return true;
}
bool checkTie()
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (spaces[i][j] == ' ')
            {
                return false;
            }
        }
    }
    std::cout << "It's a tie!";
    return true;
}