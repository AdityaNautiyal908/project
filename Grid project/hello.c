#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;
int data,value,choice;

void menu(){
    printf("\nMain Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the top element\n");
    printf("4. Print all the element of the stack\n");
    printf("5. Quit\n");
    printf("Enter your choice : ");
}

int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

void push(){
    if(isFull()){
        printf("Stack overflow");
    }
    top +=1;
    stack_arr[top]=data;
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow");
        exit(1);
    }
    value = stack_arr[top];
    top-=1;
    return value;
    
}

int print_top(){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

void print_All(){
    if(isFull()){
        printf("Stack overflow\n");
    }
    for(int i=top; i>=0; i--){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main(){
    do{
        menu();
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            data = pop();
            printf("Deleted element is %d\n",data);
            break;
            case 3:
            printf("The topmost element of the stack is %d\n",print_top());
            break;
            case 4:
            print_All();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid choice");
        }

    }while(choice!=5);
}