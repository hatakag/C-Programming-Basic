#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_t {
  char name[40];
  char id[12];
  float grade;
  struct student_t *next;
}student;

student* add_student(student* root,student* to_add) {
  student * curr_std, *prev_std=NULL;
  if (root==NULL)
    return to_add;
  if (to_add->grade >= root->grade) {
    to_add->next=root;
    return to_add;
  }
  curr_std=root;
  while (curr_std!=NULL && to_add->grade < curr_std->grade) {
    prev_std=curr_std;
    curr_std=curr_std->next;
  }
  prev_std->next=to_add;
  to_add->next=curr_std;
  return root;
}

student* find_student(student *root,char* id) {
  student* to_search=root;
  while(to_search!=NULL) {
    if (strcmp(to_search->id,id)==0)
      return to_search;
    to_search = to_search->next;
  }
  return NULL;
}

student* remove_student(student *root,char* id) {
  if (root==NULL) return root;
  student *cur,*prev=NULL;
  cur=root;
  if (strcmp(cur->id,id)==0) {
    root=root->next;
    free(cur);
    return root;
  }
  while (cur!=NULL && strcmp(cur->id,id)!=0) {
    prev=cur;
    cur=cur->next;
  }
  if (cur!=NULL) {
    prev->next=cur->next;
    free(cur);
  }
  return root;
}

student *create_student(char *name,char *id,float grade){
  student *new=(student*)malloc(sizeof(student));
  strcpy(new->name,name);
  strcpy(new->id,id);
  new->grade=grade;
  new->next=NULL;
  return new;
}

student *change_grade(student * root,char *id,int new_grade) {
  student *std=find_student(root,id);
  std=create_student(std->name,id,new_grade);
  root=remove_student(root,id);
  return add_student(root,std);
}

void displayNode(student* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  printf("%s----%s----%.2f----%p\n",p->id,p->name,p->grade,p->next);
}

void traversingList(student *q){ //printData
  student *p;
  for (p=q;p!=NULL;p=p->next) 
    displayNode(p);
}

int main() {
  student *root=NULL;
  root=create_student("bui cong thanh","20153363",10);
  traversingList(root);printf("\n");
  printf("Add student\n");
  root=add_student(root,create_student("nguyen van thanh","20153366",6.5));
  root=add_student(root,create_student("pham cong thanh","20153333",7));
  root=add_student(root,create_student("nguyen thi lan","20153361",4.9));
  traversingList(root);printf("\n");
  printf("Remove id %s: \n","20153361");
  root=remove_student(root,"20153361");
  traversingList(root);printf("\n");
  printf("Find id %s and change grade to %d: \n","20153366",9);
  root=change_grade(root,"20153366",9);
  traversingList(root);printf("\n");
}
