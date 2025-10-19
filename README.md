# RC4-Encryption-Decryption-C-
# Hướng dẫn dùng chương trình RC4
## Công cụ sử dụng
- Sử dụng cmd (Command Prompt) để dùng lệnh chạy chương trình
- Mở Notepad (hoặc cmd) để theo dõi, chỉnh sửa text được mã hóa, giải mã 
## Các câu lệnh sử dụng trên cmd 
- Bước 1: Lệnh di chuyển đến mục dự án `cd Rc4-cpp`
- Bước 2: Lệnh biên dịch chương trình `make`
- Bước 3: (Nếu dùng Notepad thì bỏ qua): Tạo text mới & viết hoặc ghi đè text trùng tên: `echo <text> > <input.txt>`
  Ví dụ `echo Xin chao! Minh la Khang > plaintext.txt`
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
- In text trên cmd `type <input.txt>`
