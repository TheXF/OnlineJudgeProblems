#include <bits/stdc++.h>

using namespace std;

char B[105][105];
int n,m;
int T;
const long long mod=1e9+7;
const int maxn=10005;
long long p2[10005];
int vis[maxn];
const int drx[]={0,0,-1,1};
const int dry[]={-1,1,0,0};
void dfs(int x,int y){
	vis[x*m+y]=1;
	for(int i=0;i<4;i++){
		int dx=x+drx[i],dy=y+dry[i];
		if(dx<0||dx>=n||dy<0||dy>=m) continue;
		if(!vis[dx*m+dy]&&B[dx][dy]=='Y') dfs(dx,dy);
	}
}
int main(){
	freopen("./in","r",stdin);
	p2[0]=1;
	for(int i=1;i<10005;i++) p2[i]=p2[i-1]*2%mod;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n*m;i++) vis[i]=0;
		for(int i=0;i<n;i++) scanf("%s",B[i]);
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(B[i][j]=='Y'&&!vis[i*m+j]) dfs(i,j),cnt++;
			}
		}
		cout<<p2[cnt-1]<<endl;
	}
	return 0;
}
