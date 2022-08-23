#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    list<int> li;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        li.push_back(num);
    }
    li.sort();
    int minVal = li.front(), maxVal = li.back();
    int sum = maxVal - minVal;
    li.pop_front();
    li.pop_back();
    while (li.size() > 1) {
        sum += maxVal - li.front();
        sum += li.back() - minVal;
        minVal = li.front();
        maxVal = li.back();
        li.pop_front();
        li.pop_back();
    }
    if (li.size() == 1) {
        sum += max(abs(li.front()-maxVal), abs(li.front()-minVal));
    }
    cout << sum;
    return 0;
}
