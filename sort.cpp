#include <cstdio>


void InsertSort(int a[],int p, int q){
	for(int i=p+1; i<=q;i++){
		int x = a[i];

		int j;
		for(j=i;j>p && a[j-1] > x; j--)
			a[j] = a[j-1];
		a[j] = x;

		/*
		printf("i = %d\n",i);
		for(int k=p;k<=q;k++) printf("%d ",a[k]);
		printf("\n");
		*/
	}
}

void SelectSort(int a[],int p,int q){
	for(int i=p;i<q;i++){
		int min = i;
		for(int j=i+1;j<=q;j++)
			if(a[j] < a[min]) 
				min = j;
		if(min == i) continue;
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
}

void swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort(int a[],int p,int q){
	for(int i=q; i>p; i--){
		for(int j=p+1;j<=i;j++)
			if(a[j] < a[j-1]) swap(a[j],a[j-1]);
	}
}

int main(){


	int n;
	int a[20];

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	//qsort(a,n,sizeof(int),cmp_int);
	BubbleSort(a,0,n-1);

	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");


}