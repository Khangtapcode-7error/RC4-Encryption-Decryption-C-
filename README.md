# RC4-Encryption-Decryption-C++
# Hướng dẫn dùng chương trình RC4
## Công cụ sử dụng
- Sử dụng cmd (Command Prompt) để dùng lệnh chạy chương trình
- Mở Notepad (hoặc cmd) để theo dõi, chỉnh sửa text được mã hóa, giải mã 
## Các câu lệnh sử dụng trên cmd 
- Bước 1: Lệnh di chuyển đến mục dự án `cd Rc4-cpp`
- Bước 2: Lệnh biên dịch chương trình `make`
- Bước 3: (Nếu dùng Notepad thì bỏ qua): Tạo text mới & viết hoặc ghi đè text trùng tên: `echo <text>><input.txt>`
    - Ví dụ `echo Xin chao! Minh la Khang>plaintext.txt`
### Encrypt
- Lệnh `rc4_encrypt.exe <key> <input.txt> <output.bin>`
- Ví dụ: `rc4_encrypt.exe xinchao plaintext.txt ciphertext.bin`
    - Kết quả ciphertext.bin chứa dữ liệu mã hóa, không đọc được trực tiếp
    - Tạo ciphertext_hex.txt in ra kết quả theo Hex để dễ đọc 
### Decrypt
- Lệnh `rc4_decrypt.exe <key> <output.bin> <decrypted.txt>`
- Ví dụ: `rc4_decrypt.exe xinchao ciphertext.bin decoded.txt`
    - Kết quả decoded.txt chứa text được giải mã
### Chú ý
- `<key>` của 2 quá trình phải giống nhau
- In text trên cmd `type <input.txt>`
### Bộ Test
| STT | Key         | Plaintext                    | Ciphertext (hex, chuẩn)                            |
| --- | ----------- | ---------------------------- | -------------------------------------------------- |
| 1   | `Key`       | `Plaintext`                  | `BBF316E8D940AF0AD3`                               |
| 2   | `Wiki`      | `pedia`                      | `1021BF0420`                                       |
| 3   | `Secret`    | `Attack at dawn`             | `45A01F645FC35B383552544B9BF5`                     |
| 4   | `Key`       | `RC4`                        | `EB9F7781B734CA72A719`                             |
| 5   | `Test`      | `1234567890`                 | `7494C2E7104B0879ECA8`                             |
| 6   | `123456`    | `abcdef`                     | `8C7CFFB36F01`                                     |
| 7   | `RC4Test`   | `HELLO`                      | `A6F68D5D03`                                       |
| 8   | `Crypto`    | `Security`                   | `68A2D0E8B3F46A47`                                 |


