#include<iostream>
#include<omp.h>
using namespace std;

int fibo(int n){
    if(n==0||n==1) return 1;
    int x,y;
    #pragma omp task shared(x)
    x=fibo(n-1);
    #pragma omp task shared(y)
    y=fibo(n-2);

    #pragma omp taskwait
    return x+y;
}


int main(){
    int n=8;
    cout<<fibo(n);   

}