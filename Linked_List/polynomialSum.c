#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} Node;

Node *create();
void traverse(Node *);

Node *create()
{
    Node *head_node = NULL;
    Node *temp_node = NULL;
    Node *new_node = NULL;
    int flag = 1;

    while (flag == 1)
    {
        new_node = (Node *)malloc(sizeof(Node));
        if (head_node == NULL)
        {
            printf("Enter the data(coeff,exp): ");
            scanf("%d,%d", &new_node->coef, &new_node->exp);
            head_node = temp_node = new_node;
        }

        else
        {
            printf("Enter the data(coeff,exp): ");
            scanf("%d,%d", &new_node->coef, &new_node->exp);
            temp_node->next = new_node;
            temp_node = new_node;
        }

        printf("Do you want add more nodes?(1/0): ");
        scanf("%d", &flag);
    }

    temp_node->next = NULL;
    return head_node;
}

void traverse(Node *head_node)
{
    while (head_node != NULL)
    {
        printf("+ %dx^%d ", head_node->coef, head_node->exp);
        head_node = head_node->next;
    }
}

void main()
{

    printf("polynomial 1\n");
    Node *head1 = create();
    printf("polynomial 2\n");
    Node *head2 = create();
    Node *head3 = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *temp3 = NULL;
    Node *new_node = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        new_node = (Node *)malloc(sizeof(Node));
        if (temp1->exp == temp2->exp)
        {
            new_node->coef = temp1->coef + temp2->coef;
            new_node->exp = temp1->exp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            new_node->coef = temp1->coef;
            new_node->exp = temp1->exp;
            temp1 = temp1->next;
        }
        else
        {
            new_node->coef = temp2->coef;
            new_node->exp = temp2->exp;
            temp2 = temp2->next;
        }
        if (head3 == NULL)
        {
            head3 = temp3 = new_node;
        }
        else
        {
            temp3->next = new_node;
            temp3 = new_node;
        }
    }
    temp3->next = NULL;

    while (temp1 != NULL)
    {
        temp3->next = temp1->next;
        temp3 = temp3->next;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        temp3->next = temp2->next;
        temp3 = temp3->next;
        temp2 = temp2->next;
    }
    traverse(head3);
}
