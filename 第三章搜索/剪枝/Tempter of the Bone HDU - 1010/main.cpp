// 这题看起来是bfs，实际上是dfs
#include <iostream>
#include <cmath>
using namespace std;
int n,m,open_t,x,y,dx[6]={0,1,0,-1,0},dy[6]={0,0,1,0,-1},obx,oby;
char maze[10][10];
bool vis[10][10],isFind=false;
void dfs(int x,int y,int t) {
    if(t>open_t || isFind) return;
    if(t==open_t && maze[x][y]=='D') {
        cout<<"YES"<<endl;isFind=true;return;
    }
    for(int i=1;i<=4;i++) {
        int cx=x+dx[i],cy=y+dy[i];
        if(cx>=1 && cx<=n && cy>=1 && cy<=m && !vis[cx][cy] && maze[cx][cy]!='X' && !isFind) {
            vis[cx][cy]=true;
            dfs(cx,cy,t+1);
            vis[cx][cy]=false;
        }
    }
}
int main()
{
    while (true) {
        cin>>n>>m>>open_t;
        if(n==0 && m==0 && open_t==0) {break;}
        isFind=false;
        for(int i=1;i<=9;i++) {
            for(int j=1;j<=9;j++) {vis[i][j]=false;}
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>maze[i][j];
                if(maze[i][j]=='S') {x=i,y=j;}
                if(maze[i][j]=='D') {obx=i,oby=j;}
            }
        }
        if((abs(x-obx)+abs(y-oby)+open_t)%2!=0) {cout<<"NO"<<endl;continue;} // 奇偶判断（即曼哈顿距离需与open_t奇偶性相同）
        vis[x][y]=true;
        dfs(x,y,0);
        if(!isFind) cout<<"NO"<<endl;
    }
    return 0;
}
// TLE https://vjudge.net/solution/54625806 没有加奇偶判断
// WA https://vjudge.net/solution/54629118  进入点vis一定要标为访问过
// AC https://vjudge.net/solution/54630273