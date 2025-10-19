#ifndef RC4_H
#define RC4_H

#include <string>
#include <vector>

class RC4 {
public:
    RC4(const std::string& key);
    void process(std::vector<unsigned char>& data);

    static bool processFile(const std::string& key,
                            const std::string& inputPath,
                            const std::string& outputPath);

private:
    void ksa(const std::string& key);
    unsigned char prga();

    unsigned char S[256];
    unsigned int i, j;
};

// Các hàm tiện ích dành riêng cho 2 project
int rc4_encrypt_file(int argc, char** argv);
int rc4_decrypt_file(int argc, char** argv);

#endif
