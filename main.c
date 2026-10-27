#include <stdio.h>
#include <stdbool.h>    /* C99 only */
#include <stdlib.h>
#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;
bool overflow = false;
bool underflow = false;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void){
    char user_input;
    printf("Enter parentheses and/or braces: ");
    char temp_pop;
    while(1){

        user_input = getchar();
        if(user_input == '\n')
            break;
        if(user_input == '(' || user_input == '{')
            push(user_input);
        else if(user_input == ')' || user_input == '}'){
            temp_pop = pop();
            if(temp_pop == '{' && user_input != '}'){
                printf("Parentheses/braces are not nested properly!\n");
                return 0;
            }else if(temp_pop == '(' && user_input != ')'){
                printf("Parentheses/braces are not nested properly!\n");
                return 0;
            }
        }
    }

    if (!is_empty() || underflow)
        printf("Parentheses/braces are not nested properly!\n");
    else
        printf("Parentheses/braces are nested properly!\n");

    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty()){
        stack_underflow();
        return '\0';
    }

    else
        return contents[--top];
}

void stack_overflow(void){
    overflow = true;
    printf("Stack OVERFLOW!\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void){
    underflow = true;
}
