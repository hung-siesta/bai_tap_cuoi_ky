//HOI QUY TUYEN TINH VOI ARRAYFIRE: Fasle
#include <iostream>
#include <arrayfire.h>

using namespace std;
using namespace af;

int main() {
    try {
        cout << "=== HOI QUY TUYEN TINH VOI ARRAYFIRE ===" << endl;
        
        // Hien thi thong tin thiet bi dang dung (CPU hoac GPU)
        af::info();

        // 1. Chuan bi du lieu (Dữ liệu mẫu)
        // x = [1, 2, 3, 4], y = [2, 3, 5, 7]
        float h_x[] = {1, 2, 3, 4};
        float h_y[] = {2, 3, 5, 7};

        // Tao ArrayFire array (Vector cot 4x1)
        array x(4, 1, h_x);
        array y(4, 1, h_y);

        // 2. Tao Ma tran thiet ke (Design Matrix) X
        // Can them mot cot toan so 1 vao sau x de tinh he so chan (Bias/Intercept)
        // X = [x, 1]
        array ones = constant(1, 4, 1, f32); // Vector cot 4x1 toan so 1
        array X = join(1, x, ones);          // Noi cot 1 (x) va cot 2 (ones)

        cout << "Ma tran X: " << endl;
        af::print(X);

        // 3. Giai bai toan Binh phuong toi thieu (Least Squares)
        // ArrayFire cung cap ham solve() tu dong xu ly he phuong trinh qua quy dinh
        // Ham nay tim nghiem tot nhat cho: X * beta = y
        array beta = solve(X, y);

        // 4. Ket qua
        cout << "Ket qua (Beta):" << endl;
        af::print(beta);

        // Lay du lieu tu GPU/Library ve CPU de in ra dep hon
        float* h_beta = beta.host<float>();
        cout << "---------------------------" << endl;
        cout << "He so a (Slope)     : " << h_beta[0] << endl;
        cout << "He so b (Intercept) : " << h_beta[1] << endl;
        cout << "Phuong trinh: y = " << h_beta[0] << "x + " << h_beta[1] << endl;

        // Giai phong vung nho host
        delete[] h_beta;

    } catch (af::exception& e) {
        cerr << "Loi ArrayFire: " << e.what() << endl;
        return 1;
    }

    return 0;
}