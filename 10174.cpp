#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (n--) {
        string str;
        getline(cin, str);
        bool check = true;
        for (int i = 0; i < str.size() / 2; ++i) {
            if (tolower(str[i]) != tolower(str[str.size()-i-1])) {
                check = false;
                break;
            }
        }
        cout << (check ? "Yes" : "No") << '\n';
    }
    return 0;
}
