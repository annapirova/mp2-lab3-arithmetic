#include "arithmetic.h"

int prioretet(const string &s) {
    return !Arithmetic::find_func_in_str(s).empty() ? 4 :
           s == "^" ? 3 :
           s == "*" || s == "/" ? 2 :
           s == "+" || s == "-" ? 1 :
           s == "(" || s == "{" || s == "[" ||
           s == ")" || s == "}" || s == "]" ? 0
                                            : -1;
}

//CHECKERS
bool Arithmetic::is_it_substr_of_str(const string &str, const string &substr) {
    return str.find(substr) != string::npos;
}

int Arithmetic::count_substr_in_str(const string &str, const string &substr) {
    int count = 0;

    for (unsigned long i = 0; i < str.size(); ++i)
        if (str[i] == substr[0])
            if (str.substr(i, substr.size()) == substr) {
                ++count;
                i = i + substr.size() - 1;
            }

    return count;
}

list<string> Arithmetic::find_func_in_str(const string &str) {
    list<string> funcs{
            "sqrt", "exp", "ln",
            "sin", "cos", "tan", "cot", "sec", "csc",
            "arcsin", "arccos", "arctan", "arccot", "arcsec", "arccsc",
            "sinh", "cosh", "tanh", "coth", "sech", "csch",
            "arcsinh", "arccosh", "arctanh", "arccoth", "arcsech", "arccsch"
    };
    list<string> funcs_in_str;
    for (const auto &i: funcs) {
        if (is_it_substr_of_str(str, i)) {
            funcs_in_str.push_back(i);
        }
    }
    return funcs_in_str;
}

bool Arithmetic::ch_skob(const string &str) {
    bool f = true;
    int count_open = 0, count_close = 0;

    for (int i = 0; f && i < str.size(); ++i) {
        if (str[i] == '(') {
            ++count_open;
        }
        if (str[i] == ')') {
            ++count_close;
            f = count_close <= count_open && f;
        }
    }

    return f
           && count_open == count_close
           && !is_it_substr_of_str(str, "()")
           && !is_it_substr_of_str(str, ")(");
}

bool Arithmetic::ch_double_dot(const string &str) {
    return !is_it_substr_of_str(str, "..");
}

bool Arithmetic::ch_double_znak(const string &str) {
    bool have_double_znak = false;
    string znak = "+*-/^";

    for (auto i: znak) {
        for (auto j: znak) {
            if (is_it_substr_of_str(str, string(1, i) + string(1, j))) {
                have_double_znak = true;
            }
        }
    }

    return !have_double_znak;
}

bool Arithmetic::ch_znak_first_elem(const string &str) {
    bool f = true;
    string znak = "+*/^";

    for (int i = 0; f && i < znak.size(); ++i) {
        if (str[0] == znak[i]) {
            f = false;
        }
    }

    return f;
}

bool Arithmetic::ch_znak_after_skob(const string &str) {
    bool f = true;
    string znak = "+*/^";

    for (int i = 0; f && i < znak.size(); ++i) {
        for (int j = 0; f && j < str.size() - 1; ++j) {
            if (str[j] == '(' && str[j + 1] == znak[i]) {
                f = false;
            }
        }
    }

    return f;
}

bool Arithmetic::ch_znak_after_operand(const string &str) {
    bool f = true;
    string znak = "+-*/^";

    if (str.size() <= 2) {
        if (prioretet(string(1, str[0])) == OPERAND) {
            if (prioretet(string(1, str[1])) > OPERAND) {
                f = false;
            }
        }
    } else {
        for (int i = 0; f && i < str.size() - 2; ++i) {
            if (prioretet(string(1, str[i])) == OPERAND) {
                for (int j = 0; f && j < znak.size(); ++j) {
                    if (str[i + 1] == znak[j]) {
                        if (prioretet(string(1, str[i + 2])) != OPERAND
                            && prioretet(string(1, str[i + 2])) != SKOBKA) {
                            f = false;
                        }
                    }
                }
            }
        }
    }

    return f;
}

bool Arithmetic::ch_all_func(const string &str) {
    bool f = true;
    list<string> funcs_in_str = find_func_in_str(str);

    for (const auto &i: funcs_in_str) {
        auto counter = count_substr_in_str(str, i);
        for (int j = 0; j < counter; ++j) {
            auto pos_b = str.find(i);
            auto pos_e = pos_b + i.size();
            if (str[pos_e] != '(') {
                f = false;
            }
        }
    }

    return f;
}

//PREPARE
string Arithmetic::erase_space(const string &str) {
    string str1 = str;
    list<int> space_index;
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] == ' ') {
            space_index.push_back(i);
        }
    }

    int count = 0;
    for (const auto &i: space_index) {
        str1.erase(i - count, 1);
        count++;
    }
    return str1;
}

string Arithmetic::make_unary_minus(const string &str) {
    string str1 = str;
    if (str1[0] == '-') {
        str1 = "0" + str1;
    }
    str1 = regex_replace(str1, regex(R"(\(\-)"), "(0-");
    return str1;
}

