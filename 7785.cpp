#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<string> li;
    for (int i = 0; i < n; ++i) {
        string name, commute;
        cin >> name >> commute;
        li.push_back(name);
    }
    li.sort();
    list<string> li2;
    for (auto it = li.cbegin(); it != li.cend(); ++it) {
        if (!li2.empty() && *it == li2.front()) {
            li2.pop_front();
        } else {
            li2.push_front(*it);
        }
    }
    for (auto const &x : li2) {
        cout << x << '\n';
    }
    return 0;
}
