//
// Created by montaha rayyan on 6/11/22.
//

#ifndef PLAYER_CPP_EXCEPTION_H
#define PLAYER_CPP_EXCEPTION_H

#include <exception>
#include <cstring>


class Exception : public std::exception {
};

class DeckFileNotFound : public Exception {
    const char *what() const noexcept override {
        return "Deck File Error: File not found";
    }
};

class DeckFileInvalidSize : public Exception {
    const char *what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};

class DeckFileFormatError : public Exception {
public:

    explicit DeckFileFormatError(int lineNum) {
        m_message = "Deck File Error: File format error in line ";
        std::string line = std::to_string(lineNum);
        m_message += line;
//        std::cout << " montaha debug " << m_message <<std::endl;
    };

    const char *what() const noexcept override {

        return m_message.c_str();
    }
private:
    std::string m_message;
};

class InvalidType : public Exception {
};

#endif //PLAYER_CPP_EXCEPTION_H
