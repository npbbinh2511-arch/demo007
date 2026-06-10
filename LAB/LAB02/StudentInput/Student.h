#ifndef STUDENT_H
#define STUDENT_H

#include "../DateInput/Date.h"
#include <string>
#include <iostream>
#include <chrono>

// Chọn class để đóng gói dữ liệu và bảo vệ các điều kiện logic của Sinh viên
class Student {
private:
    std::string m_id;
    std::string m_fullname;
    std::string m_address;
    std::string m_email;
    Date m_dob; // Thuộc tính kiểu lớp Date

public:
    // Hàm tĩnh lấy năm hiện tại từ hệ thống bằng std::chrono (C++20)
    static int getCurrentYear() noexcept {
        auto now = std::chrono::system_clock::now();
        auto dp = std::chrono::floor<std::chrono::days>(now);
        std::chrono::year_month_day ymd{dp};
        return static_cast<int>(ymd.year());
    }

    static bool isValidEmailFormat(const std::string& email) noexcept {
        if (email.empty()) return true; // Chấp nhận để trống theo yêu cầu

        size_t atPos = email.find('@');
        if (atPos == std::string::npos || atPos == 0 || atPos == email.length() - 1) {
            return false; 
        }

        size_t dotPos = email.find('.', atPos + 1);
        if (dotPos == std::string::npos || dotPos == atPos + 1 || dotPos == email.length() - 1) {
            return false; 
        }

        return true;
    }

    // Kiểm tra điều kiện tiên quyết (Preconditions) của Sinh viên
    static bool isValidDOB(const Date& dob) noexcept {
        // Tối ưu tài nguyên: Chỉ kiểm tra logic lịch và năm hiện tại, tuyệt đối không copy chuỗi
        if (!Date::isValidDate(dob.getDay(), dob.getMonth(), dob.getYear())) return false;
        if (dob.getYear() > getCurrentYear() - 5) return false;
        return true;
    }

    static bool isValidStudent(const std::string& id, const std::string& name, const std::string& email, const Date& dob) noexcept {
        if (id.empty() || name.empty()) return false;
        // Ngày sinh phải là ngày hợp lệ trên lịch và năm sinh không vượt quá năm hiện tại
        if (!isValidEmailFormat(email)) return false;
        if (!isValidDOB(dob)) return false;
        return true;
    }

    Student() : m_id{"SV000"}, m_fullname{"Unknown"}, m_address{"Unknown"}, m_email{"Unknown"}, m_dob{} {}

    // Getters & Setters
    std::string getId() const noexcept { return m_id; }
    std::string getFullname() const noexcept { return m_fullname; }
    std::string getAddress() const noexcept{ return m_address; }
    std::string getEmail() const noexcept { return m_email; }
    Date getDOB() const noexcept { return m_dob; }

    void setId(const std::string& id) { m_id = id; }
    void setFullname(const std::string& name) { m_fullname = name; }
    void setAddress(const std::string& addr) { m_address = addr; }
    void setEmail(const std::string& email) { m_email = email; }
    void setDOB(const Date& dob) noexcept { m_dob = dob; }

    friend std::istream& operator>>(std::istream& in, Student& student);
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

#endif // STUDENT_H