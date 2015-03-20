#include <cstdio>

const int MAXN = 20;

int parent[MAXN];

void makeSet(int a[],int n){
	for(int i=0;i<n;i++)
		a[i] = i;
}

int find(int a[],int k){
	if(a[k] == k) 
		return k;
	else return a[k] = find(a,a[k]);
}

void join(int a[],int i,int j){
	a[find(a,i)] = find(a,j);
}

void output(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",find(a,i));
	printf("\n");
}

int main(){
	int n = 10;

	makeSet(parent,n);

	output(parent,n);

	join(parent,1,3);

	output(parent,n);

	join(parent,4,6);
	join(parent,5,9);
	join(parent,3,4);

	output(parent,n);

	return 0;
}

