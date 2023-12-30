// Crypto.h
#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

class Crypto {
public:
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);
};

#endif