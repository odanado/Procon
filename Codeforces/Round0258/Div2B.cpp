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

const int INF=1000000010;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int n;
int a[100005];
int main() {
    cin>>n;
    rep(i,n) cin>>a[i];
    a[n]=INF;
    int ansL=-1,ansR=-1;
    int cnt=0;
    int f=false;

    rep(i,n) {
        if(a[i]>a[i+1] && !f) {
            ansL=i;
            f=true;
        }
        if(a[i]<a[i+1] && f) {
            ansR=i;
            cnt++;
            f=false;
        }
    }
    if(cnt>=2) {
        cout<<"no"<<endl;
        return 0;
    }
    if(cnt==0) {
        cout<<"yes"<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    reverse(a+ansL,a+ansR+1);
    if(!is_sorted(a,a+n)) {
        cout<<"no"<<endl;
        return 0;
    }

    cout<<"yes"<<endl;
    cout<<ansL+1<<" "<<ansR+1<<endl;
    

    return 0;
}

