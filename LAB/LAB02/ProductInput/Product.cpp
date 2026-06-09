#include "Product.h"
#include <limits>

std::istream& operator>>(std::istream& in, Product& product) {
    std::string id, name;
    float price;
    Date expiry;

    std::cout << "Mã sản phẩm: "; std::getline(in, id);
    std::cout << "Tên sản phẩm: "; std::getline(in, name);
    std::cout << "Giá bán (float): "; 
    if (!(in >> price)) return in; // Nếu nhập sai kiểu số thực, trả về luồng lỗi lập tức
    
    std::cout << "Hạn sử dụng (Ngày Tháng Nam, VD: 31 12 2026): ";
    if (in >> expiry) {
        // Dọn sạch ký tự xuống dòng thừa kẹt lại trong bộ đệm luồng
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Xác thực điều kiện tiên quyết toàn cục của Sản phẩm
        if (Product::isValidProduct(id, name, price, expiry)) {
            product.m_id = id;
            product.m_name = name;
            product.m_price = price;
            product.m_expiryDate = expiry;
        } else {
            in.setstate(std::ios::failbit); // Ép luồng vào trạng thái lỗi logic
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Product& product) {
    out << "\n===== THÔNG TIN SẢN PHẨM =====\n"
        << " Mã sản phẩm: " << product.m_id << "\n"
        << " Tên sản phẩm: " << product.m_name << "\n"
        << " Giá tiền   : " << product.m_price << " VND\n"
        << " Hạn dùng   : " << product.m_expiryDate << "\n"
        << "==============================\n";
    return out;
}