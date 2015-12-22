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

template<class T, int N=100000>
class Queue {
private:
    T ary[N];
    int head,tail;
public:
    Queue() : head(0),tail(0) {}
    bool is_empty() {
        return head == tail;
    }
    void enqueue(T x) {
        ary[tail++] = x;
        tail %= N;
    }
    T dequeue() {
        T x = ary[head++];
        head %= N;
        return x;
    }
};

struct Job {
    string name;
    int time;
};
Job job[100005];
int main() {
    int n,q;
    cin>>n>>q;
    rep(i,n) cin>>job[i].name>>job[i].time;
    Queue<Job> que;
    rep(i,n) que.enqueue(job[i]);
    int total = 0;
    while(!que.is_empty()) {
        Job t = que.dequeue();
        total += min(t.time,q);
        t.time -= q;
        if(t.time > 0) {
            que.enqueue(t);
        }
        else {
            cout<<t.name<<" "<<total<<endl;
        }
    }
    return 0;
}

