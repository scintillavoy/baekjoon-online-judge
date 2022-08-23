#include <iostream>
#include <string>
using namespace std;

int main() {
    string target;
    int N, cnt = 0;
    cin >> target >> N;
    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        input += input;
        if (input.find(target) != string::npos) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