//DIVIDE TO LEXEM
list<string> Arithmetic::find_lexem_num_and_var(const string &str, int for_submatch) {
    const regex num_and_var(R"(\w*\.?\w*)");

    list<string> fm_{
            sregex_token_iterator{begin(str), end(str), num_and_var, for_submatch},
            sregex_token_iterator{}
    };
    fm_.pop_back();

    return fm_;
}

list<string> Arithmetic::find_lexem_operations(const string &str, int for_submatch) {
    const regex operations(R"([\+\-\*\/\^\(\)])");

    list<string> fm_{
            sregex_token_iterator{begin(str), end(str), operations, for_submatch},
            sregex_token_iterator{}
    };

    return fm_;
}

list<string> Arithmetic::list_of_tokens(const list<string> &list_num_and_var, const list<string> &list_operations) {
    list<string> tokens;
    list<string> list_operations_ = list_operations;

    for (const auto &i: list_num_and_var) {
        if (!i.empty()) {
            tokens.push_back(i);
        } else {
            tokens.push_back(list_operations_.front());
            list_operations_.pop_front();
        }
    }

    return tokens;
}

list<string> Arithmetic::split_string_to_tokens(const string &str) {
    list<string> list_num_and_var = find_lexem_num_and_var(str);
    list<string> list_operations = find_lexem_operations(str);
    return list_of_tokens(list_num_and_var, list_operations);
}

list<lexem> Arithmetic::token_to_lexem(const list<string> &tokens) {
    list<lexem> lexems;
    for (const auto &i: tokens) {
        lexems.emplace_back(i);
//        lexems.emplace_back(i);
    }
    return lexems;
}

//OBRATNAY POLSKAY ZAPIS
string Arithmetic::obr_pol_zap(const list<lexem> &lst) {
    list<lexem> lexems = lst;
    string out;
    stack<string> stack;
    while (!lexems.empty()) {
        if (lexems.front().type == OPERAND) {
            out += " " + lexems.front().value;
        } else if (lexems.front().type == FUNC) {
//            out += " " + lexems.front().value; // func before operands
            stack.push((lexems.front().value));  // func after  operands (as operations +, -, * and etc)

        } else if (lexems.front().type == SKOBKA) {
            if (lexems.front().value == "(") {
                stack.push(lexems.front().value);
            } else {
                while (stack.top() != "(") {
                    out += " " + stack.top();
                    stack.pop();
                }
                stack.pop();
            }
        } else if (
                lexems.front().type == PLUS_MINUS ||
                lexems.front().type == MUL_DIV ||
                lexems.front().type == POW
                ) {
            if (stack.empty() || lexems.front().type <= prioretet(stack.top())) {
                while (!stack.empty() && lexems.front().type <= prioretet(stack.top())) {
                    out += " " + stack.top();
                    stack.pop();
                }
            }
            stack.push(lexems.front().value);
        }
        lexems.pop_front();
    }
    if (!stack.empty()) {
        while (!stack.empty()) {
            out += " " + stack.top();
            stack.pop();
        }
    }
    return out;
}

list<string> Arithmetic::split(const string &str, char sep) {
    list<string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(sep, start)) != string::npos) {
        if (end != start) {
            tokens.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }
    if (end != start) {
        tokens.push_back(str.substr(start));
    }
    return tokens;
}

list<lexem> Arithmetic::obr_pol_zap_to_lexem(const string &str) {
    return token_to_lexem(split(str, ' '));
}

//CALCULATE
double Arithmetic::calculate_func(const string &str, double x) {
    map<string, function<double(double)>> funcs;
    funcs["sqrt"] = [](double x) { return sqrt(x); };
    funcs["exp"] = [](double x) { return exp(x); };
    funcs["ln"] = [](double x) { return log(x); };
    funcs["sin"] = [](double x) { return sin(x); };
    funcs["cos"] = [](double x) { return cos(x); };
    funcs["tan"] = [](double x) { return tan(x); };
    funcs["cot"] = [](double x) { return 1 / tan(x); };
    funcs["sec"] = [](double x) { return 1 / cos(x); };
    funcs["csc"] = [](double x) { return 1 / sin(x); };
    funcs["arcsin"] = [](double x) { return asin(x); };
    funcs["arccos"] = [](double x) { return acos(x); };
    funcs["arctan"] = [](double x) { return atan(x); };
    funcs["arccot"] = [](double x) { return M_PI / 2.0 - atan(x); };
    funcs["arcsec"] = [](double x) { return acos(1.0 / x); };
    funcs["arccsc"] = [](double x) { return asin(1.0 / x); };
    funcs["sinh"] = [](double x) { return sinh(x); };
    funcs["cosh"] = [](double x) { return cosh(x); };
    funcs["tanh"] = [](double x) { return tanh(x); };
    funcs["coth"] = [](double x) { return 1.0 / tanh(x); };
    funcs["sech"] = [](double x) { return 1.0 / cosh(x); };
    funcs["csch"] = [](double x) { return 1.0 / sinh(x); };
    funcs["arcsinh"] = [](double x) { return log(x + sqrt(x * x + 1)); };
    funcs["arccosh"] = [](double x) { return log(x + sqrt(x * x - 1)); };
    funcs["arctanh"] = [](double x) { return 0.5 * (log(1 + x) - log(1 - x)); };
    funcs["arccoth"] = [](double x) { return 0.5 * (log(1 + x) - log(x - 1)); };
    funcs["arcsech"] = [](double x) { return log(1 + sqrt(1 - x * x)) - log(x); };
    funcs["arccsch"] = [](double x) { return log(1 + sqrt(1 + x * x)) - log(x); };

    return funcs[str](x);
}

