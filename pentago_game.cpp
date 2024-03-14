#include <iostream>
#include<cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct gracz{
	char imie[20];
	char zeton;
};

struct ruch{

	char zeton;
	char ktora_tablica;
	int ktore_pole;
	char tablica_do_obrotu;
	char obrot;
};

const char ddr = 0xC9;       //Box drawings double down and right
const char dh = 0xCD;		// Box drawings double horizontal 
const char	ddh = 0xCB;		//Box drawings double down and horizontal 
const char	dvh = 0xCE;				// Box drawings double vertical and horizontal
const char dvr = 0xCC; // Box drawings double vertical and right
const char  dur = 0XC8;  // Box drawings double up and right
const char	dv = 0xBA;		//Box drawings double vertical
const char	ddl = 0xBB;			// Box drawings double down and left
const char	dul = 0xBC;			//Box drawings double up and left
const char	dvl = 0xB9;			// Box drawings double vertical and left
const char duh=0xCA; 				// Box drawings double up and horizontal
const string margin="                     "; // Margin 
//-----------------------------------------------------------------------------------------
void poczatek_gry(gracz &gracz1, gracz &gracz2, int &zeton_gracza1, int &zeton_gracza2)
{  
bool end= true;
cout<<"WITAMY W GRZE"<< endl;
cout<< "Liczby odpowiadaja podanym nizej zetonom  " << endl<<
"1: O  "  <<"2: X  " << "3: "<< char(3) << "  4:" <<char(4) << endl<<endl;
cout << "Podaj imie gracza nr 1:  ";
cin>> gracz1.imie; 
cout<< endl;

do
{
	while(end)
	{
		cout<< "Graczu 1, wybierz zeton:  ";
		end=false;
		cin>> zeton_gracza1 ;
		if( !cin )
			{ 
   			 cin.clear(); 
   			 cin.sync(); 
   			 end=true;
			}
	}
    
	if(zeton_gracza1>0 && zeton_gracza1<5)
		switch (zeton_gracza1)
		{case(1):gracz1.zeton='O';break;
		case(2): gracz1.zeton='X'; break;
		case(3): gracz1.zeton=0x3; break;
		case(4): gracz1.zeton=0x4; break;}
	
	else cout << " Graczu nr 1, podaj wartosc 1-4 i rozna od gracza 1"<< endl;
} while (zeton_gracza1<1 || zeton_gracza1>4 );

cout <<"zeton gracza 1 to:" << gracz1.zeton<< endl;
cout<< endl;

cout << "Podaj imie gracza nr 2: ";
cin>> gracz2.imie; 
end= true;
do
{
	while(end)
	{
		cout<< "Graczu nr 2, wybierz zeton: ";
		end=false;
		cin>> zeton_gracza2 ;
		if( !cin )
		{ 
   		 cin.clear(); 
   		 cin.sync();
    	end=true;
		}
	}
	end=true;   
	if(zeton_gracza2>0 && zeton_gracza2<5 && zeton_gracza1!=zeton_gracza2)
		switch (zeton_gracza2)
		{case(1): gracz2.zeton='O';break;
		case(2): gracz2.zeton='X'; break;
		case(3): gracz2.zeton=0x3; break;
		case(4): gracz2.zeton=0x4; break;}
		
	else cout << "Graczu nr 2, podaj wartosc 1-4 i rozna od gracza 1"<< endl;
} while (zeton_gracza2<1 || zeton_gracza2>4 || zeton_gracza1==zeton_gracza2 );

cout <<"zeton gracza 2 to:" <<gracz2.zeton<< endl;}
//-----------------------------------------------------------------------------------------
void tabelka_z_danymi (gracz gracz1, gracz gracz2)
{

cout <<"Gracz 1|"<< setw(3) << gracz1.zeton<<"|" << setw(20) << gracz1.imie <<"|" << endl;
cout <<"Gracz 2|"<< setw(3) << gracz2.zeton<<"|" << setw(20) << gracz2.imie <<"|" << endl; 	
};	
//-----------------------------------------------------------------------------------------
//PODPROGRAMY DLA KOLKO I KRZYZYK 
void rysuj_plansze_kolko_i_krzyzyk (char t[6][6])
{
	cout <<margin<< ddr<< dh<<dh<<dh<<ddh<<dh<<dh<<dh<< ddh<<dh<<dh<<dh<<ddh<< dh<<dh<<dh<<ddh<<dh<<dh<<dh<< ddh<< dh<<dh<<dh<< ddl<<endl;
	
	cout<<margin << dv << setw(3)<< t[0][0] <<dv<< setw(3)<< t[0][1]<< dv<< setw(3) <<t[0][2] << dv<< setw(3)<< t[0][3] << dv<< setw(3) <<t[0][4]<< dv<< setw(3) << t[0][5] << dv << endl; 
	cout <<margin<<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvh << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl;
	cout <<margin<< dv << setw(3)<< t[1][0] <<dv<< setw(3)<< t[1][1]<< dv<< setw(3) <<t[1][2] << dv<< setw(3)<< t[1][3] << dv<< setw(3) <<t[1][4]<< dv<< setw(3) << t[1][5] << dv << endl; 
		
	cout <<margin<<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvh << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl;
	cout <<margin<< dv << setw(3)<< t[2][0] <<dv<< setw(3)<< t[2][1]<< dv<< setw(3) <<t[2][2] << dv<< setw(3)<< t[2][3] << dv<< setw(3) <<t[2][4]<< dv<< setw(3) << t[2][5] << dv << endl; 
			
	cout <<margin<<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvh << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl;
	cout <<margin<< dv << setw(3)<< t[3][0] <<dv<< setw(3)<< t[3][1]<< dv<< setw(3) <<t[3][2] << dv<< setw(3)<< t[3][3] << dv<< setw(3) <<t[3][4]<< dv<< setw(3) << t[3][5] << dv << endl; 
		
	cout <<margin<<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvh << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl;
	cout <<margin<< dv << setw(3)<< t[4][0] <<dv<< setw(3)<< t[4][1]<< dv<< setw(3) <<t[4][2] << dv<< setw(3)<< t[4][3] << dv<< setw(3) <<t[4][4]<< dv<< setw(3) << t[4][5] << dv << endl; 
		
			
	cout <<margin<<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvh << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl;
	cout <<margin<< dv << setw(3)<< t[5][0] <<dv<< setw(3)<< t[5][1]<< dv<< setw(3) <<t[5][2] << dv<< setw(3)<< t[5][3] << dv<< setw(3) <<t[5][4]<< dv<< setw(3) << t[5][5] << dv << endl; 
	
	cout <<margin<<dur << dh << dh<<dh<< duh  << dh << dh<<dh<<duh<< dh<<dh<<dh<<duh << dh << dh<<dh<< duh  << dh << dh<<dh<<duh<< dh<<dh<<dh<<dul << endl;
	
};
//----------------------------------------------------------------------------------------
void help_kik(char t[6][6], gracz gracz1, gracz gracz2)
{system("cls");
cout<<"------------------KOLKO I KRZYZYK--------------------------" << endl;
cout<<"| Podaj rzad 1-6, w ktorym chcesz umiescic swoj zeton     |" << endl;
cout<<"|---------------------------------------------------------|" <<endl;
cout<<"|Podaj kolumne 1-6, w ktorej chcesz umiescic swoj zeton   |" << endl;
cout<<"|---------------------------------------------------------|" <<endl;
cout<<"|   Aby wygrac musisz umiescic 6 swoich zetonow           |" << endl;
cout<<"|      w rzedzie, kolumnie lub po skosie                  |" << endl;
cout<<"-----------------------------------------------------------" <<endl;
cout<<"                POWODZENIA !" <<endl<< endl;
system("pause");
system("cls");
tabelka_z_danymi ( gracz1,gracz2);
rysuj_plansze_kolko_i_krzyzyk(t);

};
//----------------------------------------------------------------------------------------
void pauza(char t[6][6], gracz gracz1, gracz gracz2)
{system("cls");
cout<<" +-----------------------------+ " <<endl;
cout<<" |          PAUZA   	       |	" <<endl;
cout<<" +-----------------------------+ " <<endl;

system("pause");
system("cls");
tabelka_z_danymi (gracz1,gracz2);
rysuj_plansze_kolko_i_krzyzyk(t);
};
//----------------------------------------------------------------------------------------	
bool remis_kik(char t[][6]) 
{ bool end=true;
  for(int i = 1; i <=6 ; i++)
  	for(int j=1; j<=6; j++)
     if(t[i][j] == ' ')  end=false;
     
 return end;
};
//--------------------------------------------------------------------------------------------
bool wygrana_kik(char t[][6], gracz gracz )
{
  bool test;
test = false;

if
(
// sprawdzanie rzedow
  	(t[0][0]==t[0][1] && t[0][1]==t[0][2] && t[0][2]==t[0][3] && t[0][3]==t[0][4] && t[0][4]==t[0][5]&& t[0][5]== gracz.zeton ) ||
   	(t[1][0]==t[1][1] && t[1][1]==t[1][2] && t[1][2]==t[1][3] && t[1][3]==t[1][4] && t[1][4]==t[1][5]&& t[1][5]== gracz.zeton ) ||
  	(t[2][0]==t[2][1] && t[2][1]==t[2][2] && t[2][2]==t[2][3] && t[2][3]==t[2][4] && t[2][4]==t[2][5]&& t[2][5]== gracz.zeton ) ||
 	(t[3][0]==t[3][1] && t[3][1]==t[3][2] && t[3][2]==t[3][3] && t[3][3]==t[3][4] && t[3][4]==t[3][5]&& t[3][5]== gracz.zeton ) ||
 	(t[4][0]==t[4][1] && t[4][1]==t[4][2] && t[4][2]==t[4][3] && t[4][3]==t[4][4] && t[4][4]==t[4][5]&& t[4][5]== gracz.zeton ) ||
 	(t[5][0]==t[5][1] && t[5][1]==t[5][2] && t[5][2]==t[5][3] && t[5][3]==t[5][4] && t[5][4]==t[5][5]&& t[5][5]== gracz.zeton ) ||
    
// sprawdzanie kolumn
	(t[0][0]==t[1][0] && t[1][0]==t[2][0] && t[2][0]==t[3][0] && t[3][0]==t[4][0] && t[4][0]==t[5][0]&& t[5][0]== gracz.zeton ) || 
	(t[0][1]==t[1][1] && t[1][1]==t[2][1] && t[2][1]==t[3][1] && t[3][1]==t[4][1] && t[4][1]==t[5][1]&& t[5][1]== gracz.zeton ) ||
	(t[0][2]==t[1][2] && t[1][2]==t[2][2] && t[2][2]==t[3][2] && t[3][2]==t[4][2] && t[4][2]==t[5][2]&& t[5][2]== gracz.zeton ) ||  
	(t[0][3]==t[1][3] && t[1][3]==t[2][3] && t[2][3]==t[3][3] && t[3][3]==t[4][3] && t[4][3]==t[5][3]&& t[5][3]== gracz.zeton ) || 
	(t[0][4]==t[1][4] && t[1][4]==t[2][4] && t[2][4]==t[3][4] && t[3][4]==t[4][4] && t[4][4]==t[5][4]&& t[5][4]== gracz.zeton ) ||
	(t[0][5]==t[1][5] && t[1][5]==t[2][5] && t[2][5]==t[3][5] && t[3][5]==t[4][5] && t[4][5]==t[5][5]&& t[5][5]== gracz.zeton ) ||
  																		
// sprawdzenie przekatnyvch 
	 (t[0][0]==t[1][1] && t[1][1]==t[2][2] && t[2][2]==t[3][3] && t[3][3]==t[4][4] && t[4][4]==t[5][5]&& t[5][5]== gracz.zeton ) || 
  	 (t[5][0]==t[4][1] && t[4][1]==t[3][2] && t[3][2]==t[2][3] && t[2][3]==t[1][4] && t[1][4]==t[5][0]&& t[5][0]== gracz.zeton )
) test=true; 
   		
 if(test) return true;
  return false;
};
//---------------------------------------------------------------------------------------------
void czyszczenie_planszy_kolko_i_krzyzyk(char t[6][6])
{for (int i=0; i<6; i++)
for (int j=0; j<6;j++)
t[i][j]=' ' ;
};
//----------------------------------------------------------------------
void szukanie_zetonu_kik (char t[6][6], char temp, gracz gracz_zmiana)
{for (int i=0; i<6; i++)
 for (int j=0;j<6; j++)
	if (t[i][j]==temp) t[i][j]=gracz_zmiana.zeton;
};

