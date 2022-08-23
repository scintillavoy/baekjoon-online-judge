#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i) {
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

        bool isPangram = true, isDoublePangram = true, isTriplePangram = true;
        for (auto const &x : arr) {
            switch (x) {
                case 0:
                    isPangram = false;
                case 1:
                    isDoublePangram = false;
                case 2:
                    isTriplePangram = false;
                    break;
            }
        }
        cout << "Case " << i + 1 << ": ";
        if (isTriplePangram) {
            cout << "Triple pangram!!!\n";
        } else if (isDoublePangram) {
            cout << "Double pangram!!\n";
        } else if (isPangram) {
            cout << "Pangram!\n";
        } else {
            cout << "Not a pangram\n";
        }
    }
    return 0;
}
