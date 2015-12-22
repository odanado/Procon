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

string s1,s2,s3;
int t1['Z'+10];
int t2['Z'+10];
int t3['Z'+10];
int a1['Z'+10];
int a2['Z'+10];

int N;
int ok(int ary1[],int ary2[]) {
    for(int i='A';i<='Z';i++) {
        if(ary1[i]<ary2[i]) return false;
    }
    return true;
}

void hoge() {

    for(int i='A';i<='Z';i++) if(a1[i]!=0) cout<<((char)i)<<":"<<a1[i]<<endl;
    cout<<endl;
    for(int i='A';i<='Z';i++) if(a2[i]!=0) cout<<((char)i)<<":"<<a2[i]<<endl;
    cout<<endl;
    cout<<endl;
}
int main() {
    cin>>s1>>s2>>s3;

    sort(all(s3));

    rep(i,s1.size()) t1[s1[i]]++;
    rep(i,s2.size()) t2[s2[i]]++;
    rep(i,s3.size()) t3[s3[i]]++;
    rep(i,26) {
        if(t1[i+'A']+t2[i+'A']<t3[i+'A']) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    N=s3.size()/2;

    rep(i,N) a1[s3[i]]++;
    for(int i=N;i<s3.size();i++) a2[s3[i]]++;
    s3 = s3+s3;

    rep(i,N+N) {
        // hoge();
        if(ok(t1,a1)&&ok(t2,a2)) {
            cout<<"YES"<<endl;
            return 0;
        }
        if(ok(t2,a1)&&ok(t1,a2)) {
            cout<<"YES"<<endl;
            return 0;
        }
        a1[s3[i]]--;
        a1[s3[i+s3.size()/2]]++;
        a2[s3[i]]++;
        a2[s3[i+s3.size()/2]]--;
    }

    cout<<"NO"<<endl;
    /*
    rep(i,s3.size()/2) {
        string ss1 = s3.substr(i,s3.size()/2);
        string ss2 = s3.substr(0,i)+s3.substr(i+s3.size()/2);
        cout<<ss1<<","<<ss2<<endl;

    }
    */
    return 0;
}

