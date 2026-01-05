//ví dụ Chuẩn hóa dữ liệu Chuẩn hóa với Eigen: good
#include <iostream>
#include <Eigen/Dense> // Thu vien Eigen
#include <cmath>       // De dung ham sqrt

using namespace std;
using namespace Eigen;

int main() {
    // 1. Tao ma tran du lieu (5 hang, 2 cot)
    // Vi du: Cot 0 la Chieu cao, Cot 1 la Can nang
    MatrixXd data(5, 2);
    data << 150, 45,
            160, 55,
            170, 65,
            180, 70,
            190, 85;

    cout << "--- Du lieu goc ---\n" << data << endl << endl;

    // 2. Tinh Trung binh (Mean) cua tung cot
    // colwise(): thuc hien theo cot
    // mean(): tinh trung binh
    RowVectorXd mean_vec = data.colwise().mean();
    cout << "Trung binh (Mean):\n" << mean_vec << endl << endl;

    // 3. Tinh Do lech chuan (Standard Deviation) cua tung cot
    // Buoc 3a: Tru trung binh (Centered data)
    // rowwise(): thuc hien tung hang
    // replicate(): lap lai vector trung binh cho khop kich thuoc ma tran
    MatrixXd centered = data.rowwise() - mean_vec;
    
    // Buoc 3b: Tinh do lech chuan: sqrt( sum(x^2) / (N-1) )
    RowVectorXd std_dev = (centered.array().square().colwise().sum() / (data.rows() - 1)).sqrt();
    cout << "Do lech chuan (Std Dev):\n" << std_dev << endl << endl;

    // 4. Ap dung Z-Score: (X - Mean) / StdDev
    // Ta da co 'centered' la (X - Mean) roi, gio chi can chia cho StdDev
    MatrixXd normalized_data = centered.array().rowwise() / std_dev.array();

    cout << "--- Du lieu da chuan hoa (Z-Score) ---\n" << normalized_data << endl;

    return 0;
}