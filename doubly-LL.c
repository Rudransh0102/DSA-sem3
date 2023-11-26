#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertAtFront(struct Node **head, int data)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = (*head);
  newNode->prev = NULL;

  if ((*head) != NULL)
  {
    (*head)->prev = newNode;
  }
  (*head) = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if ((*head) == NULL)
  {
    newNode->prev = NULL;
    (*head) = newNode;
    return;
  }
  struct Node *ptr = (*head);
  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = newNode;
  newNode->prev = ptr;
}

void insertAfterNode(struct Node *node, int data)
{
  if (node == NULL)
  {
    printf("The given node cannot be NULL.");
    return;
  }
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = node->next;
  node->next = newNode;
  newNode->prev = node;

  if (newNode->next != NULL)
  {
    newNode->next->prev = newNode;
  }
}

void insertBeforeNode(struct Node **head, struct Node *node, int data)
{
  if (node == NULL)
  {
    printf("The given node cannot be NULL.");
    return;
  }

  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = node;
  if (node->prev != NULL)
  {
    node->prev->next = newNode;
    newNode->prev = node->prev;
  }
  else
  {
    *head = newNode;
  }
  node->prev = newNode;
}

void deleteAtFront(struct Node **head)
{
  if ((*head) == NULL)
    return;
  struct Node *curr = *head;
  *head = (*head)->next;
  curr->next = NULL;
  free(curr);
}

void deleteAtLast(struct Node **head)
{
  if ((*head) == NULL)
    return;
  struct Node *curr = *head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  struct Node *prev = curr->prev;
  prev->next = NULL;
  curr->prev = NULL;
  free(curr);
}

void deleteAtPosition(struct Node **head, int position)
{
  struct Node *curr = *head;
  if (position == 1)
  {
    deleteAtFront(head);
    return;
  }
  while (position > 1 && curr)
  {
    curr = curr->next;
    position--;
  }
  if (curr == NULL)
  {
    printf("Node at position is not present.\n");
    return;
  }
  struct Node *prevNode = curr->prev;
  struct Node *nextNode = curr->next;
  curr->prev->next = nextNode;
  if (nextNode != NULL)
  {
    nextNode->prev = prevNode;
  }
  curr->next = curr->prev = NULL;
  free(curr);
}

void traverse(struct Node *head)
{
  for (struct Node *i = head; i != NULL; i = i->next)
  {
    printf("%d", i->data);
    if (i->next)
      printf(" <--> ");
  }
  printf(" -> NULL \n");
}

int main()
{
  struct Node *head = NULL;
  int choice, data, position;

  do
  {
    printf("\n-- Doubly Linked List Operations --\n");
    printf("1. Insert at the front\n");
    printf("2. Insert at the end\n");
    printf("3. Insert after a node\n");
    printf("4. Insert before a node\n");
    printf("5. Delete at the front\n");
    printf("6. Delete at the end\n");
    printf("7. Delete at a position\n");
    printf("8. Traverse the list\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to insert at the front: ");
      scanf("%d", &data);
      insertAtFront(&head, data);
      break;
    case 2:
      printf("Enter data to insert at the end: ");
      scanf("%d", &data);
      insertAtEnd(&head, data);
      break;
    case 3:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter data after which to insert: ");
      scanf("%d", &position);
      insertAfterNode(head, data);
      break;
    case 4:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter data before which to insert: ");
      scanf("%d", &position);
      insertBeforeNode(&head, head, data);
      break;
    case 5:
      deleteAtFront(&head);
      break;
    case 6:
      deleteAtLast(&head);
      break;
    case 7:
      printf("Enter position to delete: ");
      scanf("%d", &position);
      deleteAtPosition(&head, position);
      break;
    case 8:
      traverse(head);
      break;
    case 9:
      while (head != NULL)
      {
        struct Node *temp = head;
        head = head->next;
        free(temp);
      }
      printf("Exiting the program.\n");
      exit(0);
    default:
      printf("Invalid choice. Please enter a valid option.\n");
    }
    } while(choice != 9);

     return 0;
  }
