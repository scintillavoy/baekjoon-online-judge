#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    if (str == "Give you up" || str == "Let you down" ||
        str == "Run around and desert you" || str == "Make you cry" ||
        str == "Say goodbye" || str == "Tell a lie and hurt you") {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}
