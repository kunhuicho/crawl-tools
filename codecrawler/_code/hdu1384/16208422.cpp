/*
http://poj.org/problem?id=1201
é¢æï¼æ±ç¬¦åé¢æçæå°éåçåç´ ä¸ªæ°
é¢ç®è¦æ±çæ¯æ±çæç­è·¯ï¼
åå¯¹äº ä¸ç­å¼  f(b)-f(a)>=c,å»ºç« ä¸æ¡ b å° a çè¾¹ æå¼ä¸º c,åæ±çæé¿è·¯ å³ä¸º æå°å¼(éå)
å¹¶ä¸æéå«æ¡ä»¶ï¼0<=f(a)-f(a-1)<=1  åæè¾¹æå³ç³»(a,a-1,0)ä»¥å(a-1,a,-1);
å°æºç¹å°åç¹çè·ç¦»åå§åä¸ºINF(æ ç©·å¤§)ï¼å¶ä¸­ä¹1ä¸º0ï¼æç»æ±åºçæç­è·¯æ»¡è¶³ å®ä»¬ä¸è¯¥ç¹ä¹é´ç¸äºå·®å¼æå¤§
å·®åçº¦æ
ãå¨å®éçåºç¨ä¸­ï¼ä¸è¬ä½¿ç¨SPFA(Shortest Path Fast Algorithm)ç®æ³æ¥å®ç°ã
ããå·®åçº¦æç³»ç»ä¸­æºç¹å°æ¯ä¸ªç¹çè·ç¦»ç¡®å®
ããå³äºDist[]çåå§åå
ãã1.å¦æå°æºç¹å°åç¹çè·ç¦»åå§åä¸º0ï¼æç»æ±åºçæç­è·¯æ»¡è¶³ å®ä»¬ä¹é´ç¸äºææ¥è¿äº
ãã2.å¦æå°æºç¹å°åç¹çè·ç¦»åå§åä¸ºINF(æ ç©·å¤§)ï¼å¶ä¸­ä¹1ä¸º0ï¼æç»æ±åºçæç­è·¯æ»¡è¶³ å®ä»¬ä¸è¯¥ç¹ä¹é´ç¸äºå·®å¼æå¤§ã
ãã3.å·®åçº¦æç³»ç»çç¡®ç«è¦æ ¹æ®èªå·±ç¡®å®ççº¦ææ¡ä»¶ï¼ä»çº¦æç¹èµ°åè¢«çº¦æç¹
ããè¿è¾¹ä¸è¬æä¸¤ç§æ¹æ³ï¼ç¬¬ä¸ç§æ¯è¿è¾¹åæ±æé¿è·¯çæ¹æ³ï¼ç¬¬äºç§æ¯è¿è¾¹åæ±æç­è·¯çæ¹æ³ã
ããä¾ï¼d[x]-d[y]>=Z
ããå¦ææ³è¿è¾¹åæ±æé¿è·¯ é£ä¹å°ä¸ç­å¼åå½¢ä¸ºè¿ç§å½¢å¼ d[x]>=d[y]+z y---xè¿ä¸æ¡æå¼ä¸ºzçè¾¹
ããæ±æç­è·¯ååå½¢æd[y]<=d[x]-z x---yè¿ä¸æ¡æå¼ä¸º-zçè¾¹ã
ããå¦ææ¯å«çä¸ç­å¼ï¼ä¹å¯ä»¥æ ¹æ®æåµåå½¢ãä½æ¯è¦ä¿è¯çæ¯ ä¸¤ä¸ªåéï¼x,y)çç³»æ°ä¸å®è¦æ¯æ­£çãèå¸¸éåä¸ä¸å®ã
ç¬¬ä¸ï¼
æè§é¾ç¹å¨äºå»ºå¾
ç¬¬äºï¼
â ï¼å¯¹äºå·®åä¸ç­å¼ï¼a - b <= c ï¼å»ºä¸æ¡ b å° a çæå¼ä¸º c çè¾¹ï¼æ±çæ¯æç­è·¯ï¼å¾å°çæ¯æå¤§å¼
â¡ï¼å¯¹äºä¸ç­å¼ a - b >= c ï¼å»ºä¸æ¡ b å° a çæå¼ä¸º c çè¾¹ï¼æ±çæ¯æé¿è·¯ï¼å¾å°çæ¯æå°å¼
â¢ï¼å­å¨è´ç¯çè¯æ¯æ è§£
â£ï¼æ±ä¸åºæç­è·¯ï¼dist[ ]æ²¡æå¾å°æ´æ°ï¼çè¯æ¯ä»»æè§£
ç¬¬ä¸ï¼
ä¸ç§å»ºå¾æ¹æ³ï¼
è®¾x[i]æ¯ç¬¬iä½ç½®ï¼ææ¶å»ï¼çå¼ï¼è·ææ±å¼çå±æ§ä¸æ ·ï¼ï¼é£ä¹æx[i]çææ°åï¼åné¡¹åä¸ºs[n]ï¼åx[i] = s[i] - s[i-1]ï¼
é£ä¹è¿æ ·å°±å¯ä»¥æèµ·ç å»ºç«èµ·ç±»ä¼¼è¿æ ·çä¸ä¸ªå³ç³»ï¼0 <= s[i] - s[i-1] <= 1;
å¶ä»å³ç³»å°±è¦å»é¢ç®æ¢ç´¢äº
*/


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;
const int maxn=50002;
const int INF=0x3fffff;
int dis[maxn],mmin,mmax,n,NE,head[maxn],vis[maxn];
struct node
{
    int u,v,val,next;
} Edge[maxn<<2];
void addEdge(int u,int v,int val)
{
    Edge[NE].u=u;
    Edge[NE].v=v;
    Edge[NE].val=val;
    Edge[NE].next=head[u];
    head[u]=NE++;
}
void spfa()
{
    for(int i=mmin;i<=mmax;i++)
    {
        dis[i]=-INF;
    }
    queue<int>q;
    q.push(mmin);
    vis[mmin]=1;
    dis[mmin]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u]; i!=-1; i=Edge[i].next)
        {
            int v=Edge[i].v;
            if(dis[v]<dis[u]+Edge[i].val)
            {
                dis[v]=dis[u]+Edge[i].val;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    printf("%d\n",dis[mmax]);
    return;
}
int main()
{
    int a,b,c,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        NE=0;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        mmin=maxn;
        mmax=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            b++;
            if(mmin>a)mmin=a;
            if(mmax<b)mmax=b;
            addEdge(a,b,c);
        }
        for(i=mmin; i<mmax; i++)
        {
            addEdge(i+1,i,-1);
            addEdge(i,i+1,0);
        }
        spfa();
    }
    return 0;
}








   
