public class Odcinek {
	private int dataPremiery;
	private int dlugosc;
	private Serial wKtorymSerialu;
	public Odcinek(int t, Serial s) {
		wKtorymSerialu = s;
		dataPremiery = Serwer.instance.getDzien();
		dlugosc = (int)Math.random() * 11 - 5;
	}
	public Serial getWKtorymSerialu(){ return wKtorymSerialu; }
}
