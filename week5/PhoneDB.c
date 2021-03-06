#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum{SUCCESS,FAIL};
typedef struct PhoneDB {
  char model[30];
  int rom;
  float size;
  long price;
}phone;

void strlwr(char *s,char *s1) {
  int i; 
  strcpy(s1,s);
  for (i=0;i<strlen(s1);i++) {
    if (s1[i]>='A' && s1[i]<='Z') s1[i]=s1[i]+32;
  }
}

int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp1,*fp2;
  int reval=SUCCESS;
  int choice,i,irc,n=20;
  phone *phonearr;
  int flag=0,maxl=5;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Import DB from text\n");
    printf("2.Import from DB\n");
    printf("3.Print all phone DB\n");
    printf("4.Find model\n");
    printf("5.Exit\n");
    printf("Select: ");
    scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	flag=1;
	if ((fp1=fopen(argv[1],"rb"))==NULL) {
	  printf("Cannot open %s file\n",argv[1]);
	  return FAIL;
	} else if ((fp2=fopen("PhoneDB.dat","wb"))==NULL) {
	  printf("Cannot open %s file\n","PhoneDB.dat");
	  return FAIL;
	} else {
	  phonearr=(phone*)malloc(n*sizeof(phone));
	  if (phonearr==NULL) {
	    printf("Memory allocation failed\n");
	    return FAIL;
	  }	  
	  for (i=0;i<n;i++) {
	    fscanf(fp1,"%*c%[^\t]%*c %d%*s %f%*c %ld%*s",phonearr[i].model,&phonearr[i].rom,&phonearr[i].size,&phonearr[i].price);__fpurge(stdin);
	    printf("%s-",phonearr[i].model);
	    printf("%dGB-",phonearr[i].rom);
	    printf("%.1f\"-",phonearr[i].size);
	    printf("%ld VND\n",phonearr[i].price);
	  }
	  irc=fwrite(phonearr,sizeof(phone),n,fp2);
	  printf("fwrite return code = %d\n",irc);
	  free(phonearr);
	}
	fclose(fp1);fclose(fp2);
	break;
      }
    case 2:
      {
	int num=0;
	char s[5];
	if (flag==0) {
	  printf("Import database from text file to binary file first\n");
	  break;
	}
	printf("Number of elements you want to read: ");
	scanf("%d",&num);__fpurge(stdin);
	if (num>n) {
	  printf("Error--Not enough database\n");
	  break;
	}
	if (num<=0) {
	  printf("Error--Number must be more than 0\n");
	  break;
	}
	printf("Read from begin or end: ");
	scanf("%s",s);__fpurge(stdin);
	if (strcmp(s,"begin")==0) {
	  fp2=fopen("PhoneDB.dat","rb");
	  phonearr=(phone*)malloc(num*sizeof(phone));
	  rewind(fp2);
	  irc=fread(phonearr,sizeof(phone),num,fp2);
	  printf("fread return code = %d\n",irc);
	  for (i=0;i<num;i++) {
	    printf("%s----",phonearr[i].model);
	    printf("%dGB--",phonearr[i].rom);
	    printf("%.1f\"--",phonearr[i].size);
	    printf("%ld VND\n",phonearr[i].price);
	  }
	  free(phonearr);fclose(fp2);
	}
	else if (strcmp(s,"end")==0) {
	  fp2=fopen("PhoneDB.dat","rb");
	  phonearr=(phone*)malloc(num*sizeof(phone));
	  fseek(fp2,(n-num)*sizeof(phone),SEEK_SET);
	  irc=fread(phonearr,sizeof(phone),num,fp2);
	  printf("fread return code = %d\n",irc);
	  for (i=0;i<num;i++) {
	    printf("%s----",phonearr[i].model);
	    printf("%dGB--",phonearr[i].rom);
	    printf("%.1f\"--",phonearr[i].size);
	    printf("%ld VND\n",phonearr[i].price);
	  }
	  free(phonearr);fclose(fp2);
	} else 
	  printf("Invalid choice--begin or end\n");
	//fclose(fp2);
	break;
      }
    case 3:
      {
	fp2=fopen("PhoneDB.dat","rb");
	if (flag==0) {
	  printf("Import database from text file to binary file first\n");
	  break;
	}
	phonearr=(phone*)malloc(n*sizeof(phone));
	irc=fread(phonearr,sizeof(phone),n,fp2);
	printf("%s-%s-%s-%s\n\n","Model","ROM","Size","Price");
	for (i=0;i<n;i++) {
	  printf("%s-",phonearr[i].model);
	  printf("%dGB-",phonearr[i].rom);
	  printf("%.1f\"-",phonearr[i].size);
	  printf("%ld VND\n",phonearr[i].price);
	  if ((i+1)%maxl==0 && i!=(n-1)) {
	    printf("\nPress \"Enter\" for next page\n");
	    getchar();
	    printf("________________________________\n\n");
	  }
	}
	free(phonearr);fclose(fp2);
	break;
      }
    case 4:
      {
	if (flag==0) {
	  printf("Import database from text file to binary file first\n");
	  break;
	}
	char mod[30],mod2[30];
	char *pch=NULL;
	printf("Model you want to find: ");gets(mod);__fpurge(stdin);
	fp2=fopen("PhoneDB.dat","rb");
	phonearr=(phone*)malloc(n*sizeof(phone));
	irc=fread(phonearr,sizeof(phone),n,fp2);
	int mark=0;
	for (i=0;i<n;i++) {
	  strlwr(phonearr[i].model,mod2);strlwr(mod,mod);//->chu thuong
	  pch=strstr(mod2,mod);
	  //if (strcmp(mod,phonearr[i].model)==0) {
	  if (pch) {
	    printf("%s-%dGB-%.1f\"-%ld VND\n",phonearr[i].model,phonearr[i].rom,phonearr[i].size,phonearr[i].price);
	    mark=1;
	  }
	}
	if (mark==0) {
	  printf("Not exist in database\n");
	  break;
	}
	free(phonearr);fclose(fp2);
	break;
      }
    case 5:
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while (choice!=5);
  printf("\n___GOODBYE___\n");
  return reval;
}
