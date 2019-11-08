#include<bits/stdc++.h>
using namespace std;

int n, k , taken[10001];
char str[1005];
vector<char>res;

void Combination(int idx)
{
    if(res.size()==k){
        for(int j=0; j<k; j++)
            printf("%c", res[j]);
        printf("\n");
        return;
    }

    for(int i=idx; i<n ; i++){
        if( !taken[i] ){
            taken[i] = 1;
            res.push_back(str[i]);
            Combination(i+1);
            taken[i] = 0;
            res.pop_back();
            while(str[i]==str[i+1]) i++;
        }
    }
}

int main()
{
    scanf("%s %d", str, &k);
    n=strlen(str);
    sort(str, str+n);
    Combination(0);

    return 0;
}
