#ifndef classes_hpp
#define classes_hpp
#include <bits/stdc++.h>
using namespace std;

class Watchable {
  map<string, vector<string>> info;
  string title;
  float rating;
  int runtime;

 public:
  Watchable(map<string, vector<string>>, string, float, int);
  inline map<string, vector<string>> getInfo() {return info;};
 	inline string getTitle() {return title;};
 	inline float getRating() {return rating;};
 	inline void setRating(float x) {rating = x;};
 	inline int getRuntime() {return runtime;};
 	inline void setRuntime(int x) {runtime = x;};
};

class Live : public Watchable {
  int godzina;
 public:
  Live(map<string, vector<string>>, string, float, int, int);
};

class Movie : public Watchable {
  int year;

 public:
  Movie(map<string, vector<string>>, string, float, int, int);
};

class Series : public Watchable {
  int totalSeasons;

 public:
  Series(map<string, vector<string>>, string, float, int, int);
};

#endif