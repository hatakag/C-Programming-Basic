//number of data in file1
if ((fptr1=fopen(argv[1],"rb"))==NULL) {
  printf("Cannot open %s file\n",argv[1]);
  return FAIL;
 }
phonearr=(phone*)malloc(1*sizeof(phone));
if (phonearr==NULL) {
  printf("Memory allocation failed\n");
  return FAIL;
 }
while (!feof(fptr1)) {
    fread(phonearr,sizeof(phone),1,fptr1);
    if (!feof(fptr1)) num1++;
 }
free(phonearr);
fclose(fptr1);
// fseek
if (fseek(fptr3,num1*sizeof(phone),SEEK_SET)!=0) {
  printf("Fseek failed\n");
  return FAIL;
 }
//compare name (First name -> Last name)
int compareName(char* s1, char* s2)
{
  char buff1[30];
  char buff2[30];
  
  int i = strlen(s1);
  int j = strlen(s2);
  
  int check = 0;
  
  while(i >= 0 && j >= 0 && check == 0)
    {
      while(s1[i] != ' ' && i >= 0)
	i -= 1;
      
      while(s2[j] != ' ' && j >= 0)
	j -= 1;
      
      strncpy(buff1, s1 + i + 1, strlen(s1)-i+1);
      strncpy(buff2, s2 + j + 1, strlen(s2)-j+1);
      
      check = strcmp(buff1, buff2);
      
      if(check > 0) return 1;
      
      else if(check < 0) return -1;
      
      i--;
      j--;
    }
  
  if(i >= 0) return 1;
  
  if(j >= 0) return -1;
  
  return 0;   
}

// compare Name
#include <string.h>
#include <ctype.h>

#ifndef MAX_STR_LEN
#define MAX_STR_LEN 2000
#endif

void strTrim(char *s); // Xoá hết ký tự trắng bị đúp, xoá kí tự trắng ở đầu, cuối, thay hết kí tự trắng thành dấu cách
void strLowerCase(char *p);
void strUpperCase(char *p);

// Cắt xâu thành nhiều xâu nhỏ theo dấu cách
void strSplit(char* s, char arr[][MAX_STR_LEN], int * n); // n is number of words

// Nối các xâu từ begin đến end trong mảng arr thành xâu s bằng kí tự delim
void strJoin(char *s, char arr[][MAX_STR_LEN], int begin, int end, const char * delim);

// So sánh tên. Các tên được cắt ra thành 3 phần và loại bỏ các dấu cách thừa
// So sánh tên > tên đệm > họ
int nameCompare(char* fullname1, char* fullname2);

void strLowerCase(char *p) {
  for ( ; *p; ++p) *p = tolower(*p);
}

void strUpperCase(char *p) {
  for ( ; *p; ++p) *p = toupper(*p);
}


// - remove space at last and at the begin
// - remove duplicated spaces
// - turn all space into #32 ASCII
void strTrim(char *s) {
  int spaceBefore;
  int ptr1; // pointer 1: writing pointer;
  int ptr2; // reading pointer;
  
  spaceBefore = 1;
  ptr2 = 0; ptr1 = -1;
  while (ptr2 < strlen(s)) {
    if (isspace(s[ptr2])) {
      if (!spaceBefore){
	s[++ptr1] = ' ';
	spaceBefore = 1;
      } 
    } else {
      s[++ptr1] = s[ptr2];
      spaceBefore = 0;
    }
    ptr2++;
  }
  
  if (ptr1 == -1) {
    s[0] = '\0';
  }
  
  // remove last space
  if (isspace(s[ptr1])) {
    s[ptr1] = '\0';
  } else {
    s[ptr1+1] = '\0';
  }
  
}


// Split a string using space as delim
void strSplit(char* s, char arr[][MAX_STR_LEN], int * n) { // n is number of words
  char tmp[MAX_STR_LEN];
  char * word;
  
  strcpy(tmp, s);
  strTrim(tmp);
  
  *n = 0;
  word = strtok(tmp, " ");
  while (word != NULL) {
    strcpy(arr[*n], word);
    (*n)++;
    word = strtok(NULL, " ");
  }
}

