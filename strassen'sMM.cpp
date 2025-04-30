#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Adds two matrices
Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Subtracts matrix B from A
Matrix subtract(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Strassen's multiplication
Matrix strassen(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));

    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0];
    } else {
        int k = n / 2;

        // Divide matrices into 4 submatrices
        Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
               A21(k, vector<int>(k)), A22(k, vector<int>(k));
        Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
               B21(k, vector<int>(k)), B22(k, vector<int>(k));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + k];
                A21[i][j] = A[i + k][j];
                A22[i][j] = A[i + k][j + k];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + k];
                B21[i][j] = B[i + k][j];
                B22[i][j] = B[i + k][j + k];
            }

        // Compute the 7 products
        Matrix M1 = strassen(add(A11, A22), add(B11, B22));
        Matrix M2 = strassen(add(A21, A22), B11);
        Matrix M3 = strassen(A11, subtract(B12, B22));
        Matrix M4 = strassen(A22, subtract(B21, B11));
        Matrix M5 = strassen(add(A11, A12), B22);
        Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
        Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));

        // Calculate result quadrants
        Matrix C11 = add(subtract(add(M1, M4), M5), M7);
        Matrix C12 = add(M3, M5);
        Matrix C21 = add(M2, M4);
        Matrix C22 = add(subtract(add(M1, M3), M2), M6);

        // Combine into a single matrix
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++) {
                result[i][j] = C11[i][j];
                result[i][j + k] = C12[i][j];
                result[i + k][j] = C21[i][j];
                result[i + k][j + k] = C22[i][j];
            }
    }

    return result;
}

// Print matrix
void printMatrix(Matrix A) {
    for (auto row : A) {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }
}

// Driver
int main() {
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};

    Matrix C = strassen(A, B);

    cout << "Product matrix:\n";
    printMatrix(C);

    return 0;
}
