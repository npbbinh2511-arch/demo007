#include "ConsoleUtils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void Display() noexcept {
    std::cout << "========================================================\n";
    std::cout << "     UNG DUNG NHAP NGAY THANG - DATEINPUT SYSTEM        \n";
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

void HandleInputError(Date& date) {
    std::cout << "\n[CANH BAO]: Du lieu ngay nhap vao khong hop le!\n";
    ClearInputBuffer(); // Dọn dẹp bộ đệm rác ban đầu

    // KIỂM TRA ĐIỀU KIỆN TIÊN QUYẾT TOÀN CỤC
    // Nếu ngay từ đầu đối tượng chứa dữ liệu rác/sai lịch, không cho sửa từng phần!
    if (!Date::isValidDate(date.getDay(), date.getMonth(), date.getYear())) {
        std::cout << "[TAP TRUNG]: Doi tuong hien tai chua co du lieu lich phap hop le.\n";
        std::cout << "Ban bat buoc phai lam moi dong thoi ca Ngay, Thang, Nam truoc!\n";
        
        int tempDay{1}, tempMonth{0}, tempYear{0};
        while (true) {
            std::cout << "Nhap lai ca 3 gia tri (VD: 25 12 2026) hoac nhap 0 de thoat: ";
            if (std::cin >> tempDay) {
                if (tempDay == 0) { Bye(); std::exit(0); } // Lối thoát an toàn
                if (std::cin >> tempMonth >> tempYear) {
                    if (Date::isValidDate(tempDay, tempMonth, tempYear)) {
                        date.setDay(tempDay);
                        date.setMonth(tempMonth);
                        date.setYear(tempYear);
                        std::cout << "=> Khoi tao du lieu thanh cong: " << date << "\n";
                        break; // Thoát vòng lặp khóa để tiến vào menu chính
                    }
                }
            }
            ClearInputBuffer();
            std::cout << "[Loi]: Ngay thang khong ton tai. Vui long nhap lai.\n";
        }
    }

    // VÒNG LẶP MENU CHÍNH (Chỉ chạy khi đối tượng chắc chắn đã có 1 ngày hợp lệ làm gốc)
    while (true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "MENU SUA DOI DU LIEU NGAY (QUY CHUAN AN TOAN):\n";
        std::cout << "1. Nhap/Sua lai rieng NGAY (Day)\n";
        std::cout << "2. Nhap/Sua lai rieng THANG (Month)\n";
        std::cout << "3. Nhap/Sua lai rieng NAM (Year)\n";
        std::cout << "4. Nhap/Sua lai DONG THOI ca (Day, Month, Year)\n";
        std::cout << "5. Thoat chuong trinh\n";
        std::cout << "Gia tri hien tai: " << date << "\n";
        std::cout << "Lua chon cua ban (1-5): ";
        
        int choice{0};
        if (!(std::cin >> choice)) {
            ClearInputBuffer();
            std::cout << "Lua chon khong hop le!\n";
            continue;
        }

        if (choice == 1) {
            int tempDay{1};
            while (true) {
                std::cout << "Nhap Ngay moi (hoac 0 de quay lai): ";
                if (!(std::cin >> tempDay)) { ClearInputBuffer(); continue; }
                if (tempDay == 0) break;
                
                // Thử nghiệm xem Ngày mới có hợp lỳ với Tháng và Năm hiện tại không
                if (Date::isValidDate(tempDay, date.getMonth(), date.getYear())) {
                    date.setDay(tempDay);
                    break;
                } else {
                    std::cout << "[Loi]: Ngay " << tempDay << " khong hop le voi Thang " << date.getMonth() << "/" << date.getYear() << "\n";
                }
            }
        } 
        else if (choice == 2) {
            int tempMonth{1};
            while (true) {
                std::cout << "Nhap Thang moi (hoac 0 de quay lai): ";
                if (!(std::cin >> tempMonth)) { ClearInputBuffer(); continue; }
                if (tempMonth == 0) break;
                
                // Thử nghiệm xem Tháng mới có hợp lý với Ngày và Năm hiện tại không
                if (Date::isValidDate(date.getDay(), tempMonth, date.getYear())) {
                    date.setMonth(tempMonth);
                    break;
                } else {
                    std::cout << "[Loi]: Thang " << tempMonth << " khong tuong thich voi Ngay " << date.getDay() << " hien tai.\n";
                }
            }
        } 
        else if (choice == 3) {
            int tempYear{2000};
            while (true) {
                std::cout << "Nhap Nam mới (hoac 0 de quay lai): ";
                if (!(std::cin >> tempYear)) { ClearInputBuffer(); continue; }
                if (tempYear == 0) break;
                
                // Thử nghiệm kiểm tra năm nhuận 
                if (Date::isValidDate(date.getDay(), date.getMonth(), tempYear)) {
                    date.setYear(tempYear);
                    break;
                } else {
                    std::cout << "[Loi]: Nam " << tempYear << " khong phai nam nhuan de co ngay " << date.getDay() << "/" << date.getMonth() << "\n";
                }
            }
        }
        else if (choice == 4) {
            int tempDay{1}, tempMonth{0}, tempYear{0};
            while (true) {
                std::cout << "Nhap lai ca 3 gia tri (VD: 25 12 2026): ";
                if (std::cin >> tempDay >> tempMonth >> tempYear) {
                    if (Date::isValidDate(tempDay, tempMonth, tempYear)) {
                        date.setDay(tempDay); date.setMonth(tempMonth); date.setYear(tempYear);
                        break;
                    }
                }
                ClearInputBuffer();
                std::cout << "[Loi]: Ngay thang khong hop le thực te!\n";
            }
        }
        else if (choice == 5) {
            Bye();
            std::exit(0);
        }
        else {
            std::cout << "Lua chon ngoai pham vi! Vui long nhap tu 1 den 5.\n";
        }
    }
}