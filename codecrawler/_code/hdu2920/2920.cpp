#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
#define N 105000
struct Obj
{
    int sign,len;
    ll val;
}obj[N];
ll p[N],ha[N];
int tot;
void init(char *s)
{
    int len=strlen(s);
    tot=0;
    for(int i=0,nxt=0;i<len;i=nxt)
    {
        if(s[i]=='#') obj[tot++].sign=1,nxt=i+1;
        else if(s[i]=='*') obj[tot++].sign=0,nxt=i+1;
        else
        {
            ll t=0;
            while(nxt<len&&s[nxt]!='#'&&s[nxt]!='*')
            {
                t=t*133+s[nxt];
                nxt++;
            }
            obj[tot].sign=-1;
            obj[tot].val=t;
            obj[tot++].len=nxt-i;
        }
    }
}
bool solve(char *s)
{
    int len=strlen(s+1);
    ha[0]=0;
    for(int i=1;i<=len;++i) ha[i]=ha[i-1]*133+s[i];
    int cur=1;
    for(int i=0;i<tot&&cur<=len+1;++i)
    {
        if(obj[i].sign==1) cur++;
        else if(obj[i].sign<0)
        {
            if(i==0)
            {
                if(obj[i].len>len || ha[obj[i].len]!=obj[i].val) return false;
                cur+=obj[i].len;
                continue;
            }
            if(i==tot-1)
            {
                if(cur+obj[i].len>len+1) return false;
                if((len+1-(cur+obj[i].len))%2) return false;
                cur=len+1-obj[i].len;
                return ha[cur+obj[i].len-1]-ha[cur-1]*p[obj[i].len]==obj[i].val;
            }
            while(cur<=len+1&&cur+obj[i].len<=len+1)
            {
                if(ha[cur+obj[i].len-1]-ha[cur-1]*p[obj[i].len]==obj[i].val) break;
                cur+=2;
            }
            if(cur>len+1||cur+obj[i].len>len+1) return false;
            cur+=obj[i].len;


        }
    }
    --cur;
    return cur<=len&&(len-cur)%2==0;
}
char s[N];
int main ()
{
    p[0]=1;
    for(int i=1;i<N;++i) p[i]=p[i-1]*133;
    int ncase1=0,ncase2=0;
    while(scanf("%s",s) && s[0]!='Q')
    {
        init(s);
        ncase1++;ncase2=0;
        while(scanf("%s",s+1) && s[1]!='E' && s[1]!='Q')
        {
            printf("%d.%d. ",ncase1,++ncase2);
            if(solve(s)) printf("match\n");
            else printf("not\n");
        }
        if(s[1]=='Q') break;
    }
    return 0;
}