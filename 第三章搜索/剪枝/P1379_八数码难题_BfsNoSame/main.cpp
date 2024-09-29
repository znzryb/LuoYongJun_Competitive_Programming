#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
string start,ob;
set<string> vis;
struct sStep0i {
    string ss;int step;short int i0;
};
deque<sStep0i> q;
inline bool check(const string &s) {   // 判重
    // if(i<0) return false;
    // if(i>8) return false;
    if(vis.find(s)==vis.end())  return true;
    return false;
}
inline sStep0i makeSS0(string s,int step,short int i0) {
    sStep0i a;
    a.ss=s;a.step=step;a.i0=i0;
    return a;
}
void bfs() {
    q.push_back(makeSS0(start,0,start.find('0')));    // status step i0
    while (!q.empty()) {
        string s=q.front().ss;int step=q.front().step;short int i0=q.front().i0;
        q.pop_front();
        // cout<<s<<endl;
        if(s=="123804765") {
            cout<<step<<endl;
            break;
        }
        short int i1=i0-3,i2=i0+1,i3=i0+3,i4=i0-1;
        if(i0==3 || i0==6)   i4=-1;
        if(i0==2 || i0==5)   i2=-1;
        if(i1>=0 && i1<=8) {
            swap(s[i0],s[i1]);
            if(vis.find(s)==vis.end())  {q.push_back(makeSS0(s,step+1,i1));vis.insert(s);}
            swap(s[i0],s[i1]);
        }
        if(i2>=0 && i2<=8) {
            swap(s[i0],s[i2]);
            if(vis.find(s)==vis.end())  {q.push_back(makeSS0(s,step+1,i2));vis.insert(s);}
            swap(s[i0],s[i2]);
        }
        if(i3>=0 && i3<=8) {
            swap(s[i0],s[i3]);
            if(vis.find(s)==vis.end())  {q.push_back(makeSS0(s,step+1,i3));vis.insert(s);}
            swap(s[i0],s[i3]);
        }
        if(i4>=0 && i4<=8) {
            swap(s[i0],s[i4]);
            if(vis.find(s)==vis.end())  {q.push_back(makeSS0(s,step+1,i4));vis.insert(s);}
            swap(s[i0],s[i4]);
        }
    }
}
int main()
{
    cin>>start;
    bfs();
    return 0;
}
// 37 pts https://www.luogu.com.cn/record/179034472 八数码问题的0不一定在中心，需要分情况
// AC https://www.luogu.com.cn/record/179041048