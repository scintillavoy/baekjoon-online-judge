#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, unordered_map<char, char>> m = {
        {'A', {{'A', 'A'}, {'G', 'C'}, {'C', 'A'}, {'T', 'G'}}},
        {'G', {{'A', 'C'}, {'G', 'G'}, {'C', 'T'}, {'T', 'A'}}},
        {'C', {{'A', 'A'}, {'G', 'T'}, {'C', 'C'}, {'T', 'G'}}},
        {'T', {{'A', 'G'}, {'G', 'A'}, {'C', 'G'}, {'T', 'T'}}}
    };
    int N;
    cin >> N;
    string str;
    cin >> str;
    for (int i = N - 1; i > 0; --i) {
        char a = str[i-1], b = str[i];
        str.pop_back();
        str.pop_back();
        str.push_back(m[a][b]);
    }
    cout << str;
    return 0;
}
