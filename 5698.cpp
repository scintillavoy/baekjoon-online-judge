#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "*") {
            break;
        }
        istringstream iss(line);
        string curr, prev;
        iss >> prev;
        bool isTautogram = true;
        while (iss >> curr) {
            if (tolower(curr.front()) != tolower(prev.front())) {
                isTautogram = false;
                break;
            }
        }
        cout << (isTautogram ? 'Y' : 'N') << '\n';
    }
    return 0;
}
