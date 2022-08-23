#include <iostream>
using namespace std;

void solve(char (*board)[3], char mark) {
    int cnt;
        for (int m = 0; m < 3; ++m) {
            cnt = 0;
            for (int n = 0; n < 3; ++n) {
                if (board[m][n] == mark) {
                    ++cnt;
                } else if (board[m][n] != '-') {
                    --cnt;
                }
            }
            if (cnt == 2) {
                for (int n = 0; n < 3; ++n) {
                    board[m][n] = mark;
                }
                return;
            }
        }

        for (int m = 0; m < 3; ++m) {
            cnt = 0;
            for (int n = 0; n < 3; ++n) {
                if (board[n][m] == mark) {
                    ++cnt;
                } else if (board[n][m] != '-') {
                    --cnt;
                }
            }
            if (cnt == 2) {
                for (int n = 0; n < 3; ++n) {
                    board[n][m] = mark;
                }
                return;
            }
        }

        cnt = 0;
        for (int m = 0; m < 3; ++m) {
            if (board[m][m] == mark) {
                ++cnt;
            } else if (board[m][m] != '-') {
                --cnt;
            }
        }
        if (cnt == 2) {
            for (int m = 0; m < 3; ++m) {
                board[m][m] = mark;
            }
            return;
        }

        cnt = 0;
        for (int m = 0; m < 3; ++m) {
            if (board[m][2-m] == mark) {
                ++cnt;
            } else if (board[m][2-m] != '-') {
                --cnt;
            }
        }
        if (cnt == 2) {
            for (int m = 0; m < 3; ++m) {
                board[m][2-m] = mark;
            }
            return;
        }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        char board[3][3];
        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                cin >> board[m][n];
            }
        }

        char mark;
        cin >> mark;
        
        solve(board, mark);

        cout << "Case " << i << ":\n";
        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                cout << board[m][n];
            }
            cout << '\n';
        }
    }
    return 0;
}
