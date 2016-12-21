#include <bits/stdc++.h>

using namespace std;

int T,n;
int main(){
	freopen("./in","r",stdin);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<4) cout<<1<<endl;
		else{
			long long f=1;
			for(int i=2;i<n;i++) f*=i;
			cout<<f/2<<endl;
		}
	}
	return 0;
}
