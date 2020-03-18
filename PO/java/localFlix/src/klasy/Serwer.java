package klasy;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;


import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;


public class Serwer {
	public static Serwer instance;
	private MainFrame gui;
	private ArrayList<Produkt> produkty = new ArrayList<>();
	private ArrayList<Klient> klienci = new ArrayList<Klient>();
	private ArrayList<Dystrybutor> dystrybutorzy = new ArrayList<>();
	private ArrayList<JLabel> zdjecia = new ArrayList<>(); 
	private List<String> aktorzy;
	private List<String> filmy;
	private List<String> imiona;
	private List<String> nazwiska;
	private int czasStratny = 0;
	private int cenaBasic = 100;
	private int cenaFamily = 150;
	private int cenaPremium = 170;
	private int dzien = 0;
	private int dlugoscDnia = 1000;
	private int saldo = 7000;
	
	public Produkt wyszukaj() {return null;};
	public void ustawCene() {};
	public void zlistuj() {};
	public void wykres() {};
	public void zaplac(int hajs) {saldo += hajs;}
	public void usun() {};
	public void serializuj() {};
	public void odczytajStan() {};
	public void sprawdzZysk() {};
	public void dodajKlienta() {
		klienci.add(new Klient());
	};
	public void dodajDystrybutora() {
		dystrybutorzy.add(new Dystrybutor());
	};
	public void day() {
		dzien++;
		if(dzien % 30 == 0)
			for (Produkt p : produkty) { p.nastepnyMiesiac(); }
		System.out.println("******* Dzień: " + dzien + " " + saldo);
		if(Math.random() < 0.5) //* Serwer.instance.getProdukty().size()/3)
			klienci.add(new Klient());
		if(getDzien() % 30 == 0) zaplacDystrybutorom();
	}
	private void zaplacDystrybutorom() {
		for (Dystrybutor d : dystrybutorzy) {
			d.zaplac(d.getPensja());
			saldo -= d.getPensja();
		}
		for (Produkt p : produkty) {
			if(p.getDystrybutor().getZaOdtworzenie() > 0)
				for (Integer ile : p.getOgladalnosc()) {
					p.getDystrybutor().zaplac(p.getDystrybutor().getZaOdtworzenie() * ile);
					saldo -= p.getDystrybutor().getZaOdtworzenie();
				}
		}
		
		System.out.println("Zaplacono Dystrybutorom!!!");
	};
	public Serwer() {
	    final ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
	    new ButtonListener();
	    try {
			aktorzy = Files.readAllLines(Paths.get("src/aktorzy.txt"));
			filmy = Files.readAllLines(Paths.get("src/filmy.txt"));
			imiona = Files.readAllLines(Paths.get("src/imiona.txt"));
			nazwiska = Files.readAllLines(Paths.get("src/nazwiska.txt"));
		} catch (IOException e) {System.out.println("Cos poszlo nie tak przy wczytywaniu plikow.");}
	    Thread t = new Thread() {
	        @Override
	        public void run() {
					day();
	        }
	    };
	    t.setPriority(1);
	    executorService.scheduleAtFixedRate(t, 0, dlugoscDnia, TimeUnit.MILLISECONDS);
	    System.out.println("Witamy w naszym systemie");
	}
	
	public static void main(String args[]) {
		instance = new Serwer();
		instance.gui = new MainFrame("LocalFlix");
		
		File folder = new File("src/zdjecia");
		File[] listOfFiles = folder.listFiles();
		ArrayList<String> paths = new ArrayList<>();
		for (int i = 0; i < listOfFiles.length; i++) {
			if (listOfFiles[i].isFile()) {
				paths.add(listOfFiles[i].getName());
			}
		}
		for (String path : paths) {
			instance.zdjecia.add(new JLabel(new ImageIcon("src/zdjecia/"+path)));
		}

	}
	
	public int getDzien() {return dzien;};
	public int getDlugoscDnia() {return dlugoscDnia;};
	public ArrayList<Produkt> getProdukty() {return produkty;};
	public List<String> getAktorzy() {return aktorzy;}
	public List<String> getFilmy() {return filmy;}
	public List<String> getImiona() {return imiona;}
	public List<String> getNazwiska() {return nazwiska;}
	public List<JLabel> getZdjecia() {return zdjecia;}
	public MainFrame getGui() {return gui;}
}
