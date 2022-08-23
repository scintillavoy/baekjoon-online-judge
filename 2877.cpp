#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int K;
    cin >> K;
    string answer;
    for (int i = 2; K > 0; i *= 2) {
        if ((K - 1) % i < i / 2) {
            answer.push_back('4');
        } else {
            answer.push_back('7');
        }
        K -= i;
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
    return 0;
}
