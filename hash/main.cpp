#include <iostream>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
 
using namespace std;
int main(){
	ifstream mfile;             //входной поток для чтения файлов
	string str;
	string strs="";
	string file = "mfile.txt";   // инициализация переменной с файлом для хеширования содержимого файла
	mfile.open(file);           // открытие файла
	while (!mfile.eof()) {      // цикл, пока не достигнет конца файла
		getline(mfile, str);    // считываем строку
		strs = strs+str;        
	}
	cout << strs;
	string hashs;
	CryptoPP::Weak1::MD5 hashmd4;  //инициализирование переменной для типа хэша из библиотеки CryptoPP
	CryptoPP::StringSource(strs, true, new CryptoPP::HashFilter(hashmd4,new CryptoPP::HexEncoder(new CryptoPP::StringSink(hashs)))); //вычисление хэша от всех считанных строк с помощью библиотеки
	cout << endl<<hashs<<endl; //вывод хеша
}