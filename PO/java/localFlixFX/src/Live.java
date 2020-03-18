import java.util.ArrayList;
import java.util.List;

public class Live extends Produkt {
	private ArrayList<Promocja> promocje = new ArrayList<Promocja>();
	private int data;
	public Live(Dystrybutor d) {
		super(d, "Live");
		data = Serwer.instance.getDzien() + (int) (Math.random() * 15 + 10);
	}
	public int getData() {return data;}
}
