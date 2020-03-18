#include "pula.cpp"
using namespace std;

void printHelp() {
  cout << "h - help" << endl;
  cout << "a - add film to database" << endl;
  cout << "r - remove film from database" << endl;
  cout << "e - edit film" << endl;
  cout << "i - get info" << endl;
  cout << "l - list films" << endl;
  cout << "x - exit" << endl;
}

void wczytajZPliku(Pula<Series> & pulaS, Pula<Movie> & pulaM){
	fstream plik;
	plik.open("pula.txt");
	string title;
	if(plik.good()){
		while (!plik.eof()){
			getline(plik, title);
			if(title != ""){
				if(Pula<Series>::wczytajFilm(title)["Type"][0] == "Series")
					pulaS += title;
				else
					pulaM += title;
			}
		}
	}
  else throw "nie udało się otworzyć pliku pula.txt";
  plik.close();
}

void menu(Pula<Series> & pulaS, Pula<Movie> & pulaM, Pula<Live> & pulaL) {
  char c;
  while (true) {
	  cout << endl << "enter h to receive a help" << endl;
    cin>>c; //sprawdzić czy nie wczytuje razem z endlinem
    int a;
    string title;
    if (c == 'h') printHelp();
    else if (c == 'a'){
    	cout<<"1 - serial, 2 - film, 3 - live"<<endl;
    	cin>>a;
    	cout<<"podaj tytul"<<endl;
    	getline(cin, title);
    	getline(cin, title);
    	if(a == 1) pulaS += title, pulaS.saveLast();
    	if(a == 2) pulaM += title, pulaM.saveLast();
    	if(a == 3) pulaL += title;
    }
    else if (c == 'l') pulaS.listuj(), pulaM.listuj(), pulaL.listuj();
    else if (c == 'i') {
    	cout<<"podaj tytul"<<endl;
    	getline(cin, title);
    	getline(cin, title);
    	pulaS.info(title), pulaM.info(title), pulaL.info(title);
    }
    else if (c == 'r') {
    	cout<<"podaj tytul"<<endl;
    	getline(cin, title);
    	getline(cin, title);
    	pulaS.removeFilm(title), pulaM.removeFilm(title), pulaL.removeFilm(title);
    }    
    else if (c == 'e') {
    	cout<<"podaj tytul"<<endl;
    	getline(cin, title);
    	getline(cin, title);
    	pulaS.editFilm(title), pulaM.editFilm(title), pulaL.editFilm(title);
    }
    // else if (s == 's' or s == "stats") Pula::printStats();
    else if (c == 'x') return;
    else  cout << "Nieznana opcja :(" << endl;
  }
}

int main(){
	try{
	Pula<Series> pulaS;
	Pula<Movie> pulaM;
	Pula<Live> pulaL;
	wczytajZPliku(pulaS, pulaM);
	menu(pulaS, pulaM, pulaL);
	}
	catch(string s) {cout<<s<<endl;}
	catch(...) {cout<<"cos poszlo nie tak"<<endl;}
	return 0;
}