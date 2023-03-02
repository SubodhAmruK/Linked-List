#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create()
{
    int c;
    if(head!=NULL)
    {
        printf("\n ------------------------");
        printf("\n LIST IS ALREADY CREATED!\n");
        printf(" ------------------------");
    }
    else
    {
        printf("\nNumber of elements you want to insert into the list:");
        scanf("%d",&c);
    for(int i=1;i<=c;i++)
    {
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the element into the new node:");
        printf("\nelement %d : ",i);
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
        }
    }

}

void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {

                printf("%d --> ",ptr->data);
                ptr=ptr->next;

        }
        printf("%d",ptr->data);
    }
}

void inbegin()
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element you want to insert at beginning:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        ptr=head;
        head=temp;
        temp->next=ptr;
    }
}

void inlocation()
{
    int l,i;
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element you want insert at a location:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    printf("\nEnter the location of the new element:");
    scanf("%d",&l);
    if(l==0)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        for(ptr=head,i=1;i<l-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nLocation out of bounds!");
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

void inend()
{
        struct node *temp,*ptr;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the element you want insert at end:");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
}

void delbegin()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        ptr=head;
        head=ptr->next;
        printf("\%d deleted successfully",ptr->data);
        free(ptr);
    }
}

void delend()
{
    struct node *ptr,*temp;
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        free(ptr);
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("\n%d is deleted successfully",ptr->data);
        free(ptr);
    }
}

void dellocation()
{
    int l,i;
    struct node *ptr,*temp;
    printf("\nEnter the location you want to delete:");
    scanf("%d",&l);
    if(l==0)
    {
        ptr=head;
        head=head->next;
        printf("\nThe deleted element is:%dt",ptr->data);
        free(ptr);
    }
    else
    {
        for(ptr=head,i=0;i<l-1;i++)
        {
            temp=ptr;
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nLocation out of bounds!");
            }
        }
            temp->next =ptr->next ;
            printf("\nThe deleted element is:%dt",ptr->data );
            free(ptr);

}
}
void search()
{
    int n,c=1;
    struct node *ptr;
    printf("\nEnter the element you want to search:");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->data==n)
            {
                printf("\nElement location in the list is: %d",c);
                break;
            }
            c++;
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("\nElement is not in the list");
        }

    }
}
void main()
{
    int n;
    while(1)
    {
        printf("\n         --------------------------");
        printf("\n         |       Linked List      |");
        printf("\n         --------------------------");
        printf("\n         | 1.Create List          |");
        printf("\n         | 2.Display List         |");
        printf("\n         | 3.Insert at beginning  |");
        printf("\n         | 4.Insert at location   |");
        printf("\n         | 5.Insert at end        |");
        printf("\n         | 6.Delete at beginning  |");
        printf("\n         | 7.Delete at location   |");
        printf("\n         | 8.Delete at end        |");
        printf("\n         | 9.Search for element   |");
        printf("\n         | 0.Exit                 |");
        printf("\n         --------------------------");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            inbegin();
            break;
        case 4:
            inlocation();
            break;
        case 5:
            inend();
            break;
        case 6:
            delbegin();
            break;
        case 7:
            dellocation();
            break;
        case 8:
            delend();
            break;
        case 9:
            search();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\n ------------------------");
            printf("\n Wrong Input, Try Again!\n");
            printf(" ------------------------");
        }
    }

}
