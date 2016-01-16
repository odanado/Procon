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

int N;
int K[20];
bool ok(int used, int i,int j,int k) {
    if(used>>i&1) return false;
    if(used>>j&1) return false;
    if(used>>k&1) return false;

    return true;
}

bool isKado(int i,int j,int k) {
    if(K[i]==K[j]) return false;
    if(K[j]==K[k]) return false;
    if(K[k]==K[i]) return false;
    vector<int> vec;
    vec.pb(K[i]);
    vec.pb(K[j]);
    vec.pb(K[k]);
    sort(all(vec));
    return vec[1]==K[i] || vec[1]==K[k];
}
string dump_bit(int S) {
    string ret;
    while(S) {
        if(S&1) ret+="1";
        else ret += "0";
        S>>=1;
    }

    return ret;
}
bool dfs(int used,int a) {
    bool ret;
    ret=false;
    bool f=false;
    rep(i,N) rep(j,N) rep(k,N) if(i<j && j<k) if(ok(used,i,j,k)) if(isKado(i,j,k)) {
        if(a%2==1) ret|=!dfs(used|(1<<i)|(1<<j)|(1<<k),a+1);
        else ret|=dfs(used|(1<<i)|(1<<j)|(1<<k),a+1);
        f=true;
    }
    if(!f) ret=a%2;
    else if(a%2==1) ret=!ret;
    //if(a<=2) cout<<string(a,' ')<<"debug: " << dump_bit(used) << ", "<< a<<": "<<ret<<endl;

    return ret;
}
int main() {
    cin>>N;
    rep(i,N) cin>>K[i];
    rep(i,N) rep(j,N) rep(k,N) if(i<j && j<k) if(isKado(i,j,k)) {
        int used = (1<<i) | (1<<j) | (1<<k);
        //printf("%d %d %d\n",i,j,k);
        if(dfs(used,1)) {
            printf("%d %d %d\n",i,j,k);
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}

