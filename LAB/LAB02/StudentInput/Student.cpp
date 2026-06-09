#include "Student.h"
#include <iomanip>

std::istream& operator>>(std::istream& in, Student& student) {
    std::string id, name, addr, email;
    Date dob;

    std::cout << "Mã số sinh viên" << ": "; std::getline(in, id);
    std::cout << "Họ và tên" << ": "; std::getline(in, name);
    std::cout << "Địa chỉ" << ": "; std::getline(in, addr);
    std::cout << "Email" << ": "; std::getline(in, email);
    std::cout << "Ngày sinh (nhập dạng Ngày Tháng Năm, ví dụ: 15 3 2004): ";
    
    if (in >> dob) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (Student::isValidStudent(id, name, dob)) {
            student.m_id = id;
            student.m_fullname = name;
            student.m_address = addr;
            student.m_email = email;
            student.m_dob = dob;
        } else {
            in.setstate(std::ios::failbit);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
    // std::left: căn lề trái
    // std::setw(15): dành riêng một khoảng trống rộng 15 ký tự cho nhãn tiêu đề
    out << "\n" << std::setfill('.') << std::setw(60) << "." << "\n" // Vẽ đường kẻ ô vuông tách biệt
        << "--> THÔNG TIN SINH VIÊN <--\n"
        << std::left << std::setfill(' ') // Đặt lại ký tự lấp đầy là khoảng trắng
        << std::setw(20) << "  + MSSV"     << ": " << student.m_id << "\n"
        << std::setw(20) << "  + Họ tên"   << ": " << student.m_fullname << "\n"
        << std::setw(20) << "  + Địa chỉ"  << ": " << student.m_address << "\n"
        << std::setw(20) << "  + Email"    << ": " << student.m_email << "\n"
        << std::setw(20) << "  + Ngày sinh" << ": " << student.m_dob << "\n"
        << std::setfill('.') << std::setw(60) << "." << "\n";
    return out;
}