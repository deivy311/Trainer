#include <iostream>
// Define FUNC_SIG macro based on the compiler
#if defined(_MSC_VER)
    #define FUNC_SIG __FUNCSIG__
#elif defined(__GNUC__) || defined(__clang__)
    #define FUNC_SIG __PRETTY_FUNCTION__
#else
    #define FUNC_SIG __func__
#endif

class EvaluationOrder {
public:
    EvaluationOrder& First(int) {
        std::cout << FUNC_SIG << std::endl; // Use FUNC_SIG here
        return *this;
    }
    EvaluationOrder& Second(int) {
        std::cout << FUNC_SIG << std::endl; // Use FUNC_SIG here
        return *this;
    }
};

int FirstSubExpression(int) {
    std::cout << FUNC_SIG << std::endl; // Use FUNC_SIG here
    return 0;
}

int SecondSubExpression(int) {
    std::cout << FUNC_SIG << std::endl; // Use FUNC_SIG here
    return 0;
}

int main() {
    EvaluationOrder eo;
    eo.First(FirstSubExpression(0)).Second(SecondSubExpression(0));
}
