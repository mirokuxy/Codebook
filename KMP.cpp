#include <cstdio>
#include <cstring>
#include <cstdlib>

const char *kmp_search(const char *text, const char *pattern)
{
    int *T;
    int i, j;
    const char *result = NULL;
 
    if (pattern[0] == '\0')
        return text;
 
    /* Construct the lookup table */
    T = (int*) malloc((strlen(pattern)+1) * sizeof(int) );
    T[0] = -1;
    for (i=0; pattern[i] != '\0'; i++) {
        T[i+1] = T[i] + 1;
        while (T[i+1] > 0 && pattern[i] != pattern[T[i+1]-1])
            T[i+1] = T[T[i+1]-1] + 1;
    }
 
    /* Perform the search */
    for (i=j=0; text[i] != '\0'; ) {
        if (j < 0 || text[i] == pattern[j]) {
            ++i, ++j;
            if (pattern[j] == '\0') {
                result = text+i-j;
                break;
            }
        }
        else j = T[j];
    }
 
    free(T);
    return result;
}

const int MAXL = 50;

char a[MAXL],b[MAXL];

int main(){
    while(1){
        scanf("%s",a);
        if(strcmp(a,"0")==0) break;
        scanf("%s",b);

        const char *p = kmp_search(a,b);
        if(p == NULL) 
            printf("NULL\n");
        else
            printf("%s\n",p);
    }

    return 0;
}

