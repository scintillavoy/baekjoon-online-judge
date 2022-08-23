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
        int arr[26] = {0};
        string sentence;
        getline(cin, sentence);
        for (auto const &x : sentence) {
            if (isupper(x)) {
                ++arr[x-'A'];
            } else if (islower(x)) {
                ++arr[x-'a'];
            }
        }

        bool isPangram = true;
        for (auto const &x : arr) {
            if (x == 0) {
                isPangram = false;
                break;
            }
        }
        if (isPangram) {
            cout << "pangram\n";
        } else {
            cout << "missing ";
            for (int i = 0; i < 26; ++i) {
                if (arr[i] == 0) {
                    cout << char(i + 'a');
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
