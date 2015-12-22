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
 
int N,M,D;
int A[200005];
vector<int> amida;
 
void mul(vector<int> &vec1,const vector<int> &vec2) {
    vector<int> tmp(vec2.size());
    //rep(i,vec2.size()) cout<<vec2[i]<<endl;
    rep(i,vec2.size()) {
        //cout<<vec2[i]<<endl;
        tmp[vec2[i]]=vec1[i];
    }
    vec1=tmp;
}
 
int main() {
    cin>>N>>M>>D;
    amida.resize(N);
    rep(i,N) amida[i]=i;
    if(D>1000) return 0;
    rep(i,M) cin>>A[i];
    rep(i,M) A[i]--;
    rep(i,M) {
        int t1=A[i];
        int t2=A[i] + 1;
        swap(amida[t1],amida[t2]);
    }
    vector<int> t(N);
    vector<int> e(N);
    rep(i,N) e[i]=t[i]=i;
    vector<int> ans(N);
    int k=0;
    rep(i,D) {
        mul(t,amida);
        if(t==e) {
            k=i;
            break;
        }
    }
    //cout<<"k = "<<k<<endl;
    rep(i,N) t[i]=i;
    if(D%k==0)
        rep(i,k) mul(t,amida);
    else 
        rep(i,D%k) mul(t,amida);
    //rep(i,D) mul(t,amida);
    rep(i,N) cout<<t[i]+1<<endl;
    
    return 0;
}
