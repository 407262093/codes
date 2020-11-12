#include<bits/stdc++.h>
using namespace std;
int bitrees[20001] = {0};
int lowbit(int x){
	return x&(-x);
};
void add(int x,int d,int players){//建bit
	while(x<=players){
		bitrees[x]+=d;
		x+=lowbit(x);
	}
};
int sum(int x){					//找某個數的總和
	int retu = 0;
	while(x>0){
		retu += bitrees[x];
		x-=lowbit(x);
	}
	return retu;
};
int resum(int x,int d){			//找兩個數之間的總和
	return sum(d)-sum(x-1);
};
int main()
{
	int test;
	cin>>test;
	while(test--){
		int players;
		cin>>players;
		int a[players+1] = {0};
		int total = 0;
		int r[players+1] = {0};
		int l[players+1] = {0};
		for(int i = 1;i<=players;i++){
			cin>>a[i];
			bitrees[i] = 0;
			r[i] = 0;//右邊比我小
			l[i] = 0;//左邊比我小
		}
		for(int i = 1;i<=players;i++){
			add(a[i],1,players);//存進bit
			l[i] = sum(a[i]-1);//比5小 找4
		}
		for(int i = 1;i<=players;i++){
			printf("%d ",bitrees[i]);
		}
		cout<<endl;
		for(int i = 1;i<=players;i++){
			printf("%d ",l[i]);
		}
		cout<<endl;
		for(int i = 1;i<=players;i++){
			bitrees[i] = 0;
		}
		for(int i = players;i>1;i--){
			add(a[i],1,players);
			r[i] = sum(a[i]-1);
		}
		for(int i = 1;i<=players;i++){
			printf("%d ",r[i]);
		}
		cout<<endl;
		for(int i = 2;i<players;i++){
			int a = l[i]*(players-i-r[i]);
			int b = (i-1-l[i])*r[i];
			printf("%d %d\n",a,b);
			total += a+b;
		}
		cout<<total<<endl;
	}
	return 0;
}