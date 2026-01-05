// dung thu vien dlib: Fasle
// Cần include module matrix của dlib
#include <dlib/matrix.h>
#include <iostream>

using namespace dlib;
using namespace std;

int main() {
    try {
        cout << "=== DAI SO TUYEN TINH VOI DLIB ===" << endl;

        // ---------------------------------------------------------
        // 1. KHOI TAO MA TRAN (Initialization)
        // ---------------------------------------------------------
        
        // Tạo ma trận 3x3
        matrix<double> A(3, 3);
        
        // Gán giá trị bằng toán tử dấu phẩy (Comma initialization) - Giống Eigen
        A = 1, 2, 3,
            4, 5, 6,
            7, 8, 10; // Đổi số cuối để ma trận khả nghịch

        // Tạo vector cột (3 hàng, 1 cột)
        matrix<double, 3, 1> b;
        b = 3, 3, 4;

        cout << "Ma tran A:\n" << A << endl;
        cout << "Vector b:\n" << b << endl;

        // ---------------------------------------------------------
        // 2. CAC PHEP TOAN CO BAN (Basic Operations)
        // ---------------------------------------------------------
        
        // Chuyển vị (Transpose)
        matrix<double> At = trans(A);
        cout << "Chuyen vi cua A (Transposed):\n" << At << endl;

        // Định thức (Determinant)
        double d = det(A);
        cout << "Dinh thuc det(A): " << d << endl;

        // Nghịch đảo (Inverse)
        matrix<double> A_inv = inv(A);
        cout << "Nghich dao A^-1:\n" << A_inv << endl;

        // ---------------------------------------------------------
        // 3. GIAI HE PHUONG TRINH (Solving System Ax = b)
        // ---------------------------------------------------------
        
        // Cách 1: Nhân với ma trận nghịch đảo (x = A^-1 * b)
        matrix<double> x = inv(A) * b;
        cout << "Nghiem x (cach 1): \n" << x << endl;

        // Cách 2: Dùng hàm giải chuyên biệt (Chính xác hơn)
        // Dlib không có hàm solve() trực tiếp như Eigen, 
        // nhưng phép chia ma trận A\b (trong MATLAB) tương đương inv(A)*b
        // Tuy nhiên, để tối ưu người ta thường dùng phân rã LU hoặc QR.
        
        // Ví dụ dùng phân rã LU để giải:
        // x = lu_decomposition(A).solve(b); (Cú pháp nâng cao)

        // ---------------------------------------------------------
        // 4. TRI RIENG & VECTOR RIENG (Eigenvalues & Eigenvectors)
        // ---------------------------------------------------------
        
        // Tính trị riêng (chỉ áp dụng cho ma trận đối xứng hoặc dùng hàm eigenvalue_decomposition)
        // Ví dụ tạo một ma trận đối xứng để dễ demo
        matrix<double> S = A * trans(A); 
        
        eigenvalue_decomposition<matrix<double>> eig(S);
        
        cout << "Tri rieng (Eigenvalues):\n" << eig.get_real_eigenvalues() << endl;
        // cout << "Vector rieng (Eigenvectors):\n" << eig.get_pseudo_v() << endl;

    } catch (std::exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    return 0;
}