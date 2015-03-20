#include <cstdio>

const int MAXLEN = 20;

int buff[MAXLEN];

void MergeSort(int a[],int p,int q){  // [p,q)
	if(p == q-1) return;
	int mid = (p+q) / 2;
	MergeSort(a,p,mid);
	MergeSort(a,mid,q);

	int i=p,j=mid;
	int cnt = 0;
	while(i<mid && j<q){
		if(a[i] <= a[j]) buff[cnt++] = a[i++];
		else buff[cnt++] = a[j++];
	}
	while(i<mid)
		buff[cnt++] = a[i++];
	while(j<q)
		buff[cnt++] = a[j++];

	for(int k=0;k<cnt;k++)
		a[p+k] = buff[k];
}

int main(){
	int n;

	int a[20];

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	MergeSort(a,0,n);

	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
