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

void countsort(li arr[],li n,li max){
	li count[max+1];
	li i;
	reqp(i,0,max)count[i]=0;
	rep(i,0,n){
		count[arr[i]]++;
	}
	reqp(i,1,max){
		count[i]+=count[i-1];
	}
	li brr[n+1];
	rep(i,0,n){
		brr[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}

	ren arr[i]=brr[i];
}

void count_sort_special(li arr[],li dup[],li n){
	li max=10,i;
	li count[max];
	rep(i,0,max) count[i]=0;
	ren count[dup[i]]++;
	rep(i,1,max){
		count[i]+=count[i-1];
	}
	li brr[n];
	dep(i,n-1,0){
		brr[count[dup[i]]-1]=arr[i];
		count[dup[i]]--;
	}
	ren arr[i]=brr[i];

}

void radixsort(li arr[],li n,li max){
	li i,j,dig=0,d=0;
	while(max){
		max/=10;
		dig++;
	}
	li temp;
	li dup[n];
	for(d=0;d<dig;d++){
		//cout<<"hello";
		temp=pow(10,d);
		ren{
			dup[i]=arr[i]/temp;
			dup[i]=dup[i]%10;
		}
		count_sort_special(arr,dup,n);
		/*cout<<endl;
		ren cout<<arr[i]<<" ";
		cout<<endl;*/
	}

	cout<<"RADIX SORT : ";
	ren cout<<arr[i]<<" ";
	cout<<endl;


	
}


int main(){
	li n,i,k,j,m;
	cin>>n;
	li arr[n],max=INT_MIN;
	li copy[n];
	ren{
		cin>>arr[i];
		copy[i]=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	countsort(arr,n,max);
	cout<<"COUNT SORT : ";
	ren cout<<arr[i]<<" ";
	cout<<endl;
	ren arr[i]=copy[i];
	radixsort(arr,n,max);


	


	return 0;
}