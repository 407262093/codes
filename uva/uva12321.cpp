#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int length,g;
	while(cin>>length>>g){
        if(length == 0&&g == 0) break;
		int x[g],r[g],ans=0,non = 0;
		pair <int ,int > range[g];

		for(int i = 0;i<g;i++){
			cin>>x[i]>>r[i];
			range[i] = make_pair(x[i]-r[i],x[i]+r[i]);
		}
		sort(range,range+g);
		int minnum = range[0].first,maxnum = range[0].second;
		int right,left = 0, eliminate = 0, i = 0;
		while(left<length){
			right = left;
			while(i<g && range[i].first <= left){
				if(right<range[i].second) right = range[i].second;
				i++;
			}
			if(right == left)break;
			left = right;
			eliminate++;
		}
		if(left<length) cout<<"-1"<<endl;
		else cout<<(g-eliminate)<<endl;
	}
	return 0;
}
