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

const int INF=1000000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int n;
string a[1003];

ll toi(string s) {
    ll res;
    stringstream ss;
    ss<<s;
    ss>>res;
    return res;
}

void solve() {
    ll l=-INF*2,r=INF*2;
    rep(i,n) cin>>a[i];

    rep(i,n) {
        if(i!=0 && a[i-1]=="x"&&a[i]=="x") {
            cout<<"none"<<endl;
            return;
        }
        if(i&1) {
            if(i+1<n && a[i+1]!="x") {
                if(a[i]=="x") l=max(l,toi(a[i+1]));
                if(a[i]!="x") {
                    if(toi(a[i])<=toi(a[i+1])) {
                        cout<<"none"<<endl;
                        return;
                    }
                }
            }
            if(i-1>=0 && a[i-1]!="x") {
                if(a[i]=="x") l=max(l,toi(a[i-1]));
                if(a[i]!="x") {
                    if(toi(a[i])<=toi(a[i-1])) {
                        cout<<"none"<<endl;
                        return;
                    }
                }
            }
        }
        else {
            if(i+1<n && a[i+1]!="x") {
                if(a[i]=="x") r=min(r,toi(a[i+1]));
                if(a[i]!="x") {
                    if(toi(a[i])>=toi(a[i+1])) {
                        cout<<"none"<<endl;
                        return;
                    }
                }
            }
            if(i-1>=0 && a[i-1]!="x") {
                if(a[i]=="x") r=min(r,toi(a[i-1]));
                if(a[i]!="x") {
                    if(toi(a[i])>=toi(a[i-1])) {
                        cout<<"none"<<endl;
                        return;
                    }
                }
            }
        }
    }
    // cout<<l<<","<<r<<endl;
    //cout<<r-l<<endl;
    
    if(r-l>2) {
        cout<<"ambiguous"<<endl;
    }
    else if(r-l<2) {
        cout<<"none"<<endl;
    }
    else {
        cout<<l+1<<endl;
    }




}

int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

