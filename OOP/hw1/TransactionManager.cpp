#include "TransactionManager.h"

TransactionManager::TransactionManager() : capacity(4), countBlocks(-1), lastSetId(1) {
            transactionBlocks = new TransactionBlock[capacity];
}

TransactionManager::~TransactionManager() {
    delete[] transactionBlocks;
}

void TransactionManager::createTransaction(unsigned fromId, unsigned toId, unsigned amount){
    
    std::time_t t = std::time(0);

    Transaction tr;
    tr.sender = fromId;
    tr.receiver = toId;
    tr.coins = amount;
    tr.time = (unsigned)t;

    if (countBlocks == -1){
        countBlocks++;
        
        createBlock();
    }

    if (transactionBlocks[countBlocks].validTransactions == 16) {

        countBlocks++;
        createBlock();
    }


    transactionBlocks[countBlocks].transactions[transactionBlocks[countBlocks].validTransactions] = tr;
    transactionBlocks[countBlocks].validTransactions++;
}

void TransactionManager::createBlock() {

    TransactionBlock block;

    if (countBlocks == capacity) {
        resize();
    }

    
    setBlockID(block, lastSetId);
    if (countBlocks == 0) {
        block.prevBlockId = block.id;
    }
    else {  
        block.prevBlockId = transactionBlocks[countBlocks - 1].id;
        block.prevBlockHash = computeHash(reinterpret_cast<const unsigned char *>(&transactionBlocks[countBlocks-1]), sizeof(TransactionBlock));
    }
    block.validTransactions = 0;

    transactionBlocks[countBlocks] = block;
}
void TransactionManager::writeBinary(const char* fileName) {
    std::ofstream ofs(fileName, std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Cannot open file " << fileName << " for writing in binary!";
        return;
    }

    for (int i = 0; i <= countBlocks; i++) {
        ofs.write(reinterpret_cast<char *>(&transactionBlocks[i]), sizeof(TransactionBlock));
    }

    ofs.close();
}

unsigned TransactionManager::allCoinsByUserId(unsigned userId) {

    unsigned sumCoins = 0;
    for (int i = 0; i <= countBlocks; i++) {
        for (int j = 0; j < transactionBlocks[i].validTransactions; j++) {
            if (transactionBlocks[i].transactions[j].receiver == userId) {
                sumCoins+=transactionBlocks[i].transactions[j].coins;
            }
            else if (transactionBlocks[i].transactions[j].sender == userId) {
                sumCoins-=transactionBlocks[i].transactions[j].coins;
            }
        }
    }

    return sumCoins;
}

void TransactionManager::wealthiestUsers(unsigned n, User* users, int count) {

    User* copyUsers = new User[count];

    if (n > count) {
        n = count;
    }

    for (int i = 0; i < count; i++) {
        copyUsers[i].id = users[i].id;
        std::strcpy(copyUsers[i].name, users[i].name);
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (allCoinsByUserId(copyUsers[j].id) < allCoinsByUserId(copyUsers[j + 1].id)) {
                User temp = copyUsers[j];
                copyUsers[j] = copyUsers[j+1];
                copyUsers[j+1] = temp;
            }
        }
    }

    std::time_t t = std::time(0);

    unsigned sec = (unsigned)t;
    char secStr[128];
    sprintf(secStr, "%d", sec);
    char cmdName[] = "wealthiest-users";
    char* fielName = std::strcat(cmdName, secStr);

    std::ofstream ofs(fielName);

    if (!ofs.is_open()){
        std::cout << "Error\n";
    }

    for (int i = 0; i < n; i++) {
        ofs << "Name: " << copyUsers[i].name << ", " << "Coins: " << allCoinsByUserId(copyUsers[i].id) << '\n';
    }

    ofs.close();
    delete[] copyUsers;
}

void TransactionManager::biggestBlocks(unsigned n) {

    if (n > countBlocks+1) {
        n = countBlocks+1;
    }
    unsigned sumCoins = 0;
    BiggestBlockData* blockData = new BiggestBlockData[countBlocks];

    for (int i = 0; i <= countBlocks; i++) {

        for (int j = 0; j < transactionBlocks[i].validTransactions; j++) {
            
            sumCoins += transactionBlocks[i].transactions[j].coins;
        }

        blockData[i].index = i;
        blockData[i].coins = sumCoins;
        sumCoins = 0;
    }

    for (int i = 0; i < countBlocks; i++) {
        for (int j = 0; j < countBlocks - i; j++) {
            if (blockData[j].coins < blockData[j + 1].coins) {
                BiggestBlockData temp = blockData[j];
                blockData[j] = blockData[j+1];
                blockData[j+1] = temp;
            }
        }
    }
    
    std::time_t t = std::time(0);

    unsigned sec = (unsigned)t;
    char secStr[128];
    sprintf(secStr, "%d", sec);
    char cmdName[] = "biggest-blocks";
    char* fielName = std::strcat(cmdName, secStr);

    std::ofstream ofs(fielName);

    if (!ofs.is_open()) {
        std::cout << "Error!\n";
    }

    for (int i = 0; i < n; i++) {
        ofs << "Index: " << blockData[i].index << " Coins: " << blockData[i].coins << '\n';
    }

    ofs.close();
    delete[] blockData;
}

void TransactionManager::readBianry(const char* fileName) {
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "File with name " << fileName << " does not exist!\n";
        return;
    }

    ifs.seekg(0, std::ios::end);
    int fileSize = ifs.tellg();

    ifs.seekg(0, std::ios::beg);

    unsigned cntBlck = fileSize / sizeof(TransactionBlock);

    for (int i = 0; i < cntBlck; i++) {
        
        if (countBlocks == capacity) {
            resize();
        }
        
        ifs.read(reinterpret_cast<char *>(&transactionBlocks[i]), sizeof(TransactionBlock));
        countBlocks++;
    } 
    unsigned max = 0;
    for (int i = 0; i < cntBlck; i++) {
        if (transactionBlocks[i].id > max) {
            max = transactionBlocks[i].id;
        }
    }

    lastSetId = max+1;  

    ifs.close();
}

bool TransactionManager::verifyTransactions() {

    for (int i = 1; i <= countBlocks; i++) {

        // TransactionBlock prev = transactionBlocks[i - 1]; 
        std::cout<<countBlocks <<"\n";       
        unsigned hash = computeHash(reinterpret_cast<const unsigned char*>(&transactionBlocks[i - 1]), sizeof(TransactionBlock));

        std::cout << "Prev hash: " << transactionBlocks[i].prevBlockHash << " Hash: " << hash << "\n";
        if (transactionBlocks[i].prevBlockHash != hash)
        {
            return false;
        }
    } 

    return true;
} 

void TransactionManager::resize() {
    TransactionBlock* newStorage = new TransactionBlock[capacity * 2];

    for (int i = 0; i <= countBlocks; ++i) {
        newStorage[i] = transactionBlocks[i];
    }

    capacity *= 2;

    delete[] transactionBlocks;
    transactionBlocks = newStorage;
}
