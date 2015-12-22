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

map<string,int> prefix;

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >>setprecision(30) >> t;
}

void add_zero(string &s) {
    string zero="";
    rep(i,30) zero+="0";
    s=zero+s+zero;
}

void split(string line,string &s1,string &s2,string &s3) {
    int i;
    for(i=0;i<line.size();i++) {
        if(line[i]==' ') break;
        s1+=line[i];
    }
    i++;
    for(;i<line.size();i++) {
        if(line[i]==' ') break;
        if(line[i]=='\n') break;
        s2+=line[i];
    }
    if(i!=line.size()-1) {
        i++;
        for(;i<line.size();i++) {
            if(line[i]=='\n') break;
            s3+=line[i];
        }
    }
}

void solve() {
    int zero_cnt=0;
    string line;
    getline(cin,line);
    string s1,s2,s3;
    split(line,s1,s2,s3);
    if(s3=="") {
        s3=s2;
        s2="";
    }

    if(s1.find('.')==-1) s1+=".";
    else {
        for(int i=s1.size()-1;i>=0;i--) {
            if(s1[i]!='0') break;
            zero_cnt++;
        }
        while(s1[s1.size()-1]=='0') s1.erase(s1.size()-1,1);
    }
    int cnt=0;

    int pos=s1.find('.');
    if(s1[0]=='0') {
        for(int i=pos;i<s1.size()-1;i++) {
            cnt--;
            swap(s1[i],s1[i+1]);
        }
    }
    else {
        for(int i=pos;i>=2;i--) {
            cnt++;
            swap(s1[i],s1[i-1]);
        }
    }
    while(s1[0]=='0') s1.erase(0,1);
    if(s1[s1.size()-1]=='.') {
        if(s1.size()>zero_cnt+2) {
            cnt++;
            int t=s1.size()-1;
            swap(s1[t],s1[t-1]);
        }
        else s1.erase(s1.size()-1,1);
    }
    if(zero_cnt) {
        if(s1.find('.')==-1) s1+=".";
        rep(i,zero_cnt) s1+="0";
    }
    cout<<s1<<" * 10^"<<cnt+prefix[s2]<<" "<<s3<<endl;


}

int main() {
    prefix["yotta"] = 24;
    prefix["zetta"] = 21;
    prefix["exa"] = 18;
    prefix["peta"] = 15;
    prefix["tera"] = 12;
    prefix["giga"] = 9;
    prefix["mega"] = 6;
    prefix["kilo"] = 3;
    prefix["hecto"] = 2;
    prefix["deca"] = 1;
    prefix[""] = 0;
    prefix["deci"] = -1;
    prefix["centi"] = -2;
    prefix["milli"] = -3;
    prefix["micro"] = -6;
    prefix["nano"] = -9;
    prefix["pico"] = -12;
    prefix["femto"] = -15;
    prefix["ato"] = -18;
    prefix["zepto"] = -21;
    prefix["yocto"] = -24;
    int t;
    cin>>t;
    cin.ignore();
    while(t-->0) {
        solve();
    }
    return 0;
}

