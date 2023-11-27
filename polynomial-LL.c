#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int coefficient;
  int exponent;
  struct Node *next;
};

void mergeNodes(struct Node *head);
void displayPolynomial(struct Node *ptr);
struct Node *appendNode(struct Node *start, int coefficient, int exponent);

struct Node *multiplyPolynomialLL(struct Node *head1, struct Node *head2, struct Node *head3)
{
  struct Node *ptr1, *ptr2;
  ptr1 = head1;
  ptr2 = head2;

  while (ptr1 != NULL)
  {
    while (ptr2 != NULL)
    {
      int coefficient, exponent;
      coeff = ptr1->coefficient * ptr2->coefficient;
      exponent = ptr1->exponent + ptr2->exponent;
      head3 = appendNode(head3, coeff, exponent);
      ptr2 = ptr2->next;
    }
    ptr2 = head2;
    ptr1 = ptr1->next;
  }

  mergeNodes(head3);
  return head3;
}

void displayPolynomial(struct Node *ptr)
{
  while (ptr->next != NULL)
  {
    if (ptr->coefficient != 0 && ptr->coefficient != 1)
    {
      if (ptr->exponent != 0 && ptr->exponent != 1)
        printf("%dx^%d", ptr->coefficient, ptr->exponent);
      else if (ptr->exponent == 1)
        printf("%dx", ptr->coefficient);
      else
        printf("%d", ptr->coefficient);
    }
    else if (ptr->coefficient == 1)
    {
      if (ptr->exponent != 0 && ptr->exponent != 1)
        printf("x^%d", ptr->exponent);
      else if (ptr->exponent == 1)
        printf("x");
      else
        printf("%d", ptr->coefficient);
    }
    if (ptr->next != NULL && ptr->next->coefficient >= 0)
      printf("+");

    ptr = ptr->next;
  }
  printf("%d\n", ptr->coefficient);
}

struct Node *appendNode(struct Node *start, int coefficient, int exponent)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->coefficient = coefficient;
  newnode->exponent = exponent;
  newnode->next = NULL;

  if (start == NULL)
    return newnode;

  struct Node *ptr = start;

  while (ptr->next != NULL)
    ptr = ptr->next;

  ptr->next = newnode;

  return start;
}

void mergeNodes(struct Node *head)
{
  struct Node *ptr1, *ptr2, *dup;
  ptr1 = head;

  while (ptr1 != NULL && ptr1->next != NULL)
  {
    ptr2 = ptr1;

    while (ptr2->next != NULL)
    {
      if (ptr1->exponent == ptr2->next->exponent)
      {
        ptr1->coefficient = ptr1->coefficient + ptr2->next->coefficient;
        dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        free(dup);
      }
      else
        ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
}

int main()
{
  struct Node *head1, *head2, *head3;
  head1 = head2 = head3 = NULL;

  head1 = appendNode(head1, 1, 2);
  head1 = appendNode(head1, -5, 1);
  head1 = appendNode(head1, 9, 0);

  head2 = appendNode(head2, 1, 3);
  head2 = appendNode(head2, -10, 2);
  head2 = appendNode(head2, 9, 1);
  head2 = appendNode(head2, 1, 0);

  head3 = multiplyPolynomialLL(head1, head2, head3);

  printf("P(x) = ");
  displayPolynomial(head1);
  printf("Q(x) = ");
  displayPolynomial(head2);
  printf("P(x)*Q(x) = ");
  displayPolynomial(head3);

  return 0;
}
