import com.sun.xml.internal.fastinfoset.algorithm.BooleanEncodingAlgorithm;

import java.util.ArrayList;

public class Klient extends Thread{
	private ArrayList<Produkt> wykupione = new ArrayList();
	private String wykupioneStr = "";
	private ArrayList<Odcinek> wykupioneOdc = new ArrayList();
	private Abonament abonament;
	private pakiet wersja;
	private String nazwa;
	private String imie;
	private String nazwisko;
	private String dataUrodzenia;
	private String email;
	private int numerKarty;
	private Boolean czyAbonament = false;
	public boolean doUsuniecia = false;
	
	public Klient() {
		imie = Serwer.instance.getImiona().get(hashCode() % Serwer.instance.getImiona().size());
		nazwisko = Serwer.instance.getNazwiska().get(hashCode() % Serwer.instance.getNazwiska().size());
		nazwa = imie +" "+ nazwisko;
		System.gc();
		dataUrodzenia = Integer.toString(hashCode() % 30 + 1) + "." + 
						Integer.toString(hashCode() % 12 + 1) + "." +
						Integer.toString(hashCode() % 60 + 1950);
		email = imie + "." + nazwisko + "@gmail.com";
		numerKarty = hashCode();
		start();
	}
	
    @Override
    public String toString() { 
        return nazwa;
    }
	
	public void kup() {
		if(Math.random() < 0.01){
			abonament = new Abonament();
			wersja = abonament.getWersja();
			czyAbonament = true;
		}
		if(abonament != null) return;
		Produkt tmp;
		do {
		tmp = Serwer.instance.getProdukty().get((int) (Math.random() * Serwer.instance.getProdukty().size()));
		} while(wykupione.contains(tmp));
		int nrSezonu = 0;
		int nrOdcinka = 0;
		if(tmp instanceof Serial) {
			Serial stmp = (Serial) tmp;
			nrSezonu = (int) (Math.random() * stmp.getSezony().size());
			nrOdcinka = (int) (Math.random() * stmp.getSezony().get(nrSezonu).getOdcinki().size());
			wykupioneOdc.add(stmp.getSezony().get(nrSezonu).getOdcinki().get(nrOdcinka));
			wykupione.add(tmp);
		}
		else{
			wykupione.add(tmp);
		}
		System.out.print(imie + " " + nazwisko + " <- " + tmp.getNazwa());
		if(tmp instanceof Serial) {
			System.out.print(" S" + nrSezonu + " E" + nrOdcinka);
		}
		System.out.println();
		Serwer.instance.zaplac(tmp.getCena());
		if(!wykupione.isEmpty()) {
			wykupioneStr = wykupioneStr.concat(wykupione.get(wykupione.size() - 1) + "\n");
		}

	}
	public void wyswietl() {
		Produkt wybrany;
		if(!wykupioneOdc.isEmpty() && Math.random() < 0.5) {
			int tmp = (int)(Math.random()*wykupioneOdc.size());
			if(wykupioneOdc.get(tmp).getWKtorymSerialu() == null){
				wykupioneOdc.remove(wykupioneOdc.get(tmp));
				return;
			}
			Serwer.instance.zaplac(wykupioneOdc.get(tmp).getWKtorymSerialu().getCena());
			wybrany = wykupioneOdc.get(tmp).getWKtorymSerialu();
		}
		else if (!wykupione.isEmpty()){
			wybrany = wykupione.get((int)(Math.random()*wykupione.size()));
			Serwer.instance.zaplac(wybrany.getCena());
		}
		else return;
		if(wybrany != null)
			wybrany.obejrzalem();
	}
	public void zrezygnujZPakietu() {};
	public void setDoUsuniecia(boolean b) {doUsuniecia = b;}
	public Boolean getCzyAbonament(){return czyAbonament;}
	public void run() {
		System.out.println("Hello from the client " + imie + " " + nazwisko);
		try {
			while(true) {
				if(doUsuniecia) return;
				Thread.sleep(Serwer.instance.getDlugoscDnia());
				if(Math.random() < 0.06 && !Serwer.instance.getProdukty().isEmpty())
					kup();
				if(Math.random() < 0.2)
					wyswietl();
				if(czyAbonament && Serwer.instance.getDzien() % 30 == 0) {
					if(abonament.getWersja() == pakiet.Basic)
						Serwer.instance.zaplac(Serwer.instance.getCenaBasic());
					else if(abonament.getWersja() == pakiet.Family)
						Serwer.instance.zaplac(Serwer.instance.getCenaFamily());
					else if (abonament.getWersja() == pakiet.Premium)
						Serwer.instance.zaplac(Serwer.instance.getCenaPremium());
				}
			}
		} catch (InterruptedException e) {System.out.println("cos poszlo nie tak");}
	}

	public String getNazwa() { return nazwa; }
	public String getDataUrodzenia() { return dataUrodzenia; }
	public String getEmail() {return email;}
	public Integer getNumerKarty() {return numerKarty;}
	public ArrayList<Produkt> getWykupione() {return wykupione;}
	public String getWykupioneStr() {return  wykupioneStr;}

	public pakiet getWersja() { return wersja; }
}
