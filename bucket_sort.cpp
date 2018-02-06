/* AKSHAT SHARMA */
#include <iostream>
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp   make_pair
#define pb   push_back
#define F    first
#define S    second
#define ll   long long
#define li   long int 
#define ld   long double
#define MOD  1000000007
#define MAX  1000000001
#define rep(i,a,b) for(i=a;i<b;i++)
#define dep(i,a,b) for(i=a;i>=b;i--)
#define reqp(i,a,b) for(i=a;i<=b;i++)
#define ren for(i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;

void bucket_sort(double arr[],li n){
	li i,j,k=0;
	vector<double>vec[10];
	ren{
		k=10*arr[i];
		vec[k].pb(arr[i]);
	}
	k=0;
	rep(i,0,10)sort(ALL(vec[i]));
	rep(i,0,10){
		rep(j,0,vec[i].size())
			arr[k++]=vec[i][j];
	}

	cout<<"BUCKET SORT : ";
	ren cout<<arr[i]<<" ";
	cout<<endl;



}

int main(){
	li n,i,k,j,m;
	cin>>n;
	double arr[n];
	ren cin>>arr[i];
	bucket_sort(arr,n);

	


	return 0;
}