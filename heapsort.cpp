/* AKSHAT SHARMA */
#include <iostream>
#include <fstream>
//#include <bits/stdc++.h>
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
#define reqp(i,a,b) for(i=a;i<=b;i++)
#define deqp(i,a,b) for(i=a;i>=b;i--)
#define ren for(i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;

void swap(int *t,int *p){
int *temp;
*temp=*p;
*p=*t;
*t=*temp;
}

void heapify(int arr[], int n, int i)
{
    int maxx=i;
    int l=2*i+1;
    if(l>=n)
    	return;
    int r=2*i+2;
    if (arr[l] > arr[maxx])
        maxx=l;
 	if (arr[r] > arr[maxx] && r<n)
        maxx=r;
	if (maxx!= i)
    {
        swap(arr[i], arr[maxx]);
        heapify(arr, n,maxx);
    }
}


void heapSort(int arr[], int n)
{
	int i;
	deqp(i,n/2-1,0)	heapify(arr,n,i);
    deqp(i,n-1,0){
        swap(arr[0], arr[i]);
 		heapify(arr, i, 0);
    }
}
 


int main(){

FILE *fp;
int n,i,t;

/*cin>>n;
int arr[n];
ren cin>>arr[i];*/

fp=fopen("input.txt","r");
fscanf(fp,"%d",&n);
int arr[n];
ren{
fscanf(fp,"%d",arr+i);
}
fclose(fp);
heapSort(arr,n);
ren cout<<arr[i]<<" ";
cout<<endl;



return 0;
}
