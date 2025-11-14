#include<bits/stdc++.h>
const int N=1e6;
#define ll long long
#define f first
#define se second
#define AS '\n'
using namespace std;
ll m,a,b,c,d,res;
string s,x,n,k,t;
char doi(ll z)
{
    return char(z+48);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("PALIND.INP","r",stdin);
    freopen("PALIND.OUT","w",stdout);
    cin>>n;
    t=n;
    reverse(t.begin(),t.end());
    if(t==n){
        cout<<n;
        return 0;
    }
    m=n.size();
    if(m%2==0){
       s=n.substr(0,m/2);
    }
    else s=n.substr(0,m/2+1);
    string h=s;
    reverse(h.begin(),h.end());
    if(h==s){
    	if(m%2==0)cout<<s+h;
    	else{
    		h.erase(h.begin());
    		cout<<s+h;
		}
    	return 0;
	}
    c=s.size();
    for(int i=c-1;i>=0;i--){
        if(s[i]=='9'&&s[i-1]=='9'){
            s[i]='0';
        }
        else if(s[i]=='9'&&s[i-1]!='9'){
            s[i]='0';
            s[i-1]=doi(s[i-1]-48+1);

            break;
        }
        else if(s[i]!='9'){
            s[i]=doi(s[i]-48+1);
            break;
        }
    }

    for(int i=0;i<c;i++){
        x+=s[i];
    }
    k=x;
    reverse(k.begin(),k.end());
    if(m%2==0){

        cout<<x+k;
    }
    else{
        k.erase(k.begin());
        cout<<x+k;
    }

    return 0;
}
