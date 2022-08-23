#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string sentence, word, shorten;
    getline(cin, sentence);
    istringstream iss(sentence);
    iss >> word;
    shorten.push_back(word[0] - 'a' + 'A');
    while (iss >> word) {
        if (word == "i" || word == "pa" || word == "te" || word == "ni" ||
            word == "niti" || word == "a" || word == "ali" || word == "nego" ||
            word == "no" || word == "ili") {
            continue;
        } else {
            shorten.push_back(word[0] - 'a' + 'A');
        }
    }
    cout << shorten;
    return 0;
}
