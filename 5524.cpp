#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        for (auto const &x : S) {
            cout << char(tolower(x));
        }
        cout << '\n';
    }
    return 0;    
}
