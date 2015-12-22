#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int n;
int w[53];

vector<int> vec;

int main() {
	cin>>n;
	int ans=0;
	rep(i,n) cin>>w[i];
	//sort(w,w+n, greater<int>());
	vec.push_back(100007);
	rep(i,n) {
		int index=0;
		int tmp=100007;
		rep(j,vec.size()) {
			//printf("[debug] %d %d:%d\n",w[i],j,vec[j]);
			if(w[i]<=vec[j] && vec[j]-w[i] < tmp) {
				index=j;
				tmp = vec[j]-w[i];
			}
		}
		
		if(tmp!=100007)
			vec[index]=w[i];
		else 
			vec.push_back(w[i]);
	}

	cout<<vec.size()<<endl;


	return 0;
}

/* 2014/04/23 AC */