#include <iostream>
#include <string>
#include <string_view>
#include "../include/db.hpp"
#include "../include/parser.hpp"
#include "../include/operation.hpp"


int main() {

    std::cout << "Welcome to LunaDB!" << std::endl;
    std::cout << "Check github.com/cirosanchez/lunadb for more info." << std::endl;

    lunadb::Database db;
    lunadb::Parser parser;

    bool isRunning = true;

    while (isRunning) {
        std::string input;
        std::getline(std::cin, input);

        auto op = parser.parse(input);

        if (!op) {
            std::cout << "Invalid command" << std::endl;
            continue;
        }

        switch (op->type) {
            case lunadb::OperationType::Get: std::cout << "OP TYPE -> " << "Get" << std::endl; break;
            case lunadb::OperationType::Set: std::cout << "OP TYPE -> " << "Set" << std::endl; break;
            case lunadb::OperationType::Remove: std::cout << "OP TYPE -> " << "Remove" << std::endl; break;
        }   

        // TODO: fix set, to force 2 arguments, key and value. might be worth making Parser::parse(array of already split string).
        // funcitonal parser, great cpp though
    }

    return 0;
}
