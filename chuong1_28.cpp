#include <iostream>
#include <dlib/svm.h>
#include <dlib/matrix.h>

using namespace std;
using namespace dlib;

int main() {
    // 1. Tao du lieu mau (2 lop: -1 va +1)
    // Bai toan: Phan loai diem nam trong vong tron va ngoai vong tron
    std::vector<matrix<double, 2, 1>> samples;
    std::vector<double> labels;

    // Tao 100 diem ngau nhien
    for (int i = 0; i < 100; ++i) {
        matrix<double, 2, 1> sample;
        sample = randm(2, 1) - 0.5; // Random tu -0.5 den 0.5
        samples.push_back(sample);

        // Neu nam trong ban kinh 0.2 thi la lop +1, nguoc lai la -1
        if (length(sample) < 0.2)
            labels.push_back(+1);
        else
            labels.push_back(-1);
    }

    cout << "--- Bat dau Grid Search (Tim C va Gamma) ---" << endl;

    // 2. Dinh nghia khong gian tim kiem (Grid)
    std::vector<double> gamma_grid = {0.001, 0.01, 0.1, 1.0, 10.0};
    std::vector<double> C_grid = {1, 10, 100, 1000};

    // Bien luu ket qua tot nhat
    double best_accuracy = 0;
    double best_gamma = 0;
    double best_C = 0;

    // 3. Vong lap Grid Search
    // Dlib su dung Kernel Radial Basis Function (RBF)
    typedef radial_basis_kernel<matrix<double, 2, 1>> kernel_type;
    svm_c_trainer<kernel_type> trainer;

    for (double gamma : gamma_grid) {
        for (double C : C_grid) {
            
            // Cau hinh tham so cho Trainer
            trainer.set_kernel(kernel_type(gamma));
            trainer.set_c(C);

            // Thuc hien Cross Validation (Kiem thu cheo)
            // Chia du lieu lam 10 phan, train tren 9, test tren 1
            matrix<double, 1, 2> res = cross_validate_trainer(trainer, samples, labels, 10);
            
            // res(0) la Accuracy (do chinh xac)
            double current_accuracy = res(0);

            cout << "Thu Gamma=" << gamma << ", C=" << C 
                 << " -> Accuracy: " << current_accuracy << endl;

            // Cap nhat neu tim thay ket qua tot hon
            if (current_accuracy > best_accuracy) {
                best_accuracy = current_accuracy;
                best_gamma = gamma;
                best_C = C;
            }
        }
    }

    // 4. Ket qua
    cout << "\n========================================" << endl;
    cout << "KET QUA TOT NHAT:" << endl;
    cout << "Best Gamma    : " << best_gamma << endl;
    cout << "Best C        : " << best_C << endl;
    cout << "Best Accuracy : " << best_accuracy * 100 << "%" << endl;
    cout << "========================================" << endl;

    return 0;
}