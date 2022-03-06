#include <iostream>
#include <cstring>

const unsigned int MAX_CAPACITY = 16;

struct Product {
    char productName[16];
    char manufacturer[32];
    bool isFruit;
    unsigned int quantity;
    double price;

    void init() {
        std::cout << "Enter product name: ";
        std::cin >> productName;

        std::cout << "Enter manufacturer: ";
        std::cin >> manufacturer;

        std::cout << "Enter product type (fruit - 1 / vegetable - 0): ";
        std::cin >> isFruit;

        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        std::cout << "Enter price: ";
        std::cin >> price;
    }
};

struct Store {
    char storeName[32];
    unsigned int productsCount;
    const unsigned int maxCapacity = MAX_CAPACITY;
    Product products[MAX_CAPACITY];
};


void printProduct(const Product& product) {

    std::cout << "Product: " << std::endl;
    std::cout << "--Name: " << product.productName << std::endl;
    std::cout << "--Manufacturer: " << product.manufacturer << std::endl;
    std::cout << "--Type: " << (product.isFruit ? "Fruit" : "Vegetable") << std::endl;
    std::cout << "--Quantity: " << product.quantity << std::endl;
    std::cout << "--Price: " << product.price << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void printAllElementsOfStore(const Store& store) {
    std::cout << "Store: " << store.storeName << std::endl;
    
    for (int i = 0; i < store.productsCount; i++) {
        printProduct(store.products[i]);
    }
}

void swap(Product& p1, Product& p2) {
    Product temp = p1;
    p1 = p2;
    p2 = temp;
}

void sortProductsByFruit(Store& store) {

    int n = store.productsCount;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!store.products[j].isFruit && store.products[j + 1].isFruit) {
                swap(store.products[j], store.products[j + 1]);
            }
        }
    }

}

void sortProductsByVegetable(Store& store) {

    int n = store.productsCount;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (store.products[j].isFruit && !store.products[j + 1].isFruit) {
                swap(store.products[j], store.products[j + 1]);
            }
        }
    }

}

void sortProductsByPrice(Store& store) {
    int n = store.productsCount;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (store.products[j].price > store.products[j + 1].price) {
                swap(store.products[j], store.products[j + 1]);
            }
        }
    }
}

void addProduct(Store& store, const Product& product) {
    
    if (store.productsCount < store.maxCapacity) {
        store.products[store.productsCount] = product;
        store.productsCount++;
        std::cout << "Successfully added product - " << product.productName << std::endl;
    }
    else {
        std::cout << "Cannot add product" << std::endl;
    }
}

void sellProduct(Store& store, const char name[], const unsigned int quantity) {
    for (int i = 0; i <= store.productsCount; i++) {
        if (strcmp(store.products[i].productName, name) == 0 && store.products[i].quantity >= quantity) {
            store.products[i].quantity -= quantity;
        }
    }
}

const Store& storeWithTheMostFruits(const Store stores[], const unsigned int count) {

    int maxIndex = 0;

    int maxCountFruits = 0;
    int countFruits = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < stores[i].productsCount; j++) {
            if (stores[i].products[j].isFruit) {
                countFruits++;
            }
        }

        if (countFruits > maxCountFruits) {
            maxCountFruits = countFruits;
            maxIndex = i;
        }

        countFruits = 0;
    }


    return stores[maxIndex];
}

const Store& storeWithTheMostVegetables(const Store stores[], const unsigned int count) {

    int maxIndex = 0;

    int maxCountVegetables = 0;
    int countVegetables = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < stores[i].productsCount; j++) {
            if (!stores[i].products[j].isFruit) {
                countVegetables++;
            }
        }

        if (countVegetables > maxCountVegetables) {
            maxCountVegetables = countVegetables;
            maxIndex = i;
        }

        countVegetables = 0;
    }


    return stores[maxIndex];
}

const Store& cheapestStore(const Store stores[], int count) {
    
    int minIndex = 0;

    double avg = 0;
    double minAvg = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < stores[i].productsCount; j++) {
            avg += stores[i].products[j].price;
        }

        avg /= stores[i].productsCount;

        if (minAvg > avg) {
            minAvg = avg;
            minIndex = i;
        }
    }

    return stores[minIndex];
}

const Store& mostExpensiveStore(const Store stores[], int count) {

    int maxIndex = 0;

    double avg = 0;
    double maxAvg = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < stores[i].productsCount; j++) {
            avg += stores[i].products[j].price;
        }

        avg /= stores[i].productsCount;

        if (maxAvg < avg) {
            maxAvg = avg;
            maxIndex = i;
        }
    }

    return stores[maxIndex];
}

int main()
{
    Store stores[2];

    for (int i = 0; i < 2; i++) {
        Store store;

        std::cout << "Enter store name: ";
        std::cin >> stores[i].storeName;

        stores[i].productsCount = 2;

        Product productsToAdd[2];

        for (int j = 0; j < 2; j++) {
            Product product;
            product.init();
            productsToAdd[j] = product;
        }

        for (int j = 0; j < stores[i].productsCount; j++)
        {
            stores[i].products[j] = productsToAdd[j];
        }
    }

    /*Product newProdcut;
    newProdcut.init();
    addProduct(stores[0], newProdcut);

    std::cout << "=============================================" << std::endl;

    printAllElementsOfStore(stores[0]);
    sellProduct(stores[0], "p1", 5);
    std::cout << "=============================================" << std::endl;
    printAllElementsOfStore(stores[0]);

    sortProductsByFruit(stores[0]);
    std::cout << "=============================================" << std::endl;

    printAllElementsOfStore(stores[0]);

    sortProductsByVegetable(stores[0]);
    std::cout << "=============================================" << std::endl;
    printAllElementsOfStore(stores[0]);

    sortProductsByPrice(stores[0]);
    std::cout << "=============================================" << std::endl;
    printAllElementsOfStore(stores[0]);

    std::cout << "=============================================" << std::endl;
    printAllElementsOfStore(storeWithTheMostFruits(stores, 2));
    std::cout << "=============================================" << std::endl;
    printAllElementsOfStore(storeWithTheMostVegetables(stores, 2));
    std::cout << "=============================================" << std::endl;
    printAllElementsOfStore(cheapestStore(stores, 2));
    std::cout << "=============================================" << std::endl;
    printAllElementsOfStore(mostExpensiveStore(stores, 2));*/
}