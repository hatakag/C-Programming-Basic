#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum{SUCCESS,FAIL};
typedef struct PhoneDB {
  char model[30];
  int rom;
  float size;
  long price;
}phone;

struct list_el {
  phone addr;
  struct list_el *next;
};
typedef struct list_el node_addr;

node_addr *root,*cur;

node_addr* makeNewNode(phone addr) { //insert at tail
  node_addr* new=(node_addr*)malloc(sizeof(node_addr));
  new->addr=addr;
  new->next=NULL;
  return new;
}

void insertAtTail(phone addr) {
  node_addr *new=makeNewNode(addr);
  node_addr *p=root;
  if (root==NULL) {
    root=new;
  }
  else {
    while (p->next!=NULL) {
      p=p->next;
    }
    p->next=new;
    new->next=NULL;
  }
  cur=new;
}

void displayNode(node_addr* p) {
  if (p==NULL) {
    printf("Loi con tro NULL\n");
    return ;
  }
  phone tmp=p->addr;
  printf("%s----%dGB----%.1f\"----%ld VND\n",tmp.model,tmp.rom,tmp.size,tmp.price);
}

void traversingList(){
  node_addr *p;
  for (p=root;p!=NULL;p=p->next) 
    displayNode(p);
}

void strlwr(char *s,char *s1) {
  int i; 
  strcpy(s1,s);
  for (i=0;i<strlen(s1);i++) {
    if (s1[i]>='A' && s1[i]<='Z') s1[i]=s1[i]+32;
  }
}

void searchAllModel(char *mod) { //search all position (model)
  node_addr *p=root;
  int flag=0;
  char *mod2;
  mod2=(char*)malloc(30*sizeof(mod2)); // cap phat bo nho dong tranh core dumped
  strlwr(mod,mod);
  while (p!=NULL) {
    strlwr((p->addr).model,mod2);//->chu thuong
    if (strstr(mod2,mod)) { 
      displayNode(p);
      flag=1;
    }
    p=p->next;
  }
  if (flag==0) printf("Not found");
  printf("\n");
  free(mod2);
}

void searchAllPrice(long x) {
  node_addr *p=root;
  int flag=0;
  while (p!=NULL) {
    if ((p->addr).price<=x) {
      displayNode(p);
      flag=1;
    }
    p=p->next;
  }
  if (flag==0) printf("Not found");
  printf("\n");
}

void exportToArray(phone *phonearr) {
  node_addr *p;
  int i=0;
  for (p=root;p!=NULL;p=p->next) {
    phonearr[i]=p->addr;
    // printf("%s----%dGB----%.1f\"----%ld VND\n",phonearr[i].model,phonearr[i].rom,phonearr[i].size,phonearr[i].price);
    i++;
  }
}

void freeAllNode() { 
  node_addr* to_free=root;
  while (to_free!=NULL) {
    root=root->next;
    free(to_free);
    to_free=root;
  }
}

int main(int argc,char* argv[]) {
  if (argc!=4) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp1,*fp2,*fp3;
  int reval=SUCCESS;
  int choice,i,irc,n=20;
  phone * phonearr;
  int flag=0;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Import from Text\n");
    printf("2.Import from Dat\n");
    printf("3.Display List\n");
    printf("4.Search phone by Model\n");
    printf("5.Search phone by Price(lower)\n");
    printf("6.Export to Dat\n");
    printf("7.Quit\n");
    printf("Select: ");
    scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	if (flag==0) flag=1;
	else {
	  printf("Already import to linked list\n");
	  break;
	}
	if ((fp1=fopen(argv[1],"r"))==NULL) {
	  printf("Cannot open %s file\n",argv[1]);
	  return FAIL;
	} else {
	  phonearr=(phone*)malloc(n*sizeof(phone));
	  if (phonearr==NULL) {
	    printf("Memory allocation failed\n");
	    return FAIL;
	  }	  
	  for (i=0;i<n;i++) {
	    fscanf(fp1,"%[^\t]%*c %d%*s %f%*c %ld%*s",phonearr[i].model,&phonearr[i].rom,&phonearr[i].size,&phonearr[i].price);__fpurge(stdin);
	    printf("%s----%dGB----%.1f\"----%ld VND\n",phonearr[i].model,phonearr[i].rom,phonearr[i].size,phonearr[i].price);
	    insertAtTail(phonearr[i]);	    
	  }
	}
	fclose(fp1);free(phonearr);
	break;
      }
    case 2:
      {
	if (flag==0) flag=1;
	else {
	  printf("Already import to linked list\n");
	  break;
	}
	if ((fp2=fopen(argv[2],"rb"))==NULL) {
	  printf("Cannot open %s file\n",argv[2]);
	  return FAIL;
	} else {
	  phonearr=(phone*)malloc(n*sizeof(phone));
	  if (phonearr==NULL) {
	    printf("Memory allocation failed\n");
	    return FAIL;
	  }
	  irc=fread(phonearr,sizeof(phone),n,fp2);
	  printf("fread return code = %d\n",irc);
	  for (i=0;i<n;i++) {
	    printf("%s----%dGB----%.1f\"----%ld VND\n",phonearr[i].model,phonearr[i].rom,phonearr[i].size,phonearr[i].price);
	    insertAtTail(phonearr[i]);
	  }
	}
	fclose(fp2);free(phonearr);
	break;
      }
    case 3:
      {
	if (flag==0) {
	  printf("Import database from text file or dat file to linked list first\n");
	  break;
	}
	traversingList(root);
	break;
      }
    case 4:
      {
	if (flag==0) {
	  printf("Import database from text file or dat file to linked list first\n");
	  break;
	}
	char *s;
	s=(char*)malloc(30*sizeof(char));
	printf("Model you want to search: ");
	gets(s);__fpurge(stdin);
	searchAllModel(s);
	free(s);
	break;
      }
    case 5:
      {
	if (flag==0) {
	  printf("Import database from text file or dat file to linked list first\n");
	  break;
	}
	long x;
	printf("Price you can pay: ");
	scanf("%ld",&x);__fpurge(stdin);
	searchAllPrice(x);
	break;
      }
    case 6:
      {
	if (flag==0) {
	  printf("Import database from text file or dat file to linked list first\n");
	  break;
	}
	if ((fp3=fopen(argv[3],"wb"))==NULL) {
	  printf("Cannot open %s file\n",argv[3]);
	  return FAIL;
	} else {
	  phonearr=(phone*)malloc(n*sizeof(phone));
	  if (phonearr==NULL) {
	    printf("Memory allocation failed\n");
	    return FAIL;
	  }
	  exportToArray(phonearr);
	  irc=fwrite(phonearr,sizeof(phone),n,fp3);
	  printf("fwrite return code = %d\n",irc);
	}
	fclose(fp3);free(phonearr);
	if ((fp3=fopen(argv[3],"rb"))==NULL) {
	  printf("Cannot open %s file\n",argv[3]);
	  return FAIL;
	} else {
	  phonearr=(phone*)malloc(n*sizeof(phone));
	  if (phonearr==NULL) {
	    printf("Memory allocation failed\n");
	    return FAIL;
	  }
	  irc=fread(phonearr,sizeof(phone),n,fp3);
	  printf("fread return code = %d\n",irc);
	  for (i=0;i<n;i++) {
	    printf("%s----%dGB----%.1f\"----%ld VND\n",phonearr[i].model,phonearr[i].rom,phonearr[i].size,phonearr[i].price);
	  }
	}
	fclose(fp3);free(phonearr);
	break;
      }
    case 7:
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while (choice!=7);
  printf("\n____GOODBYE____\n");
  freeAllNode();
  return reval;
}