// Join a string using optional delim
void strJoin(char *s, char arr[][MAX_STR_LEN], int begin, int end, const char * delim) {
  // empty string s;
  s[0] = '\0';
  
  int i;
  for (i = begin; i <= end; ++i){
    if (strlen(s) != 0) {
      strcat(s, delim);
    }
    strcat(s, arr[i]);
  }
}


// return 0: the same; <0: name1 < name2; >0: name1 > name2
int nameCompare(char* fullname1, char* fullname2) {
  char familyName1[MAX_STR_LEN]; strcpy(familyName1, "");
  char surname1[MAX_STR_LEN]; strcpy(surname1, "");
  char name1[MAX_STR_LEN]; strcpy(name1, "");
  char familyName2[MAX_STR_LEN]; strcpy(familyName2, "");
  char surname2[MAX_STR_LEN]; strcpy(surname2, "");
  char name2[MAX_STR_LEN]; strcpy(name2, "");
	
  char a[100][MAX_STR_LEN]; int n;
  
  strSplit(fullname1, a, &n);
  if (n > 0) {
		strcpy(name1, a[n-1]);
  }
  if (n > 1) {
    strcpy(familyName1, a[0]);
  }
  if (n > 2) {
    strJoin(surname1, a, 1, n-2, " ");
  }
  
  strSplit(fullname2, a, &n);
  if (n > 0) {
    strcpy(name2, a[n-1]);
  }
  if (n > 1) {
    strcpy(familyName2, a[0]);
  }
  if (n > 2) {
    strJoin(surname2, a, 1, n-2, " ");
  }
  
  strLowerCase(familyName1); strLowerCase(surname1); strLowerCase(name1); 
  strLowerCase(familyName2); strLowerCase(surname2); strLowerCase(name2); 
  
  if (strcmp(name1, name2) != 0) {
    return strcmp(name1, name2);
  } else {
    if (strcmp(surname1, surname2) != 0) {
      return strcmp(surname1, surname2);
    } else {
      return strcmp(familyName1, familyName2);
    }
  }
  
  return 0;
}

#include <stdio.h>

#define MAX_STR_LEN 2000
#include "string_ext.h"


char name[50][MAX_STR_LEN];
char name2[50][MAX_STR_LEN];


void strSplitJoinTest() {
	printf("String Split-Join Test:\n");

	char s[MAX_STR_LEN];
	char a[50][MAX_STR_LEN]; int n;

	strcpy(s, "  xin		 chao.      cac		ban.   ");

	printf("Split: \n");
	strSplit(s, a, &n);
	for (int i = 0; i < n; ++i) {
		printf("'%s' ; ", a[i]);
	}

	printf("Join: \n");
	strJoin(s, a, 0, n-1, "'--'");
	printf("%s\n", s);

}

int main(int argc, char const *argv[])
{

  int n;
  
  FILE*fin;
  fin = fopen("ds_ten.txt", "r");
  n = 0;
  
  while(fgets(name[n], MAX_STR_LEN * sizeof(char), fin) != NULL){
    if (name[n][strlen(name[n])-1] == '\n')
      name[n][strlen(name[n])-1] = '\0';
    n++;
  }
  fclose(fin);
  
  printf("*** DS ten:\n");
  
  for (int i = 0; i < n; ++i) {
    printf("%s\n", name[i]);
  }
  
  char tmp[MAX_STR_LEN];
  for (int i = 0; i < n-1; ++i) {
    for (int j = n-2; j>=i; --j) {
      if (nameCompare(name[j], name[j+1]) > 0) {
	strcpy(tmp, name[j]);
	strcpy(name[j], name[j+1]);
	strcpy(name[j+1], tmp);
      }
    }
  }
  
  printf("*** DS ten da sx:\n");
  
  for (int i = 0; i < n; ++i) {
    printf("%s\n", name[i]);
  }
  
  
  return 0;
}

//
