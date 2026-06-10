#include "../include/executor.hpp"
#include <string>


using namespace lunadb;

std::string Executor::execute_operation(Operation& op) {
    OperationType type = op.type;

    switch (type) {
        case OperationType::Get:
            return db.get(op.key);
        case OperationType::Set:
            db.set(op.key, op.value);
            return "Set value: "+op.value+" at key "+op.key;
            break;

        case OperationType::Remove:
            db.remove(op.key);
            return "Removed value at key: "+op.key;
            break;
    }

    return "Operation failed, this should never happen.";
}