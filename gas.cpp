#include <iostream>
#include <vector>

using namespace std;

struct pipe {
    int a, b, w;
};

vector<pipe> ribs;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ways(510, -1);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        ribs.push_back({a - 1, b - 1, w});
    }
    int s, f;
    cin >> s >> f;
    s--;
    f--;
    ways[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ways[ribs[j].a] != -1 && ways[ribs[j].b] < ways[ribs[j].a] + ribs[j].w) {
                ways[ribs[j].b] = ways[ribs[j].a] + ribs[j].w;
            }
        }
    }
    if (ways[f] != -1) {
        cout << ways[f];
    } else {
        cout << "No solution";
    }

    return 0;
}
