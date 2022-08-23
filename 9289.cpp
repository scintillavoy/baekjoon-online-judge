#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, char> morseDecode = {
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
        {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
        {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
        {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
        {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
        {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
        {"-.--", 'Y'}, {"--..", 'Z'}
    };
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 1; i <= T; ++i) {
        string str;
        getline(cin, str);
        istringstream iss(str);
        cout << "Case " << i << ": ";
        for (string word; iss >> word; cout << morseDecode[word]);
        cout << '\n';
    }
    return 0;
}
