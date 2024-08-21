#include <stdio.h>
#include <stdlib.h>
void inB(int);
void inE(int);
void inS(int, int);
void deB();
void deE();
void deS(int);
void dis();
struct node
{
 int data;
 struct node *next;
} *head = NULL;
void main()
{
 int ch, val, loc;
 printf("Singly Linked List");
 for (;;)
 {
 printf("\nA.Insert:\t1.At Beginning\t2.At End\t3.At Specific Location");
 printf("\nB.Delete:\t4.At Beginning\t5.At End\t6.At Specific Location");
 printf("\n7.Display\t8.Exit\tChoice: ");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
 printf("Enter value: ");
 scanf("%d", &val);
 inB(val);
 break;
 case 2:
 printf("Enter value: ");
 scanf("%d", &val);
 inE(val);
 break;
 case 3:
 printf("Enter value: ");
 scanf("%d", &val);
 printf("Enter location: ");
 scanf("%d", &loc);
 inS(val, loc);
 break;
 case 4:
 deB();
 break;
 case 5:
 deE();
 break;
 case 6:
 printf("Enter location: ");
 scanf("%d", &val);
 deS(val);
 case 7:
 dis();
 break;
 case 8:
 return;
 default:
 printf("Invalid input");
 }
 }
}
void inB(int val)
{
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = val;
if (head == NULL)
 newnode->next = NULL;
 else
 newnode->next = head;
 head = newnode;
}
void inE(int val)
{
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = val;
 newnode->next = NULL;
 if (head == NULL)
 head = newnode;
 else
 {
 struct node *temp = head;
 while (temp->next != NULL)
 temp = temp->next;
 temp->next = newnode;
 }
}
void inS(int val, int loc)
{
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = val;
 if (head == NULL)
 {
 if (loc == 1)
 {
 newnode->next = NULL;
 head = newnode;
 }
 else
 {
printf("Invalid location. List is empty, can only insert at position 1.\n");
 free(newnode);
 }
 return;
 }
 if (loc == 1)
 {
 newnode->next = head;
 head = newnode;
 return;
 }
 struct node *temp = head;
 for (int i = 1; i < loc - 1 && temp != NULL; i++)
 {
 temp = temp->next;
 }
 if (temp == NULL)
 {
 printf("Invalid location. The position is beyond the list length.\n");
 free(newnode);
 return;
 }
 newnode->next = temp->next;
 temp->next = newnode;
}
void deB()
{
 if (head == NULL)
 printf("Empty List");
 else
 {
 struct node *temp = head;
head = head->next;
 free(temp);
 }
}
void deE()
{
 if (head == NULL)
 printf("Empty List");
 else
 {
 struct node *temp1 = head, *temp2 = NULL;
 while (temp1->next != NULL)
 {
 temp2 = temp1;
 temp1 = temp1->next;
 }
 if (temp1 == head)
 head = NULL;
 else if (temp2 != NULL)
 temp2->next = NULL;
 free(temp1);
 }
}
void deS(int loc)
{
 if (head == NULL)
 {
 printf("Empty List");
 return;
 }
 if (loc == 1) // If the node to be deleted is the first 
 {
 struct node *temp = head;
 head = head->next;
 free(temp);
 return;
 }
 struct node *temp1 = head, *temp2 = NULL;
 for (int i = 1; i < loc; i++)
 {
 temp2 = temp1;
 temp1 = temp1->next;
 if (temp1 == NULL)
 {
 printf("Invalid location. The position is beyond the list length.\n");
 return;
 }
 }
 temp2->next = temp1->next;
 free(temp1);
}
void dis()
{
 if (head == NULL)
 printf("Empty List");
 else
 {
 struct node *temp = head;
 printf("List: ");
 while (temp->next != NULL)
 {
 printf("%d--->", temp->data);
 temp = temp->next;
 }
 printf("%d", temp->data);
 }
}