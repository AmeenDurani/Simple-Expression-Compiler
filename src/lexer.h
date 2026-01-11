#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <optional>

namespace expr {

    // Supported token type
    enum class TokenType {
    NUMBER,
    PLUS,
    MINUS,
    START,
    SLASH,
    LPAREN,
    RPAREN,
    END_OF_FILE,
    INVALID
    };

    // Token structure
    struct Token {
        TokenType type;     // Token classification
        std::string lexeme; // Original text
        double value;       // Value if applicable
        size_t line;        // Line # for error reporting
        size_t column;      // Col # for error reporting

        Token(TokenType t, std::string lex = "", double val = 0.0, size_t ln = 1, size_t col = 1);
    };

    class Lexer {
    public:
        explicit Lexer(const std::string& source);

        // Get the next token from the input
        Token nextToken();
        
        // Peek at the next token from the input
        Token peekToken();

        // Tokenize the entire input
        std::vector<Token> tokenize();

        // Check if we've reached the end of the input
        bool isAtEnd() const;

    private:
        std::string source_;    // Input string
        size_t current_;        // Current position in source
        size_t line_;           // Current line number 
        size_t column_;         // Current column number

        // Helper functions
        char advance();             // Get next character
        char peek() const;          // Peek at current character
        char peekNext() const;      // Peek at next character
        bool match(char expected);  // Consume if matches
        void skipWhitespace();      // Skip spaces, tabs, newlines

        Token makeToken(TokenType type);                // Generate a token
        Token errorToken(const std::string& message);   // Token error handling
        Token number();                                 // Parse number token
    };

    // Utility functions
    std::string tokenTypeToString(TokenType type);

    // Pretty print token (for debugging)
    void printToken(const Token& token);

} // namespace expr