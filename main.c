#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

typedef struct Node Node;
Node *head;

void insertF(int data){
Node *temp = (Node*)malloc(sizeof(Node));
temp->data = data;
temp->next = NULL;
if (head == NULL){
  head = temp;
}
else{
  temp->next = head;
  head = temp;
}
}

void insertE(int data){
Node *temp = (Node*)malloc(sizeof(Node));
temp->data = data;
temp->next = NULL;

if (head == NULL){
  head = temp;
}
else{
  Node *temp2 = head;
  while (temp2->next != NULL){
    temp2 = temp2->next;
  }
  temp2->next = temp;
}
}

void insertN(int data,int location){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;

  if (location == 1){
    temp->next = head;
    head = temp;
  }
  
  else{
    Node *temp2 = head;
    int i;
    for (i = 1; i<=(location-1); i++){
      temp2=temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
  }
}

void print(){
  Node *temp = head;
  while (temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
}

int main(void) {
  head = NULL;
  int listLength,data,location,i;
  int position;

  printf("Please enter the length of the list\n");
  scanf("%d",&listLength);

  printf("Where would you like to insert the data, press 1 for front, 2 for end and 3 for a speciific node replacement\n");

  scanf("%d",&position);

  // printf("%d",position);

  if (position == 1){
    for (i =0; i<listLength;i++){
      printf("Please insert the data\n");
      scanf("%d",&data);
      insertF(data);
      print();
      printf("\n");
    }
  }

  else if (position == 2) {
    for (i = 0; i<listLength;i++){
      printf("Please insert the data\n");
      scanf("%d",&data);
      insertE(data);
      print();
      printf("\n");
    }
  }

  else if (position == 3) {
     for (i = 0; i<listLength;i++){
      printf("Please insert the data\n");
      scanf("%d",&data);
      printf("Please insert the location\n");
      scanf("%d",&location);
      insertN(data,location);
      print();
      printf("\n");
    }
  }

  return 0;
}