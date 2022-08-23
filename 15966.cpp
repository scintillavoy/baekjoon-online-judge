#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int N;
    scanf("%d", &N);
    vector<int> vec(1000001);
    while (N--) {
        int a;
        scanf("%d", &a);
        vec[a] = vec[a-1] + 1;
    }
    printf("%d", *max_element(vec.begin(), vec.end()));
    return 0;
}
