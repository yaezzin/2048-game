#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows) {
    bool moved;
    do {
        moved = false;
        for (int r = 0; r < numrows; r++) {
            for (int c = 1; c < 5; c++) {
                if(board[r][c] != 0) {
                    for (int k = c-1; k >= 0; k--) {
                        if (board[r][k] == 0) {
                            board[r][k] = board[r][k+1];
                            board[r][k+1] = 0;
                            moved = true;
                        } else if (board[r][k] == board[r][k+1]) {
                            board[r][k] *= 2;
                            board[r][k+1] = 0;
                            moved = true;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } while (moved);
}

void move_right(int board[][5], int numrows) {
    bool moved;
    do {
        moved = false;
        for (int r = 0; r < numrows; r++) {
            for (int c = 3; c >= 0; c--) {
                if(board[r][c] != 0) {
                    for (int k = c+1; k < 5; k++) {
                        if (board[r][k] == 0) {
                            board[r][k] = board[r][k-1];
                            board[r][k-1] = 0;
                            moved = true;
                        } else if (board[r][k] == board[r][k-1]) {
                            board[r][k] *= 2;
                            board[r][k-1] = 0;
                            moved = true;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } while (moved);
}

void move_up(int board[][5], int numcols) {
    bool moved;
    do {
        moved = false;
        for (int c = 0; c < numcols; c++) {
            for (int r = 1; r < 5; r++) {
                if(board[r][c] != 0) {
                    for (int k = r-1; k >= 0; k--) {
                        if (board[k][c] == 0) {
                            board[k][c] = board[k+1][c];
                            board[k+1][c] = 0;
                            moved = true;
                        } else if (board[k][c] == board[k+1][c]) {
                            board[k][c] *= 2;
                            board[k+1][c] = 0;
                            moved = true;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } while (moved);
}

void move_down(int board[][5], int numcols) {
    bool moved;
    do {
        moved = false;
        for (int c = 0; c < numcols; c++) {
            for (int r = 3; r >= 0; r--) {
                if(board[r][c] != 0) {
                    for (int k = r+1; k < 5; k++) {
                        if (board[k][c] == 0) {
                            board[k][c] = board[k-1][c];
                            board[k-1][c] = 0;
                            moved = true;
                        } else if (board[k][c] == board[k-1][c]) {
                            board[k][c] *= 2;
                            board[k-1][c] = 0;
                            moved = true;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } while (moved);
}

void print_board(int board[][5], int numrows = 5) {
    cout << endl << "\t-----------------------------------------" << endl;
    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < 5; c++) {
            if(board[r][c] > 0)
                cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
            else
                cout << "\t|" << right << setw(6) << setfill(' ') << " ";
                //cout << board[r][c] << "\t|\t";
        }
        cout << "\t|" << endl;
        cout << "\t-----------------------------------------" << endl;
    }
    cout << "\t" << endl << endl;
}

void insert_random(int board[][5], int numrows = 5) {
    int r, c;
    //count empty
    int empty_count = 0;
    
    for (int r = 0; r < numrows; r++) { 
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == 0) empty_count++;
        }
    }

    if (empty_count > 0) {
        while (true) { 
            //generate random location r, c
            r = rand() % numrows;
            c = rand() % numrows;
            //check if empty
            if (board[r][c] == 0) {
                //add number randomly {2,4}
                board[r][c] = 2 * (1 + (rand() % 2));
                break;
            }
        }
    }
}



