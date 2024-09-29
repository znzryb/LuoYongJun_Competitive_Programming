#include <iostream>
#include <deque>
#include <bitset>
using namespace std;
int n,k,T;
deque<pair<int,int> > q;
bitset<1000007> vis;
bool ok(int dis) {      // ok函数确保不会RE
    if(dis<=1000000 && dis>=0)   return true;
    return false;
}
void bfs() {
    q.push_back(make_pair(n,0)),vis[n]=true;
    while (!q.empty()) {
        int step=q.front().second,dis=q.front().first;
        q.pop_front();
        if(dis==k) {
            cout<<step<<endl;
            break;
        }
        if(dis>k) {
            if(!vis[dis-1])
                q.push_back(make_pair(dis-1,step+1)),vis[dis-1]=true;
        }else {
            if(ok(dis-1) && !vis[dis-1]) q.push_back(make_pair(dis-1,step+1)),vis[dis-1]=true;
            if(ok(dis+1) && !vis[dis+1]) q.push_back(make_pair(dis+1,step+1)),vis[dis+1]=true;
            if(ok(dis*2) && !vis[dis*2]) q.push_back(make_pair(dis*2,step+1)),vis[dis*2]=true;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    for(int _=1;_<=T;_++) {
        cin>>n>>k;
        vis.reset();
        bfs();
        q.clear();   // 一定要记得清空队列
    }
    return 0;
}
// MLE https://vjudge.net/solution/54577777
// WA http://vjudge.net/solution/54577984
// 0 pts https://www.luogu.com.cn/record/178987235
// AC https://www.luogu.com.cn/record/178995633     记得清空队列
// AC http://vjudge.net/solution/54579232