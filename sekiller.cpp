#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

// pi sayisi

#define PI 3.141592

// Ekran Boyutu 

#define BOYUT_X 800
#define BOYUT_Y 800

int matris[BOYUT_X][BOYUT_Y];
void renkDegis(int x, int y, int oldColor, int newColor);
void Doldur(int x0, int y0, int x1, int y1, int eskiRenk);

// Line Algorithm

void Cizgi(int x0, int y0, int x1, int y1, int color) {

  int delta_x = abs(x1 - x0); 
  int delta_y = abs(y1 - y0);
  
  int sx = x0 < x1 ? 1 : -1;
  int sy = y0 < y1 ? 1 : -1;
  
  int error = (delta_x > delta_y ? delta_x : -delta_y) / 2;
  int e2;

  while(1){ 
    putpixel(x0, y0, color);
    if (x0 == x1 and y0 == y1) break;
    e2 = error;
    if (e2 > -delta_x){
		error -= delta_y;
		x0 += sx; 
	}
    if (e2 < delta_y){
		error += delta_x;
		y0 += sy;
	}
  }
}

// Daire Algoritmasi

void Daire(int xmerkez, int ymerkez, int r, int color){
	for(int y = -r; y <= r; y++){
		for(int x = -r; x <= r; x++){
			if(x * x + y * y <= r * r){
				putpixel(x + xmerkez, y + ymerkez, color);
			}
		}
	}
}

// Disk Algoritmasi

 void Disk(int xmerkez, int ymerkez, int R, int r, int color, int color2){
	Daire(xmerkez, ymerkez, R, color);
	Daire(xmerkez, ymerkez, r, color2);
}

// Circle Algorithm 

void Cember(int xmerkez, int ymerkez, int R, int color){
	Disk(xmerkez, ymerkez, R, R-1, color, getbkcolor());
}

// Dikdörtgen Algoritmasi

void Dikdortgen(int x0, int y0, int x1, int y1, int doluMu, int color){
	Cizgi(x0, y0, x0, y1, color);
	Cizgi(x0, y0, x1, y0, color);
	Cizgi(x0, y1, x1, y1, color);
	Cizgi(x1, y0, x1, y1, color);
	
	if(doluMu){
		Doldur(x0, y0 - 1, x1, y1, color);
	}	
}

// Kare Algoritmasi

void Kare(int x0, int y0, int kenar, int doluMu, int color){
	Cizgi(x0, y0, x0, y0 + kenar, color);
	Cizgi(x0, y0, x0 + kenar, y0, color);
	Cizgi(x0, y0+kenar, x0 + kenar, y0 + kenar, color);
	Cizgi(x0 + kenar, y0, x0 + kenar, y0 + kenar, color);
	
	if(doluMu){
		Doldur(x0 - 1, y0 - 1, x0 + kenar + 1, y0 + kenar + 1, color);
	}
}

// Üçgen Algoritmasi

void Ucgen(int x0, int y0, int x1, int y1, int x2, int y2, int doluMu, int color){
	Cizgi(x0, y0, x1, y1, color); 
	Cizgi(x0, y0, x2, y2, color); 
	Cizgi(x1, y1, x2, y2, color); 
	
	int enBuyukX, enBuyukY, enKucukX, enKucukY;
	if(x0 > x1){
		if(x0 > x2) enBuyukX = x0;
		else if(x0 <= x2) enBuyukX = x2;
	}
	else if(x1 > x2){
		enBuyukX = x1;
	}
	else enBuyukX = x2;
	
	if(y0 > y1){
		if(y0 > y2) enBuyukY = y0;
		else if(y0 <= y2) enBuyukY = y2;
	}
	else if(y1 > y2){
		enBuyukY = y1;
	}
	else enBuyukY = y2;
	
	if(x0 < x1){
		if(x0 < x2) enKucukX = x0;
		else if(x0 >= x2) enKucukX = x2;
	}
	else if(x1 < x2){
		enKucukX = x1;
	}
	else enKucukX = x2;
	
	if(y0 < y1){
		if(y0 < y2) enKucukY = y0;
		else if(y0 >= y2) enKucukY = y2;
	}
	else if(y1 < y2){
		enKucukY = y1;
	}
	else enKucukY = y2;
		
	if(doluMu){
		Doldur(enKucukX - 1, enKucukY - 1, enBuyukX + 1, enBuyukY + 1, color);
	}
}

