#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    scanf("%d",&tc);

    while(tc--){
        int per,maxiq,ans;
        scanf("%d",&per);

        int arr[per];

        for(int i = 0;i < per;i++) scanf("%d",&arr[i]);
        maxiq = arr[0];
        ans = arr[0]-arr[1];

        for(int j = 1; j<per ;j++){
            ans = max(ans,maxiq-arr[j]);
            maxiq = max(maxiq,arr[j]);
        }
        printf("%d\n",ans);
    }
}