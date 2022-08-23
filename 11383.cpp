#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<char> > vec(N, vector<char>(M));
    for (auto &x : vec) {
        for (auto &y : x) {
            cin >> y;
        }
    }
    for (auto const &x : vec) {
        for (auto const &y : x) {
            char c;
            for (int i = 0; i < 2; ++i) {
                cin >> c;
                if (c != y) {
                    cout << "Not Eyfa";
                    return 0;
                }
            }
        }
    }
    cout << "Eyfa";
    return 0;
}
