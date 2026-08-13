/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Document Parser                                                         *
*  Description:                                                                      *
*       Reads text input with multiple paragraphs, sentences, and words.             *
*       Allows querying for:                                                         *
*           - The k-th paragraph                                                     *
*           - The k-th sentence in m-th paragraph                                    *
*           - The k-th word in m-th sentence of n-th paragraph                       *
*       Prints the requested text segments.                                          *
*  Input:                                                                            *
*       - Number of paragraphs                                                       *
*       - Paragraph text lines                                                       *
*       - Number of queries                                                          *
*       - Queries (type 1, 2, or 3 with appropriate indices)                         *
*  Output:                                                                           *
*       - Text segments corresponding to queries                                     *
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{char*data;};
struct sentence{struct word*data;int word_count;};
struct paragraph{struct sentence*data;int sentence_count;};
struct document{struct paragraph*data;int paragraph_count;};

struct document get_document(char*t){
    struct document d={malloc(10*sizeof*d.data),0};
    char *ps,*par=strtok_r(t,"\n",&ps);
    while(par){
        struct paragraph p={malloc(100*sizeof*p.data),0};
        char *ss,*sen=strtok_r(par,".",&ss);
        while(sen){
            while(*sen==' ')sen++;
            struct sentence s={malloc(100*sizeof*s.data),0};
            char *ws,*w=strtok_r(sen," ",&ws);
            while(w){s.data[s.word_count++].data=strdup(w);w=strtok_r(NULL," ",&ws);}
            p.data[p.sentence_count++]=s;sen=strtok_r(NULL,".",&ss);
        }
        d.data[d.paragraph_count++]=p;par=strtok_r(NULL,"\n",&ps);
    }
    return d;
}

#define P printf
struct paragraph kth_paragraph(struct document D,int k){return D.data[k-1];}
struct sentence kth_sentence_in_mth_paragraph(struct document D,int k,int m){return D.data[m-1].data[k-1];}
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document D,int k,int m,int n){return D.data[n-1].data[m-1].data[k-1];}
void print_word(struct word w){P("%s",w.data);}
void print_sentence(struct sentence s){for(int i=0;i<s.word_count;i++){print_word(s.data[i]);if(i<s.word_count-1)P(" ");}}
void print_paragraph(struct paragraph p){for(int i=0;i<p.sentence_count;i++){print_sentence(p.data[i]);P(".");}}

char* get_input_text(){
    int n;scanf("%d",&n);getchar();
    char*doc=calloc(1,5000);
    for(int i=0;i<n;i++){char line[1005];fgets(line,1005,stdin);line[strcspn(line,"\n")]=0;strcat(doc,line);if(i<n-1)strcat(doc,"\n");}
    return doc;
}

int main(){
    char*text=get_input_text();struct document D=get_document(text);free(text);
    int q;scanf("%d",&q);
    while(q--){int t;scanf("%d",&t);
        if(t==3){int k,m,n;scanf("%d%d%d",&k,&m,&n);print_word(kth_word_in_mth_sentence_of_nth_paragraph(D,k,m,n));}
        else if(t==2){int k,m;scanf("%d%d",&k,&m);print_sentence(kth_sentence_in_mth_paragraph(D,k,m));}
        else{int k;scanf("%d",&k);print_paragraph(kth_paragraph(D,k));}
        P("\n");
    }
}

