#ifndef __COMMAND_EXECUTOR
#define __COMMAND_EXECUTOR

#include <iostream>
#include "TransactionManager.h"
#include "UserManager.h"

#define COINS_MULTIPLAYER 420
#define STR_LEN           128
#define SYSTEM_USER_ID    0

enum class Command {
    UNKNOWN = -1,

    CREATE_USER,
    REMOVE_USER,
    SEND_COINS,
    VERIFY_TRANSACTIONS,
    WEALTHIEST_USERS,
    BIGGEST_BLOCKS,
    EXIT,

    COUNT_COMMANDS
};

class CommandExecutor {
    public:
        CommandExecutor();
        CommandExecutor(const CommandExecutor& other) = delete;
        CommandExecutor& operator=(const CommandExecutor& other) = delete;
        ~CommandExecutor() = default;

        void run();
    private:
        const char* usersBinaryFileName = "users.dat";
        const char* blocksBinaryFileName = "blocks.dat";

        bool exitFlag;
        Command selectedCmd;
        UserManager userMng;
        TransactionManager trmng;


        void selectCommand(const char* commandName);
        void loadData();
        void printInfo();
        void menu();
};


#endif