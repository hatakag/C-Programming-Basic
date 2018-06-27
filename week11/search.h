typedef int Eltype;

int selfOrgSearch (Eltype key,Eltype r[],int n) {
  int i,j;
  Eltype tempr;
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

int selfOrgSeqSearch (Eltype key,Eltype r[],int n) {
  int i;
  Eltype tempr;
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

int selfOrgSearch

int binSearch(Eltype target,Eltype list[],int size) {
  int mid,lo=0,hi=size-1;
  while (lo<=hi) {
    mid=(lo+hi)/2;
    if (list[mid]==target)
      return mid;
    else if (target<list[mid])
      hi=mid-1;
    else lo=mid+1;
  }
  return -1;
}

int binRecSearch(Eltype target,Eltype list[],int lo,int hi) {
  if (lo>hi) return -1;
  int mid=(lo+hi)/2;
  if (list[mid]<target) return binRecSearch(target,list,mid+1,hi);
  else if (list[mid]>target) return binRecSearch(target,list,lo,mid-1);
  else return mid;
  return -1;
}
