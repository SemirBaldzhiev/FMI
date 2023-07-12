#include <iostream>
#include <cstring>

class Product {
    public:
        Product() : price(0.0), quantity(0) {
            setName("Default product");
        }

        Product(const char* name, double price, double quantity) 
        : price(price), quantity(quantity) {
            setName(name);
        }

        Product(const Product& other) {
            copy(other);
        }
        Product& operator=(const Product& other) {
            if (this != &other) {
                clear();
                copy(other);
            }

            return *this;
        }
        ~Product() {
            clear();
        }


        const char* getName() const {
            return name;
        }
        void setName(const char* name) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }

        double getQuantity() const {
            return quantity;
        }

        void setQuantity(double quantity) {
            this->quantity = quantity;
        } 

        double getPricePerProduct() const {
            return price;
        }

        void setPrice(double price) {
            this->price = price;
        }

        double calcPrice() const {
            return price * quantity;
        }

        void productInfo() const {
            std::cout << "Product name: " << name << " Price br: " << price << " Quantity: " << quantity << "\n";
        }  
    private:
        char* name;
        double price;
        double quantity;

        void clear() {
            delete[] name;
        }

        void copy(const Product& other) {
            setName(other.name);
            setPrice(other.price);
            setQuantity(other.quantity);
        }
};


class ShoppingCart {
    public:
        ShoppingCart() : capacity(8), countProducts(0) {
            products = new Product[capacity];
        }
        ShoppingCart(const ShoppingCart& other) {
            copy(other);
        }
        ShoppingCart& operator=(const ShoppingCart& other) {
            if (this != &other) {
                clear();
                copy(other);
            }

            return *this;
        }
        ~ShoppingCart() {
            clear();
        }


        void addProduct(const Product& prod) {

            for (int i = 0; i < countProducts; i++) {
                if (strcmp(prod.getName(), products[i].getName()) == 0) {
                    return;
                }
            }

            if (countProducts == capacity) {
                resize();
            }

            products[countProducts] = prod;
            countProducts++;
        }
        void removeProduct(const char* name) {
            int prodIndex = -1;
            for (int i = 0; i < countProducts; i++) {
                if (strcmp(products[i].getName(), name) == 0) {
                    prodIndex = i;
                }
            }

            if (prodIndex > -1) {
                for (int i = prodIndex; i < countProducts - 1; i++) {
                    products[i] = products[i + 1];
                }
            }

            countProducts--;
        }
        double allProductsPrice() const {

            double sumProductsPrice = 0;
            for (int i = 0; i < countProducts; i++) {
                sumProductsPrice += products[i].calcPrice();
            }

            return sumProductsPrice;
        }
        void shoppingCartInfo() const {

            std::cout << "Shopping cart products: \n";
            for (int i = 0; i < countProducts; i++) {
                products[i].productInfo();
            }
        }

    private:
        Product* products;
        unsigned capacity;
        unsigned countProducts;

        void resize() {
            capacity*=2;
            Product *newProducts = new Product[capacity];

            for (int i = 0; i < countProducts; i++) {
                newProducts[i] = products[i];
            }

            delete[] products;
            products = newProducts;
        }

        void clear() {
            delete[] products;
        }

        void copy(const ShoppingCart& other) {
            capacity = other.capacity;
            countProducts  = other.countProducts;

            for (int i = 0; i < countProducts; i++) {
                products[i] = other.products[i];
            }
        }
};

int main() {
    
    ShoppingCart myCart;

    myCart.addProduct({"voda", 1.40, 1});
    myCart.addProduct({"sirene", 4.60, 1.2});
    myCart.addProduct({"hlqb", 2.40, 1});
    myCart.addProduct({"sol", 1.10, 2});
    myCart.addProduct({"krastavici", 4.50, 1});
    myCart.addProduct({"zahar", 1.0, 1});
    myCart.addProduct({"domati", 3.50, 1.5});
    myCart.addProduct({"domati", 3.50, 1.5});

    myCart.removeProduct("krastavici");
    
    std::cout << "Price Cart: " << myCart.allProductsPrice() << "\n";

    myCart.shoppingCartInfo();

    return 0;
}