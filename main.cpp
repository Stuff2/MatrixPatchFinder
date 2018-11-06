#include “stdafx.h”
void ekle(int);
void listele();
void çýkar();
int lara(int);
void ara(int, int);
//fonksiyon tanýmlamalarý

int from = 1;//baþlangýç düðümü
int to = 3;// bitiþ düðümü

const int boy = 4;// varsayýlan boy
int dizi[boy][boy] = { 0 };// oluþturulan matrisi 0 lýyoruz
struct stack{// gidilen yolu tutmak için stack yapýsý kullanýyoruz
int top=-1;
int info[boy];
}s;
void ekle(int x){// stacaka item ekleme
if (s.top < boy){
s.top++;
s.info[s.top] = x;
}
}
void listele(){//stacktaki yollarý yazdýrma
for (int i = 0; i <= s.top; i++){
printf(“%d”, s.info[i]+1);
}
}
void çýkar(){//stacktan item çýkarma
s.top–;
}
int lara(int x){//stackta item arama
for (int i = 0; i <= s.top; i++){
if (s.info[i] == x)
return 1;
}
return 0;
}
void ara(int x, int y){//matriste yol arama fonksiyonu recursive
ekle(x);//girilen yolu stacka ekleme
int c;
for (int i = 0; i < boy; i++){//yollarý arama
c = lara(i);//gidilcek yeri stackta arama
if (dizi[x][i] == 1 && c == 0 && i!=y){//yeni yere gidilebilirmi daha önce gidildimi asýl hedefmi kontrolü yapýyoruz
ara(i, y);
}
if (i == y && dizi[x][y] == 1){// asýl hedefmi ve geldiðimiz yerden asýl hedefe baðlantý varmý kontrolü
listele();// gelinen yolu yazdýr
printf_s(“%d\n”, i+1);// olduðumuz yeri yazdýr

}

}

çýkar();// girilen yerden çýk

}

int _tmain(int argc, _TCHAR* argv[])
{

for (int i = 0; i < boy; i++)// temsili matrix doldurma
for (int j = 0; j < boy; j++)
if (i != j)
dizi[i][j] = 1;

ara(from – 1, to – 1);// matrixler 0 dan baþladýðý için -1 kullanýyoruz
int x;
scanf_s(“%d”, &x);//ekran kapanmasýn
return 0;
}