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

int N,D,K;
int L[10004],R[10004];
int S[1003],T[1003];

bool is_included(int l,int r,int a) {
    return l<=a&&a<=r;
}

void merge(int i,int &l,int &r) {
    // cout<<L[i]<<","<<R[i]<<" : "<<l<<","<<r<<endl;
    if(!(l>R[i]||r<L[i])) {
        l=min(l,L[i]);
        r=max(r,R[i]);
        // cout<<"merged "<<L[i]<<","<<R[i]<<" : "<<l<<","<<r<<endl;
    }
}

int solve(int idx) {
    int l,r;
    bool f=false;
    rep(i,D) {
        if(!f&& is_included(L[i],R[i],S[idx])) {
            f=true;
            l=L[i];
            r=R[i];
        }
        if(f) {
            merge(i,l,r);
            if(is_included(l,r,T[idx])) return i+1;
        }
    }

    return -1;
}

int main() {
    cin>>N>>D>>K;
    rep(i,D) cin>>L[i]>>R[i];
    rep(i,K) cin>>S[i]>>T[i];

    rep(i,K) {
        cout<<solve(i)<<endl;
    }



    return 0;
}

