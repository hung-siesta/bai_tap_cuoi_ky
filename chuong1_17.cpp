// KHOI TAO MA TRAN & TENSOR VOI ARRAYFIRE: Fasle
#include <iostream>
#include <vector>
#include <arrayfire.h> // Thu vien chinh

using namespace std;
using namespace af;

int main() {
    try {
        // Hien thi thong tin thiet bi (CPU/OpenCL/CUDA)
        af::info();

        cout << "=== KHOI TAO MA TRAN & TENSOR VOI ARRAYFIRE ===" << endl;

        // --- PHAN 1: TU STD::VECTOR SANG MA TRAN (2D ARRAY) ---
        cout << "\n[1] Khoi tao Ma tran (2D)" << endl;
        
        // Du lieu C++ (Luu y: ArrayFire doc theo cot - Column Major)
        // Muon ma tran:
        // 1  2  3
        // 4  5  6
        // Thi phai xep du lieu thanh: {1, 4, 2, 5, 3, 6}
        vector<float> data_cpp = {1, 4, 2, 5, 3, 6};

        // Tao array (2 hang, 3 cot)
        // Cu phap: array(dim0, dim1, con_tro_du_lieu)
        array A(2, 3, data_cpp.data());

        cout << "Ma tran A:" << endl;
        af::print("A", A);


        // --- PHAN 2: TU MANG C THO SANG TENSOR (3D ARRAY) ---
        cout << "\n[2] Khoi tao Tensor (3D)" << endl;

        // Gia su Tensor kich thuoc: 2x2x2 (2 block, moi block 2x2)
        float raw_data[] = {
            1, 2, 3, 4,  // Lop thu 1
            5, 6, 7, 8   // Lop thu 2
        };

        // Tao array 3 chieu (2 hang, 2 cot, 2 lop sau)
        array T(2, 2, 2, raw_data);

        cout << "Tensor T:" << endl;
        af::print("T", T);


        // --- PHAN 3: TINH TOAN DON GIAN ---
        cout << "\n[3] Tinh toan tren Tensor" << endl;
        // Nhan toan bo Tensor voi 10
        array T2 = T * 10;
        af::print("T * 10", T2);

    } catch (af::exception& e) {
        cerr << "Loi ArrayFire: " << e.what() << endl;
    }

    return 0;
}