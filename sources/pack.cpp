#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <fstream>
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

void correct_data(std::string data, Email& post)
{
    post.nickname = "";
    post.server = "";
    bool check = false;
    for (auto i = data.begin(); i < data.end(); ++i)
    {
        if (*i == '@')
            check = true;
        if (*i != '@' && !check)
            post.nickname += *i;
        if (*i != '@' && check)
            post.server += *i;
    }

}

int main(int argc, char* argv[]) {
    std::string Path = argv[1];
    std::ofstream js(Path);
    Person data;
    json account;

    std::string data_email;
    std::cout << "Enter data to fields of the Person structure." << std::endl;
    std::cout << "First name:" << std::endl;
    std::cin >> data.first_name;
    std::cout << "Last name:" << std::endl;
    std::cin >> data.last_name;
    std::cout << "Email:" << std::endl;
    std::cin >> data_email;
    correct_data(data_email, data.email);
    std::cout << "Age (optional):" << std::endl;
    try{
    std::string age;
    std::cin.ignore();
    std::getline(std::cin, age);
    if(!age.empty() && std::stoi(age) > 0)
    	data.age = std::stoi(age);
    else 
	data.age = 0;
    }
    catch(...){data.age = 0;}
    std::cout << "Phone (optional):" << std::endl;
    std::getline(std::cin, data.phone);

    account["first_name"] = data.first_name;
    account["last_name"] = data.last_name;
    account["email"]["email_nickname"] = data.email.nickname;
    account["email"]["email_server"] = data.email.server;
	if (data.age != 0)     
	account["age"] = data.age;
if (!data.phone.empty())    
account["phone"] = data.phone;

    js << account;
    js.close();
    return 0;
}
