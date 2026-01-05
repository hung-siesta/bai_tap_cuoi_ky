//Phân Tích Định Dạng Dữ Liệu Sang Cấu Trúc Dữ Liệu C++ đọc Tệp CSV Với Thư Viện dlib
#include <iostream>
#include <fstream>
#include <string>
#include <vector>      // Thu vien vector cua C++
#include <algorithm>   // Dung de replace
#include <sstream>     // Dung stringstream
#include <dlib/matrix.h>

using namespace std;
using namespace dlib;

struct House {
    double dienTich;
    double soPhong;
    double giaTien;
    
    // Ham chuyen sang vector dac trung cua Dlib
    matrix<double, 2, 1> toFeatureVector() {
        matrix<double, 2, 1> m;
        m = dienTich, soPhong;
        return m;
    }
};

int main() {
    cout << "=== DOC CSV VOI DLIB (DA FIX LOI) ===" << endl;

    // 1. Doc file
    ifstream file("dlib_data.csv");
    if (!file.is_open()) {
        cerr << "Loi: Chua tao file dlib_data.csv!" << endl;
        return 1;
    }

    // --- SUA LOI TAI DAY ---
    // Thay vi viet "vector", ta viet ro la "std::vector" de tranh nham lan voi Dlib
    std::vector<House> dataset; 
    
    string line;
    
    // 2. Xu ly tung dong
    while (getline(file, line)) {
        // Thay dau phay ',' thanh dau cach ' ' de Dlib de doc
        replace(line.begin(), line.end(), ',', ' ');

        stringstream ss(line);
        double dt, sp, gia;
        ss >> dt >> sp >> gia;

        House h;
        h.dienTich = dt;
        h.soPhong = sp;
        h.giaTien = gia;
        dataset.push_back(h);
    }
    file.close();

    // 3. In ket qua
    cout << "Da doc duoc " << dataset.size() << " dong du lieu." << endl;
    for (int i = 0; i < dataset.size(); ++i) {
        cout << "Nha " << i+1 << ": Gia = " << dataset[i].giaTien << endl;
    }

    return 0;
}