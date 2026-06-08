#include "../include/db.hpp"
#include <iostream>



using namespace lunadb;
using namespace std;

string Database::get(std::string key) {
    auto it= map.find(key);

    if (it == map.end()) {
        cout << "there is no value at key " << key << " in the index." << endl;
        return "";
    }

    return it->second;
}

void Database::set(std::string key, std::string value) {
    map[key] = value;    
}

void Database::remove(std::string key) {
    map.erase(key);
}
