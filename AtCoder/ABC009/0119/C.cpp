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

int diff(const string &s1,const string &s2) {
    //cout<<"diff: " << s1 << ", " << s2 << endl;
    int cnt1[26]={};
    int cnt2[26]={};
    rep(i,s1.size()) cnt1[s1[i]-'a']++;
    rep(i,s2.size()) cnt2[s2[i]-'a']++;
    int ret=0;
    rep(i,26) ret+=abs(cnt1[i]-cnt2[i]);
    return ret/2;
}

int diff(multiset<char> S, multiset<char> unused,char c) {
    string s1,s2;
    unused.erase(unused.find(c));
    for(auto e:unused) s2+=e;
    for(auto e:S) s1+=e;
    return diff(s1,s2);
}
int N,K;
string S,ans;
multiset<char> unused;
int main() {
    cin>>N>>K;
    cin>>S;
    rep(i,N) unused.insert(S[i]);

    auto tmp=unused;
    rep(i,N) {
        char c;
        //cout<<i<<"="<<S[i]<<": "<<S<<endl;
        tmp.erase(tmp.find(S[i]));
        for(auto t:unused) {
            c=t;

            int a=diff(tmp, unused, t);
            a+=t!=S[i];
            //printf("[debug] %d %c:  %d\n",i,t,a);
            if(K-a>=0) {
                if(t!=S[i]) K-=1;
                break;
            }
        }
        //cout<<endl;
        unused.erase(unused.find(c));
        ans+=c;
    }
    cout<<ans<<endl;

    return 0;
}

