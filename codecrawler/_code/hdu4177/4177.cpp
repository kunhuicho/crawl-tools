#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char c1,c2,c3;
        int h1,h2,h3;
        char m11,m12,m21,m22,m31,m32;
        scanf("%d%c%c%c",&h1,&c1,&m11,&m12);
        getchar();
        scanf("%d%c%c%c",&h2,&c2,&m21,&m22);
        getchar();
        scanf("%d%c%c%c",&h3,&c3,&m31,&m32);
        int min1=0,min2=0,min3=0;
        min1=h1*60+m11*10+m12;
        min2=h2*60+m21*10+m22;
        min3=h3*60+m31*10+m32;
        int p1=0,p2=0,p3=0;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        min1+=12*60;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        min1-=12*60;
        min2+=12*60;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        min2-=12*60;
        min3+=12*60;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        min1+=12*60;
        min2+=12*60;
        min3-=12*60;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        min2-=12*60;
        min3+=12*60;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        min1-=12*60;
        min2+=12*60;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        min1+=12*60;
        if(min1+min2==2*min3&&fabs(min1-min3)<=480)
            p3++;
        else if(min1+min3==2*min2&&fabs(min1-min2)<=480)
            p2++;
        else if(min3+min2==2*min1&&fabs(min3-min1)<=480)
            p1++;
        if(p1>0&&p2>0||p1>0&&p3>0||p2>0&&p3>0)
            printf("Look at the sun\n");
        else if(p1>0)
        {
            printf("The correct time is %d:%c%c\n",h1,m11,m12);
        }
        else if(p2>0)
        {
            printf("The correct time is %d:%c%c\n",h2,m21,m22);
        }
        else if(p3>0)
        {
            printf("The correct time is %d:%c%c\n",h3,m31,m32);
        }
    }
    return 0;
}