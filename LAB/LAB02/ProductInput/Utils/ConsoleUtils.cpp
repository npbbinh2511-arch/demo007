#include "ConsoleUtils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void Display() noexcept {
    std::cout << "========================================================\n";
    std::cout << "     UNG DUNG NHAP THONG TIN SAN PHAM - PRODUCTINPUT    \n";
    std::cout << "========================================================\n\n";
}

void Bye() noexcept {
    std::cout << "\n========================================================\n";
    std::cout << " THONG BAO: Chuong trinh ket thuc an toan. Tam biet!\n";
    std::cout << "========================================================\n";
}

void ClearInputBuffer() noexcept {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void HandleProductInputError(Product& product) {
    std::cout << "\n[CẢNH BÁO]: Thông tin sản phẩm hoặc hạn sử dụng không hợp lệ!\n";
    std::cout << "(Lưu ý: Giá không được âm và ngày tháng phải đúng thực tế lịch pháp)\n";

    ClearInputBuffer(); // Xóa sạch rác trong bộ đệm ngay đầu hàm

    // VÒNG LẶP KHÓA 1: Ép buộc khởi tạo lại dữ liệu gốc sạch toàn cục
    while (true) {
        std::cout << "\nXác thực làm mới thông tin sản phẩm (Y/N): ";
        std::string confirm;
        std::getline(std::cin, confirm);

        // Áp dụng sửa đổi thuật toán logic chuẩn xác (dùng && thay vì ||) như bài trước em đính chính
        if (confirm != "y" && confirm != "Y") {
            return; 
        }

        std::cout << "\n--- BẮT BUỘC LÀM MỚI TOÀN BỘ SẢN PHẨM ---\n";
        Product tempProduct;
        if (std::cin >> tempProduct) {
            product = tempProduct;
            std::cout << "=> Khởi tạo dữ liệu sản phẩm mới thành công.\n";
            break;
        } else {
            ClearInputBuffer();
            std::cout << "[Lỗi Logic]: Nhập sai kiểu dữ liệu hoặc vi phạm lịch thực tế. Nhập lại!\n";
        }
    }

    // VÒNG LẶP KHÓA 2: Menu 5 lựa chọn chỉnh sửa cục bộ an toàn
    while (true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "MENU SỬA ĐỔI THÔNG TIN SẢN PHẨM (CẬP NHẬT):\n";
        std::cout << "1. Sửa Mã sản phẩm (ID)\n";
        std::cout << "2. Sửa Tên sản phẩm\n";
        std::cout << "3. Sửa Giá bán\n";
        std::cout << "4. Sửa Hạn sử dụng (Expiry Date)\n";
        std::cout << "5. Thoát và lưu kết quả\n";
        std::cout << product; // Xuất trạng thái hiện tại của sản phẩm
        std::cout << "Lựa chọn của bạn (1-5): ";

        int choice{0};
        if (!(std::cin >> choice)) {
            ClearInputBuffer();
            std::cout << "Lựa chọn không hợp lệ! Vui lòng chọn từ 1 đến 5.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::string newId;
            while (true) {
                std::cout << "Nhập Mã sản phẩm mới: "; std::getline(std::cin, newId);
                if (!newId.empty()) { product.setId(newId); break; }
                std::cout << "[Lỗi]: Mã sản phẩm không được rỗng!\n";
            }
        }
        else if (choice == 2) {
            std::string newName;
            while (true) {
                std::cout << "Nhập Tên sản phẩm mới: "; std::getline(std::cin, newName);
                if (!newName.empty()) { product.setName(newName); break; }
                std::cout << "[Lỗi]: Tên sản phẩm không được rỗng!\n";
            }
        }
        else if (choice == 3) {
            float newPrice;
            while (true) {
                std::cout << "Nhập Giá bán mới: ";
                if (std::cin >> newPrice) {
                    if (newPrice >= 0.0f) { product.setPrice(newPrice); break; }
                    std::cout << "[Lỗi]: Giá bán không được âm!\n";
                } else {
                    ClearInputBuffer();
                    std::cout << "[Lỗi]: Định dạng giá bán phải là số thực!\n";
                }
            }
        }
        else if (choice == 4) {
            int d, m, y;
            while (true) {
                std::cout << "Nhập Hạn sử dụng mới (Ngày Tháng Năm): ";
                if (std::cin >> d >> m >> y) {
                    // Tối ưu hóa bộ nhớ: Sử dụng trực tiếp hàm tĩnh của Date để kiểm tra, 
                    // hoàn toàn không lạm dụng copy chuỗi dữ liệu của Product.
                    if (Date::isValidDate(d, m, y)) {
                        product.setExpiryDate(Date(d, m, y));
                        std::cout << "=> Đã cập nhật hạn sử dụng.\n";
                        break;
                    } else {
                        std::cout << "[Lỗi]: Ngày tháng không có thật trên lịch thực tế!\n";
                    }
                } else {
                    ClearInputBuffer();
                    std::cout << "[Lỗi]: Phải nhập vào 3 số nguyên lý thuyết lịch!\n";
                }
            }
        }
        else if (choice == 5) {
            std::cout << "\n=> Lưu dữ liệu sản phẩm thành công.\n";
            break;
        }
        else {
            std::cout << "Lựa chọn ngoài phạm vi (1-5)! Vui lòng chọn lại.\n";
        }
    }
}