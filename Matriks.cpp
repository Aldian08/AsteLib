#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int  B[10], jumlah, ganti, hapus, cari, ketemu = 0;

ulangi :

	cout << "Masukkan jumlah data : "; 
	cin >> jumlah;

	if (jumlah > 9 )
	{
		cout << "\nMaaf, max jumlah data adalah 10!\n\n";
		goto ulangi;
	}
	else
	{
		for (int i = 0; i<jumlah; i++)
		{
			cout << "Masukkan data ke-" << i + 1 << " : "; 
			cin >> B[i];
		}

		cout << "\nData yang telah dimasukkan : ";
		for (int j = 0; j<jumlah; j++)
		{
			cout << "\nB[" << j << "]= " << B[j];
		}
	}
	
	cout << "\n\nMasukkan nilai data yang akan diubah = "; cin >> ganti;

	for (int g = 0; g<jumlah; g++)
	{
		if (B[g] == ganti)
		{
			cout << "Masukka nilai baru = "; cin >> B[g];
		}
	}

	cout << "\n\nData setelah diubah";
	for (int h = 0; h<jumlah; h++)
	{
		cout << "\nB[" << h << "]= " << B[h];
	}

	cout << "\n\nMasukkan nilai data yang akan dihapus = "; 
	cin >> hapus;

	for (int j = 0; j < jumlah; j++)
	{
		if (hapus == B[j])
		{
			for (int k = j ; k < jumlah; k++)
			{
				B[k];
			}

			jumlah -= 1;
			break;
		}
	}

	cout << "\n\nData Baru :";
	for (int p = 0; p<jumlah; p++)
	{
		cout << "\nB[" << p << "]= " << B[p];
	}
	
	cout << "\n\nMasukkan nilai data yang akan dicari = "; cin >> cari;

	for (int n = 0; n<jumlah; n++) {
		if (cari == B[n]) {

			cout << "\nNilai " << cari << " ditemukan pada index = " << n <<endl;
			ketemu = 1; 
			break;
		}
	}

	if (ketemu == 0) cout << "Maaf data yang Anda cari tidak ada";

	_getch();
}