// Yýldýz Algoritmasi

void Yildiz(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8, int x9, int y9, int x10, int y10, int color){
	Cizgi(x0, y0, x1, y1, color);
	Cizgi(x1, y1, x2, y2, color);
	Cizgi(x2, y2, x3, y3, color);
	Cizgi(x3, y3, x4, y4, color);
	Cizgi(x4, y4, x5, y5, color);
	Cizgi(x5, y5, x6, y6, color);
	Cizgi(x6, y6, x7, y7, color);
	Cizgi(x7, y7, x8, y8, color);
	Cizgi(x8, y8, x9, y9, color);
	Cizgi(x9, y9, x10, y10, color);
	Cizgi(x10, y10, x0, y0, color);
	
	int doluMu;
	
	printf("\nYildiz Dolu mu Bos mu (1 / 0) : ");
	scanf("%d", &doluMu);
	
	if(doluMu){
		renkDegis(x1 + 3, y1 + 5, getbkcolor(), color);
	}
}

// Poligon Algoritmasi

void Poligon(int color){
	int koseSayisi;
	int kose_x[2], kose_y[2];
	printf("\nCizilmesini istediginiz poligonun kaç kosesi var : ");
	scanf("%d", &koseSayisi);
	int i = 0;
	printf("\n%d. Kose noktalarini giriniz (x y): ", i + 1);
	scanf("%d %d", &kose_x[i % 2], &kose_y[i % 2]);
	i++;
	while(1){
		
		printf("\n%d. Kose noktalarini giriniz (x y): ", i + 1);
		scanf("%d %d", &kose_x[i % 2], &kose_y[i % 2]);
		Cizgi(kose_x[0], kose_y[0], kose_x[1], kose_y[1], color);
		i++;
		if(i == koseSayisi + 1){
			break;
		}
	}
	
}

// Bezier Eðri Algoritmasi

void Bezier(int color){
	
	int x[4], y[4];
	
	printf("\nIlk noktayi frame uzerinden secin");
	getche();
	getmouseclick(WM_LBUTTONDOWN, x[0], y[0]);
	
	printf("\nIkinci noktayi frame uzerinden secin");
	getche();
	getmouseclick(WM_LBUTTONDOWN, x[1], y[1]);
	
	printf("\nUcuncu noktayi frame uzerinden secin");
	getche();
	getmouseclick(WM_LBUTTONDOWN, x[2], y[2]);
	
	printf("\nDorduncu noktayi frame üzerinden secin");
	getche();
	getmouseclick(WM_LBUTTONDOWN, x[3], y[3]);
	
    double xu = 0.0 , yu = 0.0 , u = 0.0;
    int i = 0;
    for(u = 0.0 ; u <= 1.0 ; u += 0.0001){
        xu = pow(1 - u, 3) * x[0] + 3 * u * pow(1 - u, 2) * x[1] + 3 * pow(u, 2) * (1 - u) * x[2] + pow(u, 3) * x[3];
        yu = pow(1 - u, 3) * y[0] + 3 * u * pow(1 - u, 2) * y[1] + 3 * pow(u, 2) * (1 - u) * y[2] + pow(u, 3) * y[3];
        putpixel((int) xu , (int) yu, color);
    }
}

// Elips Algoritmasi 

