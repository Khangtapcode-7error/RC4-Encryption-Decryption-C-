# RC4-Encryption-Decryption-C-
# Hướng dẫn dùng chương trình RC4
## Công cụ sử dụng
- Sử dụng cmd (Command Prompt) để dùng lệnh chạy chương trình
- Mở Notepad để theo dõi, chỉnh sửa text được mã hóa, giải mã 
## Các câu lệnh sử dụng
- Bước 1: Lệnh di chuyển đến mục dự án `cd Rc4-cpp`
- Bước 2: Lệnh biên dịch chương trình `make`
### Encrypt
- Lệnh `rc4_encrypt.exe <key> <input.txt> <output.bin>`
Ví dụ: `rc4_encrypt.exe xinchao plaintext.txt ciphertext.bin`
    - Kết quả ciphertext.bin chứa dữ liệu mã hóa, không đọc được trực tiếp
    - Tạo ciphertext_hex.txt in ra kết quả theo Hex để dễ đọc 
### Decrypt
- Lệnh `rc4_decrypt.exe <key> <output.bin> <decrypted.txt>`
Ví dụ: `rc4_decrypt.exe xinchao ciphertext.bin decoded.txt`
    - Kết quả decoded.txt chứa text được giải mã
### Chú ý
- `<key>` của 2 quá trình phải giống nhau
