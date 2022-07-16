#include<iostream>

template<class T> void merge(T arr[], int left, int mid, int right){
	int n1=mid-left+1;
	int n2=right-mid;
	
	T* L= new T[n1];
	T* R= new T[n2];
	
	for(int i=0;i<n1;i++) *(L+i)=arr[left+i];
	for(int i=0;i<n2;i++) *(R+i)=arr[mid+1+i];
	
	int i=0,j=0,k=left;
	while(i<n1 && j<n2){
		if(*(L+i)<=*(R+j)) arr[k++]=*(L+i++);
		else arr[k++]=*(R+j++);
	}
	while(i<n1) arr[k++]=*(L+i++);
	while(j<n2) arr[k++]=*(R+j++);
	
	delete[] L;
	delete[] R;
}

template<class T>  void merge_sort(T arr[], int left, int right){
	if(left>=right) return;
	int mid=left+(right-left)/2;
	
	merge_sort(arr,left, mid);
	merge_sort(arr, mid+1, right);
	
	merge(arr, left, mid, right);
}
int main(){
	char a[]={'d', 'c','a', 'b', 'f', 'g', 'j', 'e', 'h'};
	merge_sort(a, 0, 8);
	for(int i=0;i<9;i++) std::cout<<a[i]<<" ";
}

