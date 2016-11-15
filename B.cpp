#include <cstdio>
#include <cstring>

using namespace std;

const int MAXLEN = 100 + 2;

int T;
char S[MAXLEN];

int count(char s){
  bool fromLeft = true;

  int p = 0, q = strlen(s)-1;
  int ans = 0;

  while(p <= q){
    if(fromLeft){
      if(s[p] == '+') ans++;
      while(s[p] == '+' && p <= q) p++;
      if(p > q) break;

      ans++;  // since s[p] == '-'
      while(s[p] == '-' && p <= q) p++;
      fromLeft = false;
    }
    else{
      if(s[q] == '-') ans++;
      while(s[q] == '-' && p <= q) q--;
      if(p > q) break;
      
      ans++; // since s[q] == '+'
      while(s[q] == '+' && p <= q) q--;
      fromLeft = true;
    }
  }

  return ans;
}


int main(){
  scanf("%d",&T);

  for(int i=0;i<T;i++){
    scanf(" %s", S);
    int ans = count(S);
    printf("Case #%d: %d\n", i+1, ans);
  }

  return 0;
}


