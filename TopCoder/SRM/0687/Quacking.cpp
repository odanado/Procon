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
#include <algorithm>
#include <cassert>

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
using P = pair<int, int>;

bool used[2503];

class Quacking {
 public:
    char next(char c) {
        string s("quack");
        rep(i, s.size()) {
            if (s[i] == c) return s[(i + 1) % s.size()];
        }
        assert(false);
        return c;
    }
    int quack(string s) {
        if (s.size() % 5) return -1;
        rep(i, 2503) used[i] = false;
        auto ans = 0;
        vector<P> vec;
        cout << endl;
        rep(i, s.size()) if (!used[i] && s[i] == 'q') {
            char c = 'q';
            c = next(c);
            P p(-1, -1);
            p.first = i;
            used[i] = true;
            rep(j, s.size()) if (i < j && !used[j]) {
                if (c == 'k' && s[j] == 'k') {
                    p.second = j;
                    used[j] = true;
                    break;
                }
                if (c == s[j]) {
                    c = next(c);
                    used[j] = true;
                }
            }
            if (p.second != -1) vec.push_back(p);
        }
        if (!vec.size()) return -1;
        bool f = true;
        rep(i, s.size()) f &= used[i];
        if (!f) return -1;
        sort(all(vec),
             [](const P &p1, const P &p2) { return p1.second < p2.second; });
        // for(auto e:vec) cout<<e.first<<", "<<e.second<<endl;
        while (vec.size()) {
            auto it = vec.begin();
            ans++;
            int t = -1;
            while (it != vec.end()) {
                if (t < it->first) {
                    t = it->second;
                    it = vec.erase(it);
                } else
                    ++it;
            }
        }

        return ans;
    }
};

// CUT begin
ifstream data("Quacking.sample");

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

bool do_test(string s, int __expected) {
    time_t startClock = clock();
    Quacking *instance = new Quacking();
    int __result = instance->quack(s);
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
        string s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1460027004;
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
        cout << "Quacking (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
