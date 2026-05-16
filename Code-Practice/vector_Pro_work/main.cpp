#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 定义商品结构体
struct Product {
    int id;
    std::string name;
    int quantity;
};

// 打印商品信息
void printProduct(const Product& product) {
    std::cout << "ID: " << product.id
              << ", Name: " << product.name
              << ", Quantity: " << product.quantity << std::endl;
}

// 添加商品
void addProduct(std::vector<Product>& products) {
    Product p;
    std::cout << "Enter Product ID: ";
    std::cin >> p.id;
    std::cout << "Enter Product Name: ";
    std::cin.ignore(); // 忽略之前输入的换行符
    std::getline(std::cin, p.name);
    std::cout << "Enter Product Quantity: ";
    std::cin >> p.quantity;
    products.push_back(p);
    std::cout << "Product added successfully.\n";
}

// 删除商品
void deleteProduct(std::vector<Product>& products) {
    int id;
    std::cout << "Enter Product ID to delete: ";
    std::cin >> id;

    auto it = std::find_if(products.begin(), products.end(), [id](const Product& p) {
        return p.id == id;
    });

    if(it != products.end()) {
        products.erase(it);
        std::cout << "Product deleted successfully.\n";
    }
    else {
        std::cout << "Product with ID " << id << " not found.\n";
    }
}

// 更新商品数量
void updateProductQuantity(std::vector<Product>& products) {
    int id, newQty;
    std::cout << "Enter Product ID to update: ";
    std::cin >> id;

    auto it = std::find_if(products.begin(), products.end(), [id](const Product& p) {
        return p.id == id;
    });

    if(it != products.end()) {
        std::cout << "Enter new quantity: ";
        std::cin >> newQty;
        it->quantity = newQty;
        std::cout << "Product quantity updated successfully.\n";
    }
    else {
        std::cout << "Product with ID " << id << " not found.\n";
    }
}

// 显示所有商品
void displayProducts(const std::vector<Product>& products) {
    if(products.empty()) {
        std::cout << "No products available.\n";
        return;
    }
    std::cout << "Product List:\n";
    for(const auto& p : products) {
        printProduct(p);
    }
}

int main() {
    std::vector<Product> products;
    int choice;

    do {
        std::cout << "\n=== Inventory Management System ===\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Delete Product\n";
        std::cout << "3. Update Product Quantity\n";
        std::cout << "4. Display All Products\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                addProduct(products);
                break;
            case 2:
                deleteProduct(products);
                break;
            case 3:
                updateProductQuantity(products);
                break;
            case 4:
                displayProducts(products);
                break;
            case 5:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Please choose between 1-5.\n";
        }

    } while(choice != 5);

    return 0;
}