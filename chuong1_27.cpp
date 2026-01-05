//code ví dụ tìm kiếm lưới Ví dụ Optuna với Flashlight: fasle
#include <iostream>
#include <flashlight/flashlight.h>

// Thu vien de doc tham so dong lenh (giong nhu argparse trong Python)
// O day dung argc, argv don gian
using namespace std;
namespace fl = flashlight;

int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "Usage: ./app <learning_rate> <momentum>" << endl;
        return 1;
    }

    // 1. Nhan tham so tu Optuna (thong qua dong lenh)
    double learning_rate = stod(argv[1]);
    double momentum = stod(argv[2]);

    // 2. Xay dung mo hinh Flashlight
    auto model = fl::Sequential();
    model.add(fl::Linear(10, 20));
    model.add(fl::ReLU());
    model.add(fl::Linear(20, 1));

    // 3. Gia lap qua trinh Train (Vi chung ta khong co data that o day)
    // Trong thuc te: Ban se train model va tinh Loss/Accuracy tren tap Validation
    
    // Gia su ham loss phu thuoc vao LR theo hinh Parabol (tim cuc tieu)
    // Muc tieu: tim LR sao cho gan 0.01 nhat
    double simulated_loss = (learning_rate - 0.01) * (learning_rate - 0.01) + 
                            (momentum - 0.9) * (momentum - 0.9);

    // 4. In ket qua ra man hinh (De Python doc duoc)
    cout << simulated_loss << endl;

    return 0;
}