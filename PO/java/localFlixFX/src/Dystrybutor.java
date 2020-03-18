import javafx.collections.FXCollections;

public class Dystrybutor extends Thread {
	private String nazwa;
	private boolean czyMiesiecznie;
	private int zaOdtworzenie;
	private int pensja;
	private Integer portfel = 0;
	private boolean doUsuniecia = false;
	
	public void renegocjuj() {
		System.out.println(nazwa + " renegocjował warunki umowy!");
		if(czyMiesiecznie)
			pensja += (int)(Math.random() * 11) - 5;
		else
			zaOdtworzenie += (int)(Math.random() * 2) - 1;
	}
	
    @Override
    public String toString() { return nazwa; }
	
	public void zrobProdukt() {
		int r = (int) (Math.random() * 10);
		Produkt p;
		if(r < 6)
			p = new Film(this);
		else if(r < 9)
			p = new Serial(this);
		else
			p = new Live(this);
		Serwer.instance.getProdukty().add(p);
		System.out.println(nazwa + " -> " + p.getNazwa());
	}
	
	public Dystrybutor() {
		String imie = Serwer.instance.getImiona().get(hashCode() % Serwer.instance.getImiona().size());
		String nazwisko = Serwer.instance.getNazwiska().get(hashCode() % Serwer.instance.getNazwiska().size());
		nazwa = imie + " " + nazwisko;
		if(hashCode() % 2 == 0) {
			czyMiesiecznie = false;
			pensja = 0;
			zaOdtworzenie = (int) (Math.random() * 4 + 1);
		}
		else {
			czyMiesiecznie = true;
			pensja = (int) (Math.random() * 2000 + 1500);
			zaOdtworzenie = 0;
		}
		start();
	}
	
	public void run() {
		System.out.println("Hello from the dystrybutor " + nazwa);
		try {
			while(true) {
				if(doUsuniecia) return;
				Thread.sleep(Serwer.instance.getDlugoscDnia());
				if(Math.random() < 0.1)
					zrobProdukt();
				if(czyMiesiecznie == true && Math.random() < 0.005)
					renegocjuj();
			}
		} catch (InterruptedException e) {System.out.println("cos poszlo nie tak");}
	}


	public void zaplac(int suma) {portfel += suma;}
	public String getNazwa() { return nazwa; }
	public Integer getPensja() { return pensja; }
	public Integer getZaOdtworzenie() {return zaOdtworzenie;}
	public Integer getPortfel() {return portfel;}
	public void setDoUsuniecia(boolean doUsuniecia) { this.doUsuniecia = doUsuniecia; }
}
