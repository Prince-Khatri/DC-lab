
// prime number

#pragma omp parallel for

for(int i = 1; i <= n; i++)
    if(prime(i)) {
        #pragma omp critical
        cout << i << " ";
}