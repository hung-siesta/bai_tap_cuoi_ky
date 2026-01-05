//Giải quyết các nhiệm vụ hồi quy tuyến tính với Blaze: Fasle
#include <iostream>
#include <blaze/Math.h> // Thu vien toan hoc cua Blaze

using namespace blaze; // Khong gian ten cua Blaze
using namespace std;

int main() {
    cout << "=== HOI QUY TUYEN TINH VOI BLAZE ===" << endl;

    // Bai toan: Tim duong thang y = ax + b di qua cac diem:
    // (1, 2), (2, 3), (3, 5), (4, 7)

    // 1. Chuan bi du lieu
    // Ma tran X (4 hang, 2 cot): Cot 1 la x, Cot 2 la 1
    DynamicMatrix<double> X(4, 2);
    
    // Vector y (4 phan tu)
    DynamicVector<double> y(4);

    // Gan du lieu (Blaze dung () de truy cap phan tu)
    X(0,0) = 1; X(0,1) = 1;
    X(1,0) = 2; X(1,1) = 1;
    X(2,0) = 3; X(2,1) = 1;
    X(3,0) = 4; X(3,1) = 1;

    y[0] = 2;
    y[1] = 3;
    y[2] = 5;
    y[3] = 7;

    cout << "Ma tran X:\n" << X << endl;
    cout << "Vector y:\n" << y << endl;

    // 2. Tinh toan (Normal Equation)
    // Cong thuc: beta = (X^T * X)^-1 * (X^T * y)
    
    // Buoc 2a: Tinh X^T * X
    DynamicMatrix<double> XtX = trans(X) * X;

    // Buoc 2b: Tinh X^T * y
    DynamicVector<double> Xty = trans(X) * y;

    // Buoc 2c: Tinh nghich dao va nhan (Giai he phuong trinh)
    // Trong Blaze, tot nhat la dung ham solve() thay vi inv() de chinh xac hon
    // Giai he: (XtX) * beta = (Xty)
    DynamicVector<double> beta;
    try {
        // Ham solve cua Blaze doi hoi ma tran vuong
        solve( XtX, beta, Xty ); 
    } catch (std::exception& e) {
        cerr << "Loi tinh toan: " << e.what() << endl;
        return 1;
    }

    // 3. Ket qua
    double a = beta[0];
    double b = beta[1];

    cout << "-----------------------" << endl;
    cout << "He so a (Slope): " << a << endl;
    cout << "He so b (Intercept): " << b << endl;
    cout << "Phuong trinh: y = " << a << "x + " << b << endl;

    return 0;
}