double Arithmetic::calculate_operator(const string &str, double x, double y) {
    map<string, function<double(double, double)>> operations;
    operations["+"] = [](double x, double y) { return x + y; };
    operations["-"] = [](double x, double y) { return x - y; };
    operations["*"] = [](double x, double y) { return x * y; };
    operations["/"] = [](double x, double y) { return x / y; };
    operations["^"] = [](double x, double y) { return pow(x, y); };

    return operations[str](x, y);
}

double Arithmetic::calculate(const list<lexem> &lexems_) {
    list<lexem> lexems = lexems_;
    stack<double> stack;

    for (auto &i: lexems) {
        if (i.type == OPERAND) {
            try {
                stack.push(stod(i.value));
            }
            catch (std::invalid_argument const &ex) {
                string tmp;
                cout << "Input value for " << i.value << ": ";
                cin >> tmp;
                cout << endl;
                string tmp_value = i.value;
                for (auto &j: lexems) {
                    if (tmp_value == j.value && i.type == j.type) {
                        j.value = tmp;
                    }
                }
                stack.push(stod(i.value));
            }
        } else if (i.type == PLUS_MINUS || i.type == MUL_DIV || i.type == POW) {
            double num2 = stack.top();
            stack.pop();
            double num1 = stack.top();
            stack.pop();

            stack.push(calculate_operator(i.value, num1, num2));
        } else if (i.type == FUNC) {
            double num1 = stack.top();
            stack.pop();

            stack.push(calculate_func(i.value, num1));
        }
    }

    return stack.top();
}

//ALL//
//check
bool Arithmetic::check_all(const string &str) {
    if (!ch_skob(str)) {
        throw logic_error("ERROR SKOB");
    }
    if (!ch_double_dot(str)) {
        throw logic_error("ERROR DOUBLE DOT");
    }
    if (!ch_double_znak(str)) {
        throw logic_error("ERROR DOUBLE ZNAK");
    }
    if (!ch_znak_first_elem(str)) {
        throw logic_error("ERROR ZNAK AS FIRST ELEM");
    }
    if (!ch_znak_after_skob(str)) {
        throw logic_error("ERROR ZNAK AFTER SKOB");
    }
    if (!ch_znak_after_operand(str)) {
        throw logic_error("ERROR ZNAK AFTER OPERAND");
    }
    if (!ch_all_func(str)) {
        throw logic_error("ERROR DOUBLE FUNC WITHOUT SKOB");
    }
    return true;
    //ch_skob(str) && ch_double_dot(str) && ch_double_znak(str) && ch_all_func(str);
}

//prepare str
void Arithmetic::prepare_str() {
    if (check_all(erase_space(input_str))) {
        corrected_str = erase_space(input_str);
        corrected_str = make_unary_minus(corrected_str);
    }
}

void Arithmetic::make_lexems_of_corrected_str() {
    lexems_of_corrected_str = token_to_lexem(split_string_to_tokens(corrected_str));
}

void Arithmetic::make_obr_pol_zap_str() {
    obr_pol_zap_str = obr_pol_zap(lexems_of_corrected_str);
}

void Arithmetic::make_lexems_after_obr_pol_zap() {
    lexems_after_obr_pol_zap = obr_pol_zap_to_lexem(obr_pol_zap_str);
}

void Arithmetic::make_result() {
    res = calculate(lexems_after_obr_pol_zap);
}

void Arithmetic::launch() {
    if (!input_str.empty()) {
        prepare_str();
        make_lexems_of_corrected_str();
        make_obr_pol_zap_str();
        make_lexems_after_obr_pol_zap();
        make_result();
        //print();
    } else {
        std::cout << "Please, setup input string!" << std::endl;
    }
}

void Arithmetic::print() const {
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

void Arithmetic::set_input_string(const string &str) {
    input_str = str;
}

string Arithmetic::get_input_str() const {
    return input_str;
}

string Arithmetic::get_corrected_str() const {
    return corrected_str;
}

string Arithmetic::get_RPN_str() const {
    return obr_pol_zap_str;
}

list<lexem> Arithmetic::get_lexem_list_of_corrected_str() const {
    return lexems_of_corrected_str;
}

list<lexem> Arithmetic::get_lexem_list_of_RPN_str() const {
    return lexems_after_obr_pol_zap;
}

double Arithmetic::get_res() const {
    return res;
}


