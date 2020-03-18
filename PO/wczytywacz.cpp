#include <bits/stdc++.h>
#include <curl/curl.h>
using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, string* data)
{
  data->append((char*)contents, size * nmemb);
  return size * nmemb;
}

map<string, vector<string> > analyzeResponse(string & buf){
	map<string, vector<string> > m;
	string kategoria, odp;
	for (int i = 0; i < buf.size(); ++i){
		if(buf[i] == '"'){	//zaczynamy nową kategorię
			kategoria.clear();
			for (++i; buf[i] != '"'; ++i) kategoria += buf[i]; //wczytujemy ją
			i+=2;
			if(buf[i] == '['){	//jezeli rekurencja
				while(buf[i] != ']') i++;
				continue;				//pomijamy wszystko co w nawiasach kwadratowych
			}
			m.insert(pair<string, vector<string> >(kategoria,vector<string>()));
			//zaczynamy odpowiedz, zakladam ze i jest na " !!!
				for (++i; buf[i] !='"'; ++i){
					if(buf[i] == ',') {
						m[kategoria].push_back(odp);
						odp.clear();
						// if(buf[i+1] == ' ') i++;
					}
					else odp += buf[i]; 
				}
			m[kategoria].push_back(odp);
			odp.clear();
		}
	}
	return m;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  string title;
	string readBuffer;
	map<string, vector<string> > zestaw;
  while (true) {
	  cout<<"*******************************"<<endl;
	  cout<<"gimme title: ";
    getline(cin, title); if(title == "-") break;
	  cout<<"*******************************"<<endl;
  	for (int i = 0; i < title.size(); ++i) 
  		if(title[i] == ' ') 
  			title[i] = '+';
    curl = curl_easy_init();
    if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, ("http://www.omdbapi.com/?apikey=9d3b578b&t=" + title).c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      readBuffer.clear();
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      zestaw = analyzeResponse(readBuffer);

			map<string,vector<string> >::iterator it = zestaw.begin();
		  for (it=zestaw.begin(); it!=zestaw.end(); ++it){
		    cout << it->first << ": ";
		    for (int i = 0; i < it->second.size(); ++i){
		     	cout << it->second[i];
		     	if(i != it->second.size()-1)
		     		cout<<",";
		    }
			  cout<<endl;
		  }
    }
  }
  return 0;
}