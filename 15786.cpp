#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    cout << boolalpha;
    while (M--) {
        string S2;
        cin >> S2;
        bool check = false;
        for (int i = 0, j = 0; j < S2.size(); ++j) {
            if (S[i] == S2[j]) {
                if (++i == S.size()) {
                    check = true;
                    break;
                }
            }
        }
        cout << check << '\n';
    }
    return 0;
}
