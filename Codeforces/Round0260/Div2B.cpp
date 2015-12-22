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

string n;
int mod1[] = {1,1,1,1};
int mod2[] = {1,2,4,3};
int mod3[] = {1,3,4,2};
int mod4[] = {1,4,1,4};
int f(int a) {
    int ret = 0;
    ret += 1;
    ret %= 5;
    ret += pow(2,a);
    ret %= 5;
    ret += pow(3,a);
    ret %= 5;
    ret += pow(4,a);
    ret %= 5;
    cout<<ret%5<<endl;
}
int main() {
    cin>>n;
    int m = n[n.size()-1]-'0';
    int a = n.size();
    if(a-2>=0) {
        m += (n[n.size()-2]-'0')*2;
    }
    m %= 4;
    int ans = mod1[m]+mod2[m]+mod3[m]+mod4[m];
    ans %= 5;
    cout<<ans<<endl;
    return 0;
}

