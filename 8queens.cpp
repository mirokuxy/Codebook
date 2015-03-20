#include <cstdio>

const int MAXN = 8;

bool row[MAXN];
bool diagi[2*MAXN - 1];
bool diagd[2*MAXN - 1];

int queen[MAXN];

void init(int n){
	for(int i=0;i<n;i++) row[i] = false;
	for(int i=0;i<2*n-1;i++) diagi[i] = diagd[i] = false;
}

void dfs(int a[],int k,int n){
	if(k==n){
		for(int i=0;i<n;i++)
			printf("%d ",queen[i]);
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++) if(!row[i] && !diagi[k-i + (n-1)] && !diagd[k + i]){
		a[k] = i;
		row[i] = diagi[k-i + (n-1)] = diagd[k + i] = true;
		dfs(a,k+1,n);
		row[i] = diagi[k-i + (n-1)] = diagd[k + i] = false;
	}
}

int main(){
	int n;

	while(1){
		scanf("%d",&n);
		if(n==0) break;
		init(n);
		dfs(queen,0,n);
		printf("Finished\n");
	}

	return 0;
}

