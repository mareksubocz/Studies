#include "classes.hpp"

Watchable::Watchable(map<string,vector<string>> m, string title, float rating, int runtime)
    : info(m), title(title), rating(rating), runtime(runtime){};

Live::Live(map<string,vector<string>> m, string title, float rating, int runtime, int h) 
		: Watchable(m, title, rating, runtime), godzina(h){};

Movie::Movie(map<string,vector<string>> m, string title, float rating, int runtime, int year)
    : Watchable(m, title, rating, runtime), year(year){};


Series::Series(map<string,vector<string>> m, string title, float rating, int runtime, int total)
    : Watchable(m, title, rating, runtime), totalSeasons(total){};
