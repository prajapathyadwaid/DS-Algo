#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int links = 0;

typedef struct node
{
    int rollno;
    double marks;
    char name[50];
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
            printf("Enter the Name: ");
            gets(new_node->name);
            printf("Enter the RollNo: ");
            scanf("%d", &new_node->rollno);
            printf("Enter the Marks: ");
            scanf("%d", &new_node->marks);
            head_node  = temp_node = new_node;}

        else{ 
            printf("Enter the Name: ");
            getchar();
            gets(new_node->name);
            printf("Enter the RollNo: ");
            scanf("%d", &new_node->rollno);
            printf("Enter the Marks: ");
            scanf("%d", &new_node->marks);
            temp_node->next = new_node;
            temp_node = new_node;}
        links++;
        printf("Do you want add more nodes?(1/0): ");
        scanf("%d",&flag);
    }
    printf("\nNew List Created\n");
    temp_node->next = NULL;
    return head_node;
    
    
}

void traverse(Node* head_node){
    printf("\n[Student List]\n");
    while(head_node != NULL){
            printf("[Name: %s | ",head_node->name);
            printf("RollNo: %d | ",head_node->rollno);
            printf("Marks: %d]\n",head_node->marks);
            head_node= head_node->next;
}
}

void insert(Node* head_node){
    
    Node* temp_node = head_node;
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* temp_addr = NULL; 
    int loc;
    int run = 0,flag=0;

    printf("Enter the location for new node(0:begin,-1:end): ");
    scanf("%d",&loc);
    printf("Enter the Name: ");
    getchar();
    gets(new_node->name);
    printf("Enter the RollNo: ");
    scanf("%d", &new_node->rollno);
    printf("Enter the Marks: ");
    scanf("%d", &new_node->marks);

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
        if(flag == 1){
        links++;   
        printf("\nNode inserted\n");}
        if(flag == 0)
        printf("\nOUT OF BOUND\n");
        }
   
}

void delete(Node* head_node){
    
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
        if (flag == 1){
        links--;  
        printf("\nNode deleted\n");}
        if(flag == 0)
        printf("\nOUT OF BOUND\n");
        }
        
}

void sort(Node* head_node){
    
    Node* temp_i;
    Node* temp_j;
    int r;double m;char n[50];
    int i,j;
    
    for( i =0, temp_i = head_node; i<links-1; i++, temp_i = temp_i->next)
    for( j=0, temp_j = head_node; j<links-i-1; j++, temp_j = temp_j->next)
    {
        if(temp_j->rollno>temp_j->next->rollno)
        {
            r = temp_j->rollno;
            m = temp_j->marks;
            strcpy(n,temp_j->name);
            temp_j->marks = temp_j->next->marks;
            temp_j->rollno = temp_j->next->rollno;
            strcpy(temp_j->name,temp_j->next->name);
            temp_j->next->rollno = r;
            temp_j->next->marks = m;
            strcpy(temp_j->next->name,n);

        }
        
    }
    printf("\nList Sorted\n");
     

}

void main(){
    Node * head = create();
    int opt;
    do{
        printf("\n1.insert\n2.delete\n3.traverse\n4.sort\n5.exit\n");
        printf(":-| ");
        scanf("%d",&opt);
        switch(opt){
            case 1:{
                insert(head);
                traverse(head);
                break;
            }
            case 2:{
                delete(head);
                traverse(head);
                break;
            }
            case 3:{
                traverse(head);
                break;
            }
            case 4:{
                sort(head);
                traverse(head);
                break;
            }
            
        }

    }while(opt!=5);
    

}