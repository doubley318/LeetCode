#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isInGrassF(float px, float py, float x1, float y1, float x3, float y3)
{
    if ((x1 - px) * (x3 - px) <= 0 && (y1 - py) * (y3 - py) <= 0) {
        return true;
    } else {
        return false;
    }
}

bool isInGrassY(float px, float py, float x, float y, float r)
{
    if ((px - x) * (px - x) + (py - y) * (py - y) <= r * r) {
        return true;
    } else {
        return false;
    }
}

// 每个玩家所属的阵营和草丛；通过对所有草丛进行查询
void GetGrass(unordered_map<int, pair<pair<int, int>, unordered_set<int>>>& Play,
    const vector<vector<float>>& players, const vector<vector<float>>& grassY,
    const vector<vector<float>>& grassF)
{
    int n = players.size();
    int F = grassF.size();
    int Y = grassY.size();
    for (int i = 0; i < n; i++) {
        float px = players[i][0], py = players[i][1];
        unordered_set<int> G;
        for (int j = 0; j < F; j++) {
            // 如果在矩形里面
            if (isInGrassF(px, py, grassF[j][0], grassF[j][1], grassF[j][4], grassF[j][5])) {
                G.insert(j);
            }
        }
        for (int j = 0; j < Y; j++) {
            // 圆形
            if (isInGrassY(px, py, grassY[j][0], grassY[j][1], grassY[j][2])) {
                G.insert(j + F);
            }
        }
        Play[i + 1].second = G;
    }
}

bool InSameGrass(const unordered_set<int>& g1, const unordered_set<int>& g2)
{
    for (auto i : g1) {
        if (g2.find(i) != g2.end()) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<float>> playes(n, vector<float>(2, 0));
    vector<vector<float>> grassF;
    vector<vector<float>> grassY;
    //           玩家编号、      属性、阵营、              草丛
    unordered_map<int, pair<pair<int, int>, unordered_set<int>>> Play;
    for (int i = 0; i < n; i++) {
        cin >> playes[i][0] >> playes[i][1];
        int D, group;
        cin >> D >> group;
        pair<pair<int, int>, unordered_set<int>> tmp;
        tmp.first = { D, group };
        Play[i + 1] = tmp;
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            // 圆心和半径
            vector<float> g(3);
            cin >> g[0] >> g[1] >> g[2];
            grassY.push_back(g);
        } else {
            vector<float> g(8);
            for (int j = 0; j < 4; j++) {
                cin >> g[j * 2] >> g[j * 2 + 1];
            }
            grassF.push_back(g);
        }
    }
    // 将每个人所属的草丛记录下来，然后做查询，
    // 如果两个人所属的草丛有交集，则能看到；
    GetGrass(Play, playes, grassY, grassF);

    for (int i = 0; i < q; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        // 属性、团队、草丛
        pair<pair<int, int>, unordered_set<int>> P1 = Play[p1];
        pair<pair<int, int>, unordered_set<int>> P2 = Play[p2];
        // P2隐身、和P1不是同一个团队且P2在草丛内且与P1不是同一个草丛
        if ((P2.first.first == 1) || ((P2.first.second != P1.first.second) && (!P2.second.empty()) && (!InSameGrass(P1.second, P2.second)))) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}