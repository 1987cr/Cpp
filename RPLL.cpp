/*  http://www.spoj.com/problems/RPLL/  */

#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

typedef struct point{
    double x,y,mx,my;
}P;

int main()
{
    //freopen("RPLL.in","r",stdin);
    int T,j;
    double searchArea,speed;
    P p[3];
    char c;
    string direction;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%lf",&searchArea);
        for(j=0;j<3;j++){
            scanf("%lf",&p[j].x);
            scanf("%lf",&p[j].y);
            getchar();
            direction.clear();
            while(c!=' '){
                scanf("%c",&c);
                direction=direction+c;
            }
            c='z';
            scanf("%lf",&speed);
            if(direction=="north "){
                p[j].my=speed;
                p[j].mx=0;
                continue;
            }
            if(direction=="south "){
                p[j].my=-speed;
                p[j].mx=0;
                continue;
            }
            if(direction=="east "){
                p[j].mx=speed;
                p[j].my=0;
                continue;
            }
            if(direction=="west "){
                p[j].mx=-speed;
                p[j].my=0;
                continue;
            }
        }
        if(((p[0].x*(p[1].y-p[2].y) + p[1].x*(p[2].y-p[0].y) + p[2].x*(p[0].y - p[1].y))/2.0)>=searchArea) printf("Scenario #%d: %d\n",i+1,0);
        else{
            double a,b,c,n,disc,aux;
            a = p[0].mx*(p[1].my-p[2].my) + p[1].mx*(p[2].my-p[0].my) + p[2].mx*(p[0].my-p[1].my);
            b = p[0].x*(p[1].my-p[2].my) + p[1].x*(p[2].my-p[0].my) + p[2].x*(p[0].my-p[1].my) + p[0].mx*(p[1].y - p[2].y) + p[1].mx*(p[2].y - p[0].y) + p[2].mx*(p[0].y - p[1].y);
            c = p[0].x*(p[1].y - p[2].y) + p[1].x*(p[2].y - p[0].y) + p[2].x*(p[0].y - p[1].y) - 2.0*searchArea;
            if(a==0){
                n=-c/b;
                if(n<0) c = p[0].x*(p[1].y - p[2].y) + p[1].x*(p[2].y - p[0].y) + p[2].x*(p[0].y - p[1].y) + 2.0*searchArea;
                n=-c/b;
            }else{
                aux=(b*b)-(4*a*c);
                if(aux<0) c = p[0].x*(p[1].y - p[2].y) + p[1].x*(p[2].y - p[0].y) + p[2].x*(p[0].y - p[1].y) + 2.0*searchArea;
                disc=sqrt((b*b)-(4.0*a*c));
                n=(b*(-1)-disc)/(2.0*a);
                if(n<0) n=(b*(-1)+disc)/(2.0*a);
            }
            printf("Scenario #%d: %.0f\n",i+1,n-0.5);
        }
    }
    //fclose(stdin);
    return 0;
}
