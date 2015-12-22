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

struct Dice {
    int top,front;
    int right;

    Dice(int top,int front) : top(top),front(front) {
        map<P,int> tmp;
        bool f[6]={};
        f[top]=true;
        f[front]=true;
        f[7-top]=true;
        f[7-front]=true;
        vector<int> vec;
        rep(i,6) if(!f[i]) vec.pb(i);
    
        sort(all(vec));

        if(top<front) right=vec[1];
        else right=vec[0];
    }

    void rote1() {
        int tmp=top;
        top=7-front;
        front=tmp;
    }
    void rote2() {
        int tmp=top;
        top=7-right;
        right=tmp;
    }

    void print() {
        printf("top = %d, front = %d, right = %d\n",top,front,right);

    }

};

int main() {
    return 0;
}

