#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Minesweeper {
private:
    char board[10][10];
    char display[10][10];
    bool flagged[10][10];

    int size;
    int bombCount;
    bool gameOver;

    time_t startTime;
    time_t endTime;

public:
    Minesweeper() {
        gameOver = false;
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== MINESWEEPER++ =====\n";
            cout << "1. Mulai Permainan Baru\n";
            cout << "2. Keluar\n";
            cout << "Pilihan : ";
            cin >> choice;

            if (choice == 1) {
                play();
            }

        } while (choice != 2);

        cout << "Terima kasih telah bermain!\n";
    }

    void setupGame() {
        gameOver = false;

        do {
            cout << "Masukkan ukuran papan (4-10): ";
            cin >> size;
        } while (size < 4 || size > 10);

        int maxBomb = size * size - 1;

        do {
            cout << "Masukkan jumlah bom (1-" << maxBomb << "): ";
            cin >> bombCount;
        } while (bombCount < 1 || bombCount > maxBomb);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = '0';
                display[i][j] = '#';
                flagged[i][j] = false;
            }
        }

        placeBombs();
        calculateNumbers();
    }

    void placeBombs() {
        int placed = 0;

        while (placed < bombCount) {
            int r = rand() % size;
            int c = rand() % size;

            if (board[r][c] != '*') {
                board[r][c] = '*';
                placed++;
            }
        }
    }

    void calculateNumbers() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (board[i][j] == '*')
                    continue;

                int count = 0;

                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {

                        if (dr == 0 && dc == 0)
                            continue;

                        int nr = i + dr;
                        int nc = j + dc;

                        if (nr >= 0 && nr < size &&
                            nc >= 0 && nc < size &&
                            board[nr][nc] == '*') {
                            count++;
                        }
                    }
                }

                board[i][j] = count + '0';
            }
        }
    }

    void displayBoard() {
        int flagsUsed = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (flagged[i][j])
                    flagsUsed++;
            }
        }

        cout << "\nBom tersisa : "
             << bombCount - flagsUsed << endl;

        cout << "Waktu       : "
             << (int)(time(NULL) - startTime)
             << " detik\n\n";

        cout << "   ";
        for (int j = 0; j < size; j++) {
            cout << j + 1 << " ";
        }
        cout << endl;

        for (int i = 0; i < size; i++) {
            cout << i + 1 << "  ";

            for (int j = 0; j < size; j++) {
                cout << display[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    void floodFill(int row, int col) {

        if (row < 0 || row >= size ||
            col < 0 || col >= size)
            return;

        if (display[row][col] != '#')
            return;

        if (flagged[row][col])
            return;

        display[row][col] = board[row][col];

        if (board[row][col] != '0')
            return;

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {

                if (dr == 0 && dc == 0)
                    continue;

                floodFill(row + dr, col + dc);
            }
        }
    }

    void openCell(int row, int col) {

        if (flagged[row][col]) {
            cout << "Kotak ditandai! Lepaskan tanda dahulu.\n";
            return;
        }

        if (board[row][col] == '*') {
            revealBombs();
            gameOver = true;
            return;
        }

        if (board[row][col] == '0') {
            floodFill(row, col);
        }
        else {
            display[row][col] = board[row][col];
        }
    }

    void toggleFlag(int row, int col) {

        if (display[row][col] != '#') {
            cout << "Kotak sudah dibuka!\n";
            return;
        }

        flagged[row][col] = !flagged[row][col];

        if (flagged[row][col])
            display[row][col] = 'F';
        else
            display[row][col] = '#';
    }

    void revealBombs() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (board[i][j] == '*')
                    display[i][j] = '*';
            }
        }
    }

    bool checkWin() {

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (board[i][j] == '*' &&
                    !flagged[i][j])
                    return false;

                if (board[i][j] != '*' &&
                    flagged[i][j])
                    return false;
            }
        }

        return true;
    }

    void play() {

        setupGame();

        startTime = time(NULL);

        while (!gameOver) {

            displayBoard();

            int choice;

            cout << "1. Buka Kotak\n";
            cout << "2. Tandai / Hapus Tanda\n";
            cout << "Pilihan : ";
            cin >> choice;

            int row, col;

            cout << "Baris : ";
            cin >> row;

            cout << "Kolom : ";
            cin >> col;

            if (row < 1 || row > size ||
                col < 1 || col > size) {

                cout << "Koordinat tidak valid!\n";
                continue;
            }

            row--;
            col--;

            if (choice == 1) {
                openCell(row, col);
            }
            else if (choice == 2) {
                toggleFlag(row, col);
            }
            else {
                cout << "Pilihan tidak valid!\n";
                continue;
            }

            if (checkWin()) {
                endTime = time(NULL);

                displayBoard();

                cout << "\n================================\n";
                cout << "SELAMAT! ANDA MENANG!\n";
                cout << "Waktu : "
                     << (int)(endTime - startTime)
                     << " detik\n";
                cout << "================================\n";

                return;
            }

            if (gameOver) {
                endTime = time(NULL);

                displayBoard();

                cout << "\n================================\n";
                cout << "BOOM! ANDA KALAH!\n";
                cout << "Waktu : "
                     << (int)(endTime - startTime)
                     << " detik\n";
                cout << "================================\n";

                return;
            }
        }
    }
};

int main() {

    srand(time(NULL));

    Minesweeper game;
    game.menu();

    return 0;
}