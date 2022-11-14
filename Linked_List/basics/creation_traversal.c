#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node* create();
void traverse(Node* );

Node* create()
{
    Node *head_node = NULL;
    Node *temp_node = NULL;
    Node *new_node = NULL;
    int flag = 1;

    while (flag == 1)
    {
        new_node = (Node*) malloc(sizeof(Node));
        if (head_node == NULL){
            printf("Enter the data: ");
            scanf("%d", &new_node->data);
            head_node  = temp_node = new_node;}

        else{ 
            printf("Enter the data: ");
            scanf("%d", &new_node->data);
            temp_node->next = new_node;
            temp_node = new_node;}

        printf("Do you want add more nodes?(1/0): ");
        scanf("%d",&flag);
    }

    temp_node->next = NULL;
    return head_node;
    
    
}

void traverse(Node* head_node){
    while(head_node != NULL){
            printf("node_data: %d\n",head_node->data);
            head_node= head_node->next;
}
}

/* void main(){
    Node * head = create();
    traverse(head);
} */