//KHOI TAO BLAZE TU CAU TRUC DU LIEU C++ 
#include <iostream>
#include <vector>
#include <blaze/Math.h> // Thu vien chinh cua Blaze

using namespace std;
using namespace blaze;

int main() {
    cout << "=== KHOI TAO BLAZE TU CAU TRUC DU LIEU C++ ===" << endl;

    // --- PHAN 1: TU STD::VECTOR SANG BLAZE VECTOR ---
    cout << "\n[1] Chuyen std::vector -> DynamicVector" << endl;
    
    // Du lieu C++ thuan
    std::vector<double> c_vector = {1.5, 2.5, 3.5, 4.5};

    // Khoi tao Blaze Vector
    // Cach 1: Copy du lieu (An toan, de dung)
    DynamicVector<double> v(c_vector.size());
    for(size_t i=0; i<c_vector.size(); ++i) {
        v[i] = c_vector[i];
    }

    cout << "Blaze Vector: \n" << v << endl;


    // --- PHAN 2: TU MANG 2 CHIEU SANG BLAZE MATRIX ---
    cout << "\n[2] Chuyen std::vector<vector> -> DynamicMatrix" << endl;
    
    // Du lieu C++ dang bang (Matrix)
    std::vector<std::vector<double>> c_matrix = {
        {10, 20, 30},
        {40, 50, 60}
    };
    size_t rows = c_matrix.size();
    size_t cols = c_matrix[0].size();

    // Tao ma tran Blaze (DynamicMatrix: Kich thuoc dong)
    DynamicMatrix<double> M(rows, cols);

    // Do du lieu vao
    for(size_t i=0; i<rows; ++i) {
        for(size_t j=0; j<cols; ++j) {
            M(i, j) = c_matrix[i][j]; // Blaze dung dau ngoac tron ()
        }
    }

    cout << "Blaze Matrix (Copy): \n" << M << endl;


    // --- PHAN 3: KY THUAT "CUSTOM MATRIX" (NANG CAO) ---
    // Day la cach map truc tiep du lieu ma KHONG can copy (Sieu nhanh)
    // Thuong dung khi doc du lieu tho tu cam bien hoac file Binary
    cout << "\n[3] CustomMatrix (Map truc tiep tu mang C)" << endl;

    // Gia su co mot mang C lien tuc trong bo nho
    double raw_data[] = { 1, 2, 3, 
                          4, 5, 6, 
                          7, 8, 9 }; 

    // Tao mot "View" (Goc nhin) vao mang tren duoi dang Ma tran 3x3
    // Tham so: (pointer, rows, cols, spacing, storage_order)
    CustomMatrix<double, unaligned, unpadded, rowMajor> viewMatrix(raw_data, 3, 3);

    cout << "Ma tran anh xa tu Raw Data: \n" << viewMatrix << endl;

    // Thu thay doi Raw Data -> Blaze tu cap nhat
    cout << "-> Thay doi raw_data[0] thanh 999..." << endl;
    raw_data[0] = 999; 
    
    cout << "Ma tran sau khi doi nguon: \n" << viewMatrix << endl;

    // --- PHAN 4: TINH TOAN THU ---
    cout << "\n[4] Tinh toan thu: Vector * Matrix" << endl;
    // Phep nhan Vector dong (RowVector) voi Matrix
    // Luu y: Trong Blaze, Vector mac dinh la cot (Column). 
    // Muon nhan hang ngang phai chuyen vi (trans) hoac dung RowVector.
    
    DynamicVector<double, rowVector> rowV(3); 
    rowV[0]=1; rowV[1]=1; rowV[2]=1; // [1, 1, 1]

    // Ket qua = [1 1 1] * Matrix(3x3)
    // Cong thuc toan: $$ y = x * A $$
    auto ketQua = rowV * viewMatrix; 

    cout << "Ket qua phep nhan: " << ketQua << endl;

    return 0;
}