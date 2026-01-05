//HOI QUY TUYEN TINH VOI DLIB:good
#include <iostream>
#include <dlib/matrix.h>

using namespace std;
using namespace dlib;

int main() {
    cout << "=== HOI QUY TUYEN TINH VOI DLIB ===" << endl;

    /* Du lieu mau:
       x = [1, 2, 3, 4]
       y = [2, 3, 5, 7]
    */

    // 1. Chuan bi du lieu
    // Ma tran X (4 hang, 2 cot). Cot 1 la x, Cot 2 la 1 (bias)
    matrix<double> X(4, 2);
    // Vector y (4 hang, 1 cot)
    matrix<double> y(4, 1);

    // Gan du lieu
    X = 1, 1,
        2, 1,
        3, 1,
        4, 1;

    y = 2, 
        3, 
        5, 
        7;

    cout << "Ma tran X:\n" << X << endl;
    cout << "Vector y:\n" << y << endl;

    // 2. Tinh toan (Normal Equation)
    // Cong thuc: beta = inv(X' * X) * X' * y
    // Trong Dlib: trans(X) la chuyen vi, inv() la nghich dao
    
    matrix<double> Xt = trans(X);          // X chuyen vi
    matrix<double> XtX = Xt * X;           // X' * X
    matrix<double> XtX_inv = inv(XtX);     // Nghich dao
    matrix<double> Xty = Xt * y;           // X' * y
    
    matrix<double> beta = XtX_inv * Xty;   // Ket qua

    // 3. Ket qua
    double a = beta(0, 0); // He so goc
    double b = beta(1, 0); // He so chan

    cout << "-----------------------" << endl;
    cout << "He so a (Slope)     : " << a << endl;
    cout << "He so b (Intercept) : " << b << endl;
    cout << "Phuong trinh: y = " << a << "x + " << b << endl;

    // Du bao thu x = 10
    cout << "Du bao tai x=10: y = " << (a*10 + b) << endl;

    return 0;
}