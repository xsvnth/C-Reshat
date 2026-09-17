#include "Stack.h" 
int isNum(char *s){
    if (*s == '-' && s[1])
        s++;
    else if (*s == '-')
        return 0;
    while (*s){
        if (!(*s >= '0' && *s <= '9'))
            return 0;
        s++;
    }
    return 1;
}

int isSep(char *s){
    if (*s == '+' || *s == '-' || *s == '*' || *s == '/')
        return 1;
    return 0;
}

int Operation(int x, int y, char *sep){
    if (*sep == '+')
        return (x + y);
    else if (*sep == '-')
        return (x - y);
    else if (*sep == '*')
        return (x * y);
    else if (*sep == '/')
        return (x / y);
    return 0;
}

int evalRPN(char **tockens, int tsize){
    t_Stack *obj = StackCreate();
    int res = 0, left = 0, right = 0;
    for (int i = 0; i < tsize; i++) {
        if (isNum(tockens[i]))
            Push(obj, atoi(tockens[i]));
        else if (isSep(tockens[i])){
            right = Top(obj);
            Pop(obj);
            left = Top(obj);
            Pop(obj);
            res = Operation(left, right, tockens[i]);
            Push(obj, res);
        }
    }
    return Top(obj);
}
#include <stdio.h>
int main(){
    char *RPN[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int size = sizeof(RPN) / sizeof(RPN[0]);
    printf("%d\n", evalRPN(RPN, size));
}
