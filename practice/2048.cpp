#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
using namespace std;

static vector<vector<int>> board(4,vector<int>(4,0));

int generate_random_number() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> randomnumber(0,3);
    int random = randomnumber(gen);
    return random;
}

void input_random_num() {
    int random_row;
    int random_col;
    do {
        random_row = generate_random_number();
        random_col = generate_random_number();
    } while (board[random_row][random_col] != 0);
    board[random_row][random_col] = 2;
}

void print_board() {
    cout << endl;
    for(int i = 0; i < 4; i++) {   
        for(int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void init_board() {
    int first_row = generate_random_number();
    int first_col = generate_random_number();
    int second_row;
    int second_col;

    do {
        second_row = generate_random_number();
        second_col = generate_random_number();
    } while (board[second_row][second_col] != 0 || (second_row == first_row && second_col == first_col));
    
    board[first_row][first_col] = 2;
    board[second_row][second_col] = 2;
}

bool is_game_over() {
    /* 1. board 내에 2048이 있으면 게임 종료
     * 2. board 내에 빈칸이 없으면 게임 종료 
     */
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 2048) {
                return true;
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void move_down() {
    for (int j = 0; j < 4; j++) {
        // 첫 번째 행부터 마지막 -1번째 행까지 반복
        for (int i = 0; i < 3; i++) {
            // 현재 칸이 0이라면 다음 칸으로 이동
            if (board[i][j] == 0) {
                continue;
            }
            // 위로 이동 가능한지 판단하고 가능하다면 이동
            for (int k = i+1; k < 4; k++) {
                if (board[k][j] == 0) {
                    continue;
                }
                if (board[k][j] == board[i][j]) {
                    board[i][j] *= 2;
                    board[k][j] = 0;
                }
                break;
            }
            
            // 비어있는 칸으로 이동
            int empty_row = i;
            for (int k = i+1; k < 4; k++) {
                if (board[k][j] == 0) {
                    empty_row = k;
                    continue;
                }
                break;
            }
            if (empty_row != i) {
                board[empty_row][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
    input_random_num();
}

      
void move_right() {};
void move_left() {};
void move_up() {};

void play_game() {
    print_board();
    while (!is_game_over()) {
        cout << "w : move up, a: move left, s: move down, d: move right \n";
        char choice;
        cin >> choice;

        switch (choice) {
            case 'w':
                move_up();
                break;
            case 'a':
                move_left();
                break;
            case 's':
                move_down();
                break;
            case 'd':
                move_right();
                break;
            default:
                cout << "Invalid input. Please enter w, a, s, or d." << endl;
                continue;
        }
        print_board();
    }
}

void menu() {
    char choice;
    do {
        cout << "n: new game & q: quit";
        cin >> choice;
        
        switch (choice) {
        case 'n':
            cout << "You are playing the game\n";
            init_board();
            play_game();
            break;
        case 'q':
            cout << "Bye\n";
            exit(0);
        default:
            cout << "Invalid input. Please enter 'n' or 'q'.\n";
        }
    } while (choice != 'q');
}

int main() {  
    menu();
    return 0;
}