void Elips(int color){
	
    long x, y, x_center, y_center, doluMu;
    long a_sqr, b_sqr, fx, fy, d, a, b, tmp1, tmp2;
   
    printf("\nX ve Y noktalarini giriniz : (x y) ");
    scanf("%ld %ld", &x_center, &y_center);
    printf("\nA ve B degerlerini giriniz : ");
    scanf("%ld %ld", &a, &b);
    printf("\nElipsin ici dolu olsun mu (1 / 0) : ");
    scanf("%d", &doluMu);
    x = 0;
    y = b;
    a_sqr = a * a;
    b_sqr = b * b;
    fx = 2 * b_sqr * x;
    fy = 2 * a_sqr * y;
  	d = b_sqr - (a_sqr * b) + (a_sqr * 0.25);
  	do{
    	putpixel(x_center + x, y_center + y, color);
	 	putpixel(x_center - x, y_center - y, color);
	  	putpixel(x_center + x, y_center - y, color);
	  	putpixel(x_center - x, y_center + y, color);

	    if(d < 0){
	  		d = d + fx + b_sqr;
	    }
	    else{
			y = y - 1;
			d = d + fx + -fy + b_sqr;
			fy = fy - (2 * a_sqr);
	  	}
	  	x = x + 1;
		fx = fx + (2 * b_sqr);

    }while(fx < fy);
	    tmp1 = (x + 0.5) * (x + 0.5);
	    tmp2 = (y - 1) * (y - 1);
	    d = b_sqr * tmp1 + a_sqr * tmp2 - (a_sqr * b_sqr);
   	do{
		putpixel(x_center + x, y_center + y, color);
		putpixel(x_center - x, y_center - y, color);
		putpixel(x_center + x, y_center - y, color);
		putpixel(x_center - x, y_center + y, color);

	   	if(d >= 0) d = d - fy + a_sqr;
	    else{
		 	x = x + 1;
			d = d + fx - fy + a_sqr;
			fx = fx + (2 * b_sqr);
  		}
  		
   		y = y - 1;
   		fy = fy - (2 * a_sqr);
   		
    }while(y > 0);
    
    if(doluMu){
    	Doldur(abs(x_center - a) - 1, abs(y_center - b) - 1, x_center + a + 1, y_center + b + 1, color);
	}
}

// Yay Algoritmasi

void Yay(int x_merkez, int y_merkez, int r, int baslangicDerece, int bitisDerece, int color){
    
	float aci = (((baslangicDerece <= bitisDerece) ? baslangicDerece : bitisDerece) * (PI / 180));
    float range = (((bitisDerece > baslangicDerece) ? bitisDerece : baslangicDerece) * (PI / 180));
    float x = r * cos(aci);
    float y = r * sin(aci);
    
    do{
        putpixel((int)(x_merkez + x + 0.5), (int)(y_merkez - y + 0.5), color);
        aci += 0.001;
        x = r * cos(aci);
        y = r * sin(aci);
        
    }while(aci <= range);
}

// Renk Degistirme Algoritmasi

void renkDegis(int x, int y, int oldColor, int newColor){
	if (getpixel(x,y) == oldColor){
		putpixel(x, y, newColor);
		
		renkDegis(x + 1, y, oldColor, newColor);
		renkDegis(x - 1, y, oldColor, newColor);
		renkDegis(x, y + 1, oldColor, newColor);
		renkDegis(x, y - 1, oldColor, newColor);
	}
}

// Alan Doldurma Algoritmasi

void Doldur(int x0, int y0, int x1, int y1, int eskiRenk){
	
	for(int i = x0; i < x1; i++){
		int sayac = 0, kontrol = 0, ilkNokta;
		for(int j = y0 + 1; j < y1; j++){
			
			if(getpixel(i, j) == eskiRenk){
				sayac++;
				ilkNokta = j;
			}
			if(sayac == 1){
				j = y1 + 1;
				while(1){
					
					if(getpixel(i, j) == eskiRenk){
						kontrol = 1;
					}
					if(kontrol == 1){
						putpixel(i, j, eskiRenk);
					}
					
					if(ilkNokta == j){
						break;
					}
					j--;
				}
				break;
			}
		}	
	}
}

// Kýrpma Algoritmasi

void Kirp(int x0, int y0, int x1, int y1, int color){
	Dikdortgen(x0, y0, x1, y1, 0, color);
	for(int i = 0; i < BOYUT_X; i++){
		for(int j = 0; j < BOYUT_Y; j++){
			if(((x0 <= i) and (i <= x1)) and ((y0 <= j) and (j <= y1))) continue;
			
			putpixel(i, j, getbkcolor());	
		}
	}	
}

// Öteleme Algoritmasi

