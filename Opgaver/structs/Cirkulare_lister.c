#include <stdio.h>
#include <stdlib.h>

struct point {int x; int y;};
typedef struct point point;

struct list_node {
  void             *data;
  struct list_node *next;
};
typedef struct list_node list_node;

void print_point(point *p);
void print_circular_point_list(list_node *cl);
list_node *insert_head(list_node *cl, void *el);
list_node *insert_tail(list_node *cl, void *el);
list_node *delete_head(list_node *cl);
list_node *delete_tail(list_node *cl);
int length_of_circular_list(list_node *cl);
list_node *find_previous_node(list_node *cl);

int main(void) {
  point p1 = {1,2}, p2 = {3,4}, p3 = {5,6}, p4 = {7,8};

  list_node *circular_list = NULL;
  printf("Length of circular list: %d\n", length_of_circular_list(circular_list));

  return EXIT_SUCCESS;
}

void print_point(point *p){
  printf("(%1d, %1d)\n", p->x, p->y);
}

void print_circular_point_list(list_node *cl){
  list_node *cur, *prev;

  if (cl != NULL){
   cur = cl->next;
   do{
     prev = cur;
     print_point(cur->data);
     cur = cur->next;
   }
   while(prev != cl);
  }
}

/* An exercise */
int length_of_circular_list(list_node *cl) {
  int length = 0;
  int first_element = cl->data;
  
  if(cl->next == NULL) {
   return 0;
  }
  
  return length; 
}