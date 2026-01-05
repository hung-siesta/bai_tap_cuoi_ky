#include <iostream>
#include <vector>
// Thu vien mlpack Core de load du lieu
#include <mlpack/core.hpp>

using namespace std;
using namespace mlpack;

// 1. Dinh nghia Cau truc du lieu C++ ma chung ta muon chuyen doi sang
struct House {
    double dienTich;
    double soPhong;
    double giaTien;

    void print() const {
        cout << "[Nha] DT: " << dienTich 
             << " | Phong: " << soPhong 
             << " | Gia: " << giaTien << endl;
    }
};

int main() {
    cout << "=== DOC CSV VOI MLPACK & MAP SANG STRUCT ===" << endl;

    // 2. Load du lieu vao ma tran Armadillo
    arma::mat dataset;
    
    // mlpack::data::Load se tra ve true neu thanh cong
    // Tham so cuoi cung = true nghia la (Load va Transpose)
    // CSV (Hang = Mau) --> Matrix (Cot = Mau) de toi uu toc do tinh toan
    bool loaded = data::Load("data_mlpack.csv", dataset, true);

    if (!loaded) {
        cerr << "Khong the mo file data_mlpack.csv" << endl;
        return -1;
    }

    cout << "Kich thuoc ma tran sau khi load: " 
         << dataset.n_rows << " hang x " << dataset.n_cols << " cot" << endl;
    cout << "(Luu y: mlpack luu moi mau du lieu la mot COT)\n" << endl;

    // 3. Chuyen doi (Parse) tu Ma tran mlpack sang Vector Struct C++
    vector<House> listHouses;

    // Duyet qua tung COT (vi moi cot la mot ngoi nha)
    for (size_t i = 0; i < dataset.n_cols; ++i) {
        House h;
        // Lay du lieu tu cac hang tuong ung cua cot thu i
        h.dienTich = dataset(0, i); // Hang 0
        h.soPhong  = dataset(1, i); // Hang 1
        h.giaTien  = dataset(2, i); // Hang 2

        listHouses.push_back(h);
    }

    // 4. Kiem tra ket qua
    cout << "--- Danh sach du lieu trong C++ Struct ---" << endl;
    for (const auto& h : listHouses) {
        h.print();
    }

    return 0;
}