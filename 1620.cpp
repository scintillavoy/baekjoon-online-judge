#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<string> vec(N);
    unordered_map<string, int> m;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        vec[i] = name;
        m[name] = i;
    }
    for (int i = 0; i < M; ++i) {
        string question;
        cin >> question;
        if (isalpha(question[0])) {
            cout << m[question] + 1;
        } else {
            cout << vec[stoi(question) - 1];
        }
        cout << '\n';
    }
    return 0;
}
