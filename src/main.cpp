#include <iostream>
#include <string>
#include <string_view>
#include "../include/db.hpp"
#include "../include/parser.hpp"
#include "../include/operation.hpp"

using namespace lunadb;

int main() {

    std::cout << "Welcome to LunaDB!" << std::endl;
    std::cout << "Check github.com/cirosanchez/lunadb for more info." << std::endl;

    Database db;
    Parser parser;

    bool isRunning = true;

    while (isRunning) {
        // Get input
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        // Split the string into a vector of it's components to separate command and arguments/parameters.
        std::stringstream ss(input);

        std::vector<std::string> command;
        std::string token;

        while (std::getline(ss, token, ' ')) {
            command.push_back(token);
        }
        
        // Pass the new split command to the Parser to get an Operation object.
        auto op = parser.parse(command);

        if (!op.has_value()) {
            std::cout << "Skipping iteration..." << std::endl;
            continue;
        }

        std::cout << "Operation key -> " << op->key << std::endl;
    }

    return 0;
}
