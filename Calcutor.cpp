#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


void gecmisEkle(vector<string>& liste, string islem) {
	if (liste.size() >= 3) {
		liste.erase(liste.begin());  // En eski kaydı sil
	}
	liste.push_back(islem);          // Yeni kaydı ekle
}
void gecmisGoster(vector<string>& liste) {
	system("cls");
	cout << "|=====================|" << endl;
	cout << "|       GECMIS        |" << endl;
	cout << "|=====================|" << endl;

	if (liste.empty()) {
		cout << "|  Gecmis bos.        |" << endl;
	}
	else {
		for (int i = 0; i < liste.size(); i++) {
			cout << "|  " << i + 1 << ". " << liste[i] << endl;
		}
	}

	cout << "|=====================|" << endl;
	system("pause");
}

enum isaret { toplama, carpma, cikarma, bolme, gecmis, cikis };

template <typename index>

class operation
{
private:

	index sonuc;

public:


	index toplama(index a, index b) {
		sonuc = a + b ;
		return sonuc;
	}
	index carpma(index a, index b) {
		sonuc = a * b;
		return sonuc;
	}
	index cikarma(index a, index b) {
		sonuc = a - b;
		return sonuc;
	}
	index bolme(index a, index b) {
			if (b == 0) {
				cout << "0'a bolunemez" << endl;
			}
			sonuc = a / b;
			return sonuc;
	}

	index getsonuc(){
		return sonuc;
	}

	void menuciz() {
		cout << "|=====================|" << endl;
		cout << "|    HESAP MAKINESI   |" << endl;
		cout << "|=====================|" << endl;
		cout << "|    1.TOPLAMA        |" << endl;
		cout << "|    2.CIKARMA        |" << endl;
		cout << "|    3.CARPMA         |" << endl;
		cout << "|    4.BOLME          |" << endl;
		cout << "|    5.GECMIS         |" << endl;
		cout << "|    6.CIKIS          |" << endl;
		cout << "|=====================|" << endl;

	}

};

// girilen sayıyı string olan s karakterine dönüştürüyor her rakamı mesela 3.14 "3",".","1","4" oluyor. 
//eğer ondalıklıysa 1 değerini veriyor.
bool noktakontrol(string s) {
	for (char c : s)
		if (c == '.')return true;
	return false;

}

isaret secimBelirle(string yazi) {
	if (yazi == "1" || yazi == "toplama") return toplama;
	if (yazi == "2" || yazi == "cikarma") return cikarma;
	if (yazi == "3" || yazi == "carpma")  return carpma;
	if (yazi == "4" || yazi == "bolme")   return bolme;
	if (yazi == "5" || yazi == "gecmis")  return gecmis;
	if (yazi == "6" || yazi == "cikis")   return cikis;
	cout << "Gecersiz secim!" << endl;
	exit(0);
}
int main()
{
	vector<string> gecmisListesi;
	
	operation<int> menu;
	while (true) {
		menu.menuciz();

		string secimyazi;
		cout << "yapmak istediginiz islemi secin:";
		cin >> secimyazi;
		isaret secim = secimBelirle(secimyazi);

		if (secim == cikis) {
			cout << "Cikiliyor..." << endl;
			break;   // Döngüden çık, program biter
		}

		if (secim == gecmis) {
			gecmisGoster(gecmisListesi);
			continue;  // Döngü başına dön, değer isteme!
		}

		string girdi1, girdi2;
		cout << "1. Deger : ";
		cin >> girdi1;
		cout << "2. Deger : ";
		cin >> girdi2;
		// geçmişe ekleme yapmak için sonuc diye bir double atadık
		double sonuc;

		string islemSembol;
		if (secim == toplama) islemSembol = " + ";
		else if (secim == cikarma) islemSembol = " - ";
		else if (secim == carpma)  islemSembol = " * ";
		else if (secim == bolme)   islemSembol = " / ";

		if (noktakontrol(girdi1) || noktakontrol(girdi2)) {
			operation<double> hesap;
			double a = stod(girdi1);
			double b = stod(girdi2);

			switch (secim) {
			case toplama: sonuc = hesap.toplama(a, b); break;
			case cikarma: sonuc = hesap.cikarma(a, b); break;
			case carpma:  sonuc = hesap.carpma(a, b);  break;
			case bolme:   sonuc = hesap.bolme(a, b);   break;
			default: break;
			}
		}
		else {
			operation<int> hesap;
			int a = stoi(girdi1);
			int b = stoi(girdi2);

			switch (secim) {
			case toplama: sonuc = hesap.toplama(a, b); break;
			case cikarma: sonuc = hesap.cikarma(a, b); break;
			case carpma:  sonuc = hesap.carpma(a, b);  break;
			case bolme:   sonuc = hesap.bolme(a, b);   break;
			default: break;
			}
		}

		cout << "Sonuc: " << sonuc << endl;

		// ✓ Tam işlemi string olarak geçmişe ekle
		string kayit = girdi1 + islemSembol + girdi2 + " = " + to_string(sonuc);
		gecmisEkle(gecmisListesi, kayit);

		system("pause");
		}
	
		return 0;


}
