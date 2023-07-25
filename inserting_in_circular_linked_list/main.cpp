//
//  main.cpp
//  inserting_in_circular_linked_list
//
//  Created by Uby H on 25/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;
void create(int A[],int n)
{
    struct Node *t=NULL,*last=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=head;
        last->next=t;
        last=t;
    }
}
void display(int n)
{
    struct Node *p=NULL;
    p=head;
    for(int i=0;i<n;i++)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void insert(int pos,int x)
{
    struct Node *t,*p;
    int i;
    t= new Node;
    t->data=x;
    t->next=NULL;
    if(pos==0)
    {
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            p=head;
            while(p->next!=head)
                p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        p=head;
        for(i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int main()
{
    int n=0,x=0,pos=0;
    cout<<"Enter the number of elements in the circular linked list : "<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the elements in the linked list : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    create(A,n);
    cout<<"The original linked list is given by : "<<endl;
    display(n);
    cout<<"Enter the element to be entered in the linked list : "<<endl;
    cin>>x;
    cout<<"Enter the position at which the element should be entered : "<<endl;
    cin>>pos;
    insert(pos,x);
    cout<<"The updated linked list is given by : "<<endl;
    display(n+1);
    return 0;
}
