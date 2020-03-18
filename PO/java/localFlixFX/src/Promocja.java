import java.util.Random;

public class Promocja {
	private int poczatek;
	private int koniec;
	private int upust;
	
	public Promocja() {
		poczatek = Serwer.instance.getDzien();
		Random rand = new Random();
		koniec = poczatek + rand.nextInt(15) + 1;
		upust = rand.nextInt(45) + 5;
	}
}
