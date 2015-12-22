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

typedef string::const_iterator State;
string s;

// mmemewwemeww
void cat(State &begin) {
    if(*begin=='m') {
        begin++;
        cat(begin);
        if(*begin=='e') {
            begin++;
            cat(begin);
            if(*begin=='w') begin++;
        }
    }

}

int main() {
    cin>>s;
    s+="$";
    State begin=s.begin();
    cat(begin);

    string ans;
    if(*begin=='$') ans="Cat";
    else ans="Rabbit";
    cout<<ans<<endl;
    return 0;
}

