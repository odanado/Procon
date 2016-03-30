#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using P = pair<int, int>;
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
using Weight = ll;
struct Edge {
    int to;
    Weight cost;
};
struct Node {
    int v;
    Node(int v) : v(v) {}
    bool operator<(const Node &rhs) const { return tie(v) < tie(rhs.v); }
};
struct State : public Node {
    Weight cost;
    State(Node node, Weight cost) : Node(node), cost(cost) {}
    bool operator<(const State &rhs) const { return cost > rhs.cost; }
};

map<Node, Weight> dijkstra(const vector<vector<Edge>> &adj, const Node &source) {
    map<Node, Weight> dist;
    priority_queue<State> que;

    que.push(State(source, 0));
    dist[source] = 0;

    while (que.size()) {
        State s = que.top();
        que.pop();
        Node cur{s.v};

        for (auto u : adj[s.v]) {
            Node next{u.to};
            if (!dist.count(next) || dist[next] > dist[cur] + u.cost) {
                dist[next] = dist[cur] + u.cost;
                que.push(State(next, dist[next]));
            }
        }
    }

    return dist;
}
int N, M, T;
int A[100005];

ll ans;

int main() {
    vector<vector<Edge>> adj, radj;
    cin >> N >> M >> T;
    rep(i, N) cin >> A[i];
    adj.resize(N);
    radj.resize(N);

    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(Edge{b, c});
        radj[b].push_back(Edge{a, c});
    }

    auto dist = dijkstra(adj, Node(0));
    auto rdist = dijkstra(radj, Node(0));

    rep(i, N) {
        Node node{i};
        //cout<<i<<": "<<dist[node]<<", "<<rdist[node]<<endl;
        if(!dist.count(node)) continue;
        if(!rdist.count(node)) continue;
        ll diff = T - dist[node] - rdist[node];
        if (diff < 0) continue;
        ans = max(ans, A[i] * diff);
    }
    cout << ans << endl;

    return 0;
}
