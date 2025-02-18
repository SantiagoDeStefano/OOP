#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {'1', '2', '3', 
                      '4', '5', '6',
                      '7', '8', '9'};
    char player = 'X';
    char computer = 'O';
    bool isRunning = true;

    drawBoard(spaces);

    while(isRunning) {
        playerMove(spaces, player);
        if(checkWinner(spaces, player, computer) || checkTie(spaces)) {
            isRunning = false;
            drawBoard(spaces);
            break;
        }
        computerMove(spaces, computer);
        if(checkWinner(spaces, player, computer) || checkTie(spaces)) {
            isRunning = false;
            drawBoard(spaces);
            break;
        }
        drawBoard(spaces);
    }
}

void drawBoard(char *spaces) {
    cout << "     " << "|" << "     " << "|" << "     " << '\n';
    cout << "  " << spaces[0] << "  " << "|" << "  " << spaces[1] << "  " << "|" << "  " << spaces[2] << "  " << '\n';
    cout << "_____" << "|" << "_____" << "|" << "_____" << '\n';

    cout << "     " << "|" << "     " << "|" << "     " << '\n';
    cout << "  " << spaces[3] << "  " << "|" << "  " << spaces[4] << "  " << "|" << "  " << spaces[5] << "  " << '\n';
    cout << "_____" << "|" << "_____" << "|" << "_____" << '\n';

    cout << "     " << "|" << "     " << "|" << "     " << '\n';
    cout << "  " << spaces[6] << "  " << "|" << "  " << spaces[7] << "  " << "|" << "  " << spaces[8] << "  " << '\n';
    cout << "     " << "|" << "     " << "|" << "     " << '\n';
}
void playerMove(char *spaces, char player) {
    int position;
    do {
        cout << "Enter a position from 1 -> 9: ";
        cin >> position;
        position = position - 1;
        if(spaces[position] >= '1' && spaces[position] <= '9') {
            spaces[position] = player;
            break;
        }
        else {
            cout << "Please enter a different position." << endl;
        }
    } while(position >= 0 && position <= 8);
}
void computerMove(char *spaces, char computer) {
    int position;
    srand(time(0));
    do {
        position = rand()%9;
        if(spaces[position] >= '1' && spaces[position] <= '9') {
            spaces[position] = computer;
            break;
        }
    } while(position >= 0 && position <= 8);
}
bool checkWinner(char *spaces, char player, char computer) {
    //Horizontal check
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        spaces[0] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        spaces[3] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        spaces[6] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    //Vertical check
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        spaces[0] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        spaces[1] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        spaces[2] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    //Diagonal check
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        spaces[2] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }
    else {
        return false;
    }
    return true;
}
bool checkTie(char *spaces) {
    for(int i = 0; i < 9; i++) {
        if(spaces[i] >= '1' && spaces[i] <= '9') {
            return false;
        }
    }
    cout << "It's a Tie!\n";
    return true;
}