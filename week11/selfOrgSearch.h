

int selfOrgSearch (int key,int r[],int n) {
  int i,j;
  int tempr;
  for (i=0;i<n-1 && r[i]!=key;i++) ;
  if (key==r[i]) {
    if (i>0) {
      tempr=r[i];
      for (j=i;j>0;j--) r[j]=r[j-1];
      r[0]=tempr;
    }
    return (i);
  } else return (-1);
}
