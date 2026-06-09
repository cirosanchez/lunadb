#pragma once

#include <string>

namespace lunadb {
    enum class OperationType {
        Get,
        Set,
        Remove
    };


    struct Operation {
        OperationType type;
        std::string key;
        std::string value;
    };
}