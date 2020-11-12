#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int j = 1 ; j<=test ; j++){
        int te,max_k=0;
        cin>>te;
        int arr[te+1]= {0};
        for(int i = 1 ; i <= te; i++){
            cin>>arr[i];
        }
        max_k = arr[te]-arr[te-1];
        for(int i = te-1; 0<i;i--){
            if(max_k == arr[i]-arr[i-1]){
                max_k++;
            }
            else if(max_k < arr[i]-arr[i-1]){
               max_k = arr[i]-arr[i-1];
            }
        }
        cout<<"Case "<< j <<": "<< max_k <<endl;
    }
}

