#include "RC4.h"
#include <fstream>
#include <iostream>
#include <iomanip>  // thêm để dùng std::setw và std::setfill

RC4::RC4(const std::string& key) : i(0), j(0) {
    ksa(key);
}

void RC4::ksa(const std::string& key) {
    for (int i = 0; i < 256; ++i)
        S[i] = static_cast<unsigned char>(i);

    unsigned int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + static_cast<unsigned char>(key[i % key.size()])) & 0xFF;
        std::swap(S[i], S[j]);
    }
}

unsigned char RC4::prga() {
    i = (i + 1) & 0xFF;
    j = (j + S[i]) & 0xFF;
    std::swap(S[i], S[j]);
    return S[(S[i] + S[j]) & 0xFF];
}

void RC4::process(std::vector<unsigned char>& data) {
    for (auto& byte : data) {
        byte ^= prga();
    }
}

bool RC4::processFile(const std::string& key,
                      const std::string& inputPath,
                      const std::string& outputPath) {
    std::ifstream in(inputPath, std::ios::binary);
    if (!in.is_open()) {
        std::cerr << "Khong the mo file dau vao: " << inputPath << "\n";
        return false;
    }

    std::vector<unsigned char> buffer((std::istreambuf_iterator<char>(in)),
                                      std::istreambuf_iterator<char>());
    in.close();

    RC4 rc4(key);
    rc4.process(buffer);

    std::ofstream out(outputPath, std::ios::binary);
    if (!out.is_open()) {
        std::cerr << "Khong the mo file dau ra: " << outputPath << "\n";
        return false;
    }
    out.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
    out.close();

    return true;
}

/* ---------- Project-specific functions ---------- */

static void printUsage(const std::string& prog, const std::string& action) {
    std::cout << "Cach dung: " << prog << " <key> <input_file> <output_file>\n"
              << "Thuc hien RC4 " << action << " tren file.\n";
}

int rc4_encrypt_file(int argc, char** argv) {
    if (argc != 4) {
        printUsage(argv[0], "ma hoa");
        return 1;
    }
    if (RC4::processFile(argv[1], argv[2], argv[3])) {
        std::cout << "Ma hoa thanh cong!\n";

        // Đọc lại ciphertext.bin và in ra dạng hex
        std::ifstream in(argv[3], std::ios::binary);
        std::vector<unsigned char> data((std::istreambuf_iterator<char>(in)),
                                        std::istreambuf_iterator<char>());
        in.close();

        std::ofstream out("ciphertext_hex.txt");
        for (unsigned char c : data) {
            out << std::hex << std::setw(2) << std::setfill('0') << (int)c;
        }
        out.close();

        std::cout << "Da luu dang hex vao ciphertext_hex.txt\n";
    }
        
    else
        std::cerr << "Loi ma hoa.\n";
    return 0;
}

int rc4_decrypt_file(int argc, char** argv) {
    if (argc != 4) {
        printUsage(argv[0], "giai ma");
        return 1;
    }
    if (RC4::processFile(argv[1], argv[2], argv[3]))
        std::cout << "Giai ma thanh cong!\n";
    else
        std::cerr << "Loi giai ma.\n";
    return 0;
}

void saveToHexFile(const std::vector<unsigned char>& data, const std::string& filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Khong the mo file de: " << filename << std::endl;
        return;
    }
    for (unsigned char c : data) {
        out << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    out.close();
}

