#pragma once

#include <unordered_map>
#include <string>

namespace lunadb {
    class Database {
        private:
            std::unordered_map<std::string, std::string> map;
        
        public:
            std::string get(std::string key);

            void set(std::string key, std::string value);

            void remove(std::string key);
    };
} 