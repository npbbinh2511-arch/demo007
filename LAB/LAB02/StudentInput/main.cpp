#include "Student.h"
#include "./Utils/ConsoleUtils.h"
#include <iostream>

int main() {
    Display();

    bool keepRunning = true;
    while (keepRunning) {
        Student s{};
        std::cout << "Vui lòng nhập thông tin sinh viên:\n";

        if (std::cin >> s) {
            std::cout << "=> Dữ liệu sinh viên hợp lệ: " << s << "\n";
        } else {
            HandleStudentInputError(s);
            std::cout << "=> Sau khi hiệu chỉnh, thông tin sinh viên là: " << s << "\n";
        }

        std::cout << "\nBạn có muốn nhập sinh viên mới không? (Y/N): ";
        char answer;
        std::cin >> answer;
        std::string dummy; std::getline(std::cin, dummy); // Dọn dẹp dòng
        if (answer != 'Y' && answer != 'y') {
            keepRunning = false;
        }
    }

    Bye();
    return 0;
}