void Otele(int x0, int y0, int x1, int y1, int x_otele, int y_otele){
	
	for(int i = x1; i >= x0; i--){
		for(int j = y1; j >= y0; j--){
			putpixel(i + x_otele, j + y_otele, getpixel(i, j));
			putpixel(i, j, getbkcolor());
		}
	}
}

// Dondurme Algoritmasi 

void Dondur(int x0, int y0, int x1, int y1, int donmeAci){
	
	for(int i = x0; i <= x1; i++){
		for(int j = y0; j <= y1; j++){
			putpixel(BOYUT_X / 2 + (i - BOYUT_X / 2) * cos(donmeAci) - (BOYUT_Y / 2 - j) * sin(donmeAci), BOYUT_Y / 2 + (BOYUT_X / 2 - 400) * sin(donmeAci) + (BOYUT_Y - j) * cos(donmeAci) , getpixel(i, j));
		}
	}
}

// Yansima Algoritmasi

void Yansima(int x0, int y0, int x1, int y1, int toXOrY){
	for(int i = 0; i < BOYUT_X; i++){
		putpixel(i, BOYUT_Y / 2, RED);
	}
	
	for(int i = 0; i < BOYUT_Y; i++){
		putpixel(BOYUT_X / 2, i, RED);
	}
	if(toXOrY == 1){ // eðer x eksenine göre ise
		if(x1 > BOYUT_X / 2){
			for(int j = y1; j >= y0; j--){
				for(int i = x1; i >= x0; i--){
					putpixel(i, abs(j - abs(BOYUT_Y / 2 - j) * 2), getpixel(i, j));
				}
			}
		}
		else{
			for(int j = y1; j >= y0; j--){
				for(int i = x1; i >= x0; i--){
					putpixel(i, j + abs(BOYUT_Y / 2 - j) * 2, getpixel(i, j));
				}
			}
		}		
	}	
	else{ // y eksenine göre ise
		if(x1 > BOYUT_X / 2){
			for(int j = y1; j >= y0; j--){
				for(int i = x1; i >= x0; i--){
					putpixel(abs(i - abs(BOYUT_X / 2 - i) * 2), j, getpixel(i, j));
				}
			}
		}
		else{
			for(int j = y1; j >= y0; j--){
				for(int i = x1; i >= x0; i--){
					putpixel(i + abs(BOYUT_X / 2 - i) * 2, j, getpixel(i, j));
				}
			}
		}	
	}
}

// Olceklendirme Algoritmasi

void Olceklendir(int x0, int y0, int x1, int y1, float s){
	// Tek Düze Olceklendirme
	int renk;
	
	for(int i = x0; i < x1; i++){
		for(int j = y0; j < y1; j++){
			matris[i][j] = getpixel(i, j);
		}
	}
	
	cleardevice();
	
	for(int i = x1 - 1; i >= x0; i--){
		for(int j = y1 - 1; j >= y0; j--){
			renk = matris[i][j];
			//putpixel(i, j, getbkcolor());
			putpixel(s * i + x0 * (1 - s), s * j + y0 * (1 - s), renk);
			putpixel(s * i + x0 * (1 - s), s * j + y0 * (1 - s) + 1, renk);
			putpixel(s * i + x0 * (1 - s) + 1, s * j + y0 * (1 - s), renk);
			putpixel(s * i + x0 * (1 - s) + 1, s * j + y0 * (1 - s) + 1, renk);
			
		}
	}
	
}

// Makaslama Algoritmasi

void Makasla(int x0, int y0, int x1, int y1, int makasOran, int yon){
	
	if(yon == 1){
		for(int j = y1; j >= y0; j--){
			for(int i = x1; i >= x0; i--){
				putpixel(i + makasOran * j, j, getpixel(i, j));
			}
		}
	}
	else{
		for(int j = y1; j >= y0; j--){
			for(int i = x1; i >= x0; i--){
				putpixel(i, j + makasOran * i, getpixel(i, j));
			}
		}
	}	
}

// Zoom-In Algoritmasi

