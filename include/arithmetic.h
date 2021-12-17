#ifndef MP2_LAB3_ARITHMETIC_ARITHMETIC_H
#define MP2_LAB3_ARITHMETIC_ARITHMETIC_H

#include <iostream>
#include <string>
#include <regex>
#include <list>
#include <cmath>
#include <stack>
#include <map>
#include <functional>
#include <utility>

using namespace std;

enum Types {
    OPERAND = -1, SKOBKA, PLUS_MINUS, MUL_DIV, POW, FUNC
};

int prioretet(const string &s);

struct lexem {
    string value;
    int type;

    explicit lexem(const string &value_) {
        value = value_;
        type = prioretet(value_);
    }
};

class Arithmetic {
private:

    string input_str;
    string corrected_str;
    string obr_pol_zap_str;
    list<lexem> lexems_of_corrected_str;
    list<lexem> lexems_after_obr_pol_zap;
    double res = 0.0;

    //CHECKERS
    static bool is_it_substr_of_str(const string &str, const string &substr);

    static int count_substr_in_str(const string &str, const string &substr);

    static list<string> find_func_in_str(const string &str);

    static bool ch_skob(const string &str);

    static bool ch_double_dot(const string &str);

    static bool ch_double_znak(const string &str);

    static bool ch_znak_first_elem(const string &str);

    static bool ch_znak_after_skob(const string &str);

    static bool ch_znak_after_operand(const string &str);

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

    static list<lexem> obr_pol_zap_to_lexem(const string &str);

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
    Arithmetic() = default;

    explicit Arithmetic(string str) : input_str(std::move(str)) {};

    ~Arithmetic() = default;

    void launch();

    void print() const;

    void set_input_string(const string &str);

    string get_input_str() const;

    string get_corrected_str() const;

    string get_RPN_str() const;

    list<lexem> get_lexem_list_of_corrected_str() const;

    list<lexem> get_lexem_list_of_RPN_str() const;

    double get_res() const;

    friend int prioretet(const string &s);
};


#endif //MP2_LAB3_ARITHMETIC_ARITHMETIC_H