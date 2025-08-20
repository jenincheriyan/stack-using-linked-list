#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};
struct Node*top= NULL;

void push(int value){

    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next= top;
    top= newnode;
}

int pop(){

    
    if(top==NULL){
        printf("stack underflow\n");
        return -1;
    }
    struct Node* temp;
    int value;
        temp= top;
        value=temp->data;
        top= temp->next;
        free(temp);
        return value;
    }

void display(){
    if (top==NULL){
        printf("stack is empty\n");
        return;
    }
    struct Node*temp = top;

        while(temp!=NULL){
            printf("%d \n", temp->data);
            temp= temp->next;
        }

}

void search(int value){
    int i=1;
    int p=0;
    if (top== NULL){
        printf("Empty");
        return;
    }

    struct Node* temp= top;
    while (temp!=NULL){
        if (temp->data==value){
        printf("%d found at %d\n",value, i);
        p=1;
        }
        temp= temp->next;
        i++;
    }
    if(p==0){
        printf("Value not found\n");
    }
    }

void main(){
    printf("Select the option\n ");
    int option;
    int value;

    while (option!=5)
    {
      printf("1 for push\n 2 for pop\n 3 for display\n 4 for search\n 5 for exit\n");
      scanf("%d", &option);

      switch (option)
      {
      case 1:
        printf("Enter the value to be pushed\n");
        scanf("%d", &value);
        push(value);
        break;
      case 2:
        value= pop();
        printf("%d popped\n", value);
        break;
      case 3:
        display();
        break;

      case 4:
      printf("Enter the value to search");
      scanf("%d",&value);
      search(value);
        break;

      case 5:
        printf("...exit...");
        option=5;
        break;

      default:
       printf("invalid option");
        break;
      }
    
    }
    
}