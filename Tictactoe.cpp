#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void board(char *blocks);
void choose(char &sign, char &comp);
void choose2(char &sign, char &player2);
void playerturn(char *blocks, char player1);
void playerturn2(char *blocks, char player2);
void compturn(char *blocks, char comp);
bool win(char *blocks, char player1, char comp);
bool win2(char *blocks, char player1, char player2);
bool checkwin(char *blocks, char player, char opponent, string playerwinmsg, string opswinmsg);
bool tie(char *blocks);

int main()
{
    while (true)
    {
        // Main menu
    mainmenu:
        int mode;
        cout << "----------  Tic Tac Toe  ----------" << endl;
        cout << endl;
        cout << "Choose Mode [1, 2 or 3]: " << endl;
        cout << "1. Single Player\n";
        cout << "2. Multiplayer\n";
        cout << "3. Exit\n";
        cout << "Mode: ";
        cin >> mode;

        system("cls");

        if (mode == 1) // Single Player Mode
        {
        start:
            char sign, player1, comp, j;
            char blocks[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
            choose(sign, comp);
            player1 = sign;
            board(blocks);

            while (true)
            {
                playerturn(blocks, player1);
                board(blocks);
                if (win(blocks, player1, comp) || tie(blocks))
                {

                    cout << endl;
                    cout << "Play again?\n";
                    cout << "Press 'y' to continue and 'n' for main menu.\n";
                    cin >> j;
                    if (j == 'y')
                    {
                        goto start;
                    }
                    else if (j == 'n')
                    {
                        goto mainmenu;
                    }
                }

                compturn(blocks, comp);
                board(blocks);
                if (win(blocks, player1, comp) || tie(blocks))
                {

                    cout << endl;
                    cout << "Play again?\n";
                    cout << "Press 'y' to continue and 'n' for main menu.\n";
                    cin >> j;
                    if (j == 'y')
                    {
                        goto start;
                    }
                    else if (j == 'n')
                    {
                        goto mainmenu;
                    }
                }
            }
        }
        else if (mode == 2) // Multiplayer Mode
        {
        begin:
            char sign, player1, player2, j;
            char blocks[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
            choose2(sign, player2);
            player1 = sign;
            board(blocks);

            while (true)
            {
                playerturn(blocks, player1);
                board(blocks);
                if (win2(blocks, player1, player2) || tie(blocks))
                {

                    cout << endl;
                    cout << "Play again?\n";
                    cout << "Press 'y' to continue and 'n' for main menu.\n";
                    cin >> j;
                    if (j == 'y')
                    {
                        goto begin;
                    }
                    else if (j == 'n')
                    {
                        goto mainmenu;
                    }
                }

                playerturn2(blocks, player2);
                board(blocks);
                if (win2(blocks, player1, player2) || tie(blocks))
                {

                    cout << endl;
                    cout << "Play again?\n";
                    cout << "Press 'y' to continue and 'n' for main menu.\n";
                    cin >> j;
                    if (j == 'y')
                    {
                        goto begin;
                        
                    }
                    else if (j == 'n')
                    {
                        goto mainmenu;
                        
                    }
                }
            }
        }
        else if (mode == 3)
        {
            break;
        }
    }
}

void board(char *blocks)
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << blocks[0] << "  |  " << blocks[1] << "  |  " << blocks[2] << "   " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << blocks[3] << "  |  " << blocks[4] << "  |  " << blocks[5] << "   " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << blocks[6] << "  |  " << blocks[7] << "  |  " << blocks[8] << "   " << endl;
    cout << endl;
}

void choose(char &sign, char &comp)
{
    while (true)
    {
        cout << "Player Choose Sign ('X' or 'O'): ";
        cin >> sign;
        cout << endl;
        if (sign == 'X' || sign == 'O')
        {
            comp = (sign == 'X') ? 'O' : 'X';
            cout << "Player: " << sign << endl;
            cout << "Computer: " << comp << endl;
            break;
        }
        else
        {
            cout << "Invalid Sign\n";
        }
    }
}

void choose2(char &sign, char &player2)
{
    while (true)
    {
        cout << "Player 1 Choose Sign ('X' or 'O'): ";
        cin >> sign;
        cout << endl;
        if (sign == 'X' || sign == 'O')
        {
            player2 = (sign == 'X') ? 'O' : 'X';
            cout << "Player 1: " << sign << endl;
            cout << "Player 2: " << player2 << endl;
            break;
        }
        else
        {
            cout << "Invalid Sign\n";
        }
    }
}

void playerturn(char *blocks, char player1)
{
    int n;
    while (true)
    {
        cout << "Enter a spot from 1 to 9 : ";
        cin >> n;
        if (n < 1 || n > 9)
        {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        int i = --n;
        if (blocks[i] == ' ')
        {
            blocks[i] = player1;
            break;
        }
        else
        {
            cout << "Spot already taken. Try again.\n";
        }
    }
    system("cls");
}

void playerturn2(char *blocks, char player2)
{
    int n;
    while (true)
    {
        cout << "Enter a spot from 1 to 9 : ";
        cin >> n;
        if (n < 1 || n > 9)
        {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        int i = --n;
        if (blocks[i] == ' ')
        {
            blocks[i] = player2;
            break;
        }
        else
        {
            cout << "Spot already taken. Try again.\n";
        }
    }
    system("cls");
}

void compturn(char *blocks, char comp)
{
    if (tie(blocks))
    {
        return;
    }

    vector<int> emptyspots;

    for (int i = 0; i < 9; i++)
    {
        if (blocks[i] == ' ')
        {
            emptyspots.push_back(i);
        }
    }

    if (!emptyspots.empty())
    {
        int randindx = rand() % emptyspots.size();
        blocks[emptyspots[randindx]] = comp;
    }

    system("cls");
}

bool checkwin(char *blocks, char player, char opponent, string playerwinmsg, string opswinmsg)
{
    int winpatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, //Rows
         {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
          {0, 4, 8}, {2, 4, 6}}; // Diagonals

    for (auto &pattern : winpatterns)
    {
        if (blocks[pattern[0]] != ' ' &&
            blocks[pattern[0]] == blocks[pattern[1]] &&
            blocks[pattern[1]] == blocks[pattern[2]])
        {
            cout << (blocks[pattern[0]] == player ? playerwinmsg : opswinmsg) << endl;
            return true;
        }
    }
    return false;
}

bool win(char *blocks, char player1, char comp)
{
    return checkwin(blocks, player1, comp, "You Win!", "You Lose!");
}

bool win2(char *blocks, char player1, char player2)
{
    return checkwin(blocks, player1, player2, "Player 1 Wins!", "Player 2 Wins!");
}

bool tie(char *blocks)
{
    for (int i = 0; i < 9; i++)
    {
        if (blocks[i] == ' ')
        {
            return false;
        }
    }
    cout << "Match Tied.\n";
    return true;
}