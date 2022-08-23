#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    int N;
    string input;
    vector<string> word;
    cin >> N >> input;

    // Split input into words
    word.emplace_back(1, tolower(input[0]));
    for (int i = 1; i < input.size(); ++i) {
        switch (N) {
            case 1:
            case 3:
                if (isupper(input[i])) {
                    word.emplace_back(1, tolower(input[i]));
                } else {
                    word.back().push_back(input[i]);
                }
                break;
            case 2:
                if (input[i] == '_') {
                    word.emplace_back(1, input[++i]);
                } else {
                    word.back().push_back(input[i]);
                }
                break;
        }
    }
    
    // Print in camel case
    cout << word[0];
    for (int i = 1; i < word.size(); ++i) {
        string temp = word[i];
        temp[0] = toupper(temp[0]);
        cout << temp;
    }
    cout << '\n';

    // Print in snake case
    cout << word[0];
    for (int i = 1; i < word.size(); ++i) {
        cout << '_' << word[i];
    }
    cout << '\n';

    // Print in pascal case
    for (int i = 0; i < word.size(); ++i) {
        string temp = word[i];
        temp[0] = toupper(temp[0]);
        cout << temp;
    }
    cout << '\n';
    return 0;
}
