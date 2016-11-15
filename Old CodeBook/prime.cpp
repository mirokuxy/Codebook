// find primes
// some typical primes: 1009 10009 100003 1000003

#include <cstdio>

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

int main(){
	make_prime();

	count_prime();

	return 0;
}
