#include <bits/stdc++.h>
 
using namespace std;
 
#define get sdfsdfdsf
int n,m;
int a[20];
int pos[60000];
int win[60000];
int mv[60000];
int get[60000][10];
int mod;
void init(){
	mod=1;
	for(int i=1;i<=10;i++) mod*=3;
	for(int i=0;i<60000;i++){
		int x=i;
		for(int j=0;j<10;j++){
			get[i][j]=x%3;
			x/=3;
		}
	}
}
int main(){
	freopen("./in","r",stdin);
	init();
    while(cin>>n>>m){
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        for(int i=1;i<=10;i++){
			int k=0;
			for(int j=0;j<m;j++){
				if(i-a[j]>=0){
					k=1;
					break;
				}
			}
			if(k==0){
				win[i]=2;
				continue;
			}
			int f=0;
            for(int j=0;j<m;j++){
                if(a[j]==i){
                    f=1;
                    mv[i]=a[j];
                    break;
                }
                if(i-a[j]>0&&win[i-a[j]]==0){
                    f=1;
                    mv[i]=a[j];
                    break;
                }
				if(i-a[j]>0&&win[i-a[j]]==2&&f==0){
					f=2;
				}
            }
            win[i]=f;
        }
        /*for(int i=1;i<=10;i++){
            cout<<win[i]<<endl;
        }
        cout<<endl;*/
        if(n<=10){
            if(win[n]==1){
                cout<<mv[n]<<endl;
            }else puts("No");
			continue;
        }else{
            memset(pos,-1,sizeof pos);
            int s=0;
            int last=10;
            for(int i=1;i<=10;i++){
                s*=3;
                s+=win[i];
            }
            pos[s]=10;
            int loops,looplen;
            for(int i=11;;i++){
                bool f=0;
                for(int j=0;j<m;j++){
					if(get[s][a[j]-1]==0){
						f=1;
						mv[i]=a[j];
						break;
					}
					if(get[s][a[j]-1]==2&&f==0){
						f=2;
					}
                }
                //cout<<i<<" "<<f<<endl;
                win[i]=f;
                s*=3;
                s+=f;
                s%=mod;
                last=i;
                if(pos[s]!=-1){
                    loops=pos[s];
                    looplen=i-pos[s];
                    break;
                }
                pos[s]=i;
            }
            int id=(n-loops)%looplen;
            int ss=win[id+loops];
            if(n<=last){
                if(win[n]==1){
                    cout<<mv[n]<<endl;
                }else{
                    puts("No");
                }
                continue;
            }
            if(ss==0||ss==2){
                puts("No");
            }else{
                printf("%d\n",mv[id+loops]);
            }
        }
    }
    return 0;
}
 
