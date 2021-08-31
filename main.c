#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    /* data */
    char name[50];//name of contact
    char num[10];//phone number of contact
    struct node *next; //next pointer to store the address of next node
    
};

typedef struct node Node;
typedef struct node *link;





