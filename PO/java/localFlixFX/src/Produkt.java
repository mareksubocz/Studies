import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;
import javax.swing.JLabel;

enum gatunek{
	sensacja,
	dramat,
	komedia,
	dlaDzieci,
	dokument,
	akcja
}

public abstract class Produkt {
	private SimpleStringProperty nazwa = new SimpleStringProperty();
	private String aktorzy;
	private Integer czasTrwania;
	private Integer cena;
	private Integer ocenaUzytkownikow;
	private Integer czasPoZakupie;
	private ObservableList<Integer> ogladalnosc = FXCollections.observableArrayList(new ArrayList<>());
	private Dystrybutor dystrybutor;
	private String typ;
	
    @Override
    public String toString() { return nazwa.getValue(); }
	
	public Produkt(Dystrybutor d, String typ) {
		ogladalnosc.add(0);
		this.typ = typ;
		Random rand = new Random();
		ocenaUzytkownikow = rand.nextInt(10)+1;
		cena = rand.nextInt(20) + 15;
		czasTrwania = rand.nextInt(121)+20;
		czasPoZakupie = rand.nextInt(7) + 1;
		dystrybutor = d;
		setNazwa(Serwer.instance.getFilmy().get(hashCode() % Serwer.instance.getFilmy().size()));
		int liczbaAktorow = 2;
		aktorzy = "";
		for (int i = 0; i < liczbaAktorow; i++)
			aktorzy += (Serwer.instance.getAktorzy().get((int) (Math.random() * Serwer.instance.getAktorzy().size()))) + "\n";
	}

	public void obejrzalem() {
    	if(ogladalnosc.isEmpty())
    		ogladalnosc.add(0);
    	ogladalnosc.set(ogladalnosc.size()-1, ogladalnosc.get(ogladalnosc.size()-1)+1);
    }
	public void nastepnyMiesiac() { ogladalnosc.add(0); }
	public String getNazwa() {return nazwa.getValue();}
	public String getAktorzy() {return aktorzy;}
	public Integer getCzasTrwania() {return czasTrwania;}
	public Integer getCena() {return cena;}
	public Integer getOcenaUzytkownikow() {return ocenaUzytkownikow;}
	public Integer getCzasPoZakupie() {return czasPoZakupie;}
	public ObservableList<Integer> getOgladalnosc() {return ogladalnosc;}
	public Dystrybutor getDystrybutor() {return dystrybutor;}
	public String getTyp() {return typ;}
	public void setNazwa(String nazwa) {this.nazwa.set(nazwa);}
}
