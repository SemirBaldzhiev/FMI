#include <iostream>
#include <cstring>

const int PRODUCTS_COUNT = 4;


struct Product {
    char productName[16];
    char manufacturer[32];
    bool isFruit;
    size_t quantity;
    double price;
};

struct Store {
    char storeName[32];
    size_t currentProductsCount;
    const int maxCapacity = 50;
    Product products[4];
};

void printProduct(const Product& product) {
    std::cout << "Name: " << product.productName << std::endl;
    std::cout << "Manufacturer: " << product.manufacturer << std::endl;
    std::cout << "Type: " << (product.isFruit ? "Fruit" : "Vegetable") << std::endl;
    std::cout << "Quantity: " << product.quantity << std::endl;
    std::cout << "Price: " << product.price << std::endl;
}


void printStore(const Store& store) {
    std::cout << "Store name: " << store.storeName << std::endl;
    //std::cout << "Quantity: " << store.currentQuantity << std::endl;
    std::cout << "Products: " << std::endl;

    for (int i = 0; i < store.currentProductsCount; i++) {
        printProduct(store.products[i]);
    }

}

void AddProductToStore(Store& store, const Product& product) {
    if (store.currentProductsCount < store.maxCapacity) {
        store.products[store.currentProductsCount] = product;
        store.currentProductsCount++;
    }
}

void sellProduct(Store& store, const char name[], const size_t quantity) {
    for (int i = 0; i < store.currentProductsCount; i++) {
        if (strcmp(store.products[i].productName, name) == 0 && store.products[i].quantity >= quantity) {
            store.products[i].quantity -= quantity;
        }
    }
}

int main()
{
    return 0;
}