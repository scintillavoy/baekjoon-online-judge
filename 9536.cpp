#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (T--) {
        string recordedSound;
        getline(cin, recordedSound);
        unordered_set<string> sounds;
        while (true) {
            string collectedSound;
            getline(cin, collectedSound);
            if (collectedSound == "what does the fox say?") {
                break;
            }
            istringstream iss(collectedSound);
            string word;
            for (int i = 0; i < 3; ++i) {
                iss >> word;
            }
            sounds.insert(word);
        }
        istringstream iss(recordedSound);
        string word, WDFS;
        while (iss >> word) {
            if (!sounds.count(word)) {
                WDFS += word;
                WDFS.push_back(' ');
            }
        }
        WDFS.pop_back();
        cout << WDFS << '\n';
    }
    return 0;
}
