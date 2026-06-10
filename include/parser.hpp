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
            std::optional<Operation> parse(std::vector<std::string> split_command);
    };
}