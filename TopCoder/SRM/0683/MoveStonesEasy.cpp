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
class MoveStonesEasy {
public:
    vector<int> d;
    ll cost(int idx) {
        ll ret=0;
        rep(i,d.size()) if(idx<i) {
            if(d[idx]==0) break;
            ll t=d[idx]+d[i];
            if(d[idx]>0) {
                if(d[i]>0) continue;
                // 1=6-5
                if(t>0) {
                    ret+=abs(d[i])*(i-idx);
                    d[i]=0;
                    d[idx]=t;
                }
                // -1=6-7
                else {
                    ret+=d[idx]*(i-idx);
                    d[i]=t;
                    d[idx]=0;
                }
            }
            else {
                if(d[i]<0) continue;
                // 1=-6+7
                if(t>0) {
                    ret+=abs(d[idx])*(i-idx);
                    d[i]=t;
                    d[idx]=0;
                }
                // -1=-6+5
                else {
                    ret+=d[i]*(i-idx);
                    d[i]=0;
                    d[idx]=t;
                }
            }
        }

        return ret;
    }
    ll cost2(int idx) {
        ll ret=0;
        for(int i=d.size()-1;i>=0;i--) if(i<idx) {
            if(d[idx]==0) break;
            ll t=d[idx]+d[i];
            if(d[idx]>0) {
                if(d[i]>0) continue;
                // 1=6-5
                if(t>0) {
                    ret+=abs(d[i])*(idx-i);
                    d[i]=0;
                    d[idx]=t;
                }
                // -1=6-7
                else {
                    ret+=d[idx]*(idx-i);
                    d[i]=t;
                    d[idx]=0;
                }
            }
            else {
                if(d[i]<0) continue;
                // 1=-6+7
                if(t>0) {
                    ret+=abs(d[idx])*(idx-i);
                    d[i]=t;
                    d[idx]=0;
                }
                // -1=-6+5
                else {
                    ret+=d[i]*(idx-i);
                    d[i]=0;
                    d[idx]=t;
                }
            }
        }

        return ret;
    }
    int get(vector<int> a, vector<int> b) {
        ll s1,s2;
        s1=s2=0;
        rep(i,a.size()) s1+=a[i];
        rep(i,b.size()) s2+=b[i];
        if(s1!=s2) return -1;
        d.resize(a.size());
        rep(i,a.size()) d[i]=a[i]-b[i];
        auto ans = 0LL;
        rep(i,d.size()) {
            if(d[i]==0) continue;
            ans+=cost(i);
        }
        rep(i,a.size()) d[i]=a[i]-b[i];
        ll tmp=0;
        for(int i=d.size()-1;i>=0;i--) {
            if(d[i]==0) continue;
            tmp+=cost2(i);
        }
        ans=min(tmp,ans);

        return ans;
    }
};

// CUT begin
ifstream data("MoveStonesEasy.sample");

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

bool do_test(vector<int> a, vector<int> b, int __expected) {
    time_t startClock = clock();
    MoveStonesEasy *instance = new MoveStonesEasy();
    int __result = instance->get(a, b);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456748189;
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
        cout << "MoveStonesEasy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
