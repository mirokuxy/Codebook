#include <cstdio>
#include <cstring>

void mergeSort(int a[], int p, int q){ // [p,q]
	if(p==q) return;

	int mid = (p+q) /2 +1;
	mergeSort(a,p,mid-1);
	mergeSort(a,mid,q);

	int *tmp = new int[q-p+1];

	int i=p,j=mid;
	while(i<=mid-1 && j<=q){
		if(a[i] < a[j])
			tmp[i-p + j-mid] = a[i++];
		else
			tmp[i-p + j-mid] = a[j++]; 
	}
	while(i<=mid-1)
		tmp[i-p + j-mid] = a[i++];
	while(j<=q)
		tmp[i-p + j-mid] = a[j++];

	for(int k=p;k<=q;k++)
		a[k] = tmp[k-p];

	delete [] tmp;
}

int main(){
	int n;
	int a[10];

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	mergeSort(a,0,n-1);

	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}