int selfOrgSeqSearch (int key,int r[],int n) {
  int i;
  int tempr;
  for (i=0;i<n-1 && r[i]!=key;i++);
  if (key==r[i]) {
    if (i>0) {
      //Transpose with predecessor
      tempr=r[i];
      r[i]=r[i-1];
      r[--i]=tempr;
    }
    return (i);
  } else return (-1);
}
