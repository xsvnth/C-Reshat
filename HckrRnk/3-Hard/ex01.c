/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Custom String Sorting                                                   *
*  Description: Reads n strings and prints them sorted in four ways:                 *
*               1. Lexicographically ascending                                       *
*               2. Lexicographically descending                                      *
*               3. By length (shorter first, then lexicographically)                 *
*               4. By number of distinct characters (then lexicographically)         *
*  Input:                                                                            *
*       - An integer n                                                               *
*       - n strings                                                                  *
*  Output:                                                                           *
*       - Strings printed sorted by each of the four criteria, separated by newlines *
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_lex(const char*a,const char*b){return strcmp(a,b);}
int cmp_lex_rev(const char*a,const char*b){return strcmp(b,a);}
int cmp_len(const char*a,const char*b){int d=strlen(a)-strlen(b);return d?d:strcmp(a,b);}
int cnt_dist(const char*s){int f[256]={0},c=0;for(int i=0;s[i];i++)if(!f[(unsigned char)s[i]]++)c++;return c;}
int cmp_dist(const char*a,const char*b){int d=cnt_dist(a)-cnt_dist(b);return d?d:strcmp(a,b);}
void sort(char**a,int n,int(*cmp)(const char*,const char*)){for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(cmp(a[i],a[j])>0){char*t=a[i];a[i]=a[j];a[j]=t;}}

int main(){
    int n; scanf("%d",&n);
    char**a=malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){a[i]=malloc(1024);scanf("%s",a[i]);a[i]=realloc(a[i],strlen(a[i])+1);}
    sort(a,n,cmp_lex);for(int i=0;i<n;i++)printf("%s\n",a[i]);printf("\n");
    sort(a,n,cmp_lex_rev);for(int i=0;i<n;i++)printf("%s\n",a[i]);printf("\n");
    sort(a,n,cmp_len);for(int i=0;i<n;i++)printf("%s\n",a[i]);printf("\n");
    sort(a,n,cmp_dist);for(int i=0;i<n;i++)printf("%s\n",a[i]);printf("\n");
    for(int i=0;i<n;i++) free(a[i]);
    free(a);
}

//hdarah l7wa machi C
