#include <dlib/svm.h>
#include <iostream>
#include <vector>

using namespace dlib;

// Định nghĩa kiểu dữ liệu mẫu (ví dụ: vector cột)
using SampleType = matrix<double, 0, 1>; 
using KernelType = polynomial_kernel<SampleType>;

int main() {
    // Giả lập dữ liệu
    std::vector<SampleType> samples;
    std::vector<double> raw_labels;

    // ... (Code tải dữ liệu vào samples và raw_labels) ...

    // Giả sử kết quả tìm kiếm tham số tối ưu trả về vector 'result'
    // result.x(0) = gamma, result.x(1) = C, result.x(2) = degree
    double gamma = 0.1;  // Ví dụ giá trị tìm được
    double c = 1.0;
    double degree = 2.0;

    // 1. Khởi tạo Trainer cho SVR
    svr_trainer<KernelType> trainer;

    // 2. Cài đặt Kernel với các siêu tham số đã tìm được
    trainer.set_kernel(KernelType(gamma, c, degree));

    // 3. Huấn luyện mô hình
    // Kết quả trả về là một "decision function" (hàm quyết định)
    decision_function<KernelType> decision_func = trainer.train(samples, raw_labels);

    std::cout << "Da huan luyen xong mo hinh SVR!" << std::endl;

    // Thử dự đoán một mẫu
    if (!samples.empty()) {
        double prediction = decision_func(samples[0]);
        std::cout << "Du doan mau dau tien: " << prediction << std::endl;
    }

    return 0;
}