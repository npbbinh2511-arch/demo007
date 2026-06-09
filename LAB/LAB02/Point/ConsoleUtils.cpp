#include "ConsoleUtils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void Display() noexcept {
    std::cout << "========================================================\n";
    std::cout << "     UNG DUNG NHAP DUONG THANG - PHIEN BAN CHUAN kIEN TRUC  \n";
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

void HandleInputError(Point& point) {
    std::cout << "\n[CANH BAO]: Du lieu nhap vao khong hop le!\n";
    ClearInputBuffer(); // Dọn dẹp bộ đệm rác ban đầu

    while (true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "MENU SUA DOI DU LIEU (CAP NHAT):\n";
        std::cout << "1. Nhap/Sua lai rieng toa do X\n";
        std::cout << "2. Nhap/Sua lai rieng toa do Y\n";
        std::cout << "3. Nhap/Sua lai DONG THOI ca toan do (X, Y)\n"; // Tùy chọn mới của em
        std::cout << "4. Thoat chuong trinh lap tuc (Exit)\n";
        std::cout << "Lua chon cua ban (1-4): ";
        
        int choice{0};
        if (!(std::cin >> choice)) {
            ClearInputBuffer();
            std::cout << "Lua chon khong hop le! Vui long chon lai.\n";
            continue;
        }

        if (choice == 1) {
            float tempX{0.0f};
            std::cout << "Nhap lai gia tri X: ";
            while (!(std::cin >> tempX)) {
                ClearInputBuffer();
                std::cout << "Gia tri X phai la so thuc! Nhap lai X: ";
            }
            point.setX(tempX);
            std::cout << "=> Da cap nhat X. Diem hien tai: " << point << "\n";
            break; 
        } 
        else if (choice == 2) {
            float tempY{0.0f};
            std::cout << "Nhap lai gia tri Y: ";
            while (!(std::cin >> tempY)) {
                ClearInputBuffer();
                std::cout << "Gia tri Y phai la so thuc! Nhap lai Y: ";
            }
            point.setY(tempY);
            std::cout << "=> Da cap nhat Y. Diem hien tai: " << point << "\n";
            break; 
        } 
        // XỬ LÝ LỰA CHỌN 3: ĐỒNG THỜI THAY ĐỔI CẢ X VÀ Y
        else if (choice == 3) {
            float tempX{0.0f}, tempY{0.0f};
            std::cout << "Nhap lai ca hai toa do X va Y (VD: 5.5 8.9): ";
            
            // Vòng lặp bắt lỗi cho đến khi người dùng nhập đúng cả 2 số thực
            while (!(std::cin >> tempX >> tempY)) {
                ClearInputBuffer();
                std::cout << "Loi! Ca hai gia tri phai la so thuc. Nhap lai (X Y): ";
            }
            
            // Sau khi có dữ liệu sạch, dùng các hàm setter để cập nhật đồng thời
            point.setX(tempX);
            point.setY(tempY);
            
            std::cout << "=> Tuyen voi! Da lam moi toan bo toa do diem: " << point << "\n";
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