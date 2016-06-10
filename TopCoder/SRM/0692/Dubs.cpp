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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Dubs {
 public:
    ll dp[20][2][2];
    ll dfs(int idx, int pre, bool f, bool f2, const string &R) {
        // printf("debug: %d %d %d %d %s\n", idx, pre, f, f2, R.c_str());
        int t = R[idx] - '0';
        if (R.size() == idx + 1) {
            if (!f2) return 0;
            if (f) {
                return 1;
            } else {
                return pre <= t;
            }
        }
        if (dp[idx][f][f2] != -1) return dp[idx][f][f2];
        int m = 10;
        ll ans = 0;
        if (!f) m = t + 1;
        rep(i, m) { ans += dfs(idx + 1, i, f || i < t, f2 || i != 0, R); }
        return dp[idx][f][f2] = ans;
    }
    string to_s(ll n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }
    long long count(long long L, long long R) {
        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        ans = dfs(0, -1, 0, 0, to_s(R));
        memset(dp, -1, sizeof(dp));
        ans -= dfs(0, -1, 0, 0, to_s(L - 1));

        return ans;
    }
};

// CUT begin
ifstream data("Dubs.sample");

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
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) { return "\"" + t + "\""; }

bool do_test(long long L, long long R, long long __expected) {
    time_t startClock = clock();
    Dubs *instance = new Dubs();
    long long __result = instance->count(L, R);
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
        long long L;
        from_stream(L);
        long long R;
        from_stream(R);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(L, R, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1465521250;
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
        cout << "Dubs (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
