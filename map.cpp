#include <iostream>
#include <cstdlib> 
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int colors[100];
vector<int> mappa[100];
int n;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    colors[st] = 0;

    while (!q.empty()) {
        int start = q.front();
        q.pop();
        for (int i = 0; i < mappa[start].size(); ++i) {
            int finish = mappa[start][i];
            if (colors[start] == colors[finish]) {
                cout << "-1";
                exit(0);
            }
            if (colors[finish] == -1) {
                colors[finish] = colors[start] == 0 ? 1 : 0;
                q.push(finish);
            }
        }
    }
}

int main(){
    cin >> n;

    fill_n(colors, 100, -1); // -1-empty, 0-red, 1-blue

    for (int i = 0; i < n; ++i) {
        int road = -1;
        while (road != 0) {
            cin >> road;
            if (road != 0) {
                mappa[i].push_back(road - 1);
                mappa[road - 1].push_back(i);
            }
        }
    }

    bfs(0);
	for(int i = 0; i < n; ++i){
        std::cout << colors[i];
    }
    return 0;
}
