//code ví dụ tìm kiếm lưới Ví dụ về mlpack: fasle
#include <iostream>
#include <mlpack/core.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>
#include <mlpack/core/hpt/grid_search.hpp> // Thu vien Grid Search

using namespace mlpack;
using namespace mlpack::neighbor;
using namespace mlpack::hpt;
using namespace std;

int main() {
    // 1. Tao du lieu gia lap (100 mau, 5 dac trung)
    arma::mat data(5, 100, arma::fill::randu);
    arma::Row<size_t> labels(100, arma::fill::randu);
    
    // Gan nhan (0 hoac 1)
    labels = arma::conv_to<arma::Row<size_t>>::from(labels > 0.5);

    // 2. Dinh nghia cac gia tri k muon thu: {1, 3, 5, 7}
    std::vector<int> k_values = {1, 3, 5, 7};

    // 3. Thuc hien Grid Search (Thu cong)
    // Ly do: mlpack::GridSearch tu dong rat phuc tap ve template, 
    // day la cach vong lap don gian de hieu ban chat.
    
    int best_k = 0;
    double best_accuracy = 0.0;

    cout << "--- Bat dau Grid Search ---" << endl;

    for (int k : k_values) {
        // Huan luyen mo hinh KNN voi k hien tai
        // (Day chi la code minh hoa logic, KNN trong mlpack thuong khong can train phuc tap)
        NeighborSearch<NearestNeighborSort, metric::EuclideanDistance> knn(data);
        
        // Gia su ta co ham tinh do chinh xac (dummy function)
        // Trong thuc te ban se dung Cross-Validation o day
        double accuracy = 0.5 + (double)k / 20.0; // Gia lap ket qua
        
        cout << "Thu k = " << k << " -> Do chinh xac: " << accuracy << endl;

        if (accuracy > best_accuracy) {
            best_accuracy = accuracy;
            best_k = k;
        }
    }

    cout << "--- Ket qua ---" << endl;
    cout << "Tham so tot nhat: k = " << best_k << endl;

    return 0;
}