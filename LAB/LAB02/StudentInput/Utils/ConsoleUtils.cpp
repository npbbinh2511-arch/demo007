#include "ConsoleUtils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void Display() noexcept {
    std::cout << "========================================================\n";
    std::cout << "     UNG DUNG NHAP THONG TIN SINH VIEN - STUDENTINPUT   \n";
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

void HandleStudentInputError(Student& student) {
    std::cout << "\n[CẢNH BÁO]: Thông tin sinh viên hoặc ngày sinh không hợp lệ!\n";
    std::cout << "(Lưu ý: Năm sinh không được vượt quá năm hiện tại: " << Student::getCurrentYear() << ")\n";

    // Ép buộc nhập lại toàn bộ thông tin hợp lệ ngay từ đầu để làm gốc
    while (true) {
        std::cout << "\n Xác thực làm mới thông tin (Y/N): \n";
        std::string str;
        ClearInputBuffer();
        std::getline(std::cin, str);
        if (str != "y" && str != "Y") {return;}
        std::cout << "\n--- BẮT BUỘC LÀM MỚI TOÀN BỘ THÔNG TIN ---\n";
        Student tempStudent;
        if (std::cin >> tempStudent) {
            student = tempStudent;
            std::cout << "=> Khởi tạo thông tin sinh viên thành công.\n";
            break;
        } else {
            ClearInputBuffer();
            std::cout << "[Lỗi]: Dữ liệu sai logic lịch pháp hoặc vượt quá năm hiện tại. Nhập lại!\n";
        }
    }

    // Menu quản lý chỉnh sửa từng thành phần sau khi đã có dữ liệu gốc sạch
    while (true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "MENU SUA DOI THONG TIN (CAP NHAT):\n";
        std::cout << "1. Sua MSSV\n";
        std::cout << "2. Sua Ho va ten\n";
        std::cout << "3. Sua Dia chi\n";
        std::cout << "4. Sua Email\n";
        std::cout << "5. Sua Ngay sinh (DOB)\n";
        std::cout << "6. Thoat va luu ket qua\n";
        std::cout << student; // In thong tin hien tai
        std::cout << "Lua chon cua ban (1-6): ";

        int choice{0};
        if (!(std::cin >> choice)) {
            ClearInputBuffer();
            std::cout << "Lua chon khong hop le! Vui long chon tu 1 den 6.\n";
            continue;
        }
        
        // Don sach ky tu '\n' sau khi nhap so choice de cac lenh getline ben duoi khong bi troi
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::string newId;
            while (true) {
                std::cout << "Nhap MSSV moi (Khong duoc de trong): ";
                std::getline(std::cin, newId);
                if (!newId.empty()) {
                    student.setId(newId);
                    break;
                }
                std::cout << "[Loi]: MSSV khong duoc de trong!\n";
            }
        }
        else if (choice == 2) {
            std::string newName;
            // Dùng vòng lặp khóa tại chỗ để xử lý khi nhập sai
            while (true) {
                std::cout << "Nhap Ho va ten moi (Khong duoc de trong): ";
                std::getline(std::cin, newName);
                if (!newName.empty()) {
                    student.setFullname(newName);
                    std::cout << "=> Da cap nhat Ho ten.\n";
                    break; // Nhập đúng thì bẻ gãy vòng lặp để quay lai menu chính
                }
                std::cout << "[Loi]: Ho ten bi trong! Vui long nhap lai.\n";
            }
        }
        else if (choice == 3) {
            std::string newAddr;
            while (true) {
                std::cout << "Nhap Dia chi moi (Khong duoc de trong): ";
                std::getline(std::cin, newAddr);
                if (!newAddr.empty()) {
                    student.setAddress(newAddr);
                    break;
                }
                std::cout << "[Loi]: Dia chi khong duoc de trong!\n";
            }
        }
        else if (choice == 4) {
            std::string newEmail;
            while (true) {
                std::cout << "Nhap Email moi (Khong duoc de trong): ";
                std::getline(std::cin, newEmail);
                if (!newEmail.empty()) {
                    student.setEmail(newEmail);
                    break;
                }
                std::cout << "[Loi]: Email khong duoc de trong!\n";
            }
        }
        else if (choice == 5) {
            int d, m, y;
            while (true) {
                std::cout << "Nhap Ngay sinh moi (Ngay Thang Nam, VD: 20 11 2005): ";
                if (std::cin >> d >> m >> y) {
                    Date tempDob(d, m, y);
                    
                    // TOI UU TAI NGUYEN: Goi truc tiep ham static kiem tra DOB,
                    // khong lam dung ham isValidStudent de tranh copy chuoi vo ich.
                    if (Student::isValidDOB(tempDob)) {
                        student.setDOB(tempDob);
                        std::cout << "=> Da cap nhat Ngay sinh.\n";
                        break;
                    } else {
                        std::cout << "[Loi]: Ngay sinh khong co thuc hoac vuot qua nam hien tai (" << Student::getCurrentYear() << ")!\n";
                    }
                } else {
                    ClearInputBuffer();
                    std::cout << "[Loi]: Dinh dang nhap vao phai la 3 so nguyen!\n";
                }
            }
        }
        else if (choice == 6) {
            std::cout << "\n=> Luu du lieu thanh cong.\n";
            break; // Thoat khoi menu cap nhat, quay ve luong main
        }
        else {
            std::cout << "Lua chon ngoai pham vi (1-6)! Vui long chon lai.\n";
        }
    }
}