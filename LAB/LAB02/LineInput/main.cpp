#include "../Point/Point.h"
#include "./Utils/ConsoleUtils.h"
#include "Line.h" // Nhúng cả 2 tầng vào để điều phối
#include <iostream>

int main() {
    Display(); // Gọi từ ConsoleUtils

    bool keepRunning = true;
    while (keepRunning) {
        Line l{};
        std::cout << "Vui long nhap hai diem Start va End: ";

        if (std::cin >> l) {
            std::cout << "=> Toa do duong thang hop le: " << l << "\n";
        } else {
            HandleInputError(l); // Gọi từ ConsoleUtils
            std::cout << "=> Sau khi sua doi, duong thang la: " << l << "\n";
        }

        std::cout << "\nBan co muon nhap lai duong thang moi khong? (Y/N): ";
        char answer;
        std::cin >> answer;
        if (answer != 'Y' && answer != 'y') {
            keepRunning = false;
        }
    }

    Bye(); // Gọi từ ConsoleUtils
    return 0;
}