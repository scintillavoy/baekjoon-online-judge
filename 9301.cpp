#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> grid(N, vector<char>(N, '.'));
        while (M--) {
            string type;
            int X, Y, W, H;
            char color;
            cin >> type >> X >> Y >> W >> H >> color;
            if (type == "Filled") {
                for (int y = N-Y; y > N-Y-H; --y) {
                    for (int x = X-1; x < X-1+W; ++x) {
                        grid[y][x] = color;
                    }
                }
            } else if (type == "Empty") {
                for (int x = X-1; x < X-1+W; ++x) {
                    grid[N-Y][x] = color;
                    grid[N-Y-H+1][x] = color;
                }
                for (int y = N-Y; y > N-Y-H; --y) {
                    grid[y][X-1] = color;
                    grid[y][X-2+W] = color;
                }
            }
        }
        cout << "Case " << i << ":\n";
        for (auto const &row : grid) {
            for (auto const &pixel : row) {
                cout << pixel;
            }
            cout << '\n';
        }
    }
    return 0;
}
