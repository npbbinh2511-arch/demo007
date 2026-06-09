#include "Product.h"
#include "./Utils/ConsoleUtils.h"
#include <iostream>

int main() {
    Display();

    bool keepRunning = true;
    while (keepRunning) {
        Product p{};
        std::cout << "Vui lòng nhập thông tin sản phẩm mới:\n";

        // Sử dụng nạp chồng toán tử nhập >> để tiếp nhận thông tin từ bàn phím
        if (std::cin >> p) {
            std::cout << "=> Dữ liệu sản phẩm hoàn toàn hợp lệ: " << p << "\n";
        } else {
            // Chuyển quyền điều khiển sang bộ xử lý lỗi nếu dữ liệu đầu vào bị hỏng
            HandleProductInputError(p);
            std::cout << "=> Trạng thái sản phẩm sau khi hiệu chỉnh là: " << p << "\n";
        }

        std::cout << "\nBạn có muốn nhập tiếp sản phẩm khác không? (Y/N): ";
        char answer;
        std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Làm sạch luồng
        
        if (answer != 'Y' && answer != 'y') {
            keepRunning = false;
        }
    }

    Bye();
    return 0;
}