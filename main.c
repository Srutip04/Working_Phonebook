#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure Declaration
struct node
{
    /* data */
    char name[50];     //name of contact
    char num[10];      //phone number of contact
    struct node *next; //next pointer to store the address of next node
};

typedef struct node Node;
typedef struct node *link;

//Function Definitions
void display(link head);
void insert(link head, link new_node);
void delete (link head);
void search(link head);
void modify(link head);

//Function to Create a new node initialization list
void create_link(link *head)
{
    *head = (link)malloc(sizeof(Node));
    (*head)->next = NULL;
}

//Function to insert contact details
void insert(link head, link new_node)
{
    link p, q;
    q = head;
    p = q->next;
    new_node = (link)malloc(sizeof(Node));

    printf("\n\tEnter Name: ");
    scanf("%s", new_node->name);

    //check whether the phone number has correct number of digits
    while (1 == 1)
    {
        /* code */
        printf("\tEnter Phone Number: ");
        scanf("%s", new_node->num);
        if (strlen(new_node->num) != 10)
        {
            printf("\n\tInvalid Phone Number!\n\n");
        }
        else
            break;
    }

    if (NULL == p)
    {
        q->next = new_node;
        new_node = p;
    }
    else
    {
        while (strcmp((new_node->name), (p->name)) == 1)
        {
            p = p->next;
            q = q->next;
        }
        new_node->next = p;
        q->next = new_node;
    }
}

//Function to delete a contact information
void delete_node(link head)
{
    link p, q;
    char comp[20];
    p = head->next;
    q = head;
    printf("\n\tEnter the Contact Name to be Deleted: ");
    scanf("%s", comp);
    if (p == NULL)
    {
        printf("\n\tPhonebook has no Contacts!\n\n");
    }
    else
    {
        //Determining whether the names are the same with the entered name and continue traversing
        while (p != NULL && (strcmp(p->name, comp) != 0))
        {
            q = p;
            p = p->next;
        }
        if (NULL == p)
        {
            printf("\n\tThere is no such Contact!\n\n");
        }
        else
        {
            q->next = p->next;
            free(p);
            printf("\n\tContact Deleted!\n\n");
        }
    }
}

//Function to search a given contact by its name
void search(link head)
{
	char comp[20];
	link q=head;
	link p=q->next;
	printf ("\n\tEnter the Contact Name to be Searched: "); 
	scanf("%s",comp);
	while(p!=NULL&&(strcmp(p->name,comp)!=0))
	{
		q=p;
		p=p->next;
	}
	if(NULL == p)
	{
		printf("\n\tCheck no such person!\n\n");
		return;
	}
	else
	{
		printf("\n\t\tName\t\tGender\t\tAge\t\tPhone Number\n");
		printf("\t\t%s\t\t",p->name );
		printf("%s\t\t",p->sex );
		printf("%d\t\t",p->age );
		printf("%s\n",p->num );
	}
}

int main()
{
    int i, j, m;
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
        printf("\n\tEnter your Choice: ");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            insert_node(head, new_node);
            break;
        case 2:
            search(head);
            break;
        case 3:
            mod_node(head);
            break;
        case 4:
            delete_node(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            return 0;
        }
    }
}
