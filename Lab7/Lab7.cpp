#include <iostream>
#include <cmath>
using namespace std;

void clearMemory(int** a, int n){
    for (int i = 0; i < n; i++){
        delete[] a[i];
    }
    delete[] a;
}

int findDet(int** a, int n){ 
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        int d = 0;
        for (int k = 0; k < n; k++) {
            int** m = new int* [n - 1];
            for (int i = 0; i < n - 1; i++) {
                m[i] = new int[n - 1];
            }
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
            clearMemory(m, n - 1); 
        }
        return d; 
    }
}

int main(){
    int n; 
    cout << "Mmatrix size:\n";
    cout << "n = ";
    cin >> n; 
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j]; 
        }
    }
    cout << "Determinant: " << findDet(a, n) << "\n"; 
    clearMemory(a, n); 
    return 0;
}