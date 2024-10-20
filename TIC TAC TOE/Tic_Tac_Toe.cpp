#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player);
bool draw(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player)) {
            std::cout << "YOU WIN! \n";
            running = false;
            break;
        } else if (draw(spaces)) {
            std::cout << "IT'S A TIE\n";
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, computer)) {
            std::cout << "YOU LOSE! \n";
            running = false;
            break;
        } else if (draw(spaces)) {
            std::cout << "IT'S A TIE\n";
            running = false;
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << '\n';
    std::cout << "_____|_____|_____" << '\n';

    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << '\n';
    std::cout << "_____|_____|_____" << '\n';

    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << '\n';
    std::cout << "     |     |     " << '\n';
}

void playerMove(char *spaces, char player) {
    int number;
    do {
        std::cout << "Enter a spot to place a marker (1 - 9): ";
        std::cin >> number;
        number--; // Convert to 0-based index

        if (number < 0 || number > 8) {
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
        } else if (spaces[number] != ' ') {
            std::cout << "Spot already taken. Choose another spot.\n";
        } else {
            spaces[number] = player;
            break;
        }

    } while (true);
}

void computerMove(char *spaces, char computer) {
    int number;
    srand(static_cast<unsigned>(time(0)));

    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player) {
    // Check rows, columns, and diagonals for a win
    return
        (spaces[0] == player && spaces[1] == player && spaces[2] == player) ||
        (spaces[3] == player && spaces[4] == player && spaces[5] == player) ||
        (spaces[6] == player && spaces[7] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[3] == player && spaces[6] == player) ||
        (spaces[1] == player && spaces[4] == player && spaces[7] == player) ||
        (spaces[2] == player && spaces[5] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
        (spaces[2] == player && spaces[4] == player && spaces[6] == player);
}

bool draw(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    return true;
}
