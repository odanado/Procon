#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct edge
{
public:
	int to;
	double cost;
	edge(int to,double cost) {
		this->to = to;
		this->cost = cost;
	}
};

struct Point
{
public:
	int x,y;
	int t,r;
	Point(int x,int y,int t,int r) {
		this->x = x;
		this->y = y;
		this->t = t;
		this->r = r;
	}
};

double dist(int x1,int y1,int x2,int y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int n;

vector<edge> G[1007];
vector<Point> P;

int main() {
	cin>>n;

	rep(i,n) {
		int x,y,t,r;
		cin>>x>>y>>t>>r;
		P.push_back(Point(x,y,t,r));
	}
	rep(i,P.size()) {
		rep(j,P.size()) {
			if(i==j) continue;
			
			G[i].push_back(edge(j, dist(P[i].x,P[i].y,P[j].x,P[j].y) /(1.0 * min(P[i].t,P[j].r))));
			G[j].push_back(edge(i, dist(P[i].x,P[i].y,P[j].x,P[j].y) /(1.0 * min(P[j].t,P[i].r))));

		}
	}

	return 0;
}