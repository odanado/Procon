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

int n;
bool is_prime[1003];
int main() {
    rep(i,1003) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<1003;i++) if(is_prime[i]) for(int j=i+i;j<1003;j+=i) is_prime[j]=false;
    cin>>n;
    set<int> ans;
    rep(i,n+1) if(i) if(n%i!=0) ans.insert(i);
    rep(i,n+1) if(i) if(is_prime[i]) ans.insert(i);

    int t=n;
    rep(i,1003) if(is_prime[i]&&t%i==0) t/=i;
    if(t!=1) ans.insert(n);
    cout<<ans.size()<<endl;
    auto it=ans.begin();
    while(it!=ans.end()) {
        cout<<*it;
        ++it;
        if(it==ans.end()) break;
        cout<<" ";
    }
    cout<<endl;

    return 0;
}

