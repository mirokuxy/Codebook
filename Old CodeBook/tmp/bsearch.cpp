#include <cstdio>
#include <cstring>

int bsearch(int a[], int p, int q, int x){ // [p, q)
  if(p>=q) return p;

  int mid = (p+q) /2;
  if(a[mid] >= x)
    return bsearch(a, p, mid, x);
  else
    return bsearch(a, mid+1, q, x);
}

int main(){
	int n;
	int a[10];

	scanf("%d",&n);
  printf("n = %d\n", n);

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

  
  for(int i=0;i<n;i++)
    printf("%d ", a[i]);
  printf("\n");
  


  int x;

  while(1){
    scanf("%d",&x);
    if(x==-1) break;
    printf("x=%d",x);

    int index = bsearch(a,0,n,x);
    printf(" a[%d] = %d\n", index, a[index]);
  }


	return 0;
}

