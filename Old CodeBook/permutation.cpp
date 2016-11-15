//permutation with array as input
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 10;

int perm[MAXN];
int n;

int input[MAXN];
int elem[MAXN];
int has[MAXN];
int used[MAXN];
int count=0;

int cmp_int(const void *_a,const void* _b){
	int *a = (int*) _a;
	int *b = (int*) _b;
	return *a-*b;
}

void make_elem(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&input[i]);
	
	qsort(input,n,sizeof(int),cmp_int);

	memset(elem,0,sizeof(elem));
	memset(has,0,sizeof(has));

	elem[count++] = input[0];
	has[count-1] = 1;
	for(int i=1;i<n;i++) 
		if(input[i] != elem[count-1]){
			elem[count++] = input[i];
			has[count-1] = 1;
		}
		else has[count-1]++;

}

void dfs_perm(int p){
	if(p == n){
		for(int i=0;i<n;i++) printf("%d ",perm[i]);
		printf("\n");
		return;
	}
	for(int i=0;i<count;i++) if(used[i]<has[i]){
		perm[p] = elem[i];
		used[i]++;
		dfs_perm(p+1);
		used[i]--;
	}
}

void permutation(){
	memset(perm,0,sizeof(perm));
	memset(used,0,sizeof(used));

	dfs_perm(0);
}

int main(){
	make_elem();
	permutation();

	return 0;
}
