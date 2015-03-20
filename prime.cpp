// find primes
// some typical primes: 1009 10009 100003 1000003

#include <cstdio>
#include <cmath>

const int MAXPRIME = 100010;

int is_prime[MAXPRIME];

void make_prime(){
	for(int i=2;i<MAXPRIME;i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for(int i=2;i*i<MAXPRIME;i++){
		for(int j=i*i;j<MAXPRIME;j+=i)
			is_prime[j] = 0;
	}
}

int count_prime(){
	int count=0;
	for(int i=2;i<MAXPRIME;i++) if(is_prime[i]){
		printf("%d ",i);
		count++;
		if(count%10 == 0) printf("\n");
	}
	printf("\n");
}

// judge is prime in a small range without calculating the array
bool IsPrime(int x){
	if(x == 0 || x == 1) 
		return false;
	int mid = sqrt(x);
	for(int i=2; i<=mid; i++)
		if( x % i == 0)
			return false;
	return true;
}


int main(){
	make_prime();

	//count_prime();

	int x;
	while(1){
		scanf("%d",&x);
		if(x==0) break;
		printf("%s\n",IsPrime(x)?"Yes":"No");
	}

	return 0;
}
