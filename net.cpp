#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct wire {
    int a, b, l;
};

int r[1010], t[1010];
int mx = 0;

bool comparator(wire a, wire b) {
    return a.l < b.l;
}

int find(int x) {
    if (x != t[x]) t[x] = find(t[x]);
    return t[x];
}

int main() {
    int n, m;

    cin >> n >> m;
    vector<wire> wires;

    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        wires.push_back({a - 1, b - 1, l});
    }

    sort(wires.begin(), wires.end(), comparator);

    for (int i = 1; i <= n; i++) {
        r[i] = 0;
        t[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int n1 = wires[i].a;
        int n2 = wires[i].b;

        if (find(n1) != find(n2)) {
            if (wires[i].l > mx) {
                mx = wires[i].l;
            }
            wires[i].l *= -1;

            int x = find(n1);
            int y = find(n2);
            if (r[x] > r[y]) t[y] = x;
            else {
                t[x] = y;
                if (r[x] == r[y]) r[y]++;
            }
        }
    }

    cout << mx << "\n" << n - 1 << "\n";

    for (int j = 0; j < m; ++j){
        if (wires[j].l < 0){
            cout << wires[j].a + 1 << " " << wires[j].b + 1 << "\n";
        }
    }
    return 0;
}
