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

bool is_prime(ll n) {
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}

int main() {
    int N;
    cin>>N;
    if(is_prime(N)) cout<<"Prime"<<endl;
    else if(N==1||N%2==0||N%5==0||N%3==0) cout<<"Not Prime"<<endl;
    else cout<<"Prime"<<endl;
    return 0;
}

