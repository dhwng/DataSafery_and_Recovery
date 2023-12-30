#include "Crypto.h"

#include <openssl/aes.h>

std::string Crypto::encrypt(const std::string& plaintext) {
    // tao 1 random 256-bit key
    unsigned char key[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);

    // tao  AES-256 cipher context
    AES_KEY enc_key;
    AES_set_encrypt_key(key, AES_BLOCK_SIZE * 8, &enc_key);

    // encrypt  plaintext
    unsigned char ciphertext[plaintext.size() + AES_BLOCK_SIZE];
    AES_encrypt((unsigned char*)plaintext.c_str(), ciphertext, &enc_key);

    // tra ve ciphertext duoi dang base64-encoded string
    return Utils::base64_encode(ciphertext, plaintext.size() + AES_BLOCK_SIZE);
}

std::string Crypto::decrypt(const std::string& ciphertext) {
    // Decode  ciphertext 
    unsigned char* decoded_ciphertext = Utils::base64_decode(ciphertext);

    // tao  AES-256 cipher context
    AES_KEY dec_key;
    AES_set_decrypt_key(decoded_ciphertext, AES_BLOCK_SIZE * 8, &dec_key);

    // Decrypt ciphertext
    unsigned char plaintext[strlen((char*)decoded_ciphertext) - AES_BLOCK_SIZE];
    AES_decrypt(decoded_ciphertext + AES_BLOCK_SIZE, plaintext, &dec_key);

    // giai phong bo nho
    free(decoded_ciphertext);

    // return  plaintext duoi dang 1 string
    return std::string((char*)plaintext);
}