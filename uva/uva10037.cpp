#include<bits/stdc++.h>
using namespace std;
int main(){
    int test,space,num;
    cin>>test;
    while(test--){
        cin>>num;
        int sec[num];
        for(int i = 0;i<num;i++){
            cin>>sec[i];
        }
        sort(sec,sec+num);
        int time = 0,i;
        for(i = num-1;i>=3;i-=2){
            int a = sec[0]+sec[1]+sec[i]+sec[1];
            int b = sec[0]+sec[0]+sec[i-1]+sec[i];
            if(a<b){
                time+=a;
            }
            else{
                time+=b;
            }
        }
        if(i == 2)    time+=sec[0]+sec[1]+sec[2];
        else if(i == 1)    time+=sec[1];
        else if(i == 0)    time+=sec[0];
        cout<<time<<endl;

       for(i = num-1;i>=3;i-=2){
            int a = sec[0]+sec[1]+sec[i]+sec[1];
            int b = sec[0]+sec[0]+sec[i-1]+sec[i];
            if(a<b){
                printf("%d %d\n%d\n%d %d\n%d\n",sec[0],sec[1],sec[0],sec[i-1],sec[i],sec[1]);
            }
            else{
                printf("%d %d\n%d\n%d %d\n%d\n",sec[0],sec[i-1],sec[0],sec[0],sec[i],sec[0]);
            }
        } 
        if(i == 2)    printf("%d %d\n%d\n%d %d\n",sec[0],sec[1],sec[0],sec[0],sec[2]);
        else if(i == 1)    printf("%d %d\n",sec[0],sec[1]);
        else if(i == 0)    printf("%d\n", sec[0]);
    }
    return 0;
}
