import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Sezon {
	private ArrayList<Odcinek> odcinki = new ArrayList<Odcinek>();
	private Serial wKtorymSerialu;
	private int liczbaOdcinkow;
	public Sezon(int t, Serial s) {
		wKtorymSerialu = s;
		Random rand = new Random();
		liczbaOdcinkow = rand.nextInt(26) + 5;
		for (int i = 0; i < liczbaOdcinkow; i++) {
			odcinki.add(new Odcinek(t, s));
		}
	}
	public List<Odcinek> getOdcinki(){return odcinki;};
	public int getLiczbaOdcinkow() {return liczbaOdcinkow;};
}
