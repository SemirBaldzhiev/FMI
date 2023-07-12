#include "CommandExecutor.h"

CommandExecutor::CommandExecutor() : exitFlag(false), selectedCmd(Command::UNKNOWN) {}

void CommandExecutor::selectCommand(const char* command) {

    if (!strcmp(command, "create-user"))              { selectedCmd = Command::CREATE_USER; }
    else if (!strcmp(command, "remove-user"))         { selectedCmd = Command::REMOVE_USER; }
    else if (!strcmp(command, "send-coins"))          { selectedCmd = Command::SEND_COINS; }
    else if (!strcmp(command, "verify-transactions")) { selectedCmd = Command::VERIFY_TRANSACTIONS; }
    else if (!strcmp(command, "wealthiest-users"))    { selectedCmd = Command::WEALTHIEST_USERS; }
    else if (!strcmp(command, "biggest-blocks"))      { selectedCmd = Command::BIGGEST_BLOCKS; }
    else if (!strcmp(command, "exit"))                { selectedCmd = Command::EXIT; }
    else                                              { selectedCmd = Command::UNKNOWN; }                                                  
}

void CommandExecutor::loadData() {
    userMng.readBianry(usersBinaryFileName);
    trmng.readBianry(blocksBinaryFileName);
}

void CommandExecutor::run() {

    menu();
    loadData();
    printInfo();

    while (!exitFlag) {
        char command[STR_LEN];
        std::cin >> command;

        selectCommand(command);

        switch (selectedCmd)
        {
            case Command::CREATE_USER:
            {
                char name[STR_LEN];
                int amount;

                std::cin >> name >> amount;

                if (amount < 0) {
                    std::cout << "Amount of coins cannot be negative number!\n";
                    break;
                }

                unsigned id = userMng.createUser(name);
                trmng.createTransaction(SYSTEM_USER_ID, id, COINS_MULTIPLAYER * amount);
                break;
            }
            case Command::REMOVE_USER:
            {
                char nameUsr[STR_LEN];
                std::cin >> nameUsr;

                if (!userMng.containsUser(nameUsr)) {
                    std::cout << "There is no user with this name!\n";
                    break;
                }

                unsigned idRem = userMng.removeUser(nameUsr);
                trmng.createTransaction(idRem, SYSTEM_USER_ID, trmng.allCoinsByUserId(idRem));
                break;
            }
            case Command::SEND_COINS:
            {
                unsigned fromId;
                unsigned toId;
                unsigned coins;

                std::cin >> fromId >> toId >> coins;

                if (coins < 0) {
                    std::cout << "Coins for transaction cannot be negative number!\n";
                    break;
                }

                if (!userMng.existId(fromId)) {
                    std::cout << "User with id " << fromId << " does not exists!\n";
                    break;
                }

                if (!userMng.existId(toId)) {
                    std::cout << "User with id " << toId << " does not exists!\n";
                    break;
                }

                std::cout << "From : " << fromId << " To : " << toId << " " << trmng.allCoinsByUserId(fromId)<< '\n';

                if (trmng.allCoinsByUserId(fromId) >= coins) {
                    trmng.createTransaction(fromId, toId, coins);
                }
                else {
                    std::cout << "User with id << " << fromId << "do not have enough coins!\n"; 
                }
                break;
            }
            case Command::WEALTHIEST_USERS:
            {
                int num;
                std::cin >> num;
                trmng.wealthiestUsers(num, userMng.getUsers(), userMng.getUsersCount());
                break;
            }
            case Command::BIGGEST_BLOCKS:
            {
                int n;
                std::cin >> n;
                trmng.biggestBlocks(n);
                break;
            }
            case Command::VERIFY_TRANSACTIONS:
            {
                bool res = trmng.verifyTransactions();

                if (res) {
                    std::cout << "No broken blocks!\n";
                }
                else {
                    std::cout << "There is an error in block sequence\n";
                }
                break;
            }
            case Command::EXIT:
            {
                userMng.writeBinary(usersBinaryFileName);
                trmng.writeBinary(blocksBinaryFileName);
                exitFlag = true;
                break;
            }
            case Command::UNKNOWN:
            {
                std::cout << "Unsupported command!\nPlease try again...\n"; 
                std::cin.getline(command, STR_LEN);
                break;
            }
        }
    }    
}

void CommandExecutor::printInfo() {

    std::cout << "===========================Current system state===========================\n";
    std::cout << "-----------------------------------Users----------------------------------\n";
    if (userMng.getUsersCount() > 0) {
        for (int i = 0; i < userMng.getUsersCount(); i++) {
            std::cout << "ID: " << userMng.getUsers()[i].id << "\t\tName: " << userMng.getUsers()[i].name << "\t\tCoins: " << trmng.allCoinsByUserId(userMng.getUsers()[i].id) << '\n';
        }
    }
    else {
        std::cout << "There is no users in the sysytem!\n";
    }
    std::cout << "--------------------------------------------------------------------------\n";
    std::cout << "==========================================================================\n";
}

void CommandExecutor::menu() {
    std::cout << "-------------------------Commands------------------------\n";
    std::cout << "| create-user <name> <coins>                            |\n"; 
    std::cout << "| remove-user <name>                                    |\n";
    std::cout << "| send-coins <senderId> <reciverId> <coins>             |\n";
    std::cout << "| verify-transactions                                   |\n";
    std::cout << "| wealthiest-users <n>                                  |\n";
    std::cout << "| biggest-blocks <n>                                    |\n";
    std::cout << "| exit                                                  |\n";
    std::cout << "---------------------------------------------------------\n";
}