#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; ++i) {
        string str;
        getline(cin, str);
        str[0] = toupper(str[0]);
        cout << str << '\n';
    }
    return 0;
}
