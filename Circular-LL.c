#include <stdio.h>
#include <stdlib.h>

// creating a structure for the circular singly linked list
struct node
{
  int data;
  struct node *next;
};

// code for creating a new node
struct node *createNode()
{
  struct node *n;
  n = malloc(sizeof(struct node));
  return n;
}

// insertion at the beginning of the list is the push operation
struct node *push(int data, struct node *top)
{
  struct node *temp = createNode();
  temp->data = data;
  temp->next = NULL;

  // if the top of the stack is NULL, we push the item in the stack
  if (top == NULL)
  {
    top = temp;
    top->next = top;
    return top;
  }
  else
  {
    temp->next = top->next;
  }

  top->next = temp;

  return top;
}

// deletion of the front node is the POP operation
struct node *pop(struct node *top)
{
  struct node *first;

  if (top == NULL) // empty list
  {
    printf("Cannot delete, Empty Stack -> Stack Underflow condition.\n");
    return NULL;
  }

  if (top->next == top)
  {
    printf("Popped item is %d\n", top->data);
    free(top);
    return NULL;
  }

  first = top->next;

  printf("Popped item is %d\n", first->data);

  top->next = first->next;

  free(first);

  return top;
}

// to display the list in form of a stack
void display(struct node *top)
{
  struct node *current;

  if (top == NULL)
  {
    printf("Empty Stack -> Stack Underflow condition.\n");
    return;
  }
  
  if (top->next == top)
  {
    printf("%d\n", top->data);
    return;
  }

  current = top;

  while (current->next != top)
  {
    current = current->next;
    printf("%d\n", current->data);
  }

  current = current->next;
  printf("%d\n", current->data);
}

int main()
{
  int choice, data;
  struct node *top;
  top = NULL;

  do
  {
    printf("Select a choice:\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the data to be inserted in the stack: ");
      scanf("%d", &data);
      top = push(data, top);
      break;
    case 2:
      top = pop(top);
      break;
    case 3:
      display(top);
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice.Please try again.\n");
      break;
    }
  } while (choice != 4);

  return 0;
}
