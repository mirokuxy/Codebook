#include <cstdio>
#include <cstdlib>

int cmp_int(const void* _a, const void* _b){
	int* a = (int*) _a;
	int* b = (int*) _b;
	return *a - *b;
}

int bsearch(int a[],int p,int q,int x){ // [p,q)
	if(p == q-1){
		if(a[p] < x) return p+1;
		else return p;
	}
	else{
		int mid = (p+q) /2;
		if(a[mid] < x) return bsearch(a,mid,q,x);
		else return bsearch(a,p,mid,x);
	}
}

int bsearch_nonrecursive(int a[],int p,int q,int x){ // [p,q)
	while(p < q-1){
		int mid = (p+q) /2;
		if(a[mid] < x) p = mid;
		else q = mid;
	}

	if(a[p] < x) return p+1;
	else return p;
}

int main(){
	int n;

	int a[20];

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	qsort(a,n,sizeof(int),cmp_int);

	
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	

	int x;
	while(1){
		scanf("%d",&x);
		if(x < 0) break;
		printf("%d\n",bsearch_nonrecursive(a,0,n,x));
	}

	return 0;
}
