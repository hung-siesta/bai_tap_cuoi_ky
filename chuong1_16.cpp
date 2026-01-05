//KHOI TAO MA TRAN & TENSOR VOI DLIB
#include <iostream>
#include <vector>
#include <dlib/matrix.h>
#include <dlib/dnn.h> // Thu vien Deep Learning cua Dlib

using namespace std;
using namespace dlib;

int main() {
    cout << "=== KHOI TAO MA TRAN & TENSOR VOI DLIB  ===" << endl;

    // --- PHAN 1: MA TRAN (GIU NGUYEN) ---
    cout << "\n[1] Ma tran (Matrix)" << endl;
    matrix<double> M(2, 3);
    M = 1, 2, 3,
        4, 5, 6;
    cout << "Matrix M: \n" << M << endl;

    // --- PHAN 2: TENSOR (DA SUA) ---
    cout << "\n[2] Khoi tao Tensor (Dung Resizable Tensor)" << endl;

    try {
        // SU DUNG resizable_tensor THAY VI tensor
        resizable_tensor t; 
        
        // Thiet lap kich thuoc: 2 anh, 3 kenh mau (RGB), cao 2, rong 2
        t.set_size(2, 3, 2, 2); 

        // Truy cap du lieu de ghi (mutable_cpu_data)
        float* p = t.host(); 
        
        // Dien gia tri gia lap
        for(long i = 0; i < t.size(); ++i) {
            p[i] = (float)i; 
        }

        cout << "Kich thuoc Tensor: " 
             << t.num_samples() << " mau x " 
             << t.k() << " kenh x " 
             << t.nr() << " cao x " 
             << t.nc() << " rong" << endl;
        
        cout << "Gia tri tai vi tri dau tien: " << p[0] << endl;
        cout << "Gia tri tai vi tri cuoi cung: " << p[t.size()-1] << endl;
             
    } catch(std::exception& e) {
        cout << "Loi tensor: " << e.what() << endl;
    }

    return 0;
}