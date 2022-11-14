#include<stdio.h>
#include<stdlib.h>
#include "creation_traversal.c"


void main(){
    Node* head_node = create();
    Node* temp_node = head_node;
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* temp_addr = NULL; 
    int loc;
    int run = 0,flag=0;
    int data;

    printf("Enter the location for new node(0:begin,-1:end): ");
    scanf("%d",&loc);
    printf("Enter the data for new node: ");
    scanf("%d",&data); 
    new_node->data = data;

    if(loc == 0){ 
        head_node = new_node;
        head_node->next = temp_node;}

    else if(loc == -1){
        while (temp_node->next!=NULL){
            temp_node=temp_node->next;}
        new_node->next = NULL;
        temp_node->next = new_node;}

    else {
      while (temp_node!=NULL){
        if(loc == run+1){
            temp_addr = temp_node->next;
            temp_node->next= new_node;
            new_node->next = temp_addr;
            flag = 1;}
            run++;
            temp_node =temp_node->next;}
      
        if(flag == 0)
        {printf("OUT OF BOUND\n");
        exit(0);}}
    
    traverse(head_node); 
   
        
}