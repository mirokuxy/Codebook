#include <cstdio>

int Lcm(int a,int b){
	if(a<b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int ans = a;
	while(ans % b != 0) {
		ans += a;
	}

	return ans;
}

int main(){
	int a,b;

	while(1){
		scanf("%d %d",&a,&b);

		if(a==0) break;
		printf("%d\n",Lcm(a,b));
	}

	return 0;
}
