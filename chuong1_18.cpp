//KHOI TAO MA TRAN & TENSOR VOI MLPACK 
#include <iostream>
#include <vector>

// mlpack dung Armadillo lam nen tang toan hoc
// Ban co the include <mlpack/core.hpp> hoac truc tiep <armadillo>
#include <armadillo> 

using namespace std;
using namespace arma; // Khong gian ten cua Armadillo

int main() {
    cout << "=== KHOI TAO MA TRAN & TENSOR VOI MLPACK (ARMADILLO) ===" << endl;

    // --- PHAN 1: TU STD::VECTOR SANG MA TRAN (MATRIX) ---
    cout << "\n[1] Vector C++ -> Matrix" << endl;
    
    // Gia su du lieu 1 dong: {1, 2, 3, 4, 5, 6}
    std::vector<double> data_cpp = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    // Buoc 1: Chuyen vector thanh Ma tran cot (6 hang, 1 cot)
    // cu phap: mat(con_tro_du_lieu, so_hang, so_cot, copy_aux_mem, strict)
    mat A(data_cpp.data(), data_cpp.size(), 1, false, true);

    // Buoc 2: Dinh hinh lai (Reshape) thanh 2 hang, 3 cot
    // Luu y: Armadillo luu theo COT (Column-major), khac voi C++ (Row-major)
    // Nen ta thuong phai chuyen vi (.t()) neu nhap du lieu thu cong kieu C++
    A.reshape(2, 3); 

    cout << "Ma tran A (tu vector): \n" << A << endl;


    // --- PHAN 2: TU MANG 2 CHIEU THO SANG MA TRAN ---
    cout << "\n[2] Mang 2 chieu -> Matrix" << endl;

    // Du lieu mong muon:
    // 1  2  3
    // 4  5  6
    // Vi Armadillo doc theo cot, ta phai nhap du lieu theo thu tu: 1, 4, 2, 5, 3, 6
    double raw_data[] = {1, 4, 2, 5, 3, 6}; 

    mat B(raw_data, 2, 3); // 2 hang, 3 cot
    
    cout << "Ma tran B (nhap theo cot): \n" << B << endl;
    
    // Phep toan mlpack/armadillo
    cout << "B * 2 = \n" << B * 2 << endl;


    // --- PHAN 3: KHOI TAO TENSOR (CUBE) ---
    cout << "\n[3] Khoi tao Tensor (Cube - 3D)" << endl;
    
    // Trong Armadillo/mlpack, Tensor goi la Cube
    // Kich thuoc: 2 hang, 2 cot, 2 lát cắt (slices)
    cube C(2, 2, 2);

    // Gan gia tri thu cong
    C(0, 0, 0) = 10; // Hang 0, Cot 0, Slice 0
    C(1, 1, 1) = 99; // Hang 1, Cot 1, Slice 1
    
    // Hoac do toan bo du lieu vao (fill)
    C.fill(1.5); 

    cout << "Tensor C (Slice 0):\n" << C.slice(0) << endl;
    cout << "Kich thuoc: " << C.n_rows << "x" << C.n_cols << "x" << C.n_slices << endl;

    return 0;
}#include <iostream>
#include <vector>

// mlpack dung Armadillo lam nen tang toan hoc
// Ban co the include <mlpack/core.hpp> hoac truc tiep <armadillo>
#include <armadillo> 

using namespace std;
using namespace arma; // Khong gian ten cua Armadillo

int main() {
    cout << "=== KHOI TAO MA TRAN & TENSOR VOI MLPACK (ARMADILLO) ===" << endl;

    // --- PHAN 1: TU STD::VECTOR SANG MA TRAN (MATRIX) ---
    cout << "\n[1] Vector C++ -> Matrix" << endl;
    
    // Gia su du lieu 1 dong: {1, 2, 3, 4, 5, 6}
    std::vector<double> data_cpp = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    // Buoc 1: Chuyen vector thanh Ma tran cot (6 hang, 1 cot)
    // cu phap: mat(con_tro_du_lieu, so_hang, so_cot, copy_aux_mem, strict)
    mat A(data_cpp.data(), data_cpp.size(), 1, false, true);

    // Buoc 2: Dinh hinh lai (Reshape) thanh 2 hang, 3 cot
    // Luu y: Armadillo luu theo COT (Column-major), khac voi C++ (Row-major)
    // Nen ta thuong phai chuyen vi (.t()) neu nhap du lieu thu cong kieu C++
    A.reshape(2, 3); 

    cout << "Ma tran A (tu vector): \n" << A << endl;


    // --- PHAN 2: TU MANG 2 CHIEU THO SANG MA TRAN ---
    cout << "\n[2] Mang 2 chieu -> Matrix" << endl;

    // Du lieu mong muon:
    // 1  2  3
    // 4  5  6
    // Vi Armadillo doc theo cot, ta phai nhap du lieu theo thu tu: 1, 4, 2, 5, 3, 6
    double raw_data[] = {1, 4, 2, 5, 3, 6}; 

    mat B(raw_data, 2, 3); // 2 hang, 3 cot
    
    cout << "Ma tran B (nhap theo cot): \n" << B << endl;
    
    // Phep toan mlpack/armadillo
    cout << "B * 2 = \n" << B * 2 << endl;


    // --- PHAN 3: KHOI TAO TENSOR (CUBE) ---
    cout << "\n[3] Khoi tao Tensor (Cube - 3D)" << endl;
    
    // Trong Armadillo/mlpack, Tensor goi la Cube
    // Kich thuoc: 2 hang, 2 cot, 2 lát cắt (slices)
    cube C(2, 2, 2);

    // Gan gia tri thu cong
    C(0, 0, 0) = 10; // Hang 0, Cot 0, Slice 0
    C(1, 1, 1) = 99; // Hang 1, Cot 1, Slice 1
    
    // Hoac do toan bo du lieu vao (fill)
    C.fill(1.5); 

    cout << "Tensor C (Slice 0):\n" << C.slice(0) << endl;
    cout << "Kich thuoc: " << C.n_rows << "x" << C.n_cols << "x" << C.n_slices << endl;

    return 0;
}