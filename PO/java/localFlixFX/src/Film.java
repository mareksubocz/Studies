import java.util.ArrayList;
import java.util.List;

public class Film extends Produkt {
	private ArrayList<Promocja> promocje = new ArrayList<Promocja>();
	private ArrayList<String> aktorzy = new ArrayList<String>();
	private ArrayList<String> linki = new ArrayList<String>();
	private gatunek g;
	private int czasPoZakupie;
	public Film(Dystrybutor d) {
		super(d, "Film");
	}
}
