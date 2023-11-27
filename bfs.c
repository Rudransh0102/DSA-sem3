#include<stdio.h>
#define MAX 10

void bfs(int adj[][MAX], int visited[], int start, int n)
{
  int queue[MAX], rear = -1, front = -1, i;

  // adding the starting vertex to the queue
  queue[++rear] = start;

  // marking the starting vertex as visited
  visited[start] = 1;

  while (rear != front)
  {
    // removing the vertex at the front of the queue
    start = queue[++front];
    printf("%d ", start);

    // adding the adjacent unvisited vertices to the queue
    for (i = 0; i < n; i++)
    {
      if (adj[start][i] == 1 && visited[i] == 0)
      {
        queue[++rear] = i;
        visited[i] = 1;
      }
    }
  }
}

int main(){
  int adj[MAX][MAX], visited[MAX], i, j, n, start;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix: \n");
  for (i = 0; i < n; i++)
  {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < n; j++)
      scanf("%d", &adj[i][j]);
  }

  for (i = 0; i < n; i++)
    visited[i] = 0;

  printf("Enter the starting vertex: ");
  scanf("%d", &start);

  printf("The BFS traversal of the graph is: ");
  bfs(adj, visited, start, n);

  printf("\n");

  return 0;
}

// Enter the number of vertices: 6    
// Enter the adjacency matrix:
// Enter row 1: 0 1 1 0 0 0
// Enter row 2: 0 0 0 1 1 0
// Enter row 3: 0 0 0 0 0 1
// Enter row 4: 0 0 0 0 0 0
// Enter row 5: 0 0 0 0 0 0
// Enter row 6: 0 0 0 0 0 0
// Enter the starting vertex: 0
// The BFS traversal of the graph is: 0 1 2 3 4 5