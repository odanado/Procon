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

P f(int N,int M) {
    if(M<2*N) return P(-1,-1);
    if(4*N<M) return P(-1,-1);
    int a=M/2;
    int c=a-N;

    a-=c*2;
    //printf("%d %d: %d %d\n",N,M,a,c);


    return P(a,c);
}
P f2(int N,int M) {
    if(M<2*N) return P(-1,-1);
    if(3*N<M) return P(-1,-1);
    int a=M/2;
    int b=a-N;

    a-=b;
    return P(a,b);
}
int N,M;
int main() {
    cin>>N>>M;
    if(M<2*N) {
        cout<<"-1 -1 -1"<<endl;
        return 0;
    }
    if(4*N<M) {
        cout<<"-1 -1 -1"<<endl;
        return 0;
    }
    int a=-1,b=-1,c=-1;
    rep(i,N+1) {
        int t=M-3*i;
        if(t<0) break;
        if(t%2==0) {
            P p=f(N-i,M-3*i);
            if(p.fr==-1&&p.sc==-1) continue;
            a=p.fr;
            b=i;
            c=p.sc;
        }
    }
    //printf("%d %d\n",a+b+c,2*a+3*b+4*c);
    printf("%d %d %d\n",a,b,c);
    return 0;
}

