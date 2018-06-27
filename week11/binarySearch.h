typedef int Eltype;

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
