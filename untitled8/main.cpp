#include <iostream>
#include <map>
#include <stdexcept>

int main() {
    try {
        std::map<std::string, int> shop;
        std::map<std::string, int> basket;
        std::cout << "Enter the article and quantity of the product ('stop' for stop enter): " << std::endl;
        std::string article;
        int count;

        // Заполнение магазина
        while (article != "stop") {
            std::cin >> article;
            if (article != "stop") {
                std::cin >> count;
                shop.insert(std::pair<std::string, int>(article, count));
            }
        }

        // Просмотр магазина
        for (const auto& pair : shop) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }

        // Шоппинг
        std::string command;
        while (true) {
            try {
                std::cout << "Enter the command (add/remove or stop): " << std::endl;
                std::cin >> command;

                if (command == "add") {
                    std::cout << "Enter the article and the quantity of the product to be added: " << std::endl;
                    std::string user_article;
                    int user_count;
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
                            for (const auto& pair : basket) {
                                std::cout << pair.first << " " << pair.second << std::endl;
                            }
                            std::cout << "Shop:" << std::endl;
                            for (const auto& pair : shop) {
                                std::cout << pair.first << " " << pair.second << std::endl;
                            }
                        }
                    }
                } else if (command == "remove") {
                    std::cout << "Enter the article and the quantity of the product to be removed: " << std::endl;
                    std::string user_article;
                    int user_count;
                    std::cin >> user_article;

                    if (basket.find(user_article) == basket.end()) {
                        throw std::invalid_argument("Article not found in the basket");
                    } else {
                        std::cin >> user_count;
                        if (user_count <= 0 || user_count > basket[user_article]) {
                            throw std::invalid_argument("Invalid quantity");
                        } else {
                            basket[user_article] -= user_count;
                            shop[user_article] += user_count;
                            std::cout << "Product removed successfully.\nYour basket:" << std::endl;
                            for (const auto& pair : basket) {
                                std::cout << pair.first << " " << pair.second << std::endl;
                            }
                            std::cout << "Shop:" << std::endl;
                            for (const auto& pair : shop) {
                                std::cout << pair.first << " " << pair.second << std::endl;
                            }
                        }
                    }
                } else if (command == "stop") {
                    break;
                } else {
                    std::cout << "Invalid command. Please enter 'add', 'remove', or 'stop'." << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Exception caught: " << e.what() << std::endl;
            } catch (...) {
                std::cerr << "Unknown exception caught." << std::endl;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught outside shopping loop: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught outside shopping loop." << std::endl;
    }
}
