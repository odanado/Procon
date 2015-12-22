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

int h,w,n;
char initField[51][51];
char field[51][51];
int cnt=0;
bool del[51][51];

bool search(){
	int sum=0;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(field[i][j]!='.')sum++;
	while(sum){
		// ????????
		for(int j=0;j<w;j++){
			for(int i=h-2;i>=0;i--){
				if(field[i][j]!='.'){
					char ch=field[i][j];
					field[i][j]='.';
					for(int k=i;k<h;k++){
						if(k+1==h||field[k+1][j]!='.'){
							field[k][j]=ch;
							break;
						}
					}
				}
			}
		}
        rep(y,h) {
            rep(x,w) {
                cout<<field[y][x];
            }
            cout<<endl;
        }
        cout<<endl;
		memset(del,0,sizeof(del));
		int dec=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(field[i][j]=='.')continue;
				// tate
				int cnt=0;
				for(int k=i;k<h;k++){
					if(field[i][j]==field[k][j])cnt++;
					else break;
				}
				if(cnt>=n){
					for(int k=i;k<h;k++){
						if(field[i][j]==field[k][j])del[k][j]=true;
						else break;
					}
				}
				// yoko
				cnt=0;
				for(int k=j;k<w;k++){
					if(field[i][j]==field[i][k])cnt++;
					else break;
				}
				if(cnt>=n){
					for(int k=j;k<w;k++){
						if(field[i][j]==field[i][k])del[i][k]=true;
						else break;
					}
				}
			}
		}
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(del[i][j])field[i][j]='.',dec++;
		if(dec==0)return false;
		sum-=dec;
	}
	return true;
}

int main(){

	cin>>h>>w>>n;
	bool ok=false;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>initField[i][j];
	for(int i=0;i<h;i++){
		for(int j=0;j<w-1;j++){
			for(int k=0;k<h;k++)for(int l=0;l<w;l++)field[k][l]=initField[k][l];
            if(!(i==8&&j==2)) continue;
			cnt++;
			swap(field[i][j],field[i][j+1]);
			ok|=search();
			if(ok) {
                cout<<i<<","<<j<<endl;
                cout<<initField[i][j]<<endl;
                break;
            }
		}
		if(ok)break;
	}
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
