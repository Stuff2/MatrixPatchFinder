#include �stdafx.h�
void ekle(int);
void listele();
void ��kar();
int lara(int);
void ara(int, int);
//fonksiyon tan�mlamalar�

int from = 1;//ba�lang�� d���m�
int to = 3;// biti� d���m�

const int boy = 4;// varsay�lan boy
int dizi[boy][boy] = { 0 };// olu�turulan matrisi 0 l�yoruz
struct stack{// gidilen yolu tutmak i�in stack yap�s� kullan�yoruz
int top=-1;
int info[boy];
}s;
void ekle(int x){// stacaka item ekleme
if (s.top < boy){
s.top++;
s.info[s.top] = x;
}
}
void listele(){//stacktaki yollar� yazd�rma
for (int i = 0; i <= s.top; i++){
printf(�%d�, s.info[i]+1);
}
}
void ��kar(){//stacktan item ��karma
s.top�;
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
for (int i = 0; i < boy; i++){//yollar� arama
c = lara(i);//gidilcek yeri stackta arama
if (dizi[x][i] == 1 && c == 0 && i!=y){//yeni yere gidilebilirmi daha �nce gidildimi as�l hedefmi kontrol� yap�yoruz
ara(i, y);
}
if (i == y && dizi[x][y] == 1){// as�l hedefmi ve geldi�imiz yerden as�l hedefe ba�lant� varm� kontrol�
listele();// gelinen yolu yazd�r
printf_s(�%d\n�, i+1);// oldu�umuz yeri yazd�r

}

}

��kar();// girilen yerden ��k

}

int _tmain(int argc, _TCHAR* argv[])
{

for (int i = 0; i < boy; i++)// temsili matrix doldurma
for (int j = 0; j < boy; j++)
if (i != j)
dizi[i][j] = 1;

ara(from � 1, to � 1);// matrixler 0 dan ba�lad��� i�in -1 kullan�yoruz
int x;
scanf_s(�%d�, &x);//ekran kapanmas�n
return 0;
}