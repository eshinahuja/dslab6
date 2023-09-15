#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX], prefix[MAX],infix[MAX];
int top=-1;

void push( char c){
    if(top==MAX-1){
        printf(“Stack full\n”);
        return;
        }
    else
        top++;
        stack[top]=c;
}

char pop(){
    char c;
    if(top==-1){
        printf("underflow ");
        exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;
}

int space(char c ){
    if (c=='\t'||c==' ')
        return 1;
    else 
        return 0;
}

int isEmpty(){
    if (top==-1){
        return 1 ;
    }
    else return 0;
}
void infixTorPre();



int precedence(char c){
    switch (c){
        case '^':
        return 3;
        case'/':
        case'*':
        return 2;
        case'-':
        case'+':
        return 1;
        default :
        return 0;
    }
}

void revtoPre(char str[]){
    for (int i=strlen(infix)-1;i>=0;i--)
    printf("%c",str[i]);
    printf('\0');
}
    



int main(){
    printf("enter the infix expression:");
    scanf("%s",infix);
    infixTorPre();
    revtoPre(prefix);
    return 0;
} 

void infixTorPre(){
    int i,j=0;
    char next;
    char symbol;
    for (int i=strlen(infix)-1;i>=0;i--){
        if (infix[i]=='(')
            infix[i]=')';
        else if (infix[i]==')')
            infix[i]='(';
        symbol=infix[i];
        if (!space(symbol)){
            switch(symbol)
            {
                case '(':
                push(symbol);
                break;
                
                case')':
                while((next=pop())!=')'){
                    prefix[j++]=next;
                }
                
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                while(!isEmpty()&& precedence(stack[top])>precedence(symbol))
                    prefix[j++]=pop();
                push(symbol);
                break;
                default:
                prefix[j++]=symbol;
                
                break;
            }
        } 
    }
    while(!isEmpty())
        prefix[j++]=pop();
    prefix[j]='\0';
}
        