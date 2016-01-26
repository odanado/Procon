#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>
#include <fstream>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
class ForbiddenStreets {
public:
    void update(int N,int d[102][102]) {
        rep(k,N) rep(i,N) rep(j,N) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    int d1[102][102];
    int d2[102][102];
    vector<int> find(int N, vector<int> A, vector<int> B, vector<int> time) {
        auto ans = vector<int>();
        ans.resize(A.size());
        rep(i,102) rep(j,102) d1[i][j]=i==j?0:INF;
        rep(i,A.size()) d1[A[i]][B[i]]=d1[B[i]][A[i]]=time[i];
        update(N,d1);
        rep(i,A.size()) {
            rep(a,102) rep(b,102) d2[a][b]=a==b?0:INF;
            rep(a,A.size()) d2[A[a]][B[a]]=d2[B[a]][A[a]]=time[a];
            d2[A[i]][B[i]]=d2[B[i]][A[i]]=INF;
            update(N,d2);
            rep(a,N) rep(b,N) if(a<b) {
                ans[i]+=d1[a][b]!=d2[a][b];
            }
        }

        return ans;
    }
};

// CUT begin
ifstream data("ForbiddenStreets.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int N, vector<int> A, vector<int> B, vector<int> time, vector<int> __expected) {
    time_t startClock = clock();
    ForbiddenStreets *instance = new ForbiddenStreets();
    vector<int> __result = instance->find(N, A, B, time);
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
        int N;
        from_stream(N);
        vector<int> A;
        from_stream(A);
        vector<int> B;
        from_stream(B);
        vector<int> time;
        from_stream(time);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, A, B, time, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1453811817;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ForbiddenStreets (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
