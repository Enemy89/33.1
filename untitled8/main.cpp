#include <iostream>
#include <map>
#include <stdexcept>

int main() {
    std::map<std::string, int> shop;
    std::map<std::string, int> basket;
    std::cout << "Enter the article and quantity of the product ('stop' for stop enter): " << std::endl;
    std::string article;
    int count;

    //заполнение магазина
    while (article != "stop") {
        std::cin >> article;
        if (article != "stop") {
            std::cin >> count;
            shop.insert(std::pair<std::string, int>(article, count));
        }
    }

    //просмотр магазина
    for (std::map<std::string, int>::iterator it = shop.begin(); it != shop.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    //шоппинг
    std::string command;
    while (command!="stop") {
        if (command!="stop") {
            std::cout << "Enter the command (add/remove or stop): " << std::endl;
            std::string user_article;
            int user_count;
            std::cin >> command;

            if (command == "add") {
                std::cout << "Enter the article and the quantity of the product to be added: " << std::endl;
                std::cin >> user_article;

                if (shop.find(user_article) == shop.end()) {
                    throw std::invalid_argument("Article not found in the shop");
                } else {
                    std::cin >> user_count;
                    if (user_count <= 0 || user_count > shop[user_article]) {
                        throw std::invalid_argument("Invalid quantity");
                    } else {
                        basket.insert(std::pair<std::string, int>(user_article, user_count));
                        shop[user_article] -= user_count;
                        std::cout << "Product added successfully.\nYour basket:" << std::endl;
                        for (std::map<std::string, int>::iterator it = basket.begin(); it != basket.end(); ++it) {
                            std::cout << it->first << " " << it->second << std::endl;
                        }
                        std::cout << "Shop:" << std::endl;
                        for (std::map<std::string, int>::iterator it = shop.begin(); it != shop.end(); ++it) {
                            std::cout << it->first << " " << it->second << std::endl;
                        }
                    }
                }
            } else if (command == "remove") {
                std::cout << "Enter the article and the quantity of the product to be removed: " << std::endl;
                std::cin >> user_article;

                if (basket.find(user_article) == basket.end()) {
                    throw std::invalid_argument("Article not found in the shop");
                } else {
                    std::cin >> user_count;
                    if (user_count <= 0 || user_count > basket[user_article]) {
                        throw std::invalid_argument("Invalid quantity");
                    } else {
                        basket[user_article]-=user_count;
                        shop[user_article] += user_count;
                        std::cout << "Product removed successfully.\nYour basket:" << std::endl;
                        for (std::map<std::string, int>::iterator it = basket.begin(); it != basket.end(); ++it) {
                            std::cout << it->first << " " << it->second << std::endl;
                        }
                        std::cout << "Shop:" << std::endl;
                        for (std::map<std::string, int>::iterator it = shop.begin(); it != shop.end(); ++it) {
                            std::cout << it->first << " " << it->second << std::endl;
                        }
                    }
                }
            } else if (command == "stop") {
                break;
            } else {
                throw std::runtime_error("Invalid command");
            }
        }
    }
}

