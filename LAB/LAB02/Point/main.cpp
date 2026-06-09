#include "Point.h"
#include "ConsoleUtils.h" // Nhúng cả 2 tầng vào để điều phối
#include <iostream>

int main() {
    Display(); // Gọi từ ConsoleUtils

    bool keepRunning = true;
    while (keepRunning) {
        Point p{};
        std::cout << "Vui long nhap toa do X va Y: ";

        if (std::cin >> p) {
            std::cout << "=> Toa do diem hop le: " << p << "\n";
        } else {
            HandleInputError(p); // Gọi từ ConsoleUtils
            std::cout << "=> Sau khi sua doi, diem la: " << p << "\n";
        }

        std::cout << "\nBan co muon nhap lai diem moi khong? (Y/N): ";
        char answer;
        std::cin >> answer;
        if (answer != 'Y' && answer != 'y') {
            keepRunning = false;
        }
    }

    Bye(); // Gọi từ ConsoleUtils
    return 0;
}