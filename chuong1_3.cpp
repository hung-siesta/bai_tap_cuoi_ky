// su dung blaze: chay duoc
#include <iostream>
// Chỉ cần include file này là đủ cho hầu hết tác vụ
#include <blaze/Math.h> 

using namespace std;
using namespace blaze; // Namespace của Blaze

int main() {
    cout << "=== DEMO BLAZE API (HIGH PERFORMANCE) ===\n" << endl;

    // ---------------------------------------------------------
    // 1. KHỞI TẠO VECTOR VÀ MA TRẬN
    // ---------------------------------------------------------
    // DynamicVector: Kích thước thay đổi được (giống std::vector)
    // rowVector: Vector hàng (mặc định là vector cột nếu không ghi gì)
    DynamicVector<double, rowVector> vec1 = { 1.0, 2.0, 3.0 };
    
    // StaticVector: Kích thước cố định ngay khi code (nhanh hơn)
    StaticVector<double, 3> vec2 = { 4.0, 5.0, 6.0 };

    // Ma trận động (Dynamic Matrix), lưu trữ theo hàng (rowMajor)
    DynamicMatrix<double, rowMajor> mat1 = { {1, 2, 3},
                                             {4, 5, 6} }; // 2x3

    cout << "Vector 1: " << vec1 << endl;
    cout << "Matrix 1:\n" << mat1 << "\n" << endl;


    // ---------------------------------------------------------
    // 2. CÁC PHÉP TOÁN CƠ BẢN (Expression Templates)
    // ---------------------------------------------------------
    cout << "2. Tinh toan co ban:" << endl;
    
    // Blaze tự động hiểu vec2 (cột) cần chuyển vị để cộng với vec1 (hàng) 
    // hoặc báo lỗi nếu không khớp kiểu. Ở đây ta cộng từng phần tử.
    DynamicVector<double, rowVector> sum_vec = vec1 + trans(vec2);
    
    cout << "Tong 2 vector: " << sum_vec << endl;

    // Nhân ma trận với Vector
    // mat1 (2x3) * vec2 (3x1) -> Kết quả (2x1)
    DynamicVector<double> result = mat1 * vec2;
    cout << "Matrix * Vector:\n" << result << "\n" << endl;


    // ---------------------------------------------------------
    // 3. VIEWS VÀ SLICING (Cắt mảng - Rất mạnh của Blaze)
    // ---------------------------------------------------------
    cout << "3. Views (Subvector / Submatrix):" << endl;

    // Lấy hàng thứ 1 (index 1) của ma trận
    // 'row' trả về một view, không copy dữ liệu -> Rất nhanh
    auto r1 = row(mat1, 1); 
    
    cout << "Hang thu 2 cua Matrix: " << r1 << endl;

    // Sửa view -> Sửa luôn dữ liệu gốc
    r1[0] = 99.0;
    cout << "-> Matrix goc sau khi sua View:\n" << mat1 << endl;


    // ---------------------------------------------------------
    // 4. TIỆN ÍCH KHÁC (Chéo, Ma trận đơn vị)
    // ---------------------------------------------------------
    // Tạo ma trận đơn vị (Identity) kích thước 3x3
    IdentityMatrix<double> I(3);
    cout << "\n4. Ma tran don vi (3x3):\n" << I << endl;

    return 0;
}