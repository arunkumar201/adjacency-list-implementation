#include<stdio.h>
#include<stdlib.h>
#define v 5
void add_edge(int s,int dest);
void print();
void empty_list();



struct node 
{
int data;
struct node *next;
};
struct node *adjlist[v];
void empty_list()
{
  int i;
  for(i=0;i<v;i++)
  {
    adjlist[i]=NULL;

  }
}

int main()
{ int p;
int s,dest;
  empty_list();
  printf("\nplease enter\nnumber of the pairs of source and destination vertices\n");
    scanf("%d",&p);
     for(int i=0;i<p;i++)
       { 
        scanf("%d %d",&s,&dest); 
      
        add_edge(s,dest);
       }
        print();
        return 0;
}
        





/*void add_edge(int s,int dest) //O(N)
{
  struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=dest;
    newnode->next=0;
  if(adjlist[s]==NULL)
  {
    adjlist[s]=newnode;
  }
  else
{
    struct node *temp=adjlist[s];
    while(temp->next)
    {
      temp=temp->next;
    }
    temp->next=newnode;
   }

}*/
void add_edge(int s,int dest)  //O(1)
{    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=dest;
    newnode->next=adjlist[s];
    adjlist[s]=newnode;
    
}
void print()
{
int i;
for(i=0;i<v;i++)
{
  struct node *temp=adjlist[i];
  printf("for adjlist[%d]:",i);
  while(temp)
  {
    printf("%d >",temp->data);
    temp=temp->next;
  }
  printf(">NULL");
  printf("\n");
}
}
