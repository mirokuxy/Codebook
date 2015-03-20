#include <cstdio>


bool isUsed[15];

void permutation(int a[], int k, int n){
	if(k==n) {
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++) if(! isUsed[i]){
		isUsed[i] = true;
		a[k] = i;
		permutation(a,k+1,n);
		isUsed[i] = false;
	}
}

int main(){
	int n;

	int a[15];

	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0;i<n;i++) isUsed[i] = false;
		permutation(a,0,n);
	}

	return 0;
}
