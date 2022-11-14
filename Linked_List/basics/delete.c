#include<stdio.h>
#include<stdlib.h>
#include "creation_traversal.c"


void main(){
    Node* head_node = create();
    Node* temp_node = head_node;
    Node* temp_addr = NULL; 
    int loc;
    int run = 0,flag=0;

    printf("Enter the location of the node to be deleted(0:begin,-1:end): ");
    scanf("%d",&loc);
    if(loc==0){   //delete from the begining
        temp_node = head_node;
        head_node = head_node ->next;
        free(temp_node);
    }
    else if (loc == -1){  //delete from the end
        while (temp_node->next->next!=NULL){
            temp_node=temp_node->next;}
        temp_addr = temp_node->next;
        free(temp_addr);
        temp_node->next = NULL;
    }
    else { //random deletion
      while (temp_node!=NULL){
        if(loc == run+1){
            if(temp_node->next!=NULL )
            {   temp_addr = temp_node->next;
                temp_node->next = temp_node->next->next;
                free(temp_addr);
                flag = 1;
            }
            }
            run++;
            temp_node =temp_node->next;}
      
        if(flag == 0)
        {printf("OUT OF BOUND\n");
        exit(0);}}
        traverse(head_node);
}
