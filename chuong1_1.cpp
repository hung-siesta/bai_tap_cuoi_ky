//dung Eigen :chay duoc
#include <iostream>
#include <vector>
#include <numeric>

// Thư viện Eigen (Cần tải về và thêm vào đường dẫn include)
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main() {
    cout << "=== DEMO MACHINE LEARNING API VOI EIGEN ===\n" << endl;

    // ---------------------------------------------------------
    // PHẦN 1: KHỞI TẠO MA TRẬN (Matrix Initialization)
    // ---------------------------------------------------------
    cout << "1. Khoi tao Ma tran:" << endl;
    
    // Cách 1: Ma trận tĩnh (Kích thước cố định tại Compile-time) -> Tối ưu nhất
    Matrix3d static_mat; // 3x3 double
    static_mat << 1, 2, 3,
                  4, 5, 6,
                  7, 8, 9;
    cout << "Ma tran tinh (3x3):\n" << static_mat << "\n" << endl;

    // Cách 2: Ma trận động (Kích thước quyết định lúc Run-time) -> Linh hoạt
    int rows = 4, cols = 2;
    MatrixXd dynamic_mat(rows, cols);
    dynamic_mat.setRandom(); // Điền giá trị ngẫu nhiên
    cout << "Ma tran dong (Random 4x2):\n" << dynamic_mat << "\n" << endl;


    // ---------------------------------------------------------
    // PHẦN 2: ZERO-COPY VỚI EIGEN::MAP (Quan trọng cho ML)
    // ---------------------------------------------------------
    cout << "2. Ky thuat Map (Zero-Copy):" << endl;

    // Giả lập dữ liệu thô đọc từ file CSV hoặc Sensor (Dạng vector 1 chiều)
    vector<double> raw_data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    // Ánh xạ vector này thành Ma trận 2x3 mà KHÔNG COPY dữ liệu
    // Map<Matrix<Type, Rows, Cols>>(pointer)
    Map<Matrix<double, 2, 3, RowMajor>> mapped_mat(raw_data.data());

    cout << "Ma tran Map tu vector:\n" << mapped_mat << endl;

    // Chứng minh Map dùng chung bộ nhớ: Sửa Map -> Vector gốc đổi theo
    mapped_mat(0, 0) = 999.9;
    cout << "-> Gia tri dau tien trong vector goc sau khi sua Map: " << raw_data[0] << "\n" << endl;


    // ---------------------------------------------------------
    // PHẦN 3: TÍNH TOÁN ĐẠI SỐ TUYẾN TÍNH (Algebra Operations)
    // ---------------------------------------------------------
    cout << "3. Tinh toan Dai so:" << endl;

    Matrix2d A; A << 1, 2, 
                     3, 4;
    Matrix2d B; B << 2, 0, 
                     0, 2;

    // Phép nhân ma trận (Matrix Multiplication)
    Matrix2d C = A * B;
    cout << "A * B =\n" << C << endl;

    // Phép nhân từng phần tử (Element-wise)
    Matrix2d D = A.array() * B.array();
    cout << "A .* B (Nhan tung phan tu) =\n" << D << endl;

    // Chuyển vị (Transpose)
    cout << "Chuyen vi cua A:\n" << A.transpose() << endl;

    // Nghịch đảo (Inverse)
    cout << "Nghich dao cua A:\n" << A.inverse() << endl;


    // ---------------------------------------------------------
    // PHẦN 4: ỨNG DỤNG - GIẢI HỆ PHƯƠNG TRÌNH TUYẾN TÍNH (Ax = b)
    // ---------------------------------------------------------
    cout << "\n4. Giai he phuong trinh Ax = b:" << endl;
    // Bài toán: Tìm x biết A*x = b
    // A = [[3, 1], [1, 2]], b = [9, 8]
    // Giải: 3x1 + x2 = 9 và x1 + 2x2 = 8 -> Kết quả x = [2, 3]

    Matrix2d SysA; 
    SysA << 3, 1, 
            1, 2;
    Vector2d b(9, 8);

    // Giải phương trình sử dụng phân rã ColPivHouseholderQR (Chính xác & Ổn định)
    Vector2d x = SysA.colPivHouseholderQr().solve(b);

    cout << "Ma tran he so A:\n" << SysA << endl;
    cout << "Vector b:\n" << b << endl;
    cout << "-> Nghiem x tim duoc:\n" << x << endl;

    // Kiểm tra lại sai số
    double error = (SysA * x - b).norm();
    cout << "Sai so du doan: " << error << endl;

    // Dừng màn hình
    cout << "\nNhan Enter de ket thuc...";
    cin.get();
    
    return 0;
}