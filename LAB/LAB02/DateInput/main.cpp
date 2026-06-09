#include "Date.h"
#include "./Utils/ConsoleUtils.h"
#include <iostream>

int main() {
    Display(); 

    bool keepRunning = true;
    while (keepRunning) {
        Date d{};
        std::cout << "Vui long nhap Ngay, Thang va Nam (cach nhau bang dau cach): ";

        if (std::cin >> d) {
            std::cout << "=> Ngay thang hop le: " << d << "\n";
        } else {
            HandleInputError(d); 
            std::cout << "=> Sau khi sua doi, thong tin la: " << d << "\n";
        }

        std::cout << "\nBan co muon tiep tuc nhap ngay moi khong? (Y/N): ";
        char answer;
        std::cin >> answer;
        if (answer != 'Y' && answer != 'y') {
            keepRunning = false;
        }
    }

    Bye(); 
    return 0;
}