#include <cstdio>
#include <cstring>

using namespace std;

void qsort(int a[], int p, int q){ // [p,q]
  int mid = (p+q) /2;
  int x= a[mid];

  a[mid] = a[p];

  int i=p,j=q;
  while(i<j){
  	while(i<j && a[j] >= x) j--;
  	if(i<j) a[i++] = a[j];
  	while(i<j && a[i] < x ) i++;
  	if(i<j) a[j--] = a[i];
  }

  a[i] = x;
  if(p<i-1) qsort(a, p, i-1);
  if(j+1<q) qsort(a, j+1, q);
}

int main(){
	int n;
	int a[10];

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	qsort(a,0,n-1);

	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

