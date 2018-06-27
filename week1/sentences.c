#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main() {
  int i;
  char article[5][10]={"the","a","one","some","any"};
  char noun[5][10]={"boy","girl","dog","town","car"};
  char verb[5][10]={"drove","jumped","ran","walked","skipped"};
  char preposition[5][10]={"to","from","over","under","on"};
  srand(time(NULL));
  char sentences[10][100];
  for (i=0;i<10;i++) {
    strcpy(sentences[i],article[rand()%5]);
    strcat(sentences[i]," ");
    strcat(sentences[i],noun[rand()%5]);
    strcat(sentences[i]," ");
    strcat(sentences[i],verb[rand()%5]);
    strcat(sentences[i]," ");
    strcat(sentences[i],preposition[rand()%5]);
    strcat(sentences[i]," ");
    strcat(sentences[i],article[rand()%5]);
    strcat(sentences[i]," ");
    strcat(sentences[i],noun[rand()%5]);
  }
  for (i=0;i<10;i++) {
    sentences[i][0]=sentences[i][0]-'a'+'A';
  }
  for (i=0;i<10;i++) {
    printf("%s.\n",sentences[i]);
  }
}
