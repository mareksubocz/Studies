#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;

RenderWindow okno(VideoMode(1700 , 1000), "Symulacja Entropia");
int offset;
int particleSize;
int borderSize;
int ilosc;
int maxi = 0;
vector< vector<int> > stan; //stany położenia
vector< vector<int> > stanV;//stany pędu
vector<int> wykres;

void drawBorders() { //odpowiedzialna za rysowanie wszystkich odcinków
    RectangleShape sciana(Vector2f(borderSize, particleSize));
    sciana.setPosition(Vector2f(offset, offset));
    sciana.setFillColor(Color::Black);
    okno.draw(sciana);
    sciana.setPosition(Vector2f(offset, borderSize + offset));
    okno.draw(sciana);
    sciana.setSize(Vector2f(particleSize, borderSize));
    sciana.setPosition(Vector2f(offset, offset));
    okno.draw(sciana);
    sciana.setPosition(Vector2f(borderSize + offset, offset));
    okno.draw(sciana);
    RectangleShape os(Vector2f(borderSize, particleSize));
    os.setFillColor(Color::Black);
    os.setPosition(borderSize + 10 * offset, borderSize + offset);
    okno.draw(os);
}

struct czastka {
    float x, y;
    float vx, vy;
};
//przygotowanie macierzy stanów położeń i pędów:
void inicjalizacjaStanow(int liczbaStanow, int liczbaStanowV) {
    for (int i = 0; i < liczbaStanow; ++i) {
        stan.push_back(vector<int>());
        for (int j = 0; j < liczbaStanow; ++j)
            stan[i].push_back(0);
    }
    for (int i = 0; i < liczbaStanowV; ++i) {
        stanV.push_back(vector<int>());
        for (int j = 0; j < liczbaStanowV; ++j)
            stanV[i].push_back(0);
    }
}

void inicjalizacjaCzastek(czastka p[], int szybkosc) {
    for (int i = 0; i < ilosc; ++i) {
        p[i].x = offset * 2; //wszystkie cząstki zaczynają w pierwszej kolumnie
        p[i].y = (std::rand() % (borderSize - offset * 2)) + offset * 2;
//losowanie wartosci od -1 do 1 i pomnozenie ich przez ustaloną szybkosc:
        p[i].vx = (((float(rand()) / float(RAND_MAX)) * 2) - 1) * szybkosc;
        p[i].vy = (((float(rand()) / float(RAND_MAX)) * 2) - 1) * szybkosc;
    }
}

void ruchCzastek(czastka p[], Clock * clock) {
    Time et;
    et = clock->restart();
    for (int i = 0; i < ilosc; ++i) {   //odbicia od ścian
        if (p[i].x >= borderSize + offset - 2 * particleSize)
            p[i].vx = -abs(p[i].vx);
        if (p[i].x <= offset + particleSize)
            p[i].vx = abs(p[i].vx);
        if (p[i].y >= borderSize + offset - 2 * particleSize)
            p[i].vy = -abs(p[i].vy);
        if (p[i].y <= offset + particleSize)
            p[i].vy = abs(p[i].vy);
    }
    for (int i = 0; i < ilosc; ++i) {   //ruch cząstek
        p[i].x += (p[i].vx * et.asSeconds());
        p[i].y += (p[i].vy * et.asSeconds());
    }
}

void rysujWykres(int lnP) {
    wykres.push_back(lnP);
    CircleShape point(2); //grubość wykresu
    point.setFillColor(Color::Red);
    RectangleShape rekord(Vector2f(borderSize, particleSize));
    rekord.setFillColor(Color::Red);
    if(lnP > maxi)
        maxi = lnP;
    //linia wyznaczająca maksymalną entropię:
    rekord.setPosition(borderSize + 10 * offset, float(borderSize) + float(offset) - float(maxi)/float(ilosc) * 100);
    okno.draw(rekord);
    //rysowanie kolejnych punktów wykresu:
    for (int i = 0; i < wykres.size(); ++i){
        point.setPosition(borderSize + 10 * offset + float(i)/10,
        float(borderSize) + float(offset) - float(wykres[i])/float(ilosc) * 100);
        okno.draw(point);
    }
}

void liczEntropie(czastka p[], int liczbaStanow, int liczbaStanowV, int szybkosc) {
    int a, b;
    //wyliczenie gęstości zapełnienia stanów:
    for (int i = 0; i < liczbaStanow; ++i)
        for (int j = 0; j < liczbaStanow; ++j)
            stan[i][j] = 0;
    for (int i = 0; i < ilosc; ++i) {
        a = (p[i].x - offset) / (borderSize / liczbaStanow);
        b = (p[i].y - offset) / (borderSize / liczbaStanow);
        if (a >= liczbaStanow)
            a = liczbaStanow - 1;
        if (b >= liczbaStanow)
            b = liczbaStanow - 1;
        stan[b][a]++;
    }
    for (int i = 0; i < liczbaStanowV; ++i)
        for (int j = 0; j < liczbaStanowV; ++j)
            stanV[i][j] = 0;
    for (int i = 0; i < ilosc; ++i) {
        a = (p[i].vx + szybkosc) * liczbaStanowV / (szybkosc * 2) ;
        b = (p[i].vy + szybkosc) * liczbaStanowV / (szybkosc * 2) ;
        stanV[b][a]++;
    }
    //wyliczenie entropii na podstawie gęstości zapełnienia
    //poszczególnych stanów:
    long long lnP = 0;
    for (int i = 0; i < liczbaStanow; ++i){
        for (int j = 0; j < liczbaStanow; ++j){
            if(stan[i][j] > 0)
                lnP -= stan[i][j]*log(float(stan[i][j])) - stan[i][j];
        }
    }
    lnP += ilosc*log(float(ilosc))-ilosc;
    // cout<<"Entropia: "<<lnP<<endl;
    rysujWykres(lnP);
    //wypisanie stanów w terminalu w postaci macierzy:
    for (int i = 0; i < liczbaStanow; ++i){
        for (int j = 0; j < liczbaStanow; ++j)
            cout<<stan[i][j]<<",";
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i < liczbaStanowV; ++i){
        for (int j = 0; j < liczbaStanowV; ++j)
            cout<<stanV[i][j]<<",";
        cout<<endl;
    }
    cout<<endl<<"*******************************"<<endl;
}


int main(int argc, char const *argv[]) {
    srand(time(NULL));
    borderSize = 800;
    ilosc = 1000;
    int szybkosc = 50;
    int r = int(log2(float(ilosc)));
    int liczbaStanow = (2 * r) + 1;
    int liczbaStanowV = r + (r % 2);
    Clock clock;
    czastka p[ilosc];
    offset = 10;
    particleSize = 3;
    CircleShape circ(particleSize);
    circ.setFillColor(Color::Green);

    inicjalizacjaCzastek(p, szybkosc);
    inicjalizacjaStanow(liczbaStanow, liczbaStanowV);
    Event zdarzenie;
    while (okno.isOpen()) {
        while (okno.pollEvent(zdarzenie)) { //wyłączanie klawiszem ESC
            if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
                okno.close();
            if (zdarzenie.type == Event::Resized){
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, zdarzenie.size.width, zdarzenie.size.height);
                okno.setView(sf::View(visibleArea));
            }
        }
        okno.clear(Color::White);
        drawBorders();
        ruchCzastek(p, &clock);
        for (int i = 0; i < ilosc; ++i) { //rysowanie czastek
            circ.setPosition(p[i].x, p[i].y);
            okno.draw(circ);
        }
        liczEntropie(p, liczbaStanow, liczbaStanowV, szybkosc);
        okno.display();
    }
    return 0;
}