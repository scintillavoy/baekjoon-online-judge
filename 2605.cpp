#include <iostream>
#include <list>
using namespace std;

int main() {
    int numOfStudents;
    cin >> numOfStudents;
    list<int> li;
    for (int i = 1; i <= numOfStudents; ++i) {
        int num;
        cin >> num;
        auto it = li.end();
        while (num--) {
            --it;
        }
        li.insert(it, i);
    }
    for (auto const &x : li) {
        cout << x << ' ';
    }
    return 0;
}
