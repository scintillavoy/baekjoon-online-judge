#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int A, B, G;
    cin >> A >> B >> G;

    unordered_map<string, int> players;
    string name;
    while (A--) {
        cin >> name;
        players.emplace(name, 1);
    }
    while (B--) {
        cin >> name;
        players.emplace(name, -1);
    }

    int score = 0;
    while (G--) {
        cin >> name;
        score += players[name];
    }

    if (score > 0) {
        cout << 'A';
    } else if (score < 0) {
        cout << 'B';
    } else {
        cout << "TIE";
    }
    cout << '\n';
    return 0;
}
