#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <fstream>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template<typename T>
class UnionFind {
    int size_;
    std::vector<T> par;
    std::vector<T> rank;

public:
    UnionFind(int size_) : size_(size_) {
        par.resize(size_);
        rank.resize(size_);

        for(int i=0; i<size_; i++) {
            par[i]  = i;
            rank[i] = 0;
        }
    }

    T find(T x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    void unite(T x,T y) {
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(rank[x] < rank[y]) {
            par[x] = y;
        }
        else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(T x, T y) {
        return find(x) == find(y);
    }
};

class Sunnygraphs2 {
 public:
    vector<int> G[51];
    vector<int> rG[51];
    int label[51];
    int cnt;
    int n;
    bool is_cycle[51];
    void init() {
        rep(i, 51) is_cycle[i] = false;
        rep(i, 51) label[i] = -1;
        rep(i, 51) rG[i].clear();
        rep(i, 51) G[i].clear();
        cnt = 0;
    }
    vector<int> cycle(int k) {
        vector<int> vs;
        queue<int> que;
        bool used[51] = {};
        rep(i, n) if (k == label[i]) {
            que.push(i);
            vs.push_back(i);
            break;
        }
        while (que.size()) {
            int v = que.front();
            que.pop();
            if (used[v]) {
                int t = vs.back();
                auto it = vs.begin();
                bool f = true;
                while (f) {
                    if (*it == t) f = false;
                    it = vs.erase(it);
                }
                break;
            }
            used[v] = true;
            for (auto u : G[v]) {
                // cout << v << " -> " << u << endl;
                que.push(u);
                vs.push_back(u);
            }
        }
        return vs;
    }
    long long count(vector<int> a) {
        long long ans = 0;
        n = a.size();
        init();
        UnionFind<int> uf(a.size());
        rep(i, a.size()) G[i].push_back(a[i]);
        rep(i, a.size()) rG[a[i]].push_back(i);
        rep(i,a.size()) {
            uf.unite(i, a[i]);
        }

        rep(i, a.size()) if (label[i] == -1) {
            dfs(i, -1);
            cnt++;
        }

        vector<vector<int>> vec;

        rep(k, cnt) {
            auto vs = cycle(k);
            vec.push_back(vs);
        }
        ans = 1;
        for (auto vs : vec) {
            ans *= (1LL << vs.size()) - 1;
        }
        for (auto vs : vec)
            for (auto &v : vs) is_cycle[v] = 1;

        for (auto vs : vec) {
            int t = 0;
            int v = vs.front();
            rep(i, n) {
                if(!is_cycle[i] && uf.same(v, i)) t++;
            }
            ans *= 1LL << t;
        }
        if(vec.size() == 1) ans++;

        return ans;
    }
    void dfs(int v, int p) {
        if (label[v] != -1) return;
        label[v] = cnt;
        for (auto u : G[v]) {
            if (p == u) continue;
            dfs(u, v);
        }
        for (auto u : rG[v]) {
            if (p == u) continue;
            dfs(u, v);
        }
    }
};

// CUT begin
ifstream data("Sunnygraphs2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T>
void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) { s = next_line(); }

template <typename T>
void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) { return "\"" + t + "\""; }

bool do_test(vector<int> a, long long __expected) {
    time_t startClock = clock();
    Sunnygraphs2 *instance = new Sunnygraphs2();
    long long __result = instance->count(a);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!"
             << " (" << elapsed << " seconds)" << endl;
        return true;
    } else {
        cout << "FAILED!"
             << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0) break;
        vector<int> a;
        from_stream(a);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(a, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1464621156;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs"
             << endl;
        cout << "Score  : "
             << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
             << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "Sunnygraphs2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
