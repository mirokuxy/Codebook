#include <cstdio>

using namespace std;


const int MAXLEN = 50;

class Heap{
public:
	int array[MAXLEN];
	int len;
	int size;

	Heap(int a[],int n){
		for(int i=0;i<n;i++)
			array[i] = a[i];
		len = n;
		size = n;
	}

	int Left(int k){
		return (k+1) * 2 - 1;
	}

	int Right(int k){
		return (k+1) * 2;
	}

	int Parent(int k){
		return (k+1) /2;
	}

	void Maintain(int k){
		int tmp = array[k];
		while(1){
			int max = tmp;
			int maxj = k;
			if(Left(k) < size && array[Left(k)] > max) {
				max = array[Left(k)];
				maxj = Left(k);
			}
			if(Right(k) < size && array[Right(k)] > max) {
				max = array[Right(k)];
				maxj = Right(k);
			}
			if(maxj == k) break;
			array[k] = array[maxj];
			k = maxj;
		}
		array[k] = tmp;
	}

	void Output(){
		/*
		for(int i=1;i<=len;i++)
			printf("%d ",i);
		printf("\n");
		*/
		for(int i=0;i<len;i++)
			printf("%d ",array[i]);
		printf("\n");
	}

	void Build(){
		for(int i = len/2 -1; i>=0; i--){
			Maintain(i);
			//Output();
		}
	}

	void Sort(){
		Build();
		for(int i=len-1;i>0;i--){
			int tmp = array[i];
			array[i] = array[0];
			array[0] = tmp;

			size--;
			Maintain(0);
		}
		size = len;
	}

};


int main(){
	
	int a[20],n;

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	Heap h(a,n);

	//h.Build();
	h.Sort();
	h.Output();

	return 0;


}
