#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        unordered_set<int> s;
        int K;
        cin >> K;
        while (K--) {
            int num;
            cin >> num;
            s.insert(num);
        }
        int bestNum, bestRecord = 1440, numOfCertificates = 0;
        int N;
        cin >> N;
        while (N--) {
            int num, hour, minute;
            cin >> num >> hour >> minute;
            if (s.count(num) && hour != -1 && minute != -1) {
                int record = hour * 60 + minute;
                if (record <= 360) {
                    ++numOfCertificates;
                }
                if (bestRecord > record) {
                    bestRecord = record;
                    bestNum = num;
                }
            }
        }
        cout << bestNum << ' ' << numOfCertificates << '\n';
    }
    return 0;
}
