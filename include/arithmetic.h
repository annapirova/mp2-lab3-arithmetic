#ifndef MP2_LAB3_ARITHMETIC_ARITHMETIC_H
#define MP2_LAB3_ARITHMETIC_ARITHMETIC_H

#include <iostream>
#include <string>
#include <regex>
#include <list>
#include <cmath>
#include <stack>
//#include "stack.h"
#include <map>
#include <functional>
#include <utility>

using namespace std;

enum Types {
    OPERAND = -1, SKOBKA, PLUS_MINUS, MUL_DIV, POW, FUNC
};

class Arithmetic {
private:
    struct lexem {
        string value;
        int type;

        explicit lexem(const string &value_) {
            value = value_;
            type = prioretet(value_);
        }
    };

    string input_str;
    string corrected_str;
    string obr_pol_zap_str;
    list<lexem> lexems_of_corrected_str;
    list<lexem> lexems_after_obr_pol_zap;
    double res = 0.0;

    //PRIORITET
    static int prioretet(const string &s);

    //CHECKERS
    static bool is_it_substr_of_str(const string &str, const string &substr);

    static int count_substr_in_str(const string &str, const string &substr);

    static list<string> find_func_in_str(const string &str);

    static bool ch_skob(const string &str);

    static bool ch_dot(const string &str);

    static bool ch_all_znak(const string &str);

    static bool ch_all_func(const string &str);

    //PREPARE
    static string erase_space(const string &str);

    static string make_unary_minus(const string &str);

    //DIVIDE TO LEXEM
    static list<string> find_lexem_num_and_var(const string &str, int for_submatch = 0);

    static list<string> find_lexem_operations(const string &str, int for_submatch = 0);

    static list<string> list_of_tokens(const list<string> &list_num_and_var, const list<string> &list_operations);

    static list<string> split_string_to_tokens(const string &str);

    static list<lexem> token_to_lexem(const list<string> &tokens);

    //OBRATNAY POLSKAY ZAPIS
    static string obr_pol_zap(const list<lexem> &lst);

    static list<string> split(const string &str, char sep);

    static list<lexem> obr_poz_zap_to_lexem(const string &str);

    //CALCULATE
    static double calculate_func(const string &str, double x);

    static double calculate_operator(const string &str, double x, double y);

    static double calculate(const list<lexem> &lexems_);

    //ALL//
    static bool check_all(const string &str);

    void prepare_str();

    void make_lexems_of_corrected_str();

    void make_obr_pol_zap_str();

    void make_lexems_after_obr_pol_zap();

    void make_result();

public:
    explicit Arithmetic(const string &str) : input_str(str) {};

    ~Arithmetic() = default;

    void launch() {
        prepare_str();
        make_lexems_of_corrected_str();
        make_obr_pol_zap_str();
        make_lexems_after_obr_pol_zap();
        make_result();
        print();
    }

    void print() const {
        cout << "Input string : " << input_str << endl;
        cout << "Corrected string : " << corrected_str << endl;
        cout << "String in RPN : " << obr_pol_zap_str << endl;
        cout << "Lexems of corrected string : ";
        for (const auto &i: lexems_of_corrected_str) {
            cout << i.value << " ";
        }
        cout << endl;
        cout << "Lexems after RPN : ";
        for (const auto &i: lexems_after_obr_pol_zap) {
            cout << i.value << " ";
        }
        cout << endl;
        cout << "Result : " << res << endl;
    }

    string get_input_str() const {
        return input_str;
    }

    string get_corrected_str() const {
        return corrected_str;
    }

    string get_RPN_str() const {
        return obr_pol_zap_str;
    }

    list<lexem> get_lexem_list_of_corrected_str() const {
        return lexems_of_corrected_str;
    }

    list<lexem> get_lexem_list_of_RPN_str() const {
        return lexems_after_obr_pol_zap;
    }

    double get_res() const {
        // сделать res строкой
        // в make_result перевести calculate в string
        return res; // !res.empty() ? stod(res) : res;
    }
};


#endif //MP2_LAB3_ARITHMETIC_ARITHMETIC_H