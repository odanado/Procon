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
#include <fstream>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
/*
 * 二部マッチング
 * O(|E||V|)
 *
 * http://poj.org/problem?id=3041
 */

struct BipartiteMatching {
    vector<vector<int> > G;
    vector<int> match;
    vector<bool> used;

    int V;
    BipartiteMatching(int V):V(V){
        G.resize(V);
        match.resize(V);
        used.resize(V);
    }

    void add_edge(int u,int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int v) {
        used[v]=true;
        for(int i=0;i<G[v].size();i++){
            int u=G[v][i];
            int w=match[u];
            if(w<0||(!used[w]&&dfs(w))) {
                match[v]=u;
                match[u]=v;
                return true;
            }
        }
        return false;
    }

    int operator() () {
        int res=0;
        match.assign(V,-1);
        for(int v=0;v<V;v++){
            if(match[v]<0) {
                used.assign(V,0);
                if(dfs(v)) res++;
            }
        }
        return res;
    }
};
class SegmentsAndPoints {
public:
    bool contain(int p,int l,int r) {
        return l<=p&&p<=r;
    }
    string isPossible(vector<int> p, vector<int> l, vector<int> r) {
        string ans = "Possible";
        BipartiteMatching bm(2*p.size());
        rep(i,p.size()) {
            rep(j,p.size()) {
                if(contain(p[i],l[j],r[j])) {
                    bm.add_edge(i,j+p.size());
                }
            }
        }

        int t=bm();
        if(t!=p.size()) ans="Impossible";
        return ans;
    }
};

// CUT begin
ifstream data("SegmentsAndPoints.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
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

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> p, vector<int> l, vector<int> r, string __expected) {
    time_t startClock = clock();
    SegmentsAndPoints *instance = new SegmentsAndPoints();
    string __result = instance->isPossible(p, l, r);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> p;
        from_stream(p);
        vector<int> l;
        from_stream(l);
        vector<int> r;
        from_stream(r);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, l, r, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1459213732;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "SegmentsAndPoints (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
