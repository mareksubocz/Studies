import java.util.HashMap;

enum pakiet{
	Basic,
	Family,
	Premium
}

public class Abonament {
	private pakiet wersja;
	public Abonament() {
		int w = (int) (Math.random() * 3);
		if(w == 0) wersja = pakiet.Basic;
		if(w == 1) wersja = pakiet.Family;
		if(w == 2) wersja = pakiet.Premium;
	}
	public pakiet getWersja(){return wersja;}
}
