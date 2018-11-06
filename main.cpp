#include “stdafx.h”
void ekle(int);
void listele();
void cikar();
int lara(int);
void ara(int, int);
//Functions

int from = 1;//stater node
int to = 3;// target node

const int boy = 4;// lenght
int dizi[boy][boy] = { 0 };// reset matrix
struct stack{// use stack for path
int top=-1;
int info[boy];
}s;
void ekle(int x){//push stack
if (s.top < boy){
s.top++;
s.info[s.top] = x;
}
}
void listele(){//print stack
for (int i = 0; i <= s.top; i++){
printf(“%d”, s.info[i]+1);
}
}
void cikar(){//pop stack
s.top–;
}
int lara(int x){//item search on stack
for (int i = 0; i <= s.top; i++){
if (s.info[i] == x)
return 1;
}
return 0;
}
void ara(int x, int y){//patch finder recursive
ekle(x);//push stack at point
int c;
for (int i = 0; i < boy; i++){//
c = lara(i);//check patch s point
if (dizi[x][i] == 1 && c == 0 && i!=y){//can go new point
ara(i, y);
}
if (i == y && dizi[x][y] == 1){// check can go target or at target
listele();// print path
printf_s(“%d\n”, i+1);// print point

}

}

cikar();// pop stack

}

int _tmain(int argc, _TCHAR* argv[])
{

for (int i = 0; i < boy; i++)// initial matrix
for (int j = 0; j < boy; j++)
if (i != j)
dizi[i][j] = 1;

ara(from – 1, to – 1);// 
int x;
scanf_s(“%d”, &x);//wait cursor
return 0;
}
