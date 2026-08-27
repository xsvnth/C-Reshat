/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   10-Nov-2025                                                                      *
*  Exercise: Triangle Area Sorter                                                           *
*  Description:                                                                             *
*       Reads dimensions of multiple triangles, computes their areas using Heron's formula, *
*       and sorts them in ascending order of area.                                          *
*  Input:                                                                                   *
*       - Number of triangles                                                               *
*       - Dimensions of each triangle: a b c                                                *
*  Output:                                                                                  *
*       - Triangles printed in ascending order of area, each on a new line                  *
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {int a,b,c;} triangle;

double area(triangle t){ 
    double s=(t.a+t.b+t.c)/2.0; 
    return sqrt(s*(s-t.a)*(s-t.b)*(s-t.c)); 
}

void sort_by_area(triangle* tr,int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(area(tr[j])>area(tr[j+1])){
                triangle tmp=tr[j]; tr[j]=tr[j+1]; tr[j+1]=tmp;
            }
}

int main(){
    int n; scanf("%d",&n);
    triangle *t=malloc(n*sizeof(triangle));
    for(int i=0;i<n;i++) scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
    sort_by_area(t,n);
    for(int i=0;i<n;i++) printf("%d %d %d\n",t[i].a,t[i].b,t[i].c);
    free(t);
}

