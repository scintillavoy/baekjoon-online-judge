#include <iostream>
#include <vector>
#include <limits>
#include <cstdio>
using namespace std;

int main() {
    while (true) {
        int R, C;
        cin >> R >> C;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (R == 0 && C == 0) {
            break;
        }
        
        vector< vector<char> > vec;
        for (int i = 0; i < R; ++i) {
            vector<char> vec2;
            for (int j = 0; j < C + 1; ++j) {
                char c = getc(stdin);
                if (c != '\n') {
                    vec2.push_back(c);
                }
            }
            vec.push_back(vec2);
        }

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (vec[i][j] == '*') {
                    continue;
                }
                vec[i][j] = '0';
                if (i-1 >= 0 && j-1 >= 0 && vec[i-1][j-1] == '*') {
                    ++vec[i][j];
                }
                if (i-1 >= 0 && vec[i-1][j] == '*') {
                    ++vec[i][j];
                }
                if (i-1 >= 0 && j+1 < C && vec[i-1][j+1] == '*') {
                    ++vec[i][j];
                }
                if (j-1 >= 0 && vec[i][j-1] == '*') {
                    ++vec[i][j];
                }
                if (j+1 < C && vec[i][j+1] == '*') {
                    ++vec[i][j];
                }
                if (i+1 < R && j-1 >= 0 && vec[i+1][j-1] == '*') {
                    ++vec[i][j];
                }
                if (i+1 < R && vec[i+1][j] == '*') {
                    ++vec[i][j];
                }
                if (i+1 < R && j+1 < C && vec[i+1][j+1] == '*') {
                    ++vec[i][j];
                }
            }
        }
        
        for (auto const &x : vec) {
            for (auto const &y : x) {
                cout << y;
            }
            cout << '\n';
        }
    }
    return 0;
}
