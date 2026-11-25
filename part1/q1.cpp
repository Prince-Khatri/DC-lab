#include<iostream>
#include<omp.h>
using namespace std;

int main(){
    // part 1
    int a[] = {1,2,3,4,5,6,7,8};
    int sum=0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<8;i++){
        sum+=a[i];
    }
    //part2
    #pragma omp parallel for schedule(static,2)
    for(int i=0;i<4;i++){
        cout<<omp_get_thread_num()<<":"<<i<<endl;
    }

    return 0;
}