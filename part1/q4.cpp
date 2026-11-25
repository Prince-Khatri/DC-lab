// for pi value
int main() {
    int n;
    double sum = 0.0, pi;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        double x = (i + 0.5) / n;
        sum += 4.0 / (1.0 + x * x);
    }

    pi = sum / n;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < n; i++) {
        double x = (i + 0.5) / n;
        sum += 4.0 / (1.0 + x * x);
    }

    pi = sum / n;
    cout << "Parallel PI: " << pi << endl;

}
