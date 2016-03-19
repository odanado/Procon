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
#include <queue>
#include <cstdlib>

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

template<typename T> 
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}

struct State {
    int v;
    ll cost1;
    ll cost2;
    State(int v=0,int cost1=0,int cost2=0):
        v(v),cost1(cost1),cost2(cost2){}
    bool operator<(const State &rhs) const {
        return cost1*cost2 > rhs.cost1*cost2;
        //eturn tie(cost1,cost2) > tie(rhs.cost1,rhs.cost2);
    }
    void print() {
        cout<<v<<": "<<cost1<<", "<<cost2<<endl;
    }
};


class DoubleWeights {
public:
    vector<State> G[21];
    using P=pair<ll,ll>;
    P d[21];
    ll getCost(const State &s1, const State &s2) {
        return (s1.cost1+s2.cost1)*(s2.cost1+s2.cost2);
    }
    ll getCost(const P &p1) {
        return p1.first*p1.second;
    }
    ll getCost(const P &p1, const P &p2) {
        return (p1.first+p2.first)*(p1.second+p2.second);
    }
    int minimalCost(vector<string> weight1, vector<string> weight2) {
        ll ans = INF;
        rep(i,21) d[i]=P(INF,INF);
        rep(i,weight1.size()) rep(j,weight1[i].size()) {
            if(weight1[i][j]=='.') continue;
            int cost1=weight1[i][j]-'0';
            int cost2=weight2[i][j]-'0';

            //printf("%d -> %d: %d %d\n",i,j,cost1,cost2);
            G[i].push_back(State(j,cost1, cost2));
        }
        priority_queue<State> que;
        que.push(State(0,0,0));
        d[0]=P(0,0);
        while(que.size()) {
            auto s=que.top(); que.pop();
            if(s.v==1) {
                //cout<<"aa: "<<s.cost1*s.cost2<<endl;
                ans=min(ans,s.cost1*s.cost2);
            }
            //s.print();
            for(const auto &next:G[s.v]) {
                if(getCost(d[next.v]) > getCost(d[s.v], P(next.cost1,next.cost2))) {
                //cout<<s.v<<" -> "<<next.v<<endl;
                //printf("%lld, %lld\n",d[next.v].first,d[next.v].second);
                //printf("(%lld,%lld) + (%lld,%lld)\n",d[s.v].first,d[s.v].second,next.cost1,next.cost2);
                //printf("%lld, %lld\n",getCost(d[next.v]),getCost(d[s.v],P(next.cost1,next.cost2)));
                    d[next.v].first=d[s.v].first+next.cost1;
                    d[next.v].second=d[s.v].second+next.cost2;
                    que.push(State(next.v,d[next.v].first,d[next.v].second));
                }
            }
        }

        if(ans==INF) ans=-1;
        return ans;
    }
};

// CUT begin
ifstream data("DoubleWeights.sample");

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

bool do_test(vector<string> weight1, vector<string> weight2, int __expected) {
    time_t startClock = clock();
    DoubleWeights *instance = new DoubleWeights();
    int __result = instance->minimalCost(weight1, weight2);
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
        vector<string> weight1;
        from_stream(weight1);
        vector<string> weight2;
        from_stream(weight2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(weight1, weight2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1458403949;
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
        cout << "DoubleWeights (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
