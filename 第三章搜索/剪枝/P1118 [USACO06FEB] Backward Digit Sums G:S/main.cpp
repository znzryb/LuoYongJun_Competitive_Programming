#include <iostream>
#include <vector>
using namespace std;
int n,sum,ans;
vector<int> comb,param[15]; // Parameter 系数
bool isFind=false;
bool vis[15];
void dfs(int x) {   // x 就是个数，当然可以不用
    if(isFind) return;
    ans=0;
    for(int i=0;i<x;i++) {ans+=comb[i]*param[n][i];}
    if(ans>sum) return;
    if(ans==sum && x==n) {
        isFind=true;
        for(int i=0;i<n;i++) {cout<<comb[i]<<" ";}
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!vis[i] && !isFind) {vis[i]=true;comb.push_back(i);dfs(x+1);comb.pop_back();vis[i]=false;}
    }
}
int main()
{
    cin>>n>>sum;
    // 计算杨辉三角
    param[1].push_back(1);
    for(int i=2;i<=n;i++) {
        param[i].push_back(1);
        for(int j=1;j<i-1;j++) {
            param[i].push_back(param[i-1][j-1]+param[i-1][j]);
        }
        param[i].push_back(1);
    }
    dfs(0);

    // debug
    // for(int i=1;i<=n;i++) {
    //     for(int j=0;j<=i-1;j++) {
    //         cout<<param[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
// 80pts https://www.luogu.com.cn/record/179229042 数据挺水的，未剪枝就过了这么多
// AC https://www.luogu.com.cn/record/179233032