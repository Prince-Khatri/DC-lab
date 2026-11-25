#include<iostream>
#include<omp.h>

using namespace std;

void merge(int a[],int l,int m,int r){
    int temp[10000],i=l,j=m+1,k=0;
    while(i<=m&&j<=r){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
        temp[k++]=a[j++];
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)
        a[i]=temp[k++];
}


void seq_ms(int a[], int l, int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    seq_ms(a,l,mid);
    seq_ms(a,mid+1, r);
    merge(a,l,mid,r);
}
void pll_ms(int a[], int l, int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    #pragma omp parallel sections
    {
        #pragma omp section
        pll_ms(a,l,mid);
        #pragma omp section
        pll_ms(a,mid+1,r);
    }
}


int main(){
    
    int a[]= {4,3,2,5,64,0,3,5};
    int b[]= {4,3,2,5,64,0,3,5};
    int n=sizeof(a) / sizeof(a[0]);
    double start = omp_get_wtime();

    seq_ms(a,0,n);
    cout<<omp_get_wtime()-start<<endl;
    start = omp_get_wtime();
    pll_ms(b,0,n);
    cout<<omp_get_wtime()-start<<endl;

}