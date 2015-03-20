#include <cstdio>

void hanoi(int n,int a,int b){
	if(n==1){
		printf("%d -> %d\n",a,b);
		return;
	}
	int c = 6 - a - b;
	hanoi(n-1, a,c);
	printf("%d -> %d\n",a,b);
	hanoi(n-1, c,b);
}

int main(){
	int n;

	while(1){
		scanf("%d",&n);
		if(n==0) break;
		hanoi(n,1,3);
	}

	return 0;
}

