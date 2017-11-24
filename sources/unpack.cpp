#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
struct Email {
    std::string nickname;
    std::string server;
};

struct Person {
    std::string  first_name;
    std::string  last_name;
    Email        email;
    size_t       age;
    std::string  phone;
};

int main(int argc, char* argv[]) {
    std::string Path = argv[1];
    Person data_back;
    json account;
    std::ifstream file;
    file.open(Path);
    file >> account;
    file.close();

    data_back.first_name = account.at("first_name").get<std::string>();
    data_back.last_name = account.at("last_name").get<std::string>();
    data_back.email.server = account.at("email_server").get<std::string>();
    data_back.email.nickname = account.at("email_nickname").get<std::string>();
    data_back.age = account.at("age").get<size_t>();
    data_back.phone = account.at("phone").get<std::string>();

    std::cout << "[Person]" << std::endl;
    std::cout << "First name: " << data_back.first_name << std::endl;
    std::cout << "Last name: " << data_back.last_name << std::endl;
    std::cout << "Email: " << data_back.email.nickname + "@" + data_back.email.server << std::endl;
    std::cout << "Age: " << data_back.age << std::endl;
    std::cout << "Phone: " << data_back.phone << std::endl;
    return 0;
}
