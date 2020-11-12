#include<bits/stdc++.h>

using namespace std;

int main(){
    int in1,num[32553] = {0};
    long long sum[32553] = {0},count[32553] = {0};
    for(int i = 1 ; i<32553 ;i++){
        int j = 10;
        if(i<j){
            num[i] = 1;
        }
        else if(i<j*10){
            num[i] = 2; 
        }
        else if(i<j*100){
            num[i] = 3;
        }
        else if(i<j*1000){
            num[i] = 4;
        }
        else{
            num[i] = 5;
        }
    }
    for(int i = 1; i<32553 ; i++ ){
        count[i] = count[i-1]+num[i];
    }
    for(int i = 1; i<32553 ; i++){
        sum[i] = count[i]+sum[i-1];
    }
    
    cout<<sum[32551]<<endl;
    cin>>in1;
    while(in1--){
        long long int in2;
        cin>>in2;
        int k=0,nm,ans;
        for(k = 1; sum[k]<in2 ;k++){}
        nm = sum[k]-in2;
        while(1){
            if(nm == 0){
                ans = k%10;
                cout<<ans<<endl;
                break;
            }
            else if(nm == -1){
                ans = (k+1)/10;
                ans = ans%10;
                cout<<ans<<endl;
                break;
            }
            else if(nm == -2){
                ans = (k+1)/100;
                ans = ans%10;
                cout<<ans<<endl;
                break;
            }
            else if(nm == -3){
                ans = (k+1)/1000;
                ans = ans%10;
                cout<<ans<<endl;
                break;
            }
            else if(nm == -4){
                ans = (k+1)/10000;
                ans = ans%10;
                cout<<ans<<endl;
                break;
            }
            else{
                nm-=num[k];
                k--;
            }
        }
    }
    return 0;
}
