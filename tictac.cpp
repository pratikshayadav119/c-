#include <iostream>
using namespace std;

class TicTacToe {
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        // Initialize board with spaces
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
        currentPlayer = 'X'; // X starts
    }

    void displayBoard() {
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "  -+-+-\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++)
            if (board[i][0] == currentPlayer &&
                board[i][1] == currentPlayer &&
                board[i][2] == currentPlayer)
                return true;

        // Check columns
        for (int j = 0; j < 3; j++)
            if (board[0][j] == currentPlayer &&
                board[1][j] == currentPlayer &&
                board[2][j] == currentPlayer)
                return true;

        // Check diagonals
        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int row, col;
    bool validMove;

    cout << "Tic-Tac-Toe Game\n";
    game.displayBoard();

    while (true) {
        cout << "Player " << game.getCurrentPlayer() << ", enter row and column (0-2): ";
        cin >> row >> col;

        validMove = game.makeMove(row, col);
        if (!validMove) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        game.displayBoard();

        if (game.checkWin()) {
            cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            break;
        }

        if (game.isBoardFull()) {
            cout << "Game is a draw.\n";
            break;
        }

        game.switchPlayer();
    }

    return 0;
}
