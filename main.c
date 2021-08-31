#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure Declaration
struct node
{
    /* data */
    char name[50];//name of contact
    char num[10];//phone number of contact
    struct node *next; //next pointer to store the address of next node
    
};

typedef struct node Node;
typedef struct node *link;

//Function Definitions
void display(link head);
void insert(link head,link new_node);
void delete(link head);
void search(link head);
void modify(link head);


//Function to Create a new node initialization list
void create_link(link *head)
{
    *head=(link)malloc(sizeof(Node));
    (*head)->next=NULL;
}

int main()
{
    int i,j,m;
    link head;
    link new_node;
    create_link(&head);

    printf("\n\t\t\t\t\t\t\tWorking Phonebook\n");

    while (1 == 1)
    {
       printf("\n\t\t\t\t\t\t1. New Contact\n");
		printf("\t\t\t\t\t\t2. Search for Contact\n");
		printf("\t\t\t\t\t\t3. Modify Contact\n");
		printf("\t\t\t\t\t\t4. Delete Contact\n");
		printf("\t\t\t\t\t\t5. Show All Contacts\n");
		printf("\t\t\t\t\t\t6. Exit Phonebook\n");
		printf ("\n\tEnter your Choice: ");
		scanf("%d",&m);
		switch(m)
		{
			case 1:	insert_node(head,new_node);
					break;
			case 2:	search(head);
					break;
			case 3:	mod_node(head);
					break;
			case 4:	delete_node(head);
					break;
			case 5:	display(head);
					break;
			case 6:	return 0;
		}
    }
    

}





