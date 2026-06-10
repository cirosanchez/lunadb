#pragma once

#include "db.hpp"
#include "operation.hpp"
namespace lunadb {
    class Executor {
        public:
            Executor(Database& db) {
                this->db = db;
            }
            std::string execute_operation(Operation& op);
        private: 
            Database db;
    };
}