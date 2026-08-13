/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   10-Nov-2025                                                                      *
*  Exercise: Document Parser                                                                *
*  Description:                                                                             *
*       Parses a text document into paragraphs, sentences, and words.                       *
*       Supports queries to retrieve:                                                       *
*           - A specific word from a sentence in a paragraph                                *
*           - A specific sentence from a paragraph                                          *
*           - A specific paragraph                                                          *
*  Input:                                                                                   *
*       - Number of paragraphs                                                              *
*       - Paragraph text                                                                    *
*       - Number of queries                                                                 *
*       - Queries of 3 types:                                                               *
*           1 k m n : Print the k-th word in the m-th sentence of the n-th paragraph        *
*           2 k m   : Print the k-th sentence of the m-th paragraph                         *
*           3 k     : Print the k-th paragraph                                              *
*  Output:                                                                                  *
*       - Result of each query printed on a new line                                        *
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1005
#define MAX_PAR 5

char** split_words(char* s) {
    char** w = malloc(sizeof(char*) * MAX_CHAR);
    int i = 0; char* t = strtok(s," ");
    while(t){ w[i]=strdup(t); i++; t=strtok(NULL," "); }
    w[i]=NULL; return w;
}

char*** split_sentences(char* p) {
    char*** s = malloc(sizeof(char**)*MAX_CHAR); int i=0;
    char* start=p; char* end=strchr(start,'.');
    while(end){ *end=0; s[i++]=split_words(start); start=end+1; while(*start==' ') start++; end=strchr(start,'.'); }
    s[i]=NULL; return s;
}

char**** get_document(char* t){
    char**** d=malloc(sizeof(char***)*MAX_PAR); int i=0;
    char* start=t; char* end=strchr(start,'\n');
    while(end || *start){
        char p[MAX_CHAR]; if(end){ strncpy(p,start,end-start); p[end-start]=0; } else strcpy(p,start);
        d[i++]=split_sentences(p);
        if(!end) break; start=end+1; end=strchr(start,'\n');
    }
    d[i]=NULL; return d;
}

char* kw(char**** d,int k,int m,int n){ return d[n-1][m-1][k-1]; }
char** ks(char**** d,int k,int m){ return d[m-1][k-1]; }
char*** kp(char**** d,int k){ return d[k-1]; }

void print_word(char* w){ printf("%s",w); }
void print_sentence(char** s){ for(int i=0;s[i];i++){ printf("%s",s[i]); if(s[i+1]) printf(" "); } }
void print_paragraph(char*** p){ for(int i=0;p[i];i++){ print_sentence(p[i]); printf("."); } }

char* get_text(){
    int n; scanf("%d",&n); getchar();
    static char t[MAX_PAR*MAX_CHAR]; t[0]=0;
    for(int i=0;i<n;i++){ char l[MAX_CHAR]; scanf("%[^\n]%*c",l); strcat(t,l); if(i!=n-1) strcat(t,"\n"); }
    return t;
}

int main(){
    char* text=get_text();
    char**** doc=get_document(text);
    int q; scanf("%d",&q);
    while(q--){
        int type; scanf("%d",&type);
        if(type==3){ int k,m,n; scanf("%d%d%d",&k,&m,&n); print_word(kw(doc,k,m,n)); }
        else if(type==2){ int k,m; scanf("%d%d",&k,&m); print_sentence(ks(doc,k,m)); }
        else{ int k; scanf("%d",&k); print_paragraph(kp(doc,k)); }
        printf("\n");
    }
}

