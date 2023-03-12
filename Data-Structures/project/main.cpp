#include <iostream>
#include <string>
#include <cstring>
#include <vector>

std::vector<std::string> split(std::string str, std::string delimiters)
{
    std::vector<std::string> tokens;
    int delimCnt = delimiters.size();
    int cntBrack1 = 0;
    int cntBrack2 = 0;

    std::string word = "";
    for (char x : str)
    {   
        if (x == delimiters[2]) {
            cntBrack1++;
        }
        if (x == delimiters[3]) {
            cntBrack2++;
        }
        if (cntBrack1 > 1 || cntBrack2 > 1) {
            if (x == delimiters[0] || x == delimiters[1])  
            {
                if (word == "") {
                    continue;
                }
                tokens.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
        else {
            if (x == delimiters[0] || x == delimiters[1] || x == delimiters[2] || x == delimiters[3])  
            {
                if (word == "") {
                    continue;
                }
                tokens.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }

        
    }

    tokens.push_back(word);

    return tokens;
}

std::string toUpper(std::string s) {
    std::string res;
    for (int i = 0; i < s.size(); i++) {
        res[i] = toupper(s[i]);
    }

    return res;
}

bool validateCreateTableQuery(std::vector<std::string> tokens) {

    int len = tokens.size();
    if (tokens.size() <= 3)  {
        return false;
    }

    if (toUpper(tokens[0]) != "CREATE" && toUpper(tokens[1]) != "TABLE") {
        return false;
    }

    if (!onlyAlphabeticAndUnderscore(tokens[2])) {
        return false;
    }

    if (tokens[len - 2] == "KEY" && tokens[len - 3] == "PRIMARY" && onlyAlphabeticAndUnderscore(tokens[len - 1])) {
        len -= 3;
    } 
    else {
        return false;
    }

    for (int i = 3; i < len; i+=2) {
        if (!onlyAlphabeticAndUnderscore(tokens[i])) {
            return false;
        }

        if (!correctType(tokens[i + 1])) {
            return false;
        }
    }

    return true;
}

int main() {

    std::string s;

    std::getline(std::cin, s, ';');

    std::vector<std::string> res = split(s, ", ()");

    for (std::string s : res) {
        std::cout << s << '\n';
    }
    
// CREATE TABLE <table_name> (<column1> <datatype1>, <column2> <datatype2>, …) [PRIMARY KEY (<ID>)]

    return 0;
}