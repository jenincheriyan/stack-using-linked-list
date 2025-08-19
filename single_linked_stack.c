#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top= NULL;

void push(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = value;
    newNode -> next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

int pop(){
    if (top == NULL){
        printf("stack underflow!");
        return -1;
    }

    struct Node* temp = top;
    int popped = temp -> data;
    top = top -> next;
    free(temp);

    return popped;
}

void display(){

    if (top == NULL){
        printf("stack empty");
        return;
    }

    struct Node* temp = top;
    while (temp!=NULL){
        printf("%d, ",temp->data);
        temp = temp->next;
    }
}
int main(){

    push(10);
    push(20);
    push(30);
    display();
    return 0;
}

