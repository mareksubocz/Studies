#include <curl/curl.h>
#include "classes.cpp"
template <class T> class Pula {
  vector<T> pula;
  void getFilmInfo();
  void printStats();
  static size_t bufToStr(void *cont, size_t size, size_t nmemb, string *data) {
    data->append((char *)cont, size * nmemb);
    return size * nmemb;
  }
  static map<string, vector<string>> analyzeResponse(string &buf) {
    map<string, vector<string>> m;
    string kategoria, odp;
    for (int i = 0; i < buf.size(); ++i)
      if (buf[i] == '"') {  // zaczynamy nową kategorię
        kategoria.clear();
        for (++i; buf[i] != '"'; ++i) kategoria += buf[i];  // wczytujemy ją
        i += 2;
        if (buf[i] == '[') {  // jezeli rekurencja
          while (buf[i] != ']') i++;
          continue;  // pomijamy wszystko co w nawiasach kwadratowych
        }
        m.insert(pair<string, vector<string>>(kategoria, vector<string>()));
        // zaczynamy odpowiedz, zakladam ze i jest na " !!!
        for (++i; buf[i] != '"'; ++i) {
          if (buf[i] == ',') {
            m[kategoria].push_back(odp);
            odp.clear();
          } else
            odp += buf[i];
        }
        m[kategoria].push_back(odp);
        odp.clear();
      }
    return m;
  }
public:
  static map<string, vector<string>> wczytajFilm(string title) {
    CURL *curl;
    string readBuffer;
    for (int i = 0; i < title.size(); ++i)
      if (title[i] == ' ') title[i] = '+';
    curl = curl_easy_init();
    if (curl) {
      curl_easy_setopt(
          curl, CURLOPT_URL,
          ("http://www.omdbapi.com/?apikey=9d3b578b&t=" + title).c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, bufToStr);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      return analyzeResponse(readBuffer);
    }
  }

void editFilm(string title){
  int x;
  for (int i = 0; i < pula.size(); ++i)
    if(pula[i].getTitle() == title){
      cout<<"Co chcesz edytować?"<<endl;
      cout<<"1 - rating, 2 - czas trwania"<<endl;
      cin>>x;
      if(x == 1){
        cout<<"Podaj nowy rating"<<endl;
        cin>>x;
        pula[i].setRating(x);
      }
      else{
        cout<<"Podaj nowy czas trwania"<<endl;
        cin>>x;
        pula[i].setRuntime(x);
      }
    }
}

void eraseFileLine(string eraseLine) {
  string line;
  ifstream plik;
  plik.open("pula.txt");
  ofstream temp;
  temp.open("temp.txt");
  while (getline(plik, line)) {
      if (line != eraseLine)
          temp << line << endl;
  }
  temp.close();
  plik.close();
  rename("temp.txt", "pula.txt");
}

  void removeFilm(string title){
    for (int i = 0; i < pula.size(); ++i)
      if(pula[i].getTitle() == title){
        pula.erase(pula.begin() + i);
        eraseFileLine(title);
      }
  }

  void info(string title){
    for (int i = 0; i < pula.size(); ++i)
      if(pula[i].getTitle() == title){
        cout<<"*************************"<<endl;
        map<string,vector<string> >::iterator it;
        map<string, vector<string> > info = pula[i].getInfo();
        for (it=info.begin(); it!=info.end(); ++it){
          cout << it->first << ": ";
          for (int j = 0; j < it->second.size(); ++j){
            cout << it->second[j];
            if(j != it->second.size()-1)
              cout<<",";
          }
        cout<<endl;
        }
        cout<<"rating: "<<pula[i].getRating()<<endl;
        cout<<"czas trwania: "<<pula[i].getRuntime()<<endl;
      }
  }

  void saveLast(){
    ofstream plik("pula.txt", ios::app);
    if (plik.good())
      plik << pula[pula.size()-1].getTitle() << endl;
    else throw "nie udało się otworzyć pliku pula.txt";
    plik.close();
  }
  void listuj(){
    for (int i = 0; i < pula.size(); ++i)
      cout<<"-"<<pula[i].getTitle()<<endl;
  }
  Pula operator+=(string t) {  // dodaje do puli, wektora klasy i pliku
      map<string, vector<string> > info;
      if(typeid(T).name() == typeid(Live).name()){
        cout<<"By uzupełnić dane, użyj opcji edytuj."<<endl;
        map<string, vector<string> > emptyMap;
        T newt(emptyMap, t, 0, 0, 0);
        pula.push_back(newt);
      }
      else{ //jezeli serial lub film, wczytujemy!
        info = wczytajFilm(t);
        if(info["Response"][0] == "False"){
          cout<<"Nie znaleziono danych w internecie. ";
          cout<<"By uzupełnić dane, użyj opcji edytuj."<<endl;
        }
        else{
          cout<<"Wczytano dane z internetu!"<<endl;
          float rating;
          int runtime;
          int x;
          string title;
          for (int i = 0; i < info["Title"].size(); ++i)
            title += info["Title"][i];
          if(info["imdbRating"][0] == "N/A") rating = 0;
          else rating = stof(info["imdbRating"][0]);
          if(info["Runtime"][0] == "N/A") runtime = 0;
          else{
            string str = info["Runtime"][0];
            str = str.substr(0, str.size() - 4);
            runtime = stoi(str);
          }
          if(info.count("totalSeasons")){
            if(info["totalSeasons"][0] == "N/A") x = 0;
            else x = stoi(info["totalSeasons"][0]);
          }
          else if(info.count("Year")){
            if(info["Year"][0] == "N/A") x = 0;
            else x = stoi(info["Year"][0]);
          }
          pula.push_back(T(info, title, rating, runtime, x));
        }
      }
    
    return *this;
  }

  Pula operator-=(string title) {  // usuwa po tytule
    fstream plik;
    plik.open("pula.txt");
    if (plik.good()) {

    } 
    else throw "nie udało się otworzyć pliku pula.txt";
    plik.close();
  }
};