void ZoomIn(int zoomOrani){
	
	for(int i = 0; i < BOYUT_X; i++){
		for(int j = 0; j < BOYUT_Y; j++){
			matris[i][j] = getpixel(i,j);
		}
	}
	
	cleardevice();
	
	for(int i = 0; i < BOYUT_X; i++){
		for(int j = 0; j < BOYUT_Y; j++){
			int renk = matris[i][j];
			putpixel(i * zoomOrani / 100, j * zoomOrani / 100, renk);
			putpixel(i * zoomOrani / 100 + 1, j * zoomOrani / 100, renk);
			putpixel(i * zoomOrani / 100 + 1, j * zoomOrani / 100 + 1, renk);
			putpixel(i * zoomOrani / 100, j * zoomOrani / 100 + 1, renk);
		}
	}
}

// Zoom-out Algoritmasi

void ZoomOut(int zoomOrani){
	
	for(int i = 0; i < BOYUT_X; i++){
		for(int j = 0; j < BOYUT_Y; j++){
			matris[i][j] = getpixel(i,j);
		}
	}
	
	cleardevice();
	
	for(int j = 0; j < BOYUT_Y; j++){
		for(int i = 0; i < BOYUT_X; i++){
			int renk = matris[i][j];
			putpixel(i * 100 / zoomOrani, j * 100 / zoomOrani, renk);
		}
	}
}

// Main Fonksiyonu

