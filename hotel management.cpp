#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define newnode (struct node *)malloc(sizeof(struct node))
#define max 10
struct node
{
	char *num;
	int room;// room no to be alloted.
	char *id;
	char *name;
	char *city;
	char *state;
	char *country;
	char *check_in;
	struct node *next;// structure pointer.
};

struct node *head;// pointer which will hold or point to the whole linked list.
int size=0;
struct node *insert(struct node *head)// pointer function
{
  
  
	  	if(head==NULL)
	{
		head=newnode;
		printf("enter name:");
		head->name=(char *)malloc(sizeof(char));// dynamic memory allocation.
		scanf("%s",head->name);
		printf("enter id:");
		head->id=(char *)malloc(sizeof(char));
		scanf("%s",head->id);
		printf("enter city:");
		head->city=(char *)malloc(sizeof(char));
		scanf("%s",head->city);
		printf("enter state:");
		head->state=(char *)malloc(sizeof(char));
		scanf("%s",head->state);
		printf("enter country:");
		head->country=(char *)malloc(sizeof(char));
		scanf("%s",head->country);
		printf("enter check in date:");
		head->check_in=(char *)malloc(sizeof(char));
		scanf("%s",head->check_in);
		printf("enter number:");
		head->num=(char *)malloc(sizeof(char));
		scanf("%s",head->num);
		printf("enter room:");
		scanf("%d",&head->room);
		head->next=NULL;
		
	}
	else
	{
		struct node *p=(struct node *)malloc(sizeof(struct node));
		struct node *q=head;
		printf("enter name:");
		p->name=(char *)malloc(sizeof(char));
		scanf("%s",p->name);
		printf("enter id:");
		p->id=(char *)malloc(sizeof(char));
		scanf("%s",p->id);
		printf("enter city:");
		p->city=(char *)malloc(sizeof(char));
		scanf("%s",p->city);
		printf("enter state:");
		p->state=(char *)malloc(sizeof(char));
		scanf("%s",p->state);
		printf("enter country:");
		p->country=(char *)malloc(sizeof(char));
		scanf("%s",p->country);
		printf("enter check in date:");
		p->check_in=(char *)malloc(sizeof(char));
		scanf("%s",p->check_in);
		printf("enter number:");
		p->num=(char *)malloc(sizeof(char));
		scanf("%s",p->num);
		printf("enter room no:");
		scanf("%d",&p->room);
		p->next=NULL;
		while(q->next!=NULL)
		{
			q=q->next;
		};
		q->next=p;
		
		return head;
	
  }
  
}
void display(struct node*head)
{
	struct node *m=head;
 	printf("\nRecord of hotel:\n");
    printf("name\tid\tcity\t\tstate\t\tcountry\t\tcheck-date\t\tnumber\t\troom-no");
	while(m!=NULL)
	{
	  printf("\n%s\t%s\t%s\t\t%s\t%s\t\t%s\t\t%s\t%d",m->name,m->id,m->city,m->state,m->country,m->check_in,m->num,m->room);
		m=m->next;
	}

}
struct node *del(struct node *head)
{
	int c,k,i;
	printf("\n1-delete first booking\n2-delete last booking\n3-delete bookings");
	printf("\nenter choice:");
	scanf("%d",&c);
	struct node *t=head;
	struct node *temp=head;
   	switch(c)
	{
		case 1:
		        temp=temp->next;
		        head=temp;
		        return head;
		        break;
		case 2:printf("\nlast room no to deleted\n");
		        temp=head;
		        while(t->next!=NULL)
		        {  
		            temp=t;
		        	t=t->next;
				}
				temp->next=NULL;
				return head;
				break;
	    case 3:temp=head;
		        printf("enter position:");
		        scanf("%d",&k);
		        for(i=1;i<=k-1;i++)
		        {   
		            t=temp;
		        	temp=temp->next;
				}
				t->next=temp->next;
				printf("\nRoom no at %dth position has been deleted\n",i);
				return head;
	}
}
void search(struct node *head)
{
	char name[50];
	int room_no,c,flag;
	struct node *p=head;
	struct node *temp=head;
	printf("\n1-room-no\n2-name");
	printf("\nenter choice:");
	scanf("%d",&c);
	switch(c)
	{
	
	       case 1:   printf("\nenter room no :-");
	                scanf("%d",&room_no);
	                while(p!=NULL)
	               {
	
	                 if(p->room==room_no)
	                {
		              printf("booking found\n");
		            
					   flag=1;	
		               break;
	                }
	 
		             p=p->next;
                   }
                    if(flag==0)
                    {
   
                      printf("booking not found");
		    
                    }
                    break;
            
			case 2: printf("enter name:");
			        scanf("%s",&name);
			        
			        while(p!=NULL)
			        {
			        	if(strcmp(p->name,name)==0) // strcmp is used to compare 2 strings .
			        	{   
			        		printf("booking found\n");
			        	
			        		flag=1;
			        		break;
						}
						p=p->next;
						
					}
					if(flag==0)
						{
							printf("booking not found");
						}
						break;
			
		}
}
int main()
{
	printf("Welcome to Hotel rivera\n");
	printf("please proceed with your bookings");
	int c,size;
	while(1)
	{
		printf("\n1-book\n2-bookings\n3-check-out\n4-search\n5-exit:");
		printf("\nenter choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:if(size<max)
			       {
				     head=insert(head);
				     size=size+1;
				   }
				   else
				   {
				   	 printf("Hotel is fully booked\n");
				   }
				   	printf("booking sucessfully completed\n");
			       break;
			case 2:display(head);
		            break;
		    case 3: head=del(head);
		            printf("booking sucessfully deleted\n");
		            break;
		    case 4: search(head);
		            break;
		    case 5: exit(0);
		       
		}
	}
}
