#include<stdio.h>
#include<stdlib.h>
// void swap(int*a,int*b){
// 	int t=*a;
// 	*a=*b;
// 	// *b=t;
// }
void quicksort(int a[],int f, int l){
	int dn=f+1,up=l,fix=a[f];
	while(fix>a[dn])
		dn++;
	while(fix<a[up])
		up--;
	while(dn<up){
		swap(&a[dn],&a[up]);
		while(fix>a[dn])
			dn++;
		while(fix<a[up])
			up--;
		
	}
	if(f!=up){
		swap(&a[f],&a[up]);
	}
	if(f<up-1){
		quicksort(a,f,up-1);
	}
	if(l>up+1){
		quicksort(a,up+1,l);
	}
}

int BinarySearch(int a[],int b,int e,int s){
	int mid;
	if(b>e){
		return -1;
	}
	else{
		mid=(b+e)/2;
		if(a[mid]==s)
			return mid;
		else if(s<a[mid]){
			return BinarySearch(a,b,mid-1,s);
		}
		else{
			return BinarySearch(a,mid+1,e,s);
		}
	}
}


int main(){

	int a[8];
	for(int i=0;i<8;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,7);
	for(int i=0;i<8;i++)
		printf("%d\t",a[i]);
	
	printf("\n35 found at %d",BinarySearch(a,0,7,35));
	return 0;
}