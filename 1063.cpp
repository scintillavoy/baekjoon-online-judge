#include <iostream>
#include <string>
using namespace std;

int main() {
    string king, stone;
    int N;
    cin >> king >> stone >> N;
    while (N--) {
        string move;
        cin >> move;
        string king2(king), stone2(stone);
        if (move == "R") {
            ++king2[0];
            if (king2 == stone2) {
                ++stone2[0];
            }
        } else if (move == "L") {
            --king2[0];
            if (king2 == stone2) {
                --stone2[0];
            }
        } else if (move == "B") {
            --king2[1];
            if (king2 == stone2) {
                --stone2[1];
            }
        } else if (move == "T") {
            ++king2[1];
            if (king2 == stone2) {
                ++stone2[1];
            }
        } else if (move == "RT") {
            ++king2[0];
            ++king2[1];
            if (king2 == stone2) {
                ++stone2[0];
                ++stone2[1];
            }
        } else if (move == "LT") {
            --king2[0];
            ++king2[1];
            if (king2 == stone2) {
                --stone2[0];
                ++stone2[1];
            }
        } else if (move == "RB") {
            ++king2[0];
            --king2[1];
            if (king2 == stone2) {
                ++stone2[0];
                --stone2[1];
            }
        } else if (move == "LB") {
            --king2[0];
            --king2[1];
            if (king2 == stone2) {
                --stone2[0];
                --stone2[1];
            }
        }
        if ('A' <= king2[0] && king2[0] <= 'H' &&
            '1' <= king2[1] && king2[1] <= '8' &&
            'A' <= stone2[0] && stone2[0] <= 'H' &&
            '1' <= stone2[1] && stone2[1] <= '8') {
            king = king2;
            stone = stone2;
        }
    }
    cout << king << '\n' << stone << '\n';
    return 0;
}
