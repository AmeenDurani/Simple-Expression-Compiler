#include "lexer.h"
#include <cctype>
#include <iostream>

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

    

} // namespace expr