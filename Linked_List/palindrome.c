#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_dl
{
    char ch;
    struct node_dl *next;
    struct node_dl *prev;
    
}Node_dl; 

Node_dl *create();


Node_dl *create()
{
    Node_dl *head_node = NULL;
    Node_dl *temp_node = NULL;
    Node_dl *new_node = NULL;
    char str[50];
    printf("enter the string : ");
    gets(str);
    int length = strlen(str);
    

    for(int i = 0;i<length;i++)
    {
        new_node = (Node_dl *)malloc(sizeof(Node_dl));
        if (head_node == NULL)
        {
           
            new_node->ch = str[i];
            head_node = temp_node = new_node;
            head_node->prev = NULL;
        }

        else
        {
            new_node->ch = str[i];
            new_node->prev = temp_node;
            temp_node->next = new_node;
            temp_node = new_node;
           

        }
    }

    temp_node->next = NULL;
    return head_node;
}


void main(){
    Node_dl * head = create();
    Node_dl * temp = head;
    Node_dl  *tail = NULL;
    int bool=1;
    while(temp->next!=NULL){
        temp = temp->next;}
    tail = temp;
    temp = head;
    while(temp!=NULL&&tail!=NULL){
        if(temp->ch != tail->ch){
            bool = 0;
            printf("not palindrome");
            break;}
        temp = temp->next;
        tail = tail->prev;}
    if(bool == 1)
    printf("palindrome");

}