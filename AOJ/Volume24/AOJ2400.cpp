#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int T,P,R;
int pena[52][12];
//解いた問題数,ペナルティ,チーム番号
pair<int,pair<int,int> > p[52];

int main() {
    while(cin>>T>>P>>R) {
        if(T+P+R==0) return 0;
        rep(i,52) {
            rep(j,12) pena[i][j]=0;
            p[i]=make_pair(0,make_pair(0,i));
        }

        rep(i,R) {
            int tID,pID,time;
            string ss;
            cin>>tID>>pID>>time>>ss;
            if(ss == "CORRECT") {
                p[tID].first--;
                p[tID].second.first += (pena[tID][pID]*1200+time);
                p[tID].second.second = tID;
            }
            else {
                pena[tID][pID]++;
            }
        }

        sort(p+1,p+T+1);

        rep(i,T+1) {
            if(!i) continue;
            cout<<p[i].second.second<<" "<<-p[i].first<<" "<<p[i].second.first<<endl;
        }

    }
    return 0;
}
