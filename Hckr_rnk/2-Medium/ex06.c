/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   10-Nov-2025                                                                      *
*  Exercise: Box Volume Checker                                                             *
*  Description:                                                                             *
*       Reads dimensions of multiple boxes and prints the volume of those boxes whose       *
*       height is less than MAX_HEIGHT.                                                     *
*  Input:                                                                                   *
*       - Number of boxes                                                                   *
*       - Dimensions of each box: length, width, height                                     *
*  Output:                                                                                  *
*       - Volume of each box (height < MAX_HEIGHT), each on a new line                      *
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

typedef struct {int l,w,h;} box;

int get_volume(box b){ return b.l*b.w*b.h; }
int is_lower_than_max_height(box b){ return b.h<MAX_HEIGHT; }

int main(){
    int n; scanf("%d",&n);
    box *b=malloc(n*sizeof(box));
    for(int i=0;i<n;i++) scanf("%d%d%d",&b[i].l,&b[i].w,&b[i].h);
    for(int i=0;i<n;i++) if(is_lower_than_max_height(b[i])) printf("%d\n",get_volume(b[i]));
    free(b);
}

