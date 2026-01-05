//Phân Tích Định Dạng Dữ Liệu Sang Cấu Trúc Dữ Liệu C++ Ghi và đọc tệp HDF5 với thư viện HighFive
#include <iostream>
#include <vector>
#include <string>

// Thu vien HighFive
#include <highfive/H5File.hpp>

using namespace std;
using namespace HighFive;

// 1. Dinh nghia Cau truc du lieu
struct House {
    int id;
    double dienTich;
    double giaTien;
};

// Ham hien thi danh sach
void printHouses(const vector<House>& list) {
    for (const auto& h : list) {
        cout << "ID: " << h.id 
             << " | DT: " << h.dienTich 
             << " | Gia: " << h.giaTien << endl;
    }
}

int main() {
    cout << "=== GHI VA DOC FILE HDF5 VOI HIGHFIVE ===" << endl;
    string fileName = "housing_data.h5";

    // --- PHAN 1: TAO DU LIEU VA GHI FILE ---
    cout << "\n[1] Dang ghi du lieu vao file " << fileName << "..." << endl;
    
    // Du lieu mau
    vector<int> ids = {1, 2, 3, 4, 5};
    vector<double> dienTichs = {50.5, 70.0, 100.0, 45.0, 120.0};
    vector<double> giaTiens = {1.5, 2.2, 3.5, 1.1, 4.5};

    try {
        // Mo file moi (File::Overwrite de ghi de neu file da ton tai)
        File file(fileName, File::ReadWrite | File::Create | File::Truncate);

        // Tao Dataset cho tung thuoc tinh (HDF5 luu theo dang cot/mang se toi uu nhat)
        file.createDataSet("house_ids", ids);
        file.createDataSet("areas", dienTichs);
        file.createDataSet("prices", giaTiens);
        
        cout << "-> Ghi thanh cong!" << endl;

    } catch (const Exception& err) {
        cerr << "Loi ghi file: " << err.what() << endl;
        return -1;
    }

    // --- PHAN 2: DOC FILE VA MAP SANG STRUCT ---
    cout << "\n[2] Dang doc du lieu tu file HDF5..." << endl;
    
    vector<House> database;

    try {
        // Mo file o che do Chi Doc (ReadOnly)
        File file(fileName, File::ReadOnly);

        // Khai bao cac vector trung gian de hung du lieu
        vector<int> read_ids;
        vector<double> read_areas;
        vector<double> read_prices;

        // Doc Dataset vao vector
        file.getDataSet("house_ids").read(read_ids);
        file.getDataSet("areas").read(read_areas);
        file.getDataSet("prices").read(read_prices);

        // Kiem tra kich thuoc du lieu
        size_t n = read_ids.size();
        if (read_areas.size() != n || read_prices.size() != n) {
            cerr << "Loi: Du lieu khong dong nhat ve kich thuoc!" << endl;
            return -1;
        }

        // Map (Anh xa) tu Vector sang Struct House
        for (size_t i = 0; i < n; ++i) {
            House h;
            h.id = read_ids[i];
            h.dienTich = read_areas[i];
            h.giaTien = read_prices[i];
            
            database.push_back(h);
        }

        cout << "-> Da doc duoc " << n << " ngoi nha." << endl;

    } catch (const Exception& err) {
        cerr << "Loi doc file: " << err.what() << endl;
        return -1;
    }

    // --- PHAN 3: HIEN THI KET QUA ---
    cout << "\n--- KET QUA SAU KHI PARSE ---" << endl;
    printHouses(database);

    return 0;
}