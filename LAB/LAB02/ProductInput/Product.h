#ifndef PRODUCT_H
#define PRODUCT_H

#include "../DateInput/Date.h"
#include <string>
#include <iostream>

// Chọn class để thực hiện cơ chế đóng gói (Encapsulation), bảo vệ các điều kiện logic 
// tiên quyết của Sản phẩm (ví dụ: Giá tiền không được âm, các chuỗi thông tin không rỗng).
class Product {
private:
    std::string m_id;
    std::string m_name;
    float m_price;
    Date m_expiryDate; // Thuộc tính kiểu lớp Date tự định nghĩa

public:
    // Kiểm tra điều kiện tiên quyết (Preconditions) của Sản phẩm
    static bool isValidProduct(const std::string& id, const std::string& name, float price, const Date& expiry) noexcept {
        if (id.empty() || name.empty()) return false;
        if (price < 0.0f) return false; // Luật kinh doanh: Giá sản phẩm không thể âm
        // Kiểm tra tính hợp lệ của ngày tháng trên lịch thực tế
        if (!Date::isValidDate(expiry.getDay(), expiry.getMonth(), expiry.getYear())) return false;
        return true;
    }

    // Constructor mặc định đặt các giá trị an toàn ban đầu
    Product() : m_id{"PROD000"}, m_name{"Unknown"}, m_price{0.0f}, m_expiryDate{} {}

    // Getters & Setters tuân thủ C++ Core Guidelines
    std::string getId() const { return m_id; }
    std::string getName() const { return m_name; }
    float getPrice() const noexcept { return m_price; }
    Date getExpiryDate() const noexcept { return m_expiryDate; }

    void setId(const std::string& id) { m_id = id; }
    void setName(const std::string& name) { m_name = name; }
    void setPrice(float price) noexcept { m_price = price; }
    void setExpiryDate(const Date& expiry) noexcept { m_expiryDate = expiry; }

    friend std::istream& operator>>(std::istream& in, Product& product);
    friend std::ostream& operator<<(std::ostream& out, const Product& product);
};

#endif // PRODUCT_H