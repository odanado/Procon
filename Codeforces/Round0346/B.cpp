#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
int n, m;
struct Result {
    string name;
    int score;
    bool operator<(const Result &rhs) const { return score > rhs.score; }
};

vector<Result> results[100005];
set<int> regs;
multiset<int> scoreSet[100005];

int main() { 
    cin>>n>>m;
    rep(i,n) {
        string s;
        int reg,score;
        cin>>s>>reg>>score;
        regs.insert(reg);
        results[reg].push_back(Result{s,score});
        scoreSet[reg].insert(score);
    }
    for(auto reg:regs) sort(all(results[reg]));

    for(auto reg:regs) {
        auto &res=results[reg];
        if(res.size() == 2) {
            cout<<res[0].name<<" "<<res[1].name<<endl;
            continue;
        }
        int top=res[0].score;
        if(scoreSet[reg].count(top) > 2) {
            cout<<"?"<<endl;
            continue;
        }
        if(scoreSet[reg].count(top) == 2) {
            cout<<res[0].name<<" "<<res[1].name<<endl;
            continue;
        }
        assert(scoreSet[reg].count(top) == 1);
        int second = res[1].score;
        if(scoreSet[reg].count(second) == 1) {
            cout<<res[0].name<<" "<<res[1].name<<endl;
            continue;
        }
        cout<<"?"<<endl;
    }

    return 0; 
}
