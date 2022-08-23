#include <iostream>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; ++i) {
        string nickname, word, godname = "god";
        getline(cin, nickname);
        istringstream iss(nickname);
        iss >> word;
        while (iss >> word) {
            godname += word;
        }
        cout << godname << '\n';
    }
    return 0;
}
