#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int s;
    string n;
    cin >> s >> n;
    vector<string> vec(2*s + 3);
    for (auto const &x : n) {
        switch (x) {
            case '0':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += "|" + string(s, ' ') + "| ";
                }
                vec[s + 1] += string(s + 3, ' ');
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += "|" + string(s, ' ') + "| ";
                }
                vec[2*s + 2] += " " + string(s, '-') + "  ";
                break;
            case '1':
                vec[0] += string(s + 3, ' ');
                for (int i = 1; i <= s; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[s + 1] += string(s + 3, ' ');
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[2*s + 2] += string(s + 3, ' ');
                break;
            case '2':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[s + 1] += " " + string(s, '-') + "  ";
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += "|" + string(s + 2, ' ');
                }
                vec[2*s + 2] += " " + string(s, '-') + "  ";
                break;
            case '3':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[s + 1] += " " + string(s, '-') + "  ";
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[2*s + 2] += " " + string(s, '-') + "  ";
                break;
            case '4':
                vec[0] += string(s + 3, ' ');
                for (int i = 1; i <= s; ++i) {
                    vec[i] += "|" + string(s, ' ') + "| ";
                }
                vec[s + 1] += " " + string(s, '-') + "  ";
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[2*s + 2] += string(s + 3, ' ');
                break;
            case '5':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += "|" + string(s + 2, ' ');
                }
                vec[s + 1] += " " + string(s, '-') + "  ";
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[2*s + 2] += " " + string(s, '-') + "  ";
                break;
            case '6':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += "|" + string(s + 2, ' ');
                }
                vec[s + 1] += " " + string(s, '-') + "  ";
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += "|" + string(s, ' ') + "| ";
                }
                vec[2*s + 2] += " " + string(s, '-') + "  ";
                break;
            case '7':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[s + 1] += string(s + 3, ' ');
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[2*s + 2] += string(s + 3, ' ');
                break;
            case '8':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += "|" + string(s, ' ') + "| ";
                }
                vec[s + 1] += " " + string(s, '-') + "  ";
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += "|" + string(s, ' ') + "| ";
                }
                vec[2*s + 2] += " " + string(s, '-') + "  ";
                break;
            case '9':
                vec[0] += " " + string(s, '-') + "  ";
                for (int i = 1; i <= s; ++i) {
                    vec[i] += "|" + string(s, ' ') + "| ";
                }
                vec[s + 1] += " " + string(s, '-') + "  ";
                for (int i = s + 2; i <= 2*s + 1; ++i) {
                    vec[i] += string(s + 1, ' ') + "| ";
                }
                vec[2*s + 2] += " " + string(s, '-') + "  ";
                break;
        }
    }
    for (auto const &x : vec) {
        cout << x << '\n';
    }
    return 0;
}
