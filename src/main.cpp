#include "lexer.h"
#include <iostream>
#include <string>

using namespace expr;

void testLexer(const std::string& input) {
    std::cout << "\n=== Testing: \"" << input << "\" ===\n";

    Lexer lexer(input);
    std::vector<Token> tokens = lexer.tokenize();

    for (const auto& token: tokens) {
        printToken(token);
    }
}

void interactiveMode() {
    std::cout << "Simple Expression Compiler - Lexer Test\n";
    std::cout << "Enter expressions to tokenize (or 'quit' to exit):\n\n";

    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            break;
        }
        
        if (line == "quit" || line == "exit") {
            break;
        }
        
        if (line.empty()) {
            continue;
        }
        
        Lexer lexer(line);
        std::vector<Token> tokens = lexer.tokenize();
        
        std::cout << "Tokens:\n";
        for (const auto& token : tokens) {
            printToken(token);
        }
        std::cout << "\n";
    }
    
    std::cout << "Goodbye!\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string input = argv[1];
        testLexer(input);
        return 0;
    }

    interactiveMode();
    return 0;
}