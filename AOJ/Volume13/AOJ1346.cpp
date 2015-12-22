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

int func1(string line) {
    int res=0;
    rep(i,line.size()) {
        if(i==0) res=line[0]-'0';
        else if(i%2==1) {
            if(line[i]=='+') {
                res+=line[i+1]-'0';
            }
            else {
                res*=line[i+1]-'0';
            }
            i++;
        }
    }
    return res;
}
template<class T>
string to_s(T x) {
    stringstream ss;
    ss<<x;
    return ss.str();
}
int to_i(string s) {
    int res;
    stringstream ss;
    ss<<s;
    ss>>res;
    return res;
}
int func2(string line) {
    vector<string> vec;
    set<int> S;
    bool f[20]={};
    rep(i,line.size()) {
        if(line[i]=='*') {
            f[i-1]=1;
            f[i]=1;
            f[i+1]=1;
        }
    }
    int x=1,idx=0;
    while(idx<20) {
        while(!f[idx]&&idx!=20) idx++;
        if(idx==20) break;
        while(f[idx]) {
            if(isdigit(line[idx])) {
                x*=(line[idx]-'0');
                S.insert(idx);
            }
            idx++;
        }
        vec.pb(to_s(x));
        x=1;
    }

    rep(i,line.size()) {
        if(!S.count(i)) {
            if(line[i]!='+'&&line[i]!='*') vec.pb(to_s(line[i]));
        }
    }
    int res=0;
    rep(i,vec.size()) res+=to_i(vec[i]);
    return res;
}
string line;
int x;
int main() {
    cin>>line;
    cin>>x;
    int x1=func1(line);
    int x2=func2(line);

    if(x==x1&&x==x2) {
        cout<<"U"<<endl;
    }
    else if(x==x1) {
        cout<<"L"<<endl;
    }
    else if(x==x2) {
        cout<<"M"<<endl;
    }
    else {
        cout<<"I"<<endl;
    }
    
    return 0;
}

