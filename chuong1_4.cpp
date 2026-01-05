// dung arrayfire nhung loi khong chay  duoc
#include <arrayfire.h>
#include <iostream>

using namespace af;
using namespace std;

int main() {
    try {
        cout << "=== ARRAYFIRE DEMO ===" << endl;

        // 1. CẤU HÌNH (Chọn CPU hoặc GPU)
        setBackend(AF_BACKEND_DEFAULT); // Tự động chọn cái mạnh nhất (thường là GPU)
        info(); // In ra thông tin phần cứng đang chạy

        cout << "\n--- 1. KHOI TAO ---" << endl;
        // Tạo ma trận 3x3 với dữ liệu ngẫu nhiên (Uniform distribution)
        array A = randu(3, 3);
        
        // Tạo ma trận 3x3 toàn số 1
        array B = constant(1, 3, 3);
        
        // Tạo ma trận từ dữ liệu C++ thô (Host pointer)
        float host_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        array C(3, 3, host_data); // Mặc định là column-major (cột trước)

        af_print(A); // Hàm in đặc biệt của ArrayFire
        af_print(C);

        cout << "\n--- 2. TINH TOAN MA TRAN ---" << endl;
        // Cộng/Trừ/Nhân từng phần tử (Element-wise)
        array D = A + B; 
        
        // Nhân ma trận (Matrix Multiplication)
        array E = matmul(A, C);
        
        // Chuyển vị (Transpose)
        array AT = A.T();

        af_print(E);
        af_print(AT);

        cout << "\n--- 3. DAI SO TUYEN TINH (Linear Algebra) ---" << endl;
        // Giải hệ phương trình: Ax = b
        array b = randu(3, 1);
        array x = solve(A, b); // Tìm x
        
        af_print(x);

        // Nghịch đảo ma trận
        array A_inv = inverse(A);
        
        // Trị riêng và Vector riêng (Eigenvalues & Eigenvectors)
        array vals, vecs;
        eig(vals, vecs, A);
        
        cout << "Tri rieng (Eigenvalues):" << endl;
        af_print(vals);

        cout << "\n--- 4. THONG KE (Reductions) ---" << endl;
        // Tính tổng toàn bộ ma trận
        double total_sum = sum<double>(A);
        cout << "Tong tat ca phan tu cua A: " << total_sum << endl;

        // Tính trung bình theo cột (dim 0)
        array col_mean = mean(A, 0);
        af_print(col_mean);

    } catch (af::exception& e) {
        // Bắt lỗi đặc trưng của ArrayFire
        fprintf(stderr, "%s\n", e.what());
        throw;
    }

    return 0;
}