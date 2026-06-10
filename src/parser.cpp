#include "../include/parser.hpp"

using namespace lunadb;
using namespace std;

optional<Operation> Parser::parse(std::vector<std::string> split_command) {

    for (string &str : split_command) {
        for (char &c : str) {
        c = std::toupper(c);
        }
    }

    string command = split_command.at(0);

    // GET KEY, size must be 2.
    if (command == "GET") {

        // If size is less or equal to 1, throw error.
        // If size is more than 2, throw error.
        if (split_command.size() <= 1 || split_command.size() > 2) {
            cout << "[parser.cpp:18] Get command must have 1 argument. Get <key>" << endl;
            return nullopt;
        }

        // Return an operation with only the key.
        return Operation{OperationType::Get, split_command.at(1), " "};
    }

    // SET KEY VALUE, size must be 3
    if (command == "SET") {

        // If size is less or equal to 2, throw error.
        // If size is more than 3, throw error.
        if (split_command.size() <= 2 || split_command.size() > 3) {
            cout << "[parser.cpp:29] Set command must have 2 arguments. Set <key> <value>" << endl;
            return nullopt;
        }

        // Return an operation with both the key and the value
        return Operation{OperationType::Set, split_command.at(1), split_command.at(2)};
    }

    // REMOVE KEY, size must be 2.
    if (command == "REMOVE") {

        // If size is less or equal to 1, throw error.
        // If size is more than 2, throw error.
        if (split_command.size() <= 1 || split_command.size() > 2) {
            cout << "[parser.cpp:39] Get command must have 1 argument. Get <key>" << endl;
            return nullopt;
        }

        // Return an operation with only the key.
        return Operation{OperationType::Remove, split_command.at(1), " "};
    }

    cout << "Unrecognized command -> " << command << std::endl;

    return std::nullopt;
}