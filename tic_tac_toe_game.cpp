#include <iostream>
#include <vector>
#include<limits>

#ifdef _WIN32
#include <cstdlib> // For system("cls") on Windows
#else
#endif

using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (a tie)
bool checkTie(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false; // Empty cell found, game is not tied yet
        }
    }
    return true; // Board is full, game is tied
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
    char currentPlayer = 'X';

    cout << "Welcome to Tic Tac Toe!" << endl;

    do {
        // Clear the console screen
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        // Display the current board
        displayBoard(board);

        // Get player move with input validation
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        while (!(cin >> row >> col) || row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Please enter valid row and column values (1, 2, or 3) for an empty cell: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Make the move
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            // Clear the console screen
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            // Display the final board
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for a tie
        if (checkTie(board)) {
            // Clear the console screen
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            // Display the final board
            displayBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}
