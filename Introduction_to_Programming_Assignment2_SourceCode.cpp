/****************************************************************************
**					       SAKARYA �N�VERS�TES�
**			        B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				         PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 2
**				��RENC� ADI......: Davud Samed Tombul
**				��RENC� NUMARASI.: B171210007
**				DERS GRUBU.......: 1D
****************************************************************************/



#include<iostream>//Cout gibi temel komutlar� kullanmam�z i�in gerekli k�t�phane.
#include<locale.h>//T�rk�e harfleri ekrana yazd�rabilmek i�in kullad���m�z k�t�phane.
#include<iomanip>//Setw() manip�lat�r�n� kullanabilmemiz i�in gerekli k�t�phane.
#include<time.h>//srand(time(NULL)) komutunu kullanabilmek i�in gerekli k�t�phane.

//Her temel komuttan �nce std:: yazmakla vakit kaybetmemek ama�l� kullan�yoruz. 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	//Rand() komutu ile atad���m�z de�erlerin program�n bir sonraki �al��mas�nda s�f�rlan�p yeniden atanmas�n� sa�lar.
	srand(time(NULL));

	int sayi, sayac = 0;
	char Harf[5][10];

	//�� i�e d�ng�ler ile olu�turdu�umuz matrisin elemanlar� atan�yor.
	for (int satir = 0; satir < 5; satir++)
	{
		for (int s�tun = 0; s�tun < 10; s�tun++)
		{
			sayac = 0;
			//S�tunlar�n �ift rakamdan olu�tu�u yerlere b�y�k harfler atan�yor.
			if (s�tun % 2 == 0)
				sayi = 65 + rand() % 26;
			//S�tunlar�n tek rakamdan olu�tu�u yerlere b�y�k harfler atan�yor.
			else if (s�tun % 2 != 0)
				sayi = 97 + rand() % 26;

			Harf[satir][s�tun] = char(sayi);

			//Matris'e atanan 2. de�erden itibaren atanacak de�erin tekrar�n�n olup olmad��� kontol ediliyor.
			if (satir + s�tun != 0)
			{
				for (int k = 0; k <= satir; k++)
				{
					for (int t = 0; t < 10; t++)
					{//Matris'e atanacak de�erden daha �nce �retildiyse sayac 1 artt�r�l�yor.
						if (sayi == Harf[k][t])
							sayac++;
					}
				}//Atanan son de�erin tekrar� kontrol edildi. Kontol kendisine geldi�inde sayac 1 artt�. O say�dan 1 tane daha var ise sayac 2 oldu.
				//Sayac'�n 2 olmas� son de�erin �nceden �retildi�ini belitir. Ve son de�eri tekrar �retmek i�in s�tun say�s� 1 azalt�l�r.
				if (sayac == 2)
					s�tun--;
			}
		   
		}
	}

	cout << setw(35) << " ---Rastgele Harfler--- " << endl;
	//Matris'e kar���k �ekilde atanan elemanlar aralar�na ayn� miktarda bo�luk b�rak�larak ekrana yazd�r�l�r.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(5) << Harf[i][j];
		}
		cout << endl;
	}
	
	//Matris'e kar���k atad���m�z elemanlar� ascii kodlar�n� k�yaslayarak s�ral�yoruz. S�ralama yaparken BUBBLE SORT metodunu kuland�m.
	for (int t = 0; t < 5; t++)
	{
		for (int k = 0; k < 5; k++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int i = 0; i < 10; i++)
				{
					if (Harf[t][j] < Harf[k][i])
					{//S�ralama esnas�nda sayi adl� de�i�keni elemanlar�n yerlerini de�i�tirirken kulland�k.
						sayi = Harf[t][j];
						Harf[t][j] = Harf[k][i];
						Harf[k][i] = sayi;
					}
				}
			}
		}
	}

	cout << endl;

	cout << setw(35) << "--- S�ral� Harfler ---" << endl;
	
	//Bubble sort metodunu kullanarak s�ralad���m�z harfleri ekrana yazd�r�yoruz.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(5) << Harf[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
