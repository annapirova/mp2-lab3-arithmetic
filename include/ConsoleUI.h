//
// Created by Grigoriy Kobaevich Kurasbediani on 17.12.2021.
//

#ifndef MP2_LAB3_ARITHMETIC_CONSOLEUI_H
#define MP2_LAB3_ARITHMETIC_CONSOLEUI_H

#include "arithmetic.h"

enum COMMANDS {
    EXIT,
    INPUT_NEW_EXPRESSION,
    LAUNCH,
    PRINT_ALL,
    PRINT_INPUT_EXPRESSION,
    PRINT_CORRECTED_EXPRESSION,
    PRINT_RPN_EXPRESSION,
    PRINT_RESULT_EXPRESSION
};

class ConsoleUI {
private:
    int user_command = -1;
    Arithmetic arithmetic;

    static void menu_show() {
        std::cout << "MENU" << std::endl;
        std::cout << "1 - input new expression" << std::endl;
        std::cout << "2 - launch" << std::endl;
        std::cout << "3 - print all" << std::endl;
        std::cout << "4 - print input expression" << std::endl;
        std::cout << "5 - print corrected expression" << std::endl;
        std::cout << "6 - print RPN expression" << std::endl;
        std::cout << "7 - print result of expression" << std::endl;
        std::cout << "0 - exit" << std::endl << std::endl;
    }

    void action_choose() {
        std::cin >> user_command;
        std::cin.ignore(32767, '\n');
        while (user_command < 0 || user_command > 7) {
            std::cout << "Input value from 0 to 7: ";
            std::cin >> user_command;
            std::cin.ignore(32767, '\n');
        }
    }

    void action_make() {
        switch (user_command) {
            case INPUT_NEW_EXPRESSION: {
                std::cout << std::endl;
                std::string str;
                std::cout << "New expression: ";
                std::getline(cin, str);
                arithmetic.set_input_string(str);
                std::cout << std::endl;
                break;
            }
            case LAUNCH: {
                std::cout << std::endl;
                arithmetic.launch();
                std::cout << std::endl;
                break;
            }
            case PRINT_ALL: {
                std::cout << std::endl;
                std::cout << "All information: " << std::endl;
                arithmetic.print();
                std::cout << std::endl;
                break;
            }
            case PRINT_INPUT_EXPRESSION: {
                std::cout << std::endl;
                std::cout << "Input string:" << arithmetic.get_input_str();
                std::cout << std::endl;
                break;
            }
            case PRINT_CORRECTED_EXPRESSION: {
                std::cout << std::endl;
                std::cout << "Corrected string: " << arithmetic.get_corrected_str();
                std::cout << std::endl;
                break;
            }
            case PRINT_RPN_EXPRESSION: {
                std::cout << std::endl;
                std::cout << "RPN string: " << arithmetic.get_RPN_str();
                std::cout << std::endl;
                break;
            }
            case PRINT_RESULT_EXPRESSION: {
                std::cout << std::endl;
                std::cout << "Result: " << arithmetic.get_res();
                std::cout << std::endl;
                break;
            }
            case EXIT: {
                exit(0);
            }
            default:
                break;
        }
    }

public:
    explicit ConsoleUI() = default;

    ~ConsoleUI() = default;

     void launch(){
        while (user_command) {
            menu_show();
            action_choose();
            action_make();
        }
    }
};

#endif //MP2_LAB3_ARITHMETIC_CONSOLEUI_H
