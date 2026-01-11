#include "lexer.h"
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

namespace expr {

    Lexer::Lexer(const std::string& source) 
        : source_(source), current_(0), line_(0), column_(0) {}

    bool Lexer::isAtEnd() const {
        return current_ >= source_.length();
    }

    char Lexer::advance() {
        if (isAtEnd()) return '\0';
        char c = source_[current_++];
        ++column_;
        return c;
    }

    char Lexer::peek() const {
        return (isAtEnd()) ? '\0' : source_[current_];
    }

    char Lexer::peekNext() const {
        return (isAtEnd()) ? '\0' : source_[current_ + 1];
    }

    bool Lexer::match(char expected) {
        return source_[current_] == expected;
    }

    void Lexer::skipWhitespace() {
        while (!isAtEnd()) {
            char c = source_[current_];
            switch (c) {
                case ' ':   [[fallthrough]];
                case '\t':  [[fallthrough]];
                case '\r': 
                    advance();
                    break;
                case '\n':
                    ++line_;
                    column_ = 0;
                    advance();
                    break;
                default:
                    return;
            }
        }
    }

    Token Lexer::makeToken(TokenType type) {
        return Token(type);
    }

    Token Lexer::errorToken(const std::string& message) {
        return Token(TokenType::INVALID, message, 0.0, line_, column_);
    }

    Token Lexer::number() {
        size_t start = current_;

        while (std::isdigit(peek())) {
            advance();
        }

        // Extract the number string and convert to double
        std::string numStr = source_.substr(start, current_ - start);
        double val = std::stod(numStr);

        return Token(TokenType::NUMBER, numStr, val, line_, column_);
    }

    Token Lexer::nextToken() {
        skipWhitespace();

        if (isAtEnd()) {
            return makeToken(TokenType::END_OF_FILE);
        }

        char c = advance();

        switch (c) {
            case '+': return makeToken(TokenType::PLUS);
            case '-': return makeToken(TokenType::MINUS);
            case '*': return makeToken(TokenType::STAR);
            case '/': return makeToken(TokenType::SLASH);
            case '(': return makeToken(TokenType::LPAREN);
            case ')': return makeToken(TokenType::RPAREN);    
        }

        if (std::isdigit(c)) {
            return number();
        }

        return errorToken("Unexpected character " + std::string(1, c));
    }

    Token Lexer::peekToken() {
        size_t curr = current_;
        size_t ln = line_;
        size_t col = column_;
        
        Token token = nextToken();

        current_ = curr;
        line_ = ln;
        column_ = col;
        
        return token;
    }

    std::vector<Token> Lexer::tokenize() {
        std::vector<Token> tokens;

        if (isAtEnd()) {
            tokens.push_back(makeToken(TokenType::END_OF_FILE));
            return tokens;
        }

        while (!isAtEnd()) {
            Token token = nextToken();
            tokens.push_back(token);

            if (token.type == TokenType::INVALID ||
                token.type == TokenType::END_OF_FILE) {
                break;
            }
        }

        return tokens;
    }

} // namespace expr