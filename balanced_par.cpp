#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top=-1;
void push(char data){
    if (top==MAX_SIZE-1){
        printf("stack overflow\n");
        return ;


    }
    top++;
    stack[top]=data;

}
char pop(){
    if (top==-1){
        printf("empty stack \n");
        return ' ';

    }
    char data=stack[top];
    top--;
    return data;
    
        /* code */
    
    
}
int is_matching_paranticis(char char1,char char2){
    if (char1=='('&& char2==')')
    {
        return 1;

    }
    else if (char1=='['&&char2==']')
    {
        return 1;

    }
    else if(char1=='{'&& char2=='}'){
        return 1;
    }else {
        return 0;
    }

    
    
}
int is_check_the_balance(char* text){
    for (int i = 0; i < strlen(text); i++)

    {
        if (text[i]=='('||text[i]=='{'||text[i]=='[')
        
        {
            push(text[i]);
            /* code */
        }
        else if(text[i]==')'|| text[i]==']'||text[i]=='}'){
            if (top==-1)
            {
                return 0;
            }else if(!is_matching_paranticis(pop(),text[i]))  {
                return 0;
            }
            

        }
        
        /* code */
    }
    if (top==-1)
    {
        return 1;
        /* code */
    }else{
        return 0;
    }
    
    
}
int main(){
    char text[MAX_SIZE];
    printf("input expression in paranthises");
    scanf("%s",text);
    if (is_check_the_balance(text)){
        printf("the expression is balanced");
    }else{
        printf("the expression is not balanced");
    }
    
    return 0;
    
}


