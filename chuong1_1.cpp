#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#include "csv.h" // Yêu cầu thư viện fast-cpp-csv-parser

// Định nghĩa kiểu dữ liệu cho một hàng (4 số thực và 1 chuỗi nhãn)
using RowType = std::tuple<double, double, double, double, std::string>;

// Hàm hỗ trợ đọc một hàng từ file CSV vào tuple
template <std::size_t... Is, typename T, typename R>
bool read_row_helper(std::index_sequence<Is...>, T& row, R& row_reader) {
    return row_reader.read_row(std::get<Is>(row)...);
}

// Hàm hỗ trợ chuyển dữ liệu từ tuple sang vector
template <std::size_t... Idx, typename T>
void fill_values(std::index_sequence<Idx...>, T& row, std::vector<double>& data) {
    data.insert(data.end(), {std::get<Idx>(row)...});
}

int main() {
    const std::string file_path = "iris.data";
    const int32_t columns_num = 5; // Số cột trong file CSV

    try {
        io::CSVReader<columns_num> csv_reader(file_path);
        
        std::vector<std::string> categorical_column;
        std::vector<double> values;
        RowType row;
        
        bool done = false;
        while (!done) {
            // Đọc hàng tiếp theo
            done = !read_row_helper(
                std::make_index_sequence<std::tuple_size<RowType>::value>{}, 
                row, csv_reader
            );

            if (!done) {
                // Lấy nhãn (cột cuối cùng - index 4)
                categorical_column.push_back(std::get<4>(row));
                
                // Lấy các giá trị số (4 cột đầu)
                fill_values(
                    std::make_index_sequence<columns_num - 1>{}, 
                    row, values
                );
            }
        }
        
        std::cout << "Da doc xong du lieu." << std::endl;
        
    } catch (const io::error::no_digit& err) {
        std::cerr << "Loi dinh dang so: " << err.what() << std::endl;
    } catch (const std::exception& err) {
        std::cerr << "Loi: " << err.what() << std::endl;
    }

    return 0;
}