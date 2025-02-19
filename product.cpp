#include <iostream>
using namespace std;

class Validator {
    public:
        virtual bool IsValid(const class Product& product) const = 0;
    };
    
class Product {
        public:
            int price;
            Product(int price) : price(price) {}
    
        bool IsValid(const Validator& validator) const {
            return validator.IsValid(price);
        }
};  
    // Обычный валидатор - считает валидным любой продукт > 0 
class BasedValidator : public Validator {
    public:
        bool IsValid(const Product& product) const override { 
            return product.price > 0;
        }
    };
    
    // Валидатор "заказчика" - считает валидным любой продукт > 100000
class CustomerValidator : public Validator {
    public:
        bool IsValid(const Product& product) const override { 
            return product.price > 100000;
        }
    };

int main() {
        // 1
        BasedValidator bv;
        CustomerValidator cs;
    
        Product product1(50000);
        Product product2(50000);
    
        cout << "Результат проверки Product1: " << product1.IsValid(bv) << endl;
        cout << "Результат проверки Product2 (продукт для заказчика): " << product2.IsValid(cs) << endl;
        cout << "-----------------------\n";
        return 0;
}