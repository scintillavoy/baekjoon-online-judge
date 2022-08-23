#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int cnt = input.empty() ? 0 : 1;
    for (auto const &x : input) {
        if (x == ' ') {
            ++cnt;
        }
    }
    if (input.front() == ' ') {
        --cnt;
    }
    if (input.back() == ' ') {
        --cnt;
    }
    cout << cnt;
    return 0;
}
