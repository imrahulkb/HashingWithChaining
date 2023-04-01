#include <stdio.h>
#include<stdlib.h>
struct link
{
    int data;
    struct link* next;
};
typedef struct link link;

link* newNode(int data)
{
    link * new = (link *)malloc(sizeof(link));
    new->data=data;
    return new;
}

link* insert(int data,link* head)
{
    if(head==NULL) return newNode(data);
    else head->next=insert(data,head->next);
    return head;
}

link* display(link* head)
{
    link * temp = head;
    while(head!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

link* search(int data, link* head)
{
   while(head!=NULL)
   {
       if(head->data==data)
       {
           return head;
           exit(0);
       }
       head=head->next;
   }
   return NULL;
}

int main()
{
    link* arr[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    int o,d,x;
    while(1)
    {
        printf("\nEnter 1 to insert data \nEnter 2 to display hash table \nEnter 3 to search : ");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
                printf("\nEnter the integer to be inserted : ");
                scanf("%d",&d);
                x=d%10;
                if(arr[x]==NULL)
                {
                    arr[x]=insert(d,arr[x]);
                }
                else insert(d,arr[x]);
                break;
            case 2:
                for(int i=0;i<10;i++)
                {
                    printf("\n %d : ",i);
                    display(arr[i]);
                    printf("(nil)\n");
                }
                break;
            case 3:
                printf("Enter The Number To Be Searched in hash Table : ");
                scanf("%d",&d);
                x=d%10;
                if(search(d,arr[x])!=NULL)
                printf("\t\tData Found At address : %p",search(d,arr[x]));
                else printf("\t\tGiven data not found : ");
                break;
            default:
                printf("\t\tInvalid Input !!!");
        }
    }
    return 0;
}
