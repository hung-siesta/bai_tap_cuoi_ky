// dung xtensor : loi khong chay duoc
#include <iostream>
#include <vector>
#include <algorithm>

// Bao gồm các thư viện cốt lõi của xtensor
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor/xadapt.hpp>
#include <xtensor/xrandom.hpp>

using namespace std;

int main() {
    cout << "=== DEMO XTENSOR API (NUMPY FOR C++) ===\n" << endl;

    // ---------------------------------------------------------
    // 1. KHỞI TẠO MẢNG (xarray vs xtensor)
    // ---------------------------------------------------------
    // xarray: Số chiều động (giống numpy.array) -> Linh hoạt
    xt::xarray<double> arr1 = {{1.0, 2.0, 3.0},
                               {4.0, 5.0, 6.0}};

    cout << "1. Khoi tao xarray (2x3):\n" << arr1 << "\n" << endl;

    // Tạo mảng với giá trị khởi tạo (giống np.zeros, np.ones)
    xt::xarray<int> ones = xt::ones<int>({2, 2}); 
    cout << "Mang ones (2x2):\n" << ones << "\n" << endl;


    // ---------------------------------------------------------
    // 2. VIEW VÀ SLICING (Cắt mảng - Zero Copy)
    // ---------------------------------------------------------
    cout << "2. Slicing (View):" << endl;
    // Lấy hàng đầu tiên, tất cả các cột. Giống Python: arr1[0, :]
    auto row0 = xt::view(arr1, 0, xt::all()); 
    
    cout << "Hang 0 cua arr1: " << row0 << endl;

    // Sửa trên view sẽ sửa dữ liệu gốc (tham chiếu)
    row0(0) = 99.0;
    cout << "-> Gia tri goc sau khi sua View: " << arr1(0, 0) << "\n" << endl;


    // ---------------------------------------------------------
    // 3. BROADCASTING (Tính năng mạnh nhất của xtensor)
    // ---------------------------------------------------------
    cout << "3. Broadcasting (Cong vector vao ma tran):" << endl;
    
    xt::xarray<double> matrix = {{1, 2, 3}, 
                                 {4, 5, 6}}; // 2x3
    xt::xarray<double> vec = {10, 20, 30};   // 1x3

    // Cộng vector vào từ hàng của ma trận
    // Eigen sẽ lỗi nếu không dùng .rowwise(), nhưng xtensor tự hiểu
    xt::xarray<double> result = matrix + vec;

    cout << "Matrix:\n" << matrix << endl;
    cout << "Vector:\n" << vec << endl;
    cout << "Ket qua (Matrix + Vector):\n" << result << "\n" << endl;


    // ---------------------------------------------------------
    // 4. ADAPTOR (Map dữ liệu từ std::vector - Zero Copy)
    // ---------------------------------------------------------
    cout << "4. Adaptor (Tuong tu Eigen::Map):" << endl;
    
    std::vector<double> data = {1, 2, 3, 4, 5, 6};
    std::vector<std::size_t> shape = {2, 3};

    // Biến vector thường thành xarray mà không copy bộ nhớ
    auto mapped_arr = xt::adapt(data, shape);

    cout << "Mapped Array:\n" << mapped_arr << endl;
    
    mapped_arr(1, 2) = 1000;
    cout << "Gia tri vector goc thay doi theo: " << data[5] << endl;

    return 0;
}