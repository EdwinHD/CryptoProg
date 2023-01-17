#include <iostream>
#include <fstream>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/hex.h>
#include "cryptopp/aes.h"
#include "cryptopp/modes.h"

using namespace std;
using namespace CryptoPP;

void encrypt() {
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file;
    cout << "Введите имя файла, откуда считать текст:";
    cin >> file;
    fs.open(file); 
    char ch;
    while (fs.get(ch)) {
        strs.push_back(ch); // пока есть данные для считывания, мы добавляем в строку str считанный символ
    }
    byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE]; //опередляем массив byte бля ключа шифрования и для размера блока
    memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH); //инициализируем память под ключ
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);  // под блок
    string plaintext = strs;
    string ciphertext;
    cout << "Plain Text (" << plaintext.size() << " bytes)" <<endl;
    cout << plaintext;
    cout << endl;
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH); //инициализируем объект класса шифрования из библиотеки CRyptoPP
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv); //инициализируем объект класса для блочного шифрования
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext)); //инициализируем объект класса для симметричного шифрования
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length()); //заполняем шифратор текстом с файла с помощью stfEncryptor
    stfEncryptor.MessageEnd(); //шифрование
    cout << "Cipher Text (" << ciphertext.size() << " bytes)" << endl; //вывод размера зашифрованного текста в байтах
    for (int i = 0; i < ciphertext.size(); i++) {
        cout << hex << (0xFF & static_cast<byte>(ciphertext[i])); //вывод в 16 ричном виде зашифрованного сообщения
    }
    cout << "\nВыберите файл куда записать: ";
    string imp, file2;
    cin >> file2;
    fs2.open(file2);
    for (int i = 0; i < ciphertext.size(); i++) {
        fs2 << ciphertext[i];
    }
}
void decrypt() {
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file;
    cout << "Введите имя файла, откуда считать текст:";
    cin >> file;
    fs.open(file);
    char ch;
    while (fs.get(ch)) {
        strs.push_back(ch);
    }
	byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
    string plaintext = strs;
    string decryptedtext;
    cout << "Plain Text (" << plaintext.size() << " bytes)" << endl;
    cout << plaintext;
    cout << endl;
    string imp, file2;
    cout << "Выберете файл куда записать: ";
    cin >> file2;
    fs2.open(file2);
    fs3.open(file2);
    cout << endl;
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH); //создаем объект класса для дешифрования с использованием ключа
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv); //создаем объект класса для блочного дешифрования
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext)); //инициализируем объект класса для симметричного дешифрования
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size());
    stfDecryptor.MessageEnd();
    cout << decryptedtext << endl;
    fs2 << decryptedtext;
}

int main()
{
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file, str9;
    string t;
    int k, key;
    cout << "Ведите ключ: ";
    cin >> key;
            do {
                cout << "Введите 1 - шифровать или 2 -расшифровать 0 - выйти:";
                cin >> k;
                if (k == 1) {
                    encrypt();
                }
                else  if (k == 2) {
                    decrypt();
                }
            } while (k != 0);
    return 0;
}
