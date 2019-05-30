#include <iostream>
#include <vector>

using namespace std;

struct e {
    int a, b;
    double r, c;
};

vector<e> ve;
double mas[110];

int main() {
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;
    mas[s] = v;
    for (int i = 0; i < m; ++i) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        ve.push_back({a, b, rab, cab});
        ve.push_back({b, a, rba, cba});
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < ve.size(); ++j) {
            if (mas[ve[j].b] - (mas[ve[j].a] - ve[j].c) * ve[j].r < 0.000001) {
                mas[ve[j].b] = (mas[ve[j].a] - ve[j].c) * ve[j].r;
            }
        }
    }

    for (int i = 0; i < ve.size(); ++i) {
        if ((mas[ve[i].a] - ve[i].c) * ve[i].r - mas[ve[i].b]  > 0.000001) {
            cout << "YES";
            return 0;
        }
    };
    cout << "NO";
    return 0;
}
