/*  http://www.spoj.com/problems/RPLL/  */

#include<stdio.h>
#include<math.h>
#include <string.h>

typedef struct point{
    double x,y,mx,my;
}P;

inline void movement(P *p,char *direction,double speed){
    if(!strcmp(direction,"north ")){
        p->my=speed;
        p->mx=0;
        return;
    }
   if(!strcmp(direction,"south ")){
        p->my=-speed;
        p->mx=0;
        return;
    }
    if(!strcmp(direction,"east ")){
        p->mx=speed;
        p->my=0;
        return;
    }
    if(!strcmp(direction,"west ")){
        p->mx=-speed;
        p->my=0;
        return;
    }
}

inline double initialArea(P p1,P p2,P p3){
    return ((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y - p2.y))/2.0);
}

inline double res(P p1,P p2,P p3,double searchArea){
    double a,b,c,n,disc,aux;
    a = p1.mx*(p2.my-p3.my) + p2.mx*(p3.my-p1.my) + p3.mx*(p1.my-p2.my);
    b = p1.x*(p2.my-p3.my) + p2.x*(p3.my-p1.my) + p3.x*(p1.my-p2.my) + p1.mx*(p2.y - p3.y) + p2.mx*(p3.y - p1.y) + p3.mx*(p1.y - p2.y);
    c = p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y) - 2.0*searchArea;
    if(a==0){
        n=-c/b;
        if(n<0) c = p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y) + 2.0*searchArea;
        n=-c/b;
    }else{
        aux=(b*b)-(4*a*c);
        if(aux<0) c = p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y) + 2.0*searchArea;
        disc=sqrt((b*b)-(4.0*a*c));
        n=(b*(-1)-disc)/(2.0*a);
        if(n<0) n=(b*(-1)+disc)/(2.0*a);
    }
    return n;
}

/*-----------------------------------------*/

int main(){
    //freopen("RPLL.in","r",stdin);
    int T,j,i;
    double searchArea,speed;
    P p[3];
    char c,direction[256];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%lf",&searchArea);
        for(j=0;j<3;j++){
            scanf("%lf",&p[j].x);
            scanf("%lf",&p[j].y);
            getchar();
            memset(direction, 0, sizeof(direction));
            while(c!=' '){
                scanf("%c",&c);
                strncat(direction,&c,1);
            }
            c='z';
            scanf("%lf",&speed);
            movement(&p[j],direction,speed);
        }
        if(initialArea(p[0],p[1],p[2])>=searchArea) printf("Scenario #%d: %d\n",i+1,0);
        else{
            printf("Scenario #%d: %.0f\n",i+1,res(p[0],p[1],p[2],searchArea)-0.5);
        }
    }
    //fclose(stdin);
    return 0;
}
