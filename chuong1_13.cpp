//ví dụ về Phân Tích Định Dạng Dữ Liệu Sang Cấu Trúc Dữ Liệu C++ Đọc Tệp CSV Với Thư Viện nlohmann-json
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// QUAN TRONG: Phai co file nay trong thu muc
#include "json.hpp"

// Rut gon ten namespace cho de goi
using json = nlohmann::json;
using namespace std;

// 1. Dinh nghia Struct C++
struct House {
    double dienTich;
    int soPhong;
    double giaTien;
};

int main() {
    cout << "=== CHUYEN DOI CSV SANG JSON (NLOHMANN) ===" << endl;

    // --- PHAN 1: DOC CSV (Dung C++ thuan) ---
    ifstream file("dlib_data.csv");
    if (!file.is_open()) {
        cerr << "Loi: Khong tim thay file dlib_data.csv" << endl;
        return 1;
    }

    vector<House> danhSachNha;
    string line;
    
    // Doc tung dong
    while (getline(file, line)) {
        // Thay dau phay bang dau cach de de doc
        for (char &c : line) if (c == ',') c = ' ';

        stringstream ss(line);
        double dt, gia;
        int sp;

        if (ss >> dt >> sp >> gia) {
            House h;
            h.dienTich = dt;
            h.soPhong = sp;
            h.giaTien = gia;
            danhSachNha.push_back(h);
        }
    }
    file.close();
    cout << "-> Da doc " << danhSachNha.size() << " dong tu CSV." << endl;

    // --- PHAN 2: CHUYEN SANG CAU TRUC JSON ---
    json j_output; // Doi tuong JSON chinh

    // Tao mot mang JSON (JSON Array)
    j_output = json::array();

    for (const auto& nha : danhSachNha) {
        // Tao doi tuong JSON cho tung ngoi nha
        json j_nha;
        j_nha["DienTich"] = nha.dienTich;
        j_nha["SoPhong"] = nha.soPhong;
        j_nha["GiaTien"] = nha.giaTien;

        // Day vao mang
        j_output.push_back(j_nha);
    }

    // --- PHAN 3: XUAT RA MAN HINH VA FILE ---
    
    // In ra man hinh (dump(4) nghia la thut dau dong 4 khoang trang cho dep)
    cout << "\n--- KET QUA JSON ---" << endl;
    cout << j_output.dump(4) << endl;

    // Luu ra file .json
    ofstream o("ket_qua.json");
    o << j_output.dump(4) << endl;
    o.close();
    
    cout << "\n-> Da luu ket qua vao file 'ket_qua.json'" << endl;

    return 0;
}