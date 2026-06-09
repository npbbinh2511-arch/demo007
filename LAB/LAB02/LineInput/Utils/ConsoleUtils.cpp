#include "ConsoleUtils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void Display() noexcept {
    std::cout << "========================================================\n";
    std::cout << "     UNG DUNG NHAP DIEM 2D - PHIEN BAN CHUAN kIEN TRUC  \n";
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

void HandleInputError(Line& line) {
    std::cout << "\n[CANH BAO]: Du lieu nhap vao khong hop le!\n";
    ClearInputBuffer(); // Dọn dẹp bộ đệm rác ban đầu

    while (true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "MENU SUA DOI DU LIEU (CAP NHAT):\n";
        std::cout << "1. Nhap/Sua lai rieng diem Start\n";
        std::cout << "2. Nhap/Sua lai rieng diem End\n";
        std::cout << "3. Nhap/Sua lai DONG THOI ca hai diem\n"; // Tùy chọn mới của em
        std::cout << "4. Thoat chuong trinh lap tuc (Exit)\n";
        std::cout << "Lua chon cua ban (1-4): ";
        
        int choice{0};
        if (!(std::cin >> choice)) {
            ClearInputBuffer();
            std::cout << "Lua chon khong hop le! Vui long chon lai.\n";
            continue;
        }

        if (choice == 1) {
            Point tempStart{0, 0};
            std::cout << "Nhap lai gia tri Start: ";
            while (!(std::cin >> tempStart)) {
                ClearInputBuffer();
                std::cout << "Gia tri Start phai la hai so thuc! Nhap lai Start: ";
            }
            line.setStartPoint(tempStart);
            std::cout << "=> Da cap nhat X. Diem hien tai: " << line << "\n";
            break; 
        } 
        else if (choice == 2) {
            Point tempEnd{0, 0};
            std::cout << "Nhap lai gia tri End: ";
            while (!(std::cin >> tempEnd)) {
                ClearInputBuffer();
                std::cout << "Gia tri End phai la hai so thuc! Nhap lai End: ";
            }
            line.setEndPoint(tempEnd);
            std::cout << "=> Da cap nhat Y. Diem hien tai: " << line << "\n";
            break; 
        } 
        // XỬ LÝ LỰA CHỌN 3: ĐỒNG THỜI THAY ĐỔI CẢ X VÀ Y
        else if (choice == 3) {
            Point tempX{0, 0};
            Point tempY{0, 0};
            std::cout << "Nhap lai ca hai diem Start va End (VD: 3.0 6.0 6.0 7.0): ";
            
            // Vòng lặp bắt lỗi cho đến khi người dùng nhập đúng cả 2 số thực
            while (!(std::cin >> tempX >> tempY)) {
                ClearInputBuffer();
                std::cout << "Loi! Ca hai gia tri phai la doi so thuc. Nhap lai: ";
            }
            
            // Sau khi có dữ liệu sạch, dùng các hàm setter để cập nhật đồng thời
            line.setStartPoint(tempX);
            line.setEndPoint(tempY);
            
            std::cout << "=> Tuyen voi! Da lam moi toan bo toa do diem: " << line << "\n";
            break; 
        }
        else if (choice == 4) {
            std::cout << "\nNguoi dung chu dong yeu cau thoat he thong.\n";
            Bye();
            std::exit(0);
        } 
        else {
            std::cout << "Lua chon ngoai pham vi! Vui long nhap tu 1 den 4.\n";
        }
    }
}