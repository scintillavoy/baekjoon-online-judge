#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> codeToNum = {
        {"063", 0}, {"010", 1}, {"093", 2}, {"079", 3}, {"106", 4},
        {"103", 5}, {"119", 6}, {"011", 7}, {"127", 8}, {"107", 9}};
    string numToCode[10] = {"063", "010", "093", "079", "106",
                            "103", "119", "011", "127", "107"};
    string input;
    while (getline(cin, input)) {
        if (input == "BYE") {
            break;
        }
        string A, B;
        istringstream iss(input);
        getline(iss, A, '+');
        getline(iss, B, '=');
        int a = 0, b = 0;
        for (int i = 0; i < A.size(); i += 3) {
            a *= 10;
            a += codeToNum[A.substr(i, 3)];
        }
        for (int i = 0; i < B.size(); i += 3) {
            b *= 10;
            b += codeToNum[B.substr(i, 3)];
        }
        cout << input;
        string C(to_string(a + b));
        for (auto const &x : C) {
            cout << numToCode[x-'0'];
        }
        cout << '\n';
    }
    return 0;
}
