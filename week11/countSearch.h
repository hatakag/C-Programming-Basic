typedef int type;
typedef struct {
  type el;
  int count;
}Eltype;

int countSearch(type x,Eltype a[],int N){
  int i,j,k=-1;
  for (i=0;i<N;i++) {
    if (a[i].el==x) {a[i].count++;k=i;}
  }
  for (i=0;i<N;i++) {
    for (j=i;j<N;j++) {
      if (a[j].count>a[i].count) {
	Eltype tmp;
	tmp.el=a[i].el;tmp.count=a[i].count;
	a[i].el=a[j].el;a[i].count=a[j].count;
	a[j].el=tmp.el;a[j].count=tmp.count;
      }
    }
  }
  return k;
}
