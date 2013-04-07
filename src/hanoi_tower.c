/*
 ============================================================================
 Name        : HANOI KULELERI
 Author      : Oğuzhan Saltık
 Date		 : 07.04.2013
 ============================================================================
 */

/* KOD ACIKLAMASI
 * Array ile Hanoi Tower daki kuleler temsil edilmektedir.
 * Her hamlede kuleler tekrar yazdırılır ve hamledeki
 * değişiklik array' de goruntulenir.
 */

#include <stdio.h>
#include <stdlib.h>
#define disk_sayisi 3

int kaynak = 1, yardimci = 2, hedef = 3;

/*
 * Platform olarak 3 hanoi kulesi oluşturuldu
 */
typedef struct Platform {

	int bar1[disk_sayisi];
	int bar2[disk_sayisi];
	int bar3[disk_sayisi];

} platform;

/*
 * Array degerlerini ekrana tablo olarak yazar.
 */
void kuleleri_ekrana_yaz(platform y) {

	int sayac;

	printf("|-");
	for (sayac = 0; sayac < disk_sayisi; ++sayac) {
		printf("%d-", y.bar1[sayac]);
	}
	printf(">\n");

	printf("|-");
	for (sayac = 0; sayac < disk_sayisi; ++sayac) {
		printf("%d-", y.bar2[sayac]);
	}
	printf(">\n");

	printf("|-");
	for (sayac = 0; sayac < disk_sayisi; ++sayac) {
		printf("%d-", y.bar3[sayac]);
	}
	printf(">\n\n");
}

/*
 * 	kodun baslangicinda array degerlerini hanoi tower oyununun baslangici gibi ayarlar
 * 	Bir kez baslangicta calisir.
 */
void disk_no_ata(platform *y) {

	int sayac;
	for (sayac = 0; sayac < disk_sayisi; sayac++) {
		y->bar1[sayac] = disk_sayisi - sayac;
		y->bar2[sayac] = 0;
		y->bar3[sayac] = 0;
	}
}

/*
 * Bu fonksiyondaki sayaclar ilgili array'in kacinci elemanina islem yapilmasi gerektigini tutar.
 * Eger islem yapildiysa ilgili arrayin aktarilan elemani yerine '0' gelir.
 * Sayaclar her islem sonunda guncellenir.
 */
void disk_tasi(platform *y) {

	if (kaynak == 1 && hedef == 2) {

		y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3) + 1] =
				y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)];
		y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)] = 0;
	}

	if (kaynak == 1 && hedef == 3) {

		y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3) + 1] =
				y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)];
		y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)] = 0;
	}

	if (kaynak == 2 && hedef == 1) {

		y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3) + 1] =
				y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)];
		y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)] = 0;
	}

	if (kaynak == 2 && hedef == 3) {

		y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3) + 1] =
				y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)];
		y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)] = 0;
	}

	if (kaynak == 3 && hedef == 1) {

		y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3) + 1] =
				y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)];
		y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)] = 0;
	}

	if (kaynak == 3 && hedef == 2) {

		y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3) + 1] =
				y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)];
		y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)] = 0;
	}
}

/*
 * Eger array de 0 adet eleman varsa -1 dondurur.
 * Eger array de 3 adet eleman varsa 2 dondurur.
 */
int sifirdan_farkli_eleman_say(const int a[], int disk) {

	int konum, sayac = -1;

	for (konum = 0; konum < disk; konum++) {

		if (a[konum] != 0) {

			sayac++;
		}
	}
	return sayac;
}

/*
 * Recursive function olarak hanoi tower probleminin cozumunu yapar.
 */
void coz(platform* y, int disk, int kaynak, int yardimci, int hedef) {

	if (disk > 0) {

		coz(y, disk - 1, kaynak, hedef, yardimci);

		printf("Hamle:\t%d -> %d\n", kaynak, hedef);

		if (kaynak == 1 && hedef == 2) {

			y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3) + 1] =
					y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)];
			y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)] = 0;

		}

		if (kaynak == 1 && hedef == 3) {

			y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3) + 1] =
					y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)];
			y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3)] = 0;

		}

		if (kaynak == 2 && hedef == 1) {

			y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3) + 1] =
					y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)];
			y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)] = 0;

		}

		if (kaynak == 2 && hedef == 3) {

			y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3) + 1] =
					y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)];
			y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3)] = 0;

		}

		if (kaynak == 3 && hedef == 1) {

			y->bar1[sifirdan_farkli_eleman_say(y->bar1, 3) + 1] =
					y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)];
			y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)] = 0;

		}

		if (kaynak == 3 && hedef == 2) {

			y->bar2[sifirdan_farkli_eleman_say(y->bar2, 3) + 1] =
					y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)];
			y->bar3[sifirdan_farkli_eleman_say(y->bar3, 3)] = 0;

		}

	//	disk_tasi(y);
		kuleleri_ekrana_yaz(*y);

		coz(y, disk - 1, yardimci, kaynak, hedef);
	}
}

int main() {

	int disk = 3;

	platform *kule;
	kule = (platform*) malloc(sizeof(platform));

	//Kuleler icin baslangicdaki disk numaralarinin atanmasi
	disk_no_ata(kule);

	//Kulelerin ekranda gösterilmesi
	printf("\nKulelerin Durumu\n");
	kuleleri_ekrana_yaz(*kule);

	coz(kule, disk, kaynak, yardimci, hedef);

	return 0;
}
