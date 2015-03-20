#include <cstdio>

int Gcd(int a,int b){
	int tmp;
	while(b!=0){
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}


int main()
{
	int a,b;

	while(1){
		scanf("%d %d",&a,&b);
		if(a == 0) break;

		printf("%d\n",Gcd(a,b));
	}

	return 0;
}

