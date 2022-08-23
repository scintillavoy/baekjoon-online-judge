#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    string answer;
    int maxNum = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        while (num > maxNum) {
            ++maxNum;
            s.push(maxNum);
            answer.push_back('+');
        }
        if (s.top() == num) {
            s.pop();
            answer.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (auto const &x : answer) {
        cout << x << '\n';
    }
    return 0;
}
