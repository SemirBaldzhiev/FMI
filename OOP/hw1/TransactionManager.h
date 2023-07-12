#ifndef __TRANSACTION_MANAGER
#define __TRANSACTION_MANAGER

#include <iostream>
#include <cstring>
#include "Utils.h"
#include <ctime>
#include <fstream>

class TransactionManager {

    public:
        TransactionManager();
        TransactionManager(const TransactionManager& other) = delete;
        TransactionManager& operator=(const TransactionManager& other) = delete;
        ~TransactionManager();

        void createTransaction(unsigned fromId, unsigned toId, unsigned amount);
        void createBlock();
        void wealthiestUsers(unsigned n, User* users, int count);
        void biggestBlocks(unsigned n);
        bool verifyTransactions();
        unsigned allCoinsByUserId(unsigned userId);
        
        void writeBinary(const char* fileName);
        void readBianry(const char* fileName);
    private:
        TransactionBlock* transactionBlocks;
        std::size_t countBlocks;
        std::size_t capacity;
        unsigned lastSetId;

        struct BiggestBlockData {
            int index;
            unsigned coins;
        };  

        void resize();
};


#endif