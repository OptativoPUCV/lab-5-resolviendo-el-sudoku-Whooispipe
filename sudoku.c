#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int marked[10];

  for(int i=0;i<9;i++)
  {
    for(int j=0;j<=9;j++)marked[j]=0;
    for(int p=0;p<9;p++)
    {
      int val=n->sudo[i][p];
      if(val!=0)
      {
        if(marked[val])return 0;
        marked[val]=1;
      }
    }
  }
  for (int j = 0; j < 9; j++) 
  {
    for (int k = 1; k <= 9; k++) marked[k] = 0;
    for (int i = 0; i < 9; i++) 
    {
      int val = n->sudo[i][j];
      if (val != 0) 
      {
        if (marked[val]) return 0; 
         marked[val] = 1;
      }
    }
  }
  for (int k = 0; k < 9; k++) 
  {
    for (int x = 1; x <= 9; x++) marked[x] = 0;
    for (int p = 0; p < 9; p++) 
    {
        int i = 3 * (k / 3) + (p / 3);
        int j = 3 * (k % 3) + (p % 3);
        int val = n->sudo[i][j];
        if (val != 0) 
        {
          if (marked[val]) return 0; 
               marked[val] = 1;
        }
    }
  }
    return 1;
}


/*
1.Cree una función que a partir de un nodo genere una **lista con los nodos adyacentes**:

    List* get_adj_nodes(Node* n){
       List* list=createList();
      
       obtenga los nodos adyacentes a n
       y agréguelos a la lista
       
       return list;
    }

Recuerde que los nodos adyacentes son generados aplicando las acciones al estado actual.
*/

List* get_adj_nodes(Node* n)
{
    List* list=createList();
    int filas =-1; 
    int col =-1;

    for(int i=0; i<9&& filas == -1;i++)
      {

        for(int j=0;j<9;j++)
        {
          if(n->sudo[i][j]==0)
          {
            filas=i;
            col=j;
            break;
          }
        }
      }
    
    if(filas==-1){return list;}
  for(int p=1; p<=9;p++)
  {

    Node* nuevo=malloc(sizeof(Node));
    if(nuevo==NULL)
    {
      exit(EXIT_FAILURE);
    }
    memcpy(nuevo->sudo,n->sudo,sizeof(n->sudo));    
    nuevo->sudo[filas][col]=p;

    if(is_valid(nuevo))
    {
      pushBack(list,nuevo);
    }
    else{free(nuevo);}
    
    
  }
  return list;
}


int is_final(Node* n){
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {

      if(n->sudo[i][j]==0)
      {
        return 1;
      }
    }


  }
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/