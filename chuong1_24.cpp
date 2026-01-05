//Chuẩn hóa dữ liệu Chuẩn hóa với dlib: goood
#include <iostream>
#include <vector>
#include <dlib/matrix.h>
#include <dlib/statistics.h> // Thu vien thong ke va chuan hoa

using namespace std;
using namespace dlib;

// Dinh nghia kieu du lieu: Mot cot vector co 2 chieu (Vi du: Chieu cao, Can nang)
typedef matrix<double, 2, 1> sample_type;

int main() {
    // 1. Tao du lieu mau
    // Dlib thuong luu data duoi dang std::vector chua cac matrix cot
    std::vector<sample_type> samples;

    // Gia lap data: (Chieu cao, Can nang)
    sample_type m;
    
    m(0) = 150; m(1) = 45; samples.push_back(m);
    m(0) = 160; m(1) = 55; samples.push_back(m);
    m(0) = 170; m(1) = 65; samples.push_back(m);
    m(0) = 180; m(1) = 75; samples.push_back(m);
    m(0) = 190; m(1) = 85; samples.push_back(m);

    cout << "--- Mau dau tien (Chua chuan hoa) ---" << endl;
    cout << samples[0] << endl;

    // 2. Khoi tao doi tuong chuan hoa
    vector_normalizer<sample_type> normalizer;

    // 3. "Hoc" du lieu (Train)
    // Buoc nay Dlib se tinh toan Trung binh (Mean) va Phuong sai (Variance) cua toan bo tap du lieu
    normalizer.train(samples);

    cout << "Trung binh da tinh duoc:\n" << normalizer.means() << endl;
    cout << "Do lech chuan da tinh duoc:\n" << normalizer.std_devs() << endl;

    // 4. Ap dung chuan hoa (Transform)
    // Thu chuan hoa mau dau tien
    sample_type normalized_sample = normalizer(samples[0]);

    cout << "--- Mau dau tien (DA CHUAN HOA Z-Score) ---" << endl;
    cout << normalized_sample << endl;

    // 5. Chuan hoa toan bo danh sach
    std::vector<sample_type> normalized_samples;
    for(auto& s : samples) {
        normalized_samples.push_back(normalizer(s));
    }

    return 0;
}