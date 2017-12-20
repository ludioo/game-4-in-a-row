#include <iostream>
using namespace std;

char pemenang = ' ';
char map[20][20] = {
	{"[=^=^=^=^=^=^=^=]"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"(=%=%=%=%=%=%=%=)"}
};
char giliran = 'M'; // 'M' lalu 'K'

//Penggunaan Function Selesai
bool selesai() {
	int hitung;
	char symbol;
	bool status = false;
	
	//Proses
	for(int i = 1; i <= 12; i+=2) {
		for(int j = 1; j <= 20; j+=2) {
			//Mereset nilai dari variable hitung
			hitung = 1;
			
			//Jika kolom atau baris kosong maka akan mencetak Spasi
			if(map[i][j] == ' ')
				continue;
			
			//memberikan symbol pada map seperti 'M' atau 'B'
			symbol = map[i][j];
			
			//Mengecheck kolom selanjutnya
			for(int k = j + 2; k <= 20; k+=2) {
				//Jika tidak sama
				if(map[i][k] != symbol)
					break;

				hitung++; //Increment variable hitung
			}
			
			//mengehitung apabila sudah ada yang terbentuk 4 horizontal maka dia menang
			if(hitung >= 4) {
				pemenang = symbol;
				break;
			}
			else if()
			
		}
		
		if(pemenang != ' ')
			break;
		
	}
	
	//Mengcheck pemenang
	return pemenang == ' ' ? false : true;
	
}

void cetakMap();
bool isiMap(int simpan);

main() {
	//untuk menyimpan user input
	int simpan;
	
	while(!selesai()) {
		//Membersihkan layar
		system("cls");
		
		//Mencetak map
		cetakMap();
		
		//Inputan user dan outputnya
		cout<<"Giliran pemain ";
		if(giliran == 'M')
			cout<<"Merah";
		else
			cout<<"Biru";
		cout<<endl;
		
		while(1) {
			cout<<"Masukkan kolom: ";
			cin>>simpan;
			
	 		if(isiMap(simpan))
				break;
				
			cout<<"Kolom tidak di temukan"<<endl<<endl;
		}
		
		//Merubah Giliran pemain
		giliran = giliran == 'M' ? 'B' : 'M';
	}
	
	//membersihkan layar dan mencetak ulang map
	system("cls");
	cetakMap();
	
	//Mencetak siapa pemenangnya
	cout<<"\n\n=== Selamat pemenangnya adalah ";
	if(pemenang == 'M')
		cout<<"Merah";
	else
		cout<<"Biru";
	cout<<" ===";
}

//Fungsi mencetak Map 
void cetakMap() {
	for(int i = 0; i < 13; i++) {
		for(int j = 0; j < 19; j++){
			char t = map[i][j];
			
			if(t == '=')
				cout<<char(205);
			else if(t == '|')
				cout<<char(186);
			else if(t == '#')
				cout<<char(206);
			else if(t == '^')
				cout<<char(203);
			else if(t == '<')
				cout<<char(204);
			else if(t == '>')
				cout<<char(185);
			else if(t == '%')
				cout<<char(202);
			else if(t == '[')
				cout<<char(201);
			else if(t == ']')
				cout<<char(187);
			else if(t == '(')
				cout<<char(200);
			else if(t == ')')
				cout<<char(188);
			else
				cout<<t;
		}
		cout<<endl;
	}
}

//Fungsi untuk mengisi map
bool isiMap(int s) {
	//Mengecheck apabila kolom sudah penuh
	if(s < 1 || s > 8 || map[1][s * 2 - 1] != ' ')
		return false;
		
	//Bisa mengisi kolom yang kosong
	for(int i = 13; i >= 1; i-=2) {
		if(map[i][s * 2 - 1] == ' ') {
			map[i][s * 2 - 1] = giliran;
			break;
		}
	}
	
	return true;
}


