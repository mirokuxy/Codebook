#include <cstdio>

bool chosen[15];

void combination(bool a[], int k, int n){
	if(k==n){
		for(int i=0;i<n;i++) if(a[i])
			printf("%d ",i);
		printf("\n");
		return;
	}
	for(int i=0;i<=1;i++){
		a[k] = i;
		combination(a,k+1,n);
	}
}

int list[15];

void combination2(int a[],int k,int n){
	int start = 0;
	if(k>0) start = a[k-1]+1;
	if(start >= n) return;

	for(int i=start;i<n;i++){
		a[k] = i;
		for(int j=0;j<=k;j++)
			printf("%d ",a[j]);
		printf("\n");
		combination2(a,k+1,n);
	}

}

int main(){
	int n;

	while(1){
		scanf("%d",&n);
		if(n==0) break;
		combination2(list,0,n);
	}

	return 0;
}