//-----------------------------------------------------------------------------------------------------------
void zamiana_zetonu_kik(gracz &gracz_zmiana, gracz gracz_drugi,char t[6][6], int &zeton_gracza_zmieniajacego, int  zeton_gracza_innego)
{int nowy_zeton;
cout<< "Podaj liczbe odpowiadajaca zetonowi" << endl<<
"1: O  "  <<"2: X  " << "3: "<< char(3) << "  4:" <<char(4) << endl;
char temp=gracz_zmiana.zeton; 
bool end;
end= true;
do
{
	while(end)
	{
		cout<< "Graczu, wybierz zeton: ";
		end=false;
		cin>> nowy_zeton ;
		if( !cin )
			{ 
   			cin.clear(); 
   			cin.sync(); 
    		end=true;
			}
	}
	 end=true;   
	if(nowy_zeton>0 && nowy_zeton<5 &&  nowy_zeton!=zeton_gracza_innego)
		switch (nowy_zeton)
		{case(1): gracz_zmiana.zeton='O';break;
		case(2): gracz_zmiana.zeton='X'; break;
		case(3): gracz_zmiana.zeton=0x3; break;
		case(4): gracz_zmiana.zeton=0x4; break;}
	
	else cout << "Graczu, podaj wartosc 1-4 i rozna od drugiego gracza "<< endl;
} while (nowy_zeton<1 || nowy_zeton>4 || nowy_zeton==zeton_gracza_innego );
zeton_gracza_zmieniajacego=nowy_zeton; 
szukanie_zetonu_kik(t, temp, gracz_zmiana);
system("cls");

}
//---------------------------------------------------------------------------------------------
void ruch_gracza1_kik (char t[6][6], gracz &gracz1,gracz gracz2, int &ruch_gracza1_wykonany, int &zeton_gracza1, int &zeton_gracza2)
{
char r, k;   
int rzad, kolumna;
do{ cout<< "RUNDA GRACZA 1" << endl;
	cout <<"Graczu 1, podaj rzad: " ;
	cin>> r;
	cout<< endl;
		while (r=='h')
		{
			help_kik(t,gracz1, gracz2);	
			cout<<	"Graczu 1, podaj rzad: ";
			cin>>r; 
			cout<< endl;
		};
		
		while (r=='p')
		{
		pauza(t, gracz1,gracz2);	
		cout<<	"Graczu 1, podaj rzad: ";
		cin>>r; 
		cout<< endl;
		};
		
		while (r=='z')
		{
		zamiana_zetonu_kik(gracz1,gracz2, t, zeton_gracza1, zeton_gracza2);	
		tabelka_z_danymi (gracz1, gracz2);
        rysuj_plansze_kolko_i_krzyzyk(t);
		cout<<	"Graczu 1, podaj rzad: ";
		cin>>r; 
		cout<< endl;
		};
		
	cout<< "Graczu 1, podaj kolumne: "<< endl;
	cin>>k;

		while ( k=='h')
		{
  		help_kik(t, gracz1,gracz2);
  		cout<< "Graczu 1, podaj kolumne: ";
  		cin>> k; 
 		cout<< endl;
		};
		
		while (k=='p')
		{
		pauza(t, gracz1, gracz2);	
		cout<<	"Graczu 1, podaj kolumne: ";
		cin>>k; 
		cout<< endl;
		};
	
		while (k=='z')
		{
		zamiana_zetonu_kik(gracz1,gracz2, t, zeton_gracza1, zeton_gracza2);	
		tabelka_z_danymi (gracz1, gracz2);
        rysuj_plansze_kolko_i_krzyzyk(t);
		cout<<	"Graczu 1, podaj rzad: ";
		cin>>r; 
		cout<< endl;
		};

	rzad=static_cast<int>(r) -48;

	kolumna=(int)(k) -48;

}while(t[rzad-1][kolumna-1]!=' ' ||  rzad>6 || kolumna>6 || rzad<1 || kolumna<1);

t[rzad-1][kolumna-1]= gracz1.zeton;
ruch_gracza1_wykonany=1; 
};
//----------------------------------------------------------------------------------------------------
void ruch_gracza2_kik(char t[][6],gracz &gracz2,gracz gracz1, int &ruch_gracza1_wykonany, int &zeton_gracza1, int &zeton_gracza2)
{ char r, k;   
int rzad, kolumna;
do{ cout<< "RUNDA GRACZA 2"<<endl;
	cout <<"Graczu 2, podaj rzad: ";
		cin>> r;
	cout<< endl;
		while (r=='h')
		{
		help_kik(t,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj rzad: ";
		cin>>r; 
		cout<< endl;
		};
		while (r=='p')
		{
		pauza(t,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj rzad: ";
		cin>>r; 
		cout<< endl;
		};
		while (r=='z')
		{	
		zamiana_zetonu_kik(gracz2,gracz1, t, zeton_gracza2, zeton_gracza1);
		tabelka_z_danymi (gracz1, gracz2);
        rysuj_plansze_kolko_i_krzyzyk(t);;	
		cout<<	"Graczu 2, podaj rzad: ";
		cin>>r; 
		cout<< endl;
		};
	
	cout<< "Graczu 2, podaj kolumne: "; 
	cin>>k; 
	cout<< endl;

		while ( k=='h')
		{
 		help_kik(t, gracz1,gracz2);
 		 cout<< "Graczu 2, podaj kolumne: ";
 		 cin>> k; 
	 	  cout<< endl;
		};
		while (k=='p')
		{
		pauza(t, gracz1,gracz2);	
		cout<<	"Graczu 2, podaj kolumne: ";
		cin>>k; 
		cout<< endl;
		};
		while (k=='z')
		{
		zamiana_zetonu_kik(gracz2, gracz1, t, zeton_gracza2, zeton_gracza1);	
		tabelka_z_danymi (gracz1, gracz2);
        rysuj_plansze_kolko_i_krzyzyk(t);
		cout<<	"Graczu 2, podaj rzad: ";
		cin>>r; 
		cout<< endl;
		};

rzad=static_cast<int>(r) -48;
kolumna=(int)(k) -48;

}while(t[rzad-1][kolumna-1]!=' ' ||  rzad>6 || kolumna>6 || rzad<1 || kolumna<1);
t[rzad-1][kolumna-1]= gracz2.zeton;
ruch_gracza1_wykonany=0; };


//----------------------------------------------------------------------------------
void kolko_i_krzyzyk()
{gracz gracz1, gracz2;
char t[6][6];
int ruch_gracza1_wykonany=0;
int zeton_gracza1, zeton_gracza2;

czyszczenie_planszy_kolko_i_krzyzyk(t);
poczatek_gry(gracz1,gracz2, zeton_gracza1, zeton_gracza2);
system("cls");

while(1) 
{	tabelka_z_danymi (gracz1, gracz2);
	rysuj_plansze_kolko_i_krzyzyk(t);
	ruch_gracza1_kik(t, gracz1,gracz2,ruch_gracza1_wykonany, zeton_gracza1, zeton_gracza2) ;
	system("cls");
	tabelka_z_danymi (gracz1, gracz2);
	rysuj_plansze_kolko_i_krzyzyk(t);

		if (wygrana_kik(t,gracz1) ) break;
		if (remis_kik(t)) break;

	ruch_gracza2_kik(t,gracz2,gracz1, ruch_gracza1_wykonany, zeton_gracza1, zeton_gracza2);
	rysuj_plansze_kolko_i_krzyzyk(t);
		if (wygrana_kik(t,gracz2) ) break;
		if (remis_kik(t)) break;
	system("cls");
};

system("cls");
if (remis_kik(t)) cout<< "REMIS!!!!!!";
if (wygrana_kik(t,gracz1) ) cout <<"GRACZ NR 1- " << gracz1.imie << " - WYGRAL" ;
if (wygrana_kik(t,gracz2) ) cout <<"GRACZ NR 1-" << gracz1.imie << " - WYGRAL" ;
}
//-------------------------------------------------------------------------------------------------------------------------
// PODPRPROGRAMY PENTAGO
void czyszczenie_tablic_pentago (char t[9])
{for (int i=0; i<9; i++)
t[i]=' ' ;
};
//-------------------------------------------------------------------------------------
void rysuj_plansze_pentago(char q[9],char w[9],char a[9],char s[9])
{
	cout <<margin<< ddr << dh << dh<<dh << ddh << dh << dh<<dh << ddh << dh << dh<<dh << ddl<< " " 
	<< ddr << dh << dh<<dh << ddh << dh << dh<<dh << ddh << dh << dh<<dh << ddl<< endl;  // gorna linaa 	
	cout <<margin<<  dv <<setw(3)<< q[6] << dv<< setw(3)<<q[7]<< dv << setw(3)<<q[8] << dv << " " << dv <<setw(3)<<w[6]<< dv <<setw(3)<<w[7] << dv <<setw(3)<<w[8] << dv << endl; 
	
	cout <<margin<< dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << " " <<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl;  // linia 	
		
	cout <<margin<<  dv <<setw(3)<< q[3] << dv<< setw(3)<<q[4]<< dv << setw(3)<<q[5]<< dv << " " << dv <<setw(3)<<w[3]<< dv <<setw(3)<<w[4] << dv <<setw(3)<<w[5] << dv << endl; 
	cout <<margin<< dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << " " <<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl; // linia 
	cout <<margin<<  dv <<setw(3)<< q[0] << dv<< setw(3)<<q[1]<< dv << setw(3)<<q[2] << dv << " " << dv <<setw(3)<<w[0]<< dv <<setw(3)<<w[1] << dv <<setw(3)<<w[2] << dv << endl; 
	
	cout <<margin<< dur << dh << dh<<dh<< duh  << dh << dh<<dh<<duh<< dh<<dh<<dh<<dul << " " <<dur << dh << dh<<dh<< duh  << dh << dh<<dh<<duh<< dh<<dh<<dh<<dul << endl;
		
	cout <<margin<<  ddr << dh << dh<<dh << ddh << dh << dh<<dh << ddh << dh << dh<<dh << ddl<< " " 
	<< ddr << dh << dh<<dh << ddh << dh << dh<<dh << ddh << dh << dh<<dh << ddl<< endl;  // gorna linaa 
	cout <<margin<<  dv <<setw(3)<< a[6] << dv<< setw(3)<<a[7]<< dv << setw(3)<<a[8] << dv << " " << dv <<setw(3)<<s[6]<< dv <<setw(3)<<s[7] << dv <<setw(3)<<s[8]<< dv << endl; 
		

	cout <<margin<< dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << " " <<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl;  // linia 	

	cout <<margin<<  dv <<setw(3)<< a[3] << dv<< setw(3)<<a[4]<< dv << setw(3)<<a[5] << dv << " " << dv <<setw(3)<<s[3]<< dv <<setw(3)<<s[4] << dv <<setw(3)<<s[5] << dv << endl; 
	cout <<margin<< dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << " " <<dvr << dh << dh<<dh<< dvh  << dh << dh<<dh<<dvh<< dh<<dh<<dh<<dvl << endl; // linia 
	cout <<margin<<  dv <<setw(3)<< a[0] << dv<< setw(3)<<a[1]<< dv << setw(3)<<a[2] << dv << " " << dv <<setw(3)<<s[0]<< dv <<setw(3)<<s[1] << dv <<setw(3)<<s[2] << dv << endl; 
	cout <<margin<< dur << dh << dh<<dh<< duh  << dh << dh<<dh<<duh<< dh<<dh<<dh<<dul << " " <<dur << dh << dh<<dh<< duh  << dh << dh<<dh<<duh<< dh<<dh<<dh<<dul << endl;
}
//--------------------------------------------------------------------------------------------

bool wygrana_pentago(char q[9], char w[9], char a[9], char s[9], gracz gracz )
{
  bool test;
	test = false;
  
 if
(
   // sprawdzanie rzedow
  (q[6]==q[7] && q[7]==q[8] && q[8]==w[6] && w[6]==w[7] && w[7]==gracz.zeton ) ||
  (q[7]==q[8] && q[8]==w[6] && w[6]==w[7] && w[7]==w[8] && w[8]==gracz.zeton ) ||	
  (q[3]==q[4] && q[4]==q[5] && q[5]==w[3] && w[3]==w[4] && w[4]==gracz.zeton ) ||
  (q[4]==q[5] && q[5]==w[3] && w[3]==w[4] && w[4]==w[5] && w[5]==gracz.zeton ) ||
  (q[0]==q[1] && q[1]==q[2] && q[2]==w[0] && w[0]==w[1] && w[1]==gracz.zeton ) ||
  (q[1]==q[2] && q[2]==w[0] && w[0]==w[1] && w[1]==w[2] && w[2]==gracz.zeton ) ||
     
  (a[6]==a[7] && a[7]==a[8] && a[8]==s[6] && s[6]==s[7] && s[7]==gracz.zeton ) ||
  (a[7]==a[8] && a[8]==s[6] && s[6]==s[7] && s[7]==s[8] && s[7]==gracz.zeton ) ||
  (a[3]==a[4] && a[4]==a[5] && a[5]==s[3] && s[3]==s[4] && s[4]==gracz.zeton ) ||
  (a[4]==a[5 ]&& a[5]==s[3] && s[3]==s[4] && s[4]==s[5] && s[5]==gracz.zeton ) ||
  (a[0]==a[1] && a[1]==q[2] && q[2]==s[0] && s[0]==s[1] && s[1]==gracz.zeton ) ||
  (a[1]==a[2] && a[2]==s[0] && s[0]==s[1] && s[1]==s[2] && s[2]==gracz.zeton ) ||
// sprawdzanie kolumn
  (q[6]==q[3] && q[3]==q[0] && q[0]==a[6] && a[6]==a[3] && a[3]==gracz.zeton ) ||
  (q[3]==q[0] && q[0]==a[6] && a[6]==a[3] && a[3]==a[0] && a[0]==gracz.zeton ) ||
  (q[7]==q[4] && q[4]==q[1] && q[1]==a[7] && a[7]==a[4] && a[4]==gracz.zeton ) ||
  (q[4]==q[1] && q[1]==a[7] && a[7]==a[4] && a[4]==a[1] && a[1]==gracz.zeton ) ||
  (q[8]==q[5] && q[5]==q[2] && q[2]==a[8] && a[8]==a[5] && a[5]==gracz.zeton ) ||
  (q[5]==q[2] && q[2]==a[8] && a[8]==a[5] && a[5]==a[2] && a[2]==gracz.zeton ) ||
  (w[6]==w[3] && w[3]==w[0] && w[0]==s[6] && s[6]==s[3] && s[3]==gracz.zeton ) ||
  (w[3]==w[0] && w[0]==s[6] && s[6]==s[3] && s[3]==s[0] && s[0]==gracz.zeton ) ||
  (w[7]==w[4] && w[4]==w[1] && w[1]==s[7] && s[7]==s[4] && s[4]==gracz.zeton ) ||
  (w[4]==w[1] && w[1]==s[7] && s[7]==s[4] && s[4]==s[1] && s[1]==gracz.zeton ) ||
  (w[8]==w[5] && w[5]==w[2] && w[2]==s[8] && s[8]==s[5] && s[5]==gracz.zeton ) ||
  (w[5]==w[2] && w[2]==s[8] && s[8]==s[5] && s[5]==s[2] && s[2]==gracz.zeton ) ||																	
// sprawdzenie przekatnyvch 
  (q[6]==q[4] && q[4]==q[2]&& q[2]==s[6] && s[6]==s[4] && s[4]==gracz.zeton ) ||
  (q[4]==q[2] && q[2]==s[6] && s[6]==s[4] && s[4]==s[2] && s[2]==gracz.zeton ) ||						
  (a[0]==a[4] && a[4]==a[8] && a[8]==w[0] && w[0]==w[4] && w[4]==gracz.zeton ) ||
  (a[4]==a[8] && a[8]==w[0] && w[0]==w[4] && w[4]==w[8] && w[8]==gracz.zeton )
) test=true;
 		
 if(test) return true;
 else  return false;
};
//----------------------------------------------------------------------------
bool remis(char t[9]) // zwraca true gdy nie ma wolnych miejsc 
{ bool end=true;

  for(int i = 1; i <=9 ; i++)
     if(t[i] == ' ')  end=false;
     
 return end;
};
//-------------------------------------------------------------------------
bool remis_pentago(char q[9], char w[9],char a[9],char s[9])
{bool end=false;
 if(remis(q) && remis(w)&& remis(a)&& remis(s)) end=true;
 return end;	
};
//-------------------------------------------------------------------------
void obrot_w_prawo(char t[9])
{ char temp[9];

for (int i=0; i<9; i++)
temp[i]=t[i];

t[0]=temp[2];
t[1]=temp[5];
t[2]=temp[8];
t[3]=temp[1];
t[4]=temp[4];
t[5]=temp[7];
t[6]=temp[0];
t[7]=temp[3];
t[8]=temp[6];
};
//------------------------------------------------------------------------------------------
void obrot_w_lewo(char t[9])
{char temp[9];

for (int i=0; i<9; i++)
temp[i]=t[i];

t[0]=temp[6];
t[1]=temp[3];
t[2]=temp[0];
t[3]=temp[7];
t[4]=temp[4];
t[5]=temp[1];
t[6]=temp[8];
t[7]=temp[5];
t[8]=temp[2];	
}
//---------------------------------------------------------------------------------------------------
void help_pentago(char q[9],char w[9],char a[9],char s[9] )
{system("cls");
cout<<"----------------PENTAGO-----------------------" << endl;
cout<<"|Podaj plansze, w ktorej chcesz umiescic zeton|" << endl;
cout<<"|        q- lewa plansza na gorze             |" << endl;
cout<<"|        w- prawa plansza na gorze            |" << endl;
cout<<"|         a- lewa plansza na dole             |" << endl;
cout<<"|        s- prawa plansza na gorze            |" << endl;
cout<<"|---------------------------------------------|" <<endl;
cout<<"|Podaj pole na planszy jak na klawiaturze nr  |" << endl;
cout<<"|        7 |       8        |     9           |" << endl;
cout<<"|        4 |       5        |     6           |" << endl;
cout<<"|        1 |       2        |     3           |" << endl;
cout<<"|---------------------------------------------|" <<endl;
cout<<"|Aby wygrac musisz umiescic 5 swoich zetonow  | " << endl;
cout <<    "w rzedzie, kolumnie lub po skosie        |" << endl;
cout<<"-----------------------------------------------" <<endl;
cout<<"                          POWODZENIA !" <<endl<< endl;
system("pause");
system("cls");
}
//------------------------------------------------------------------------
void pauza(char q[9],char w[9],char a[9],char s[9], gracz gracz1, gracz gracz2)
{system("cls");
cout<<" +-----------------------------+ " <<endl;
cout<<" |          PAUZA   	       |	" <<endl;
cout<<" +-----------------------------+ " <<endl;

system("pause");
system("cls");
tabelka_z_danymi (gracz1,gracz2);
rysuj_plansze_pentago( q,w, a, s);
};
//---------------------------------------------------------------------------------
void szukanie_zetonu_pentago (char t[9], char temp, gracz gracz_zmiana)
{for (int i=0; i<9; i++)
	if (t[i]==temp) t[i]=gracz_zmiana.zeton;
};

//-------------------------------------------------------------------------------------
void zamiana_zetonu_pentago(gracz &gracz_zmiana, gracz gracz_drugi,char q[9],char w[9],char a[9],char s[9], int &zeton_gracza_zmieniajacego, int  zeton_gracza_innego)
{int nowy_zeton;
cout<< "Podaj liczbe odpowiadajaca zetonowi" << endl<<
"1: O  "  <<"2: X  " << "3: "<< char(3) << "  4:" <<char(4) << endl;
char temp=gracz_zmiana.zeton; 
bool end;
end= true;
do
{
	while(end)
		{
		cout<< "Graczu, wybierz zeton: ";
		end=false;
		cin>> nowy_zeton ;
			if( !cin )
			{ 
   			cin.clear(); // czyœcimy flagi b³êdu strumienia
   			 cin.sync(); // czyœcimy bufor strumienia
   			 end=true;
				}
		}
	end=true;   
	if(nowy_zeton>0 && nowy_zeton<5 &&  nowy_zeton!=zeton_gracza_innego)
		switch (nowy_zeton)
		{case(1): gracz_zmiana.zeton='O';break;
		case(2): gracz_zmiana.zeton='X'; break;
		case(3): gracz_zmiana.zeton=0x3; break;
		case(4): gracz_zmiana.zeton=0x4; break;}
	
	else cout << "Graczu, podaj wartosc 1-4 i rozna od drugiego gracza "<< endl;
} while (nowy_zeton<1 || nowy_zeton>4 || nowy_zeton==zeton_gracza_innego );

zeton_gracza_zmieniajacego=nowy_zeton; 

szukanie_zetonu_pentago(q, temp, gracz_zmiana);
szukanie_zetonu_pentago(w, temp, gracz_zmiana);
szukanie_zetonu_pentago(a, temp, gracz_zmiana);
szukanie_zetonu_pentago(s, temp, gracz_zmiana);
system("cls");
 
};
//-------------------------------------------------------------------------------------------
char opcje()
{system("cls");
cout<<" Nacisnij r ,by powrocic do gry " <<endl;
cout<<" Nacisnij p ,by zatrzymac gre " <<endl;
cout<<" Nacisnij h ,by zobaczyc jak grac " <<endl;
cout<<" Nacisnij k, by zmienic swoj zeton  " <<endl;}
//--------------------------------------------------------------------------------------------
void ruch_gracza2(char q[9], char w[9], char a[9], char s[9], gracz &gracz2,gracz gracz1, int &ruch_gracza1_wykonany, int &zeton_gracza2, int &zeton_gracza1, ruch ruchy[36], int &i)
{char t[9];
char p ,k, charpole, plansza_obrot;
int pole, kolumna;
do{
	cout <<"Graczu 2, podaj plansze: ";
	cin>> p;
	
		while (p=='m')	
		{char opcja;
		opcje() ;
   		cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> p;}
	
		while(p=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj plansze : ";
		cin>>p;
		cout<< endl; 
		};
		
		while (p=='h')
		{
		help_pentago(q,w,a,s);
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);	
		cout<<	"Graczu 2, podaj plansze: ";
		cin>>p; 
		cout<< endl;
		};
		while (p=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj plansze: ";
		cin>>p; 
		cout<< endl;
		};
		while (p=='k')
		{	
		zamiana_zetonu_pentago(gracz2,gracz1, q,w,a,s, zeton_gracza2, zeton_gracza1);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj plansze ";
		cin>>p; 
		cout<< endl;}
} while (p!='q' && p!='w' && p!='a' && p!='s');
	if (p=='q')	
	{
		do{
			cout <<"Graczu 2, podaj pole: ";
			cin>>  charpole;
		
			
			while ( charpole=='m')	
			{ opcje() ;
   			cout<<"Wybierz, co chcesz zrobic: " << endl;
			cin>> charpole;}
		
			while(charpole=='r')
			{system("cls");
			tabelka_z_danymi (gracz1,gracz2);
			rysuj_plansze_pentago( q,w, a, s);
			cout<<	"Graczu 2, podaj pole ";
			cin>>charpole;
			cout<< endl;
			}
		
			while (charpole=='h')
			{
			help_pentago(q,w,a,s);
			tabelka_z_danymi (gracz1,gracz2);	
		 	rysuj_plansze_pentago( q,w, a, s);
			cout<<	"Graczu 2, podaj pole ";
			cin>>charpole;
			cout<< endl;
			};
			while (charpole=='p')
			{
			pauza(q,w,a,s,gracz1, gracz2);	
			cout<<	"Graczu 2, podaj pole ";
			cin>>charpole;
			cout<< endl;
			};
			while (charpole=='z')
			{	
			zamiana_zetonu_pentago(gracz2,gracz1, q,w,a,s, zeton_gracza2, zeton_gracza1);
			tabelka_z_danymi (gracz1, gracz2);
      	 	rysuj_plansze_pentago( q,w, a, s);
			cout<<	"Graczu 2, podaj pole ";
			cin>>charpole;
			cout<< endl;};
			
 pole=static_cast<int>(charpole) -48;		

    	} while (pole<1 || pole>9 ||  q[pole-1]!=' ');
	q[pole-1]= gracz2.zeton;
	rysuj_plansze_pentago( q,w, a, s); };
	
if (p=='a')	
{
	do{
		cout <<"Graczu 2, podaj pole: ";
		cin>>  charpole;
	
		while ( charpole=='m')	
		{ opcje() ;
   		 cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> charpole;
		}
		
		while(charpole=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		}
		
		while (charpole=='h')
		{
		help_pentago(q,w,a,s);
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);	
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='k')
		{	
		zamiana_zetonu_pentago(gracz2,gracz1, q,w,a,s, zeton_gracza2, zeton_gracza1);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		
 pole=static_cast<int>(charpole) -48;		

	} while (pole<1 || pole>9 ||  a[pole-1]!=' ');
a[pole-1]= gracz2.zeton;
rysuj_plansze_pentago( q,w, a, s); } ;

if (p=='w')	
{
	do{
		cout <<"Graczu 2, podaj pole: ";
		cin>>  charpole;
	
		while ( charpole=='m')	
		{ opcje() ;
  	 	 cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> charpole;}
			
		while(charpole=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		
		while (charpole=='h')
		{
		help_pentago(q,w,a,s);
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);	
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='k')
		{	
		zamiana_zetonu_pentago(gracz2,gracz1, q,w,a,s, zeton_gracza2, zeton_gracza1);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		;}
		
 	pole=static_cast<int>(charpole) -48;		

	} while (pole<1 || pole>9 ||  w[pole-1]!=' ');
	w[pole-1]= gracz2.zeton;
	rysuj_plansze_pentago( q,w, a, s); };
	
if (p=='s')	
{
do{
	cout <<"Graczu 2, podaj pole: ";
	cin>>  charpole;

	while ( charpole=='m')	
	{ 
	opcje() ;
    cout<<"Wybierz, co chcesz zrobic: " << endl;
	cin>> charpole;}
		
		while(charpole=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		
		while (charpole=='h')
		{
		help_pentago(q,w,a,s);
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);	
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='z')
		{	
		zamiana_zetonu_pentago(gracz2,gracz1, q,w,a,s, zeton_gracza2, zeton_gracza1);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		
 pole=static_cast<int>(charpole) -48;		

	} while (pole<1 || pole>9 ||  s[pole-1]!=' ');
s[pole-1]= gracz2.zeton;
rysuj_plansze_pentago( q,w, a, s); };
system("cls");
tabelka_z_danymi (gracz1, gracz2);
rysuj_plansze_pentago(q,w,a,s);

//obrot 
do{
	cout <<"Graczu 2, podaj plansze do obrotu: ";
	cin>> plansza_obrot;
	
		while (plansza_obrot=='m')	
		{
		opcje() ;
   		cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> plansza_obrot;
		}
	
		while(plansza_obrot=='r')
		{
		system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj plansze do obrotu : ";
		cin>>plansza_obrot;
		cout<< endl; 
		};
		
		while (plansza_obrot=='h')
		{
		help_pentago(q,w,a,s);	
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj plansze do obrotu: ";
		cin>>plansza_obrot; 
		cout<< endl;
		};
		while (plansza_obrot=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj plansze do obrotu: ";
		cin>>plansza_obrot; 
		cout<< endl;
		};
		while (plansza_obrot=='k')
		{	
		zamiana_zetonu_pentago(gracz2,gracz1, q,w,a,s, zeton_gracza2, zeton_gracza1);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj plansze do obrotu";
		cin>>plansza_obrot; 
		cout<< endl;}
	} while (plansza_obrot!='q' && plansza_obrot!='w' && plansza_obrot!='a' && plansza_obrot!='s');
char obrot;
do{
	cout<< "graczu 2, wybierz jak obrocic plansze" << endl;
	
	cin>> obrot;

		while ( obrot=='m')	
		{ opcje() ;
   		 cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> obrot;}
		
		while(obrot=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj kierunek obrotu ";
		cin>>obrot;
		cout<< endl;
		};
		
		while (obrot=='h')
		{
		help_pentago(q,w,a,s);	
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 2, podaj kierunek obrotu";
		cin>>obrot;
		cout<< endl;
		};
		while (obrot=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 2, podaj kierunek obrotu";
		cin>>obrot;;
		cout<< endl;
		};
		while (obrot=='k')
		{	
		zamiana_zetonu_pentago(gracz2,gracz1, q,w,a,s, zeton_gracza2, zeton_gracza1);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, kierunek obrotu ";
		cin>>obrot;
		cout<< endl;
		};
	
		while(obrot=='z') 
		{ if (plansza_obrot=='q') obrot_w_prawo(q);
		if (plansza_obrot=='w') obrot_w_prawo(w);
		if (plansza_obrot=='a') obrot_w_prawo(a);
		if (plansza_obrot=='s') obrot_w_prawo(s);
		obrot='n';
		};
	
		while(obrot=='x') 
		{ if (plansza_obrot=='q') obrot_w_lewo(q);
		if (plansza_obrot=='w') obrot_w_lewo(w);
		if (plansza_obrot=='a') obrot_w_lewo(a);
		if (plansza_obrot=='s') obrot_w_lewo(s); 
		obrot='l';
		};
	 }while(obrot!='n' && obrot!='l');
ruchy[i].zeton=gracz2.zeton;
ruchy[i].ktora_tablica=p;
ruchy[i].ktore_pole=pole;
ruchy[i].tablica_do_obrotu=plansza_obrot;
ruchy[i].obrot=obrot;

i++;
}
//-----------------------------------------------------------------------------
void ruch_gracza1(char q[9], char w[9], char a[9], char s[9], gracz &gracz1,gracz gracz2, int &ruch_gracza1_wykonany, int &zeton_gracza1, int &zeton_gracza2, ruch ruchy[36], int &i)
{char p, k, charpole,  plansza_obrot; 
int pole, kolumna;
do{
	cout <<"Graczu 1, podaj plansze: ";
	cin>> p;

	
		while (p=='m')	
		{char opcja;
		opcje() ;
    	cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> p;};	
		while(p=='r')
		{
		system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		 rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj plansze : ";
		cin>>p;
		cout<< endl; 
		};
		
		while (p=='h')
		{
		help_pentago(q,w,a,s);
		tabelka_z_danymi (gracz1,gracz2);
			rysuj_plansze_pentago( q,w, a, s);	
		cout<<	"Graczu 1, podaj plansze: ";
		cin>>p; 
		cout<< endl;
		};
		
		while (p=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 1, podaj plansze: ";
		cin>>p; 
		cout<< endl;
		};
		
		while (p=='k')
		{	
		zamiana_zetonu_pentago(gracz1,gracz2, q,w,a,s, zeton_gracza1, zeton_gracza2);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj plansze ";
		cin>>p; 
		cout<< endl;
		};
} while (p!='q' && p!='w' && p!='a' && p!='s');
		
if (p=='q')	

{
	do{
		cout <<"Graczu 1, podaj pole: ";
		cin>>  charpole;
	
			while ( charpole=='m')	
			{ opcje() ;
  			cout<<"Wybierz, co chcesz zrobic: " ;
			cin>> charpole;
			};
		
			while(charpole=='r')
			{	system("cls");
			tabelka_z_danymi (gracz1,gracz2);
			rysuj_plansze_pentago( q,w, a, s);
			cout<<	"Graczu 1, podaj pole ";
			cin>>charpole;
		
			};
		
			while (charpole=='h')
			{
			help_pentago(q,w,a,s);
			tabelka_z_danymi (gracz1,gracz2);	
			rysuj_plansze_pentago( q,w, a, s);
			cout<<	"Graczu 1, podaj pole ";
			cin>>charpole;
		
			};
		
			while (charpole=='p')
			{
			pauza(q,w,a,s,gracz1, gracz2);	
			cout<<	"Graczu 1, podaj pole ";
			cin>>charpole;
			
			};
			
			while (charpole=='z')
			{	
			zamiana_zetonu_pentago(gracz1,gracz2, q,w,a,s, zeton_gracza1, zeton_gracza2);
			tabelka_z_danymi (gracz1, gracz2);
   	    	rysuj_plansze_pentago( q,w, a, s);
			cout<<	"Graczu 1, podaj pole ";
			cin>>charpole;
		
			};
		
 	pole=static_cast<int>(charpole) -48;		

} while (pole<1 || pole>9 ||  q[pole-1]!=' ');
	q[pole-1]= gracz1.zeton; 
	rysuj_plansze_pentago( q,w, a, s);
};
	
if (p=='a')	
{
do{
	cout <<"Graczu 1,, podaj pole: ";
	cin>>  charpole;

		while ( charpole=='m')	
		{ opcje() ;
   		 cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> charpole;};
		
		while(charpole=='r')
		{ system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		
		while (charpole=='h')
		{
		help_pentago(q,w,a,s);
		tabelka_z_danymi (gracz1,gracz2);	
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='k')
		{	
		zamiana_zetonu_pentago(gracz1,gracz2, q,w,a,s, zeton_gracza1, zeton_gracza2);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;};
		
 pole=static_cast<int>(charpole) -48;
 		
} while (pole<1 || pole>9 ||  a[pole-1]!=' ');
	a[pole-1]= gracz1.zeton;
	rysuj_plansze_pentago( q,w, a, s); } ;
	
if (p=='w')	
{
do{
	cout <<"Graczu 1, podaj pole: ";
	cin>>  charpole;

		while ( charpole=='m')	
		{ opcje() ;
   		 cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> charpole;};
		
		while(charpole=='r')
		{ 	
		system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		
		while (charpole=='h')
		{
		help_pentago(q,w,a,s);	
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='k')
		{	
		zamiana_zetonu_pentago(gracz1,gracz2, q,w,a,s, zeton_gracza1, zeton_gracza2);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;};
		
 pole=static_cast<int>(charpole) -48;		

} while (pole<1 || pole>9 ||  w[pole-1]!=' ');
	w[pole-1]= gracz1.zeton;
	rysuj_plansze_pentago( q,w, a, s); };
	
if (p=='s')	
{
do{
	cout <<"Graczu 1, podaj pole: ";
	cin>>  charpole;

		while ( charpole=='m')	
		{ opcje() ;
    	cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> charpole;};
		
		while(charpole=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		
		while (charpole=='h')
		{
		help_pentago(q,w,a,s);	
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;
		};
		while (charpole=='z')
		{	
		zamiana_zetonu_pentago(gracz1,gracz2, q,w,a,s, zeton_gracza1, zeton_gracza2);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj pole ";
		cin>>charpole;
		cout<< endl;};
		
 	pole=static_cast<int>(charpole) -48;		

	} while (pole<1 || pole>9 ||  s[pole-1]!=' ');
s[pole-1]= gracz1.zeton;
rysuj_plansze_pentago( q,w, a, s); };



system("cls");
tabelka_z_danymi (gracz1, gracz2);
rysuj_plansze_pentago(q,w,a,s);

//obrot 
do{
	cout <<"Graczu 1, podaj plansze do obrotu: ";
	cin>> plansza_obrot;

	
		while (plansza_obrot=='m')	
		{
		opcje() ;
  	  	cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> plansza_obrot;};
	
		while(plansza_obrot=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj plansze do obrotu : ";
		cin>>plansza_obrot;
		cout<< endl; 
		};
		
		while (plansza_obrot=='h')
		{
		help_pentago(q,w,a,s);	
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj plansze do obrotu: ";
		cin>>plansza_obrot; 
		cout<< endl;
		};
		while (plansza_obrot=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 1, podaj plansze do obrotu: ";
		cin>>plansza_obrot; 
		cout<< endl;
		};
		while (plansza_obrot=='k')
		{	
		zamiana_zetonu_pentago(gracz1,gracz2, q,w,a,s, zeton_gracza1, zeton_gracza2);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj plansze do obrotu";
		cin>>plansza_obrot; 
		cout<< endl;}
		} while (plansza_obrot!='q' && plansza_obrot!='w' && plansza_obrot!='a' && plansza_obrot!='s');
char obrot;
do{

cout<< "graczu 1, wybierz jak obrocic plansze" << endl;

cin>> obrot;

		while ( obrot=='m')	
		{ opcje() ;
   		 cout<<"Wybierz, co chcesz zrobic: " << endl;
		cin>> obrot;}
		
		while(obrot=='r')
		{system("cls");
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj kierunek obrotu ";
		cin>>obrot;
		cout<< endl;
		}
		
		while (obrot=='h')
		{
		help_pentago(q,w,a,s);	
		tabelka_z_danymi (gracz1,gracz2);
		rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, podaj kierunek obrotu";
		cin>>obrot;
		cout<< endl;
		};
		while (obrot=='p')
		{
		pauza(q,w,a,s,gracz1, gracz2);	
		cout<<	"Graczu 1, podaj kierunek obrotu";
		cin>>obrot;;
		cout<< endl;
		};
		while (obrot=='k')
		{	
		zamiana_zetonu_pentago(gracz1,gracz2, q,w,a,s, zeton_gracza1, zeton_gracza2);
		tabelka_z_danymi (gracz1, gracz2);
       	rysuj_plansze_pentago( q,w, a, s);
		cout<<	"Graczu 1, kierunek obrotu ";
		cin>>obrot;
		cout<< endl;};
	
		while(obrot=='z') 
		{ if (plansza_obrot=='q') obrot_w_prawo(q);
		if (plansza_obrot=='w') obrot_w_prawo(w);
		if (plansza_obrot=='a') obrot_w_prawo(a);
		if (plansza_obrot=='s') obrot_w_prawo(s);
		obrot='n';
		};
	
		while(obrot=='x') 
		{ if (plansza_obrot=='q') obrot_w_lewo(q);
		if (plansza_obrot=='w') obrot_w_lewo(w);
		if (plansza_obrot=='a') obrot_w_lewo(a);
		if (plansza_obrot=='s') obrot_w_lewo(s); 
		obrot='l';
		};
}while(obrot!='n' && obrot!='l');
rysuj_plansze_pentago( q,w, a, s);


ruchy[i].zeton=gracz1.zeton;
ruchy[i].ktora_tablica=p;
ruchy[i].ktore_pole=pole;
ruchy[i].tablica_do_obrotu=plansza_obrot;
ruchy[i].obrot=obrot;

i++;
};
//------------------------------------------------------------------------------------
void przeglad_gry(ruch ruchy[36], char q[9],char w[9], char a[9], char s[9], int &i, char predefiniowana, gracz gracz1, gracz gracz2)
{czyszczenie_tablic_pentago (q);
czyszczenie_tablic_pentago (w);
czyszczenie_tablic_pentago (a);
czyszczenie_tablic_pentago (s);

if(predefiniowana='o')
{q[1]=gracz1.zeton;
q[3]=gracz1.zeton;
q[4]=gracz1.zeton;
w[3]=gracz1.zeton;
w[7]=gracz1.zeton;
a[6]=gracz1.zeton;
a[7]=gracz1.zeton;
a[5]=gracz1.zeton;

q[7]=gracz2.zeton;
q[5]=gracz2.zeton;
w[4]=gracz2.zeton;
a[3]=gracz2.zeton;
a[1]=gracz2.zeton;
s[4]=gracz2.zeton;
s[1]=gracz2.zeton;
s[2]=gracz2.zeton;
}
do{ cout << "zeton: " << ruchy[i].zeton << endl;
	cout <<"wybrana tablica: " << ruchy[i].ktora_tablica << endl;
	cout<<"wybrane pole: "<< ruchy[i].ktore_pole  << endl;
	
    if (ruchy[i].ktora_tablica=='q')   	q[ruchy[i].ktore_pole - 1]= ruchy[i].zeton;
	if (ruchy[i].ktora_tablica=='w') 	w[ruchy[i].ktore_pole - 1]= ruchy[i].zeton;
	if (ruchy[i].ktora_tablica=='a') 	a[ruchy[i].ktore_pole - 1]= ruchy[i].zeton;
	if (ruchy[i].ktora_tablica=='s') 	s[ruchy[i].ktore_pole - 1]= ruchy[i].zeton;


	cout<< "plansza wybrana do obrotu: " << ruchy[i].tablica_do_obrotu << endl;
	int zmianapola, poledowymazania;
	zmianapola=ruchy[i].ktore_pole - 1;

	while(ruchy[i].obrot=='n') 
		{ cout << "obrot planszy w prawo" << endl;
		if (ruchy[i].tablica_do_obrotu=='q') obrot_w_prawo(q);
		if (ruchy[i].tablica_do_obrotu=='w') obrot_w_prawo(w);
		if (ruchy[i].tablica_do_obrotu=='a') obrot_w_prawo(a);
		if (ruchy[i].tablica_do_obrotu=='s') obrot_w_prawo(s);
		break;
		};
	
	while(ruchy[i].obrot=='l') 
		{ cout << "obrot planszy w lewo" << endl;
		if (ruchy[i].tablica_do_obrotu=='q') obrot_w_lewo(q);
		if (ruchy[i].tablica_do_obrotu=='w') obrot_w_lewo(w);
		if (ruchy[i].tablica_do_obrotu=='a') obrot_w_lewo(a);
		if (ruchy[i].tablica_do_obrotu=='s') obrot_w_lewo(s);
		break;
		}; 

rysuj_plansze_pentago(q,w,a,s);
system("pause");

cout<<"nacisnij 2, aby isc do kolejnego ruchu; 3 aby zobaczyc poprzedni" << endl;
int kolejny_do_przegladu;
cin>>kolejny_do_przegladu;
system("cls");

while (kolejny_do_przegladu==2)
{	 i++;
	czyszczenie_tablic_pentago (q);
	czyszczenie_tablic_pentago (w);
	czyszczenie_tablic_pentago (a);
	czyszczenie_tablic_pentago (s);
	
if(predefiniowana='o')
{q[1]=gracz1.zeton;
q[3]=gracz1.zeton;
q[4]=gracz1.zeton;
w[3]=gracz1.zeton;
w[7]=gracz1.zeton;
a[6]=gracz1.zeton;
a[7]=gracz1.zeton;
a[5]=gracz1.zeton;

q[7]=gracz2.zeton;
q[5]=gracz2.zeton;
w[4]=gracz2.zeton;
a[3]=gracz2.zeton;
a[1]=gracz2.zeton;
s[4]=gracz2.zeton;
s[1]=gracz2.zeton;
s[2]=gracz2.zeton;
}
	for (int n=0; n<=i; n++)
	{
    if (ruchy[n].ktora_tablica=='q')   	q[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;
	if (ruchy[n].ktora_tablica=='w') 	w[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;
	if (ruchy[n].ktora_tablica=='a') 	a[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;
	if (ruchy[n].ktora_tablica=='s') 	s[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;
	

	while(ruchy[i].obrot=='n') 
	{ 
	if (ruchy[n].tablica_do_obrotu=='q') obrot_w_prawo(q);
	if (ruchy[n].tablica_do_obrotu=='w') obrot_w_prawo(w);
	if (ruchy[n].tablica_do_obrotu=='a') obrot_w_prawo(a);
	if (ruchy[n].tablica_do_obrotu=='s') obrot_w_prawo(s);
	break;
	};
	
	while(ruchy[i].obrot=='l') 
	{
	 if (ruchy[n].tablica_do_obrotu=='q') obrot_w_lewo(q);
	if (ruchy[n].tablica_do_obrotu=='w') obrot_w_lewo(w);
	if (ruchy[n].tablica_do_obrotu=='a') obrot_w_lewo(a);
	if (ruchy[n].tablica_do_obrotu=='s') obrot_w_lewo(s);	
	break;
	}; 	
	} 
	
	rysuj_plansze_pentago(q,w,a,s); 
	cout << "zeton: " << ruchy[i].zeton << endl;
	cout <<"wybrana tablica: " << ruchy[i].ktora_tablica << endl;
	cout<<"wybrane pole: "<< ruchy[i].ktore_pole  << endl;
	cout<< "plansza wybrana do obrotu: " << ruchy[i].tablica_do_obrotu << endl;

	if(ruchy[i].obrot=='n')  cout << "obrot planszy w prawo" << endl;
	if(ruchy[i].obrot=='l')  cout << "obrot planszy w lewo" << endl;

	system("pause");
	cout<<"nacisnij 2, aby isc do kolejnego ruchu; 3 aby zobaczyc poprzedni" << endl;
	cin>>kolejny_do_przegladu;
	system("cls");
};


while(kolejny_do_przegladu==3 && i>=1)
{ 	i--; 
	czyszczenie_tablic_pentago (q);
	czyszczenie_tablic_pentago (w);
	czyszczenie_tablic_pentago (a);
	czyszczenie_tablic_pentago (s);
	
if(predefiniowana='o')
{q[1]=gracz1.zeton;
q[3]=gracz1.zeton;
q[4]=gracz1.zeton;
w[3]=gracz1.zeton;
w[7]=gracz1.zeton;
a[6]=gracz1.zeton;
a[7]=gracz1.zeton;
a[5]=gracz1.zeton;

q[7]=gracz2.zeton;
q[5]=gracz2.zeton;
w[4]=gracz2.zeton;
a[3]=gracz2.zeton;
a[1]=gracz2.zeton;
s[4]=gracz2.zeton;
s[1]=gracz2.zeton;
s[2]=gracz2.zeton;
}
	for (int n=0; n<=i; n++)	
{	
    if (ruchy[n].ktora_tablica=='q')   	q[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;
	if (ruchy[n].ktora_tablica=='w') 	w[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;
	if (ruchy[n].ktora_tablica=='a') 	a[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;
	if (ruchy[n].ktora_tablica=='s') 	s[ruchy[n].ktore_pole - 1]= ruchy[n].zeton;



while(ruchy[n].obrot=='n') 
	{ 
	if (ruchy[n].tablica_do_obrotu=='q') obrot_w_prawo(q);
	if (ruchy[n].tablica_do_obrotu=='w') obrot_w_prawo(w);
	if (ruchy[n].tablica_do_obrotu=='a') obrot_w_prawo(a);
	if (ruchy[n].tablica_do_obrotu=='s') obrot_w_prawo(s);
	break;
	};
	
while(ruchy[n].obrot=='l') 
	{
	 if (ruchy[n].tablica_do_obrotu=='q') obrot_w_lewo(q);
	if (ruchy[n].tablica_do_obrotu=='w') obrot_w_lewo(w);
	if (ruchy[n].tablica_do_obrotu=='a') obrot_w_lewo(a);
	if (ruchy[n].tablica_do_obrotu=='s') obrot_w_lewo(s);
	
	break;
	}; 	
 } 
	rysuj_plansze_pentago(q,w,a,s); 
	cout << "zeton: " << ruchy[i].zeton << endl;
	cout <<"wybrana tablica: " << ruchy[i].ktora_tablica << endl;
	cout<<"wybrane pole: "<< ruchy[i].ktore_pole  << endl;
	cout<< "plansza wybrana do obrotu: " << ruchy[i].tablica_do_obrotu << endl;
	if(ruchy[i].obrot=='n')  cout << "obrot planszy w prawo" << endl;
	if(ruchy[i].obrot=='l')  cout << "obrot planszy w lewo" << endl;

	system("pause");
	cout<<"nacisnij 2, aby isc do kolejnego ruchu; 3 aby zobaczyc poprzedni" << endl;
	cin>>kolejny_do_przegladu;
	system("cls");

};
}while(i>=0 && i<36); }
//---------------------------------------------------------------------------------------------------------------------------------	
void pentago()
{	int i=0;
	ruch ruchy[36];
	gracz gracz1, gracz2;
	char q[9], w[9], a[9], s[9];
	char predefiniowana;
	int zeton_gracza1, zeton_gracza2;
	int ruch_gracza1_wykonany;
	
czyszczenie_tablic_pentago (q);
czyszczenie_tablic_pentago (w);
czyszczenie_tablic_pentago (a);
czyszczenie_tablic_pentago (s);
poczatek_gry(gracz1,gracz2, zeton_gracza1, zeton_gracza2);
system("cls");
cout<<"Czy chcesz wczytac predefiniowana plansze? Jesli tak, nacisnij o " << endl;
cin>>predefiniowana;
system("cls");

if(predefiniowana='o')
{q[1]=gracz1.zeton;
q[3]=gracz1.zeton;
q[4]=gracz1.zeton;
w[3]=gracz1.zeton;
w[7]=gracz1.zeton;
a[6]=gracz1.zeton;
a[7]=gracz1.zeton;
a[5]=gracz1.zeton;

q[7]=gracz2.zeton;
q[5]=gracz2.zeton;
w[4]=gracz2.zeton;
a[3]=gracz2.zeton;
a[1]=gracz2.zeton;
s[4]=gracz2.zeton;
s[1]=gracz2.zeton;
s[2]=gracz2.zeton;
}
while(1) 
{tabelka_z_danymi (gracz1, gracz2);
rysuj_plansze_pentago(q,w,a,s);
ruch_gracza1(q, w, a, s, gracz1,gracz2, ruch_gracza1_wykonany, zeton_gracza1, zeton_gracza2, ruchy, i);

system("cls");
tabelka_z_danymi (gracz1, gracz2);
rysuj_plansze_pentago(q,w,a,s);

if (wygrana_pentago(q,w,a,s,gracz1) ) break;
if (remis_pentago(q,w,a,s)) break;

ruch_gracza2(q, w, a, s, gracz2,gracz1, ruch_gracza1_wykonany, zeton_gracza2, zeton_gracza1, ruchy,i);
rysuj_plansze_pentago(q,w,a,s);
if (wygrana_pentago(q,w,a,s,gracz2) ) break;
if (remis_pentago(q,w,a,s)) break;
system("cls");
};
system("cls");
if (remis_pentago(q,w,a,s)) cout<< "REMIS!!!!!!";
if (wygrana_pentago(q,w,a,s,gracz1) ) cout <<"GRACZ NR 1- " << gracz1.imie << " - WYGRAL" ;
if  (wygrana_pentago(q,w,a,s,gracz2 )) cout <<"GRACZ NR 2-" << gracz2.imie << " - WYGRAL" ;
system("pause");
i=0;

przeglad_gry(ruchy,q,w,a,s,i, predefiniowana, gracz1, gracz2);
}
//------------------------------------------------------------------------------------------------
int main()
{int gra;
cout << "WYBIERZ GRE" << endl;
cout << "1- kolko i krzyzyk 6x6" << endl;
cout << "2- pentago" << endl;

do
{cin>> gra;
if(gra==1) kolko_i_krzyzyk();
if(gra==2) pentago();
	
}while(gra!=1 && gra!=2);


}
