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
string s;
string tobin() {
    string res="";
    rep(i,s.size()) {
        char c = s[i];
        if(c=='0') res+="0000";
        if(c=='1') res+="0001";
        if(c=='2') res+="0010";
        if(c=='3') res+="0011";
        if(c=='4') res+="0100";
        if(c=='5') res+="0101";
        if(c=='6') res+="0110";
        if(c=='7') res+="0111";
        if(c=='8') res+="1000";
        if(c=='9') res+="1001";
        if(c=='a') res+="1010";
        if(c=='b') res+="1011";
        if(c=='c') res+="1100";
        if(c=='d') res+="1101";
        if(c=='e') res+="1110";
        if(c=='f') res+="1111";
    }
    return res;

}

void solve() {
    string bin = tobin();
    long long res=0;
    int a=1;
    for(int i=bin.size()-1;i>0;i--) {
        if(bin[i]=='1') res+=a;
        a<<=1;
    }

    if(bin[0]=='1') cout<<"-";
    if(res%128==0){
        printf("%d",res>>7);
        cout<<".0";
    }
    else {
        char buf[128];
        double t = res/128.0;
        int c=127;
        sprintf(buf,"%.10f",t);
        int m=strlen(buf);
        for(c=m-1;c>0;c--) {
            if(buf[c]!='0') break;
        }
        rep(i,c+1) cout<<buf[i];

    }
    cout<<endl;

}

int main() {
    cin>>N;
    rep(i,N) {
        cin>>s;
        solve();
    }

    return 0;
}

