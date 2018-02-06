/* AKSHAT SHARMA */
#include <iostream>
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp   make_pair
#define pb   push_back
#define F    first
#define S    second
#define ll   long long
#define li   int 
#define ld   long double
#define MOD  1000000007
#define MAX  1000000001
#define rep(i,a,b) for(i=a;i<b;i++)
#define reqp(i,a,b) for(i=a;i<=b;i++)
#define ren for(i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;

li arr[n],top;
li vis[n];
vector<li>vec;
stack<li>sta;

int main(){
	li n,m,i,j,k,a,b;
	cout<<"Enter number of nodes : ";
	cin>>n;
	li arr[n],top;
	li vis[n];
	ren {
		cin>>arr[i];
		insert(arr[i]);
	}
	vector<li>vec;
	stack<li>sta;
	sta.push(0);
	ren vis[i]=0;
	//cout<<arr[0]<<" ";
	vec.pb(arr[0]);
	while(!sta.empty()){
		i=sta.top();
		if((2*i+1)<n && vis[2*i+1]==0){
			sta.push(2*i+1);
			vec.pb(arr[2*i+1]);
			vis[2*i+1]=1;
			//cout<<arr[2*i+1]<<"__\n";
			continue;
		}
		if((2*i+2)<n && vis[2*i+2]==0){
			sta.push(2*i+2);
			vec.pb(arr[2*i+2]);
			vis[2*i+2]=1;
			//cout<<arr[2*i+2]<<"_\n";
			continue;
		}
		sta.pop();
	}
	cout<<"PREORDER : ";
	ren cout<<vec[i]<<" ";
	cout<<endl;





	return 0;
}