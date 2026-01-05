//ví dụ Chuẩn hóa dữ liệu Chuẩn hóa với flashlight: fasle
#include <iostream>
#include <flashlight/flashlight.h> // Thu vien Flashlight
#include <arrayfire.h>             // Flashlight dung ArrayFire lam backend

using namespace std;
namespace fl = flashlight;

int main() {
    try {
        // 1. Khoi tao du lieu (Ma tran 5x3)
        // Trong Flashlight/ArrayFire: Kich thuoc la (Cot, Hang) hoac (Dim0, Dim1)
        // af::randu tao so ngau nhien tu 0-1
        af::array data = af::randu(3, 5); 

        cout << "--- Du lieu goc (Raw Data) ---" << endl;
        af::print("Data", data);

        // 2. Tinh Trung binh (Mean) va Do lech chuan (StdDev)
        // Dim = 1 nghia la tinh theo chieu doc (tung cot du lieu)
        af::array mean = af::mean(data, 1);
        af::array stdev = af::stdev(data, 1);

        cout << "--- Thong ke ---" << endl;
        af::print("Mean", mean);
        af::print("StdDev", stdev);

        // 3. Thuc hien Chuan hoa (Normalization)
        // Cong thuc: (X - Mean) / StdDev
        // ArrayFire ho tro "Broadcasting" (tu dong khop kich thuoc ma tran voi vector)
        af::array normalized_data = (data - mean) / stdev;

        cout << "--- Du lieu da chuan hoa (Z-Score) ---" << endl;
        af::print("Normalized", normalized_data);

        // 4. (Tuy chon) Chuyen vao fl::Variable de dung cho Mang neuron
        auto input_var = fl::Variable(normalized_data, false); // false = khong can tinh dao ham
        
    } catch (af::exception& e) {
        cout << "Loi ArrayFire: " << e.what() << endl;
    }

    return 0;
}