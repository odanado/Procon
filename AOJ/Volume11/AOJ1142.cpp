#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<string>
 
 
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;
const int INF = 100000000;
const double EPS = 0.0000001;
typedef pair<int,int> P;

void solve() {
	string ss;
	cin>>ss;

	vector<string> vec;

	for(int i=1;i<ss.size();i++) {
		string ss1 = ss.substr(0,i);
		string ss2 = ss.substr(i,ss.size());

		rep(i,2) {
			
			reverse(ss1.begin(),ss1.end());
			vec.push_back(ss1+ss2);

			reverse(ss2.begin(),ss2.end());
			vec.push_back(ss1+ss2);
		
			reverse(ss1.begin(),ss1.end());
			vec.push_back(ss1+ss2);
		
			reverse(ss2.begin(),ss2.end());
			vec.push_back(ss1+ss2);

			string tmp = ss1;
			ss1 = ss2;
			ss2 = tmp;
		}
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(), vec.end()) ,vec.end());
	cout<<vec.size()<<endl;
}

int main() {
	int m;
	cin>>m;
	rep(i,m) solve();
	return 0;
}