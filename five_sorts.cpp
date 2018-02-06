/* AKSHAT SHARMA */
#include <iostream>
#include <bits/stdc++.h>
#include<fstream>
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
#define ren for(i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;

int checkint(string str){
	int len=str.size(),i=0,temp=1,ans=0;
	if(str[0]=='-'){
		i=len-1;
		if(len==1)
			return -1729;
		while(i>0){
			if(str[i]>=48 && str[i]<=57){
				ans+=temp*(str[i]-48);
				temp*=10;
			}
			else return -1729;
			i--;
		}
		return ans*(-1);
	}
	else{
		i=len-1;
		while(i>=0){
			if(str[i]>=48 && str[i]<=57){
				ans+=temp*(str[i]-48);
				temp*=10;
			}
			else return -1729;
			i--;
		}
		return ans;

	}


}

int checkpos(string str){
	int len=str.size(),i=0,temp=1,ans=0;
	i=len-1;
	while(i>=0){
		if(str[i]>=48 && str[i]<=57){
				ans+=temp*(str[i]-48);
				temp*=10;
		}
		else return -1729;
		i--;
	}
	//cout<<ans<<".....\n";
	return ans;
}

void swap(int *t,int *p){
int temp;
temp=*p;
*p=*t;
*t=temp;
}

void bs(int arr[],int n){
int i,j;
	for(j=n;j>0;j--){
		for(i=0;i<j-1;i++){
			if(arr[i]>arr[i+1])
				swap(arr+i,arr+i+1);
		}
		ren cout<<arr[i]<<" ";
		cout<<"\n";
	}
	/*cout<<"BUBBLE SORT : ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;*/

}

void ss(int arr[],int n){
int max=0,i=0,j=n;
	while(n){
	max=0;
		for(i=0;i<n;i++)
			if(arr[i]>arr[max])
				max=i;
		swap(arr+max,arr+n-1);
		n--;
	
	}
	n=j;
	/*cout<<"SELECTION SORT : ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;*/


}


void is(int arr[],int n){
int i,key,j,p;
for(i=1;i<n;i++){
	key=arr[i];
	j=i-1;
	p=j;
	while(j>=0 && arr[j]>key){
	arr[j+1]=arr[j];
	j--;
	}
	arr[j+1]=key;
}
/*cout<<"INSERTION SORT : ";
for(i=0;i<n;i++)
	cout<<arr[i]<<" ";
cout<<"\n";*/

}


int pf(int *poi,int p,int r)
{
int k,i,j,temp;
k=*(poi+r);
i=p-1;
	for(j=p;j<=r-1;j++){
		if(*(poi+j)<k){
		i++;
		temp=*(poi+i);
		*(poi+i)=*(poi+j);
		*(poi+j)=temp;				
		}
	}
	temp=*(poi+i+1);
	*(poi+i+1)=*(poi+r);
	*(poi+r)=temp;
	return i+1;
}



void qs(int *poi,int p,int r){

int q,i;
if(p<r){	
	q=pf(poi,p,r);
	qs(poi,p,q-1);
	qs(poi,q+1,r);
}
		
}


void merge(int arr[],int low,int mid,int high){
	int a1[mid-low+1],a2[high-mid+1];
	//li a1[1000],a2[1000];
	int i,j,k=0;
	rep(i,low,mid){
		a1[i-low]=arr[i];
	}
	rep(i,mid,high){
		a2[i-mid]=arr[i];
	}
	int a3[high-low+1];

	i=0;j=0;
	int len1=mid-low,len2=high-mid;
	while(i<len1 && j<len2){
		if(a1[i]>a2[j]){
			a3[k++]=a1[i++];
		}
		else
			a3[k++]=a2[j++];
	}
	while(i<len1){
		a3[k++]=a1[i++];
	}
	while(j<len2){
		a3[k++]=a2[j++];
	}

	rep(i,0,k){
		arr[low+i]=a3[i];
	}

}

void mergesort(int arr[],int low,int high){

	int mid=(high+low)/2;
	//cout<<low<<" "<<mid<<" "<<high<<"\n";
	if(low<high-1){
		mergesort(arr,low,mid);
		mergesort(arr,mid,high);
		merge(arr,low,mid,high);
	}

}




int main(){
	int n,i,temp1;
	string s1;
	FILE *fp;
	fstream fpp;
	while(1){
	fpp.open("inputsort.txt",ios::in);
	//fp=fopen("inputsort.txt","r");
	//fscanf(fp,"%s",s1);
	getline(fpp,s1);
	cout<<s1<<"\n";
	n=checkpos(s1);
	if(n==-1729){
		cout<<"ERROR RETRY AGAIN\n";
		return 0;
	}
	cout<<n;
	cout<<"\n\n\n";
	//cin>>n;
	int arr[n];
	//ren cin>>arr[i];
	ren{
		//fscanf(fp,"%s",s1);
		getline(fpp,s1);
		arr[i]=checkint(s1);
		if(arr[i]==-1729){
			cout<<"ERROR RETRY AGAIN\n";
			return 0;
		}
	}
	//ren cout<<arr[i]<<"\n";
	//fclose(fp);
	fpp.close();
	cout<<"1 for BS\n2 for SS\n3 for IS\n4 for QS\n5 for MS\n";
	cin>>temp1;
	if(temp1==1)
		bs(arr,n);
	else if(temp1==2)
		ss(arr,n);
	else if(temp1==3)
		is(arr,n);
	else if(temp1==4)
		qs(arr,0,n);
	else if(temp1==5)
		mergesort(arr,0,n);  		// MERGE SORT DESCENDING ORDER
	else
		break;
	cout<<"SORTED RESULT : \n";
	fp=fopen("outputsort.txt","a");
	ren cout<<arr[i]<<" ";
	cout<<endl;	
	ren fprintf(fp,"%d ",arr[i]);
	fprintf(fp,"\n");
	fclose(fp);
}
	return 0;
}