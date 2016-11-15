#include <cstdio>
#include <cstdlib>
#include <cstring>


// sort ascending order
int cmp_char(const void* _a, const void* _b){
	char* a = (char*) _a;
	char* b = (char*) _b;
	return *a - *b;
}

int cmp_string(const void* _a, const void* _b){
	char* a = (char*) _a;
	char* b = (char*) _b;
	return strcmp(a,b);
}

int cmp_int(const void* _a, const void* _b){
	int* a = (int*) _a;
	int* b = (int*) _b;
	return *a - *b;
}

int main()
{
	
	int n;
	int a[20];

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	qsort(a,n,sizeof(int),cmp_int);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	

	
	char b[20];
	gets(b);
	qsort(b,strlen(b),sizeof(char),cmp_char);
	puts(b);
	

	char c[20][20];
	int m;

	scanf("%d ",&m);
	for(int i=0;i<m;i++)
		gets(c[i]);
	qsort(c,m,sizeof(c[0]),cmp_string);
	for(int i=0;i<m;i++)
		puts(c[i]);

	return 0;
}
