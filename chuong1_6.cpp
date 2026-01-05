// hoi quy tuyen tinh voi thu vien Eigen: Good
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
    cout << "=== HOI QUY TUYEN TINH (LINEAR REGRESSION) VOI EIGEN ===" << endl;

    /* Gia su ta co 4 diem du lieu (x, y):
       (1, 2), (2, 3), (3, 5), (4, 7)
       Muc tieu: Tim duong thang y = a*x + b
    */

    // 1. Chuan bi du lieu
    // Ma tran thiet ke X (Design Matrix) se co dang [x, 1]
    // Cot 1 la gia tri x, Cot 2 toan so 1 (de tinh he so chan b)
    int n_samples = 4; // So luong mau
    MatrixXd X(n_samples, 2);
    VectorXd y(n_samples);

    // Nhap du lieu
    X << 1, 1,
         2, 1,
         3, 1,
         4, 1;
    
    y << 2, 3, 5, 7;

    cout << "Ma tran Input X:\n" << X << "\n\n";
    cout << "Vector Target y:\n" << y << "\n\n";

    // 2. Giai bai toan Binh phuong toi thieu (Least Squares)
    // Cong thuc: X * beta = y  => Tim beta
    // Eigen cung cap ham solve() qua phuong phap QR (colPivHouseholderQr) rat on dinh
    VectorXd beta = X.colPivHouseholderQr().solve(y);

    // 3. Lay ket qua
    double a = beta(0); // He so goc (slope)
    double b = beta(1); // He so chan (intercept/bias)

    cout << "---------------------------------" << endl;
    cout << "KET QUA:" << endl;
    cout << "He so a (Slope)     : " << a << endl;
    cout << "He so b (Intercept) : " << b << endl;
    cout << "=> Phuong trinh duong thang: y = " << a << "x + (" << b << ")" << endl;

    // 4. Du bao (Prediction) cho gia tri moi
    double x_new = 5.0;
    double y_pred = a * x_new + b;
    cout << "\n[Du bao] Voi x = " << x_new << ", gia tri y du doan la: " << y_pred << endl;

    return 0;
}