int main( void ){
	
	char cevap;
	int secim;
	initwindow(BOYUT_X, BOYUT_Y, "Cizim Ekrani", 200);
	do{
		
		printf("\nHangi Islemi Gerceklestirmek Istersiniz ? ( Cizgi = 0 - Daire = 1 - Disk = 2 - Cember = 3 \nDikdortgen = 4 - Kare = 5 - Ucgen = 6 - Poligon = 7 - Yildiz = 8\nBezier Egrisi = 9 - Kirpma = 10 - Temizle = 11 - Elips = 12 - Yay = 13 - Oteleme = 14 \nYansima = 15 - Doldurma = 16 - Renk Degistir = 17 - Dondur = 18 - Olceklendirme = 19 \nMakaslama = 20 - Zoom-In = 21 - Zoom-Out = 22 ) : ");
		scanf("%d", &secim);
	
		if(secim == 0){
			int c_x0, c_y0, c_x1, c_y1;
			// Çizgi Algoritmasi
			printf("\nLutfen cizginin baslangic ve bitis noktalarini giriniz : ");
			scanf("%d %d %d %d", &c_x0, &c_y0, &c_x1, &c_y1);
			
			Cizgi(c_x0, c_y0, c_x1, c_y1, 11);
			

		}
		else if(secim == 1){
			int d_xmerkez, d_ymerkez, yaricap;
			// Daire Algoritmasi
			printf("\nLutfen Dairenin x merkezini, y merkezini ve yaricapini giriniz : ");
			scanf("%d %d %d", &d_xmerkez, &d_ymerkez, &yaricap);
			
			Daire(d_xmerkez, d_ymerkez, yaricap, 3);
		}
		else if(secim == 2){
			int xmerkez, ymerkez, yaricapR, yaricapr;
			// Disk Algoritmasi
			printf("\nLutfen Diskin x merkezini, y merkezini frame üzerinden seciniz");
			getche();
			getmouseclick(WM_LBUTTONDOWN, xmerkez, ymerkez);
			printf("\nDiskin dis yaricapi ile diskin ic yaricapini giriniz : ");
			scanf("%d %d", &yaricapR, &yaricapr);
			
			Disk(xmerkez, ymerkez, yaricapR, yaricapr, 7, getbkcolor());
		}
		else if(secim == 3){
			int d_xmerkez, d_ymerkez, yaricap;
			// Çember Algoritmasi
			printf("\nLutfen Cemberin x merkezini, y merkezini ve yaricapini giriniz : ");
			scanf("%d %d %d", &d_xmerkez, &d_ymerkez, &yaricap);
			
			Cember(d_xmerkez, d_ymerkez, yaricap, 4);
		}
		else if(secim == 4){
			int x0, y0, x1, y1, doluMu;
			// Dikdörtgen Algoritmasý
			printf("\nLutfen Dikdortgenin sol ust kose ve sag alt kose koordinatlarini frame üzerinden seciniz : ");
			printf("\nIlk noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nIkinci noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			
			printf("\nCizilecek olan dikdortgen dolu mu bos mu olsun (1 / 0) : ");
			scanf("%d", &doluMu);
			
			Dikdortgen(x0, y0, x1, y1, doluMu, 9);
		}
		else if(secim == 5){
			int x0, y0, kenarUzunlugu, doluMu;
			// Kare Algoritmasi
			printf("\nLutfen Karenin sol ust kose koordinatlarini frame üzerinden seciniz : ");
			printf("\nnoktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nKenar uzunlugunu giriniz : ");
			printf("\nCizilecek olan kare dolu mu bos mu olsun (1 / 0) : ");
			scanf("%d %d", &kenarUzunlugu, &doluMu);
			
			Kare(x0, y0, kenarUzunlugu, doluMu, 14);
		}
		else if(secim == 6){
			int x0, y0, x1, y1, x2, y2, doluMu;
			// Üçgen Algoritmasi
			printf("\nLutfen Ucgenin kose koordinatlarini giriniz : ");
			printf("\nCizilecek olan ucgen dolu mu bos mu olsun (1 / 0) : ");
			scanf("%d %d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2, &doluMu);
			
			Ucgen(x0, y0, x1, y1, x2, y2, doluMu, 12);
		}
		else if(secim == 7){
			// Poligon Algoritmasi
			Poligon(RED);
		}
		else if(secim == 8){
			int x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10;
			// Yildiz Algoritmasi
			printf("\nLutfen Yildizin kose koordinatlarini giriniz : ");
			scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5, &x6, &y6, &x7, &y7, &x8, &y8, &x9, &y9, &x10, &y10);
			// Ornek Yýldýz Koordinatlari 395 250 418 257 418 280 431 261 454 269 440 250 453 231 431 238 417 220 417 243 395 250
			Yildiz(x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10, BLUE);
		}
		else if(secim == 9){
			// Bezier Eðri Algoritmasi
			Bezier(YELLOW);
		}
		else if(secim == 10){
			int x0, y0, x1, y1;
			// Kirpma Algoritmasi
			printf("\nLutfen Kirpmak istediginiz alanin koordinatlarini seciniz : ");
			printf("\nSol Ust noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nSag Alt noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			
			Kirp(x0, y0, x1, y1, YELLOW);
		}
		else if(secim == 11){
			// Tüm Ekrani Temizleme
			cleardevice();
		}
		else if(secim == 12){
			// Elips Algoritmasi
			Elips(GREEN);
		}
		else if(secim == 13){
			int x0, y0, yaricap, bas_aci, bit_aci;
			// Yay Algoritmasi
			printf("\nLutfen x ve y merkez koordinatlarini, yaricapi ve baslangic bitis acilarini giriniz : ");
			scanf("%d %d %d %d %d", &x0, &y0, &yaricap, &bas_aci, &bit_aci);
			
			Yay(x0, y0, yaricap, bas_aci, bit_aci, CYAN);
		}
		else if(secim == 14){
			int x0, y0, x1, y1, x_otele, y_otele;
			// Oteleme Algoritmasi
			printf("\nLutfen otelemek istediginiz alanin sol ust ve sag alt noktalarini seciniz : ");
			printf("\nSol Ust noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nSag Alt noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			printf("\nOtelemek istediginiz miktari x ekseni ve y ekseni ayri olacak sekilde giriniz : ");
			scanf("%d %d", &x_otele, &y_otele);
			
			Otele(x0, y0, x1, y1, x_otele, y_otele);
		}
		else if(secim == 15){
				int x0, y0, x1, y1, xMiYMi;
			// Yansima Algoritmasi
			printf("\nLutfen yansima yapmak istediginiz alanin sirasiyla Sol ust kose ve Sag Alt kose koordinatlarini seciniz : ");
			printf("\nSol Ust noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nSag Alt noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			printf("\nX eksenine göre mi yoksa y eksenine göre mi yansitmak istediginizi (true / false) giriniz : ");
			scanf("%d", &xMiYMi);
			
			Yansima(x0, y0, x1, y1, xMiYMi);
		}
		else if(secim == 16){
			int x0, y0, x1, y1, color;
			// Doldurma Fonksiyonu
			printf("\nLutfen Dikdortgenin sol ust kose ve sag alt kose koordinatlarini giriniz : ");
			printf("\nLutfen renk kodunu giriniz : ");
			scanf("%d %d %d %d %d", &x0, &y0, &x1, &y1, &color);
			Doldur(x0, y0, x1, y1, color);
		}
		else if(secim == 17){
			int color1, color2, x, y;
			// Renk Degistirme Fonksiyonu
			printf("\nLutfen baslangic konumlarini frame uzerinden seciniz : ");
			printf("\nBaslangic noktasini frame üzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x, y);
		
			printf("\nEski renk kodunu ve yeni renk kodunu giriniz : ");
			scanf("%d %d", &color1, &color2);
			
			renkDegis(x, y, color1, color2);
		}
		else if(secim == 18){
			int x0, y0, x1, y1, dondurmeAci;
			// Dondurme Fonksiyonu
			printf("\nLutfen Dondurmek istediginiz alanin sol ust ve sag alt koordinatlarini frame uzerinden seciniz : ");
			printf("\nSol Ust noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nSag Alt noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			printf("\nDondurme acisini giriniz : ");
			scanf("%d", &dondurmeAci);
			
			Dondur(x0, y0, x1, y1, dondurmeAci);
			
			// Eksenler
			
			for(int i = 0; i < BOYUT_X; i++){
				putpixel(i, BOYUT_Y / 2, RED);
			}
			for(int i = 0; i < BOYUT_Y; i++){
				putpixel(BOYUT_X / 2, i, RED);
			}
		}
		else if(secim == 19){
			int x0, y0, x1, y1;
			float scale;
			// Olceklendirme Algoritmasi
			printf("\nLutfen cizginin baslangic ve bitis noktalarini frame uzerinden seciniz : ");
			printf("\nSol Ust noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nSag Alt noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			
			printf("\nOlceklendirme oranini giriniz : ");
			scanf("%f", &scale);
			Olceklendir(x0, y0, x1, y1, scale);
		}
		else if(secim == 20){
			int x0, y0, x1, y1, yon;
			float makas;
			// Makaslama Algoritmasi
			printf("\nLutfen cizginin baslangic ve bitis noktalarini frame uzerinden seciniz : ");
			printf("\nSol Ust noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x0, y0);
			printf("\nSag Alt noktayi frame uzerinden secin");
			getche();
			getmouseclick(WM_LBUTTONDOWN, x1, y1);
			
			printf("\nMakaslama oranini ve x eksenine mi y eksenine gore mi (1 / 0) giriniz : ");
			scanf("%f %d", &makas, &yon);
			Makasla(x0, y0, x1, y1, makas, yon);
		}
		else if(secim == 21){
			int zoomOrani;
			printf("\nYuzde kac yakinlastirmak istersiniz : ");
			scanf("%d", &zoomOrani);
			ZoomIn(zoomOrani);
		}
		else if(secim == 22){
			int zoomOrani;
			printf("\nYuzde kac uzaklastirmak istersiniz : ");
			scanf("%d", &zoomOrani);
			ZoomOut(zoomOrani);
		}
		else if(secim == 23){
			// Hazir sekiller
			
			Cizgi(50, 50, 200, 100, 11);
			Daire(200, 200, 50, 3);
			Disk(400, 100, 75, 50, 7, getbkcolor());
			Cember(500, 100, 100, 4);
			Dikdortgen(100, 20, 200, 300, 1, 9);
			Kare(300, 200, 50, 0, 14);
			Ucgen(300, 300, 200, 450, 500, 250, 1, 12);
			Yildiz(395, 250, 418, 257, 418, 280, 431, 261, 454, 269, 440, 250, 453, 231, 431, 238, 417, 220, 417, 243, 395, 250, BLUE);
			Yay(500, 400, 50, 60, 120, CYAN);
		}
		 
		printf("\nDevam Etmek Ister Misiniz ? : ");
		scanf("%s", &cevap);
		
	}while(cevap != 'h' and cevap != 'H');
	
	// RENK KODLARI { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE };
	closegraph();
	
	return 0;
}
