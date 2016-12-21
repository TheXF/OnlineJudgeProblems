#include <bits/stdc++.h>

using namespace std;

const int maxn=10005;
int n,m;
int a[maxn];
int main(){
	freopen("./in","r",stdin);
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int dis=0;
		for(int i=2;i<=n;i++) dis=max(dis,a[i]-a[i-1]);
		dis=max(a[1]*2,dis);
		dis=max((m-a[n])*2,dis);
		printf("%.2f\n",(double)dis/2);
	}
	return 0;
}
