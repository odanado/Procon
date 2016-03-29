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

class TreeAndVertex {
public:
    bool used[101];
    vector<int> G[101];
    void dfs(int u,int ignore) {
        for(auto v:G[u]) {
            if(u==v) continue;
            if(ignore==v) continue;
            if(used[v]) continue;
            used[v]=true;
            dfs(v,ignore);
        }
    }
    int get(vector<int> tree) {
        auto ans = 0;
        rep(i,tree.size()) {
            G[i+1].push_back(tree[i]);
            G[tree[i]].push_back(i+1);
        }

        rep(i,tree.size()+1) {
            rep(i,101) used[i]=false;
            used[i]=true;
            int cnt=0;
            rep(j,tree.size()+1) if(!used[j]) {
                dfs(j,i);
                cnt++;
            }
            ans=max(ans,cnt);
        }

        return ans;
    }
};

// CUT begin
ifstream data("TreeAndVertex.sample");

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

bool do_test(vector<int> tree, int __expected) {
    time_t startClock = clock();
    TreeAndVertex *instance = new TreeAndVertex();
    int __result = instance->get(tree);
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
        vector<int> tree;
        from_stream(tree);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(tree, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1459213204;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TreeAndVertex (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
