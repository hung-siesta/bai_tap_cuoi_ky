//Chuẩn hóa dữ liệu Chuẩn hóa với mlpack: fasle
#include <iostream>
#include <mlpack/core.hpp> // Thu vien mlpack

using namespace std;
using namespace arma; // mlpack dung ma tran cua Armadillo
using namespace mlpack;
using namespace mlpack::data;

int main() {
    // 1. Tao du lieu mau (3 hang, 3 cot)
    // Luu y: mlpack luu tru theo kieu (Cot truoc, Hang sau)
    mat dataset = "1.0  2.0  3.0;"
                  "5.0  5.0  5.0;"
                  "10.0 20.0 30.0";
    
    // Chuyen vi de hang/cot dung theo tu duy thong thuong (Hang la mau, Cot la dac trung)
    dataset = dataset.t(); 

    cout << "--- Du lieu goc ---" << endl;
    dataset.print();

    // 2. Khoi tao doi tuong scaler
    MinMaxScaler scaler;
    
    // 3. Hoc du lieu (Tim min, max) va bien doi
    mat normalized_dataset;
    
    // Fit: Tinh min/max, Transform: Ap dung cong thuc
    scaler.Fit(dataset);
    scaler.Transform(dataset, normalized_dataset);

    cout << "\n--- Du lieu sau khi chuan hoa [0, 1] ---" << endl;
    normalized_dataset.print();

    return 0;
}