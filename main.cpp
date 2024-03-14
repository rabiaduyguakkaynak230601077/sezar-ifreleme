#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// �ifreleme fonksiyonu,  parametre olarak �ifrelenecek metni (metin) ve �ifreleme i�in kullan�lacak kayd�rma miktar�n� (kaydirma) al�r.
string sifrele(string metin, int kaydirma) {
    string sonuc = "";

    for (int i = 0; i < metin.length(); i++) {
        // B�y�k harfleri �ifreler
        if (isupper(metin[i]))//if (isupper(metin[i])): Bu ko�ul, metin i�indeki karakterin b�y�k harf olup olmad���n� kontrol eder. 
            sonuc += char(int(metin[i] + kaydirma - 65) % 26 + 65);//B�y�k harfleri �ifrelemek i�in, ASCII de�erlerini kullanarak bir kayd�rma yap�l�r.
        // K���k harfleri �ifreler
        else if (islower(metin[i]))// Bu ko�ul, karakterin k���k harf olup olmad���n� kontrol eder. E�er karakter bir k���k harfse, �ifreleme i�lemi uygulan�r.
            sonuc += char(int(metin[i] + kaydirma - 97) % 26 + 97); /*K���k harfleri �ifrelemek i�in, b�y�k harflerde oldu�u gibi ASCII de�erlerini kullanarak bir kayd�rma yap�l�r.
			 Ancak, k���k harfler i�in kayd�rma i�lemi 97 (ASCII'de 'a' harfinin de�eri) baz al�narak yap�l�r. */
        // Di�er karakterleri de�i�tirmeden ekler
        else
            sonuc += metin[i];// B�y�k ya da k���k harf de�ilse karakter de�i�tirilmeden sonuc dizisine eklenir.
    }

    return sonuc;
}

/*De�ifreleme fonksiyonu Parametre olarak de�ifre edilecek metni (metin) ve �ifreleme i�in kullan�lan kayd�rma miktar�n� (kaydirma) al�r.
Metni de�ifrelemek i�in sifrele fonksiyonunu tersine �evirir ve de�ifrelenmi� metni geri d�nd�r�r.*/
string desifrele(string metin, int kaydirma) {
    // �ifreleme i�lemi tersine �evrilerek de�ifre eder.
    return sifrele(metin, 26 - kaydirma);
}

int main() {
    string girisMetni;
    int kaydirmaorani;
    
    // Kullan�c�dan giri� metnini ve kayd�rma oran�n� al�p kayd�r�r.
    cout << "Sifrelenecek metni girin: ";
    getline(cin, girisMetni);
    
    cout << "Kayd�rma oranini girin: ";
    cin >> kaydirmaorani;
    
    // �ifreleme i�lemini yapan fonksiyon
    string sifrelenmisveri = sifrele(girisMetni, kaydirmaorani);
    cout << "Sifrelenmis metin: " << sifrelenmisveri << endl;
    
    // De�ifreleme i�lemi yapan fonksiyon
    string desifrelenmisveri = desifrele(sifrelenmisveri, kaydirmaorani);
    cout << "Desifrelenmis metin: " << desifrelenmisveri << endl;
    
    // Dosyaya �ifrelenmi� metni yaz
    ofstream ciktiDosyasi("sifrelenmis_metin.txt");
    if (ciktiDosyasi.is_open()) {
        ciktiDosyasi << sifrelenmisveri;
        ciktiDosyasi.close();
        cout << "Sifrelenmis metin dosyaya yazildi." << endl;
    } else {
        cout << "Dosya acilmiyor." << endl;
    }
    
    return 0;
}
