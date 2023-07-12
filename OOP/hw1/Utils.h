#ifndef __UTILS_H
#define __UTILS_H

unsigned computeHash(const unsigned char *memory, int length);
struct User
{
    unsigned id;
    char name[128];
};
struct Transaction
{
    unsigned sender;
    unsigned receiver;
    double coins;
    long long time;
};
struct TransactionBlock
{
    unsigned id;
    unsigned prevBlockId;
    unsigned prevBlockHash;
    int validTransactions;
    Transaction transactions[16];
};

void setBlockID(TransactionBlock& obj, unsigned lastSetId);

void setUserID(User& obj, unsigned lastSetId);


#endif