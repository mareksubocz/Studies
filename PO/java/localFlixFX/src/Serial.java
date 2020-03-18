import java.util.ArrayList;
import java.util.Random;

public class Serial extends Produkt {
	private ArrayList<Promocja> promocje = new ArrayList<Promocja>();
	private ArrayList<String> aktorzy = new ArrayList<String>();
	private ArrayList<String> linki = new ArrayList<String>();
	private ArrayList<Sezon> sezony = new ArrayList<Sezon>();
	private int liczbaSezonow;
	private gatunek g;
	private int czasPoZakupie;
	private int przyblizonyCzasOdcinka;
	
	public Serial(Dystrybutor d) {
		super(d, "Serial");
		Random rand = new Random();
		g = gatunek.values()[rand.nextInt(gatunek.values().length)];
        przyblizonyCzasOdcinka = (rand.nextInt(18) + 3) * 5;
        liczbaSezonow = rand.nextInt(8)+1;
        for (int i = 0; i < liczbaSezonow; i++) {
			sezony.add(new Sezon(przyblizonyCzasOdcinka, this));
		}
	}
	
	public ArrayList<Sezon> getSezony(){return sezony;};
}
