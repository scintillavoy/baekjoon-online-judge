#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string idxToSpecies[4] = {"Bobcat", "Coyote", "Mountain Lion", "Wolf"};
    while (n--) {
        string location, species;
        cin >> location >> species;
        int cnt[4] = {0};
        for (auto const &x : species) {
            switch (x) {
                case 'B':
                    ++cnt[0];
                    break;
                case 'C':
                    ++cnt[1];
                    break;
                case 'M':
                    ++cnt[2];
                    break;
                case 'W':
                    ++cnt[3];
                    break;
            }
        }
        cnt[0] *= 2;
        cnt[2] *= 4;
        cnt[3] *= 3;
        int maxIdx = 0;
        bool check = true;
        for (int i = 1; i < 4; ++i) {
            if (cnt[maxIdx] < cnt[i]) {
                maxIdx = i;
                check = true;
            } else if (cnt[maxIdx] == cnt[i]) {
                check = false;
            }
        }
        cout << location << ": ";
        if (check) {
            cout << "The " << idxToSpecies[maxIdx];
            cout << " is the dominant species";
        } else {
            cout << "There is no dominant species";
        }
        cout << '\n';
    }
    return 0;
}
