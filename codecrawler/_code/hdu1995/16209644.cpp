#include <stdio.h>
/*
æ°æ®ï¼
1 1:1
2 1:2
2 2:1
3 1:4
3 2:2
3 3:1
ç¬¬ä¸ä¸ªæ¯2^(n-1)
bæ¯å¢å 1å°±ç¼©å°ä¸å
*/
__int64 pow(int n)
{
    __int64 s = 1;
    for(int i = 1;i<=n;i++)
    s*=2;
    return s;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        __int64 ans;
        scanf("%d%d",&a,&b);
        ans = pow(a-1);
        if(b>1)
        {
            ans = ans/(2*(b-1));
        }
        printf("%I64d\n",ans);

    }

    return 0;
}
