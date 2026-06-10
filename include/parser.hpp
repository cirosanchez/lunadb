#pragma once

#include "./operation.hpp"
#include <cctype>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace lunadb {
    class Parser {
        public:
            std::optional<Operation> parse(std::string str) {
                std::stringstream ss(str);

                std::vector<std::string> split_str;
                std::string token;

                while (std::getline(ss, token, ' ')) {
                    split_str.push_back(token);
                }

                std::string command = split_str.at(0);

                for (char& c : command) {
                    c = std::toupper(c);
                }

                if (command == "GET") {
                    return Operation{ OperationType::Get, split_str.at(1), " " };
                }

                if (command == "SET") {
                    return Operation{ OperationType::Set, split_str.at(1), split_str.at(2) };
                }

                if (command == "REMOVE") {
                    return Operation{ OperationType::Remove, split_str.at(1), " " };
                }

                std::cout << "Unrecognized command -> " << command << std::endl;

                return std::nullopt;
            }
    };
}