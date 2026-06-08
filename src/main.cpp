#include <iostream>
#include "../include/db.hpp"

int main() {
    std::cout << "This is LunaDB" << std::endl;
    lunadb::Database db;

    db.set("artist", "catriel y pacoh");

    db.set("language", "cpp");

    std::cout << db.get("artist") << std::endl;

    std::cout << db.get("not an artist") << std::endl;

    return 0;
}
