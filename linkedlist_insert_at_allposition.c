#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void traverse(struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("element is :%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node* insertatfirst(struct node* head,int x)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=x;
    return ptr;
}
struct node* insertatend(struct node* head,int data)
{
    struct node* ptr=(struct node* )malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p= head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertatindex(struct node* head,int data,int index)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    while(i != index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}
struct node* insertatnode(struct node* head,struct node* prevnode,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;

    return head;
} 
int main()
{
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head= (struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;
    traverse(head);
    head=insertatfirst(head,50);
    printf("\nat first node \n");
    traverse(head);
    printf("\nAt the end\n");
    head=insertatend(head,120);
    traverse(head);

    printf("\n AT THE index\n");
    head=insertatindex(head,500,3);
    traverse(head);

    printf("\n AT the given position :\n");
    head=insertatnode(head,second,300);
    traverse(head);
    return 0;
}