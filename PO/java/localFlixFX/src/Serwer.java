import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Serwer {

        public static Serwer instance;
        private ObservableList<Produkt> produkty = FXCollections.observableArrayList(new ArrayList());
        private ObservableList<Klient> klienci = FXCollections.observableArrayList(new ArrayList());
        private ObservableList<Dystrybutor> dystrybutorzy = FXCollections.observableArrayList(new ArrayList());
        private List<String> aktorzy;
        private List<String> filmy;
        private List<String> imiona;
        private List<String> nazwiska;
        public StringProperty dzienStr = new SimpleStringProperty();
        public StringProperty saldoStr = new SimpleStringProperty();
        private int czasStratny = 0;
        private int cenaBasic = 100;
        private int cenaFamily = 150;
        private int cenaPremium = 170;
        private int dzien = 0;
        private int dlugoscDnia = 500;
        private int saldo = 10000;

        public void zaplac(int hajs) { saldo += hajs; }
        public void usun() { }
        public void serializuj() { }
        public void dodajDystrybutora() { dystrybutorzy.add(new Dystrybutor()); }
        public void day() {
            dzien++;
            dzienStr.setValue("Dzień: " + dzien);
            saldoStr.setValue("Saldo: " + saldo);
            if(dzien % 10 == 0)
                for (Produkt p : produkty) { p.nastepnyMiesiac(); }
            if (dzien % 30 == 0) {
                zaplacDystrybutorom();
                if(saldo < 0) czasStratny++;
                else czasStratny = 0;
                if(czasStratny >= 3) System.exit(0);
            }
            System.out.println("******* Dzień: " + dzien + " " + saldo);
            if (Math.random() < 0.02* Serwer.instance.getProdukty().size()/3)
                klienci.add(new Klient());
        }

        private void zaplacDystrybutorom() {
            for (Dystrybutor d : dystrybutorzy) {
                d.zaplac(d.getPensja());
                saldo -= d.getPensja();
            }
            for (Produkt p : produkty) {
                if (p.getDystrybutor().getZaOdtworzenie() > 0)
                    for (Integer ile : p.getOgladalnosc()) {
                        p.getDystrybutor().zaplac(p.getDystrybutor().getZaOdtworzenie() * ile);
                        saldo -= p.getDystrybutor().getZaOdtworzenie() * ile;
                    }
            }

            System.out.println("Zaplacono Dystrybutorom!!!");
        }

        public Serwer() {
            final ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
            try {
                aktorzy = Files.readAllLines(Paths.get("../../production/localFlixFX/dane/aktorzy.txt"));
                filmy = Files.readAllLines(Paths.get("../../production/localFlixFX/dane/filmy.txt"));
                imiona = Files.readAllLines(Paths.get("../../production/localFlixFX/dane/imiona.txt"));
                nazwiska = Files.readAllLines(Paths.get("../../production/localFlixFX/dane/nazwiska.txt"));
            } catch (IOException e) {
                System.out.println("Cos poszlo nie tak przy wczytywaniu plikow.");
            }
            Thread t = new Thread() {
                @Override
                public void run() {
                    day();
                }
            };
            t.setPriority(1);
            executorService.scheduleAtFixedRate(t, 0, dlugoscDnia, TimeUnit.MILLISECONDS);
            System.out.println("Witamy w naszym systemie");
        }

        public int getDzien() { return dzien; }

        public int getDlugoscDnia() { return dlugoscDnia; }

        public ObservableList<Produkt> getProdukty() { return produkty; }

        public ObservableList<Klient> getKlienci() {return klienci;}

        public ObservableList<Dystrybutor> getDystrybutorzy() {return dystrybutorzy;}

        public List<String> getAktorzy() { return aktorzy; }

        public List<String> getFilmy() { return filmy; }

        public List<String> getImiona() { return imiona; }

        public List<String> getNazwiska() { return nazwiska; }

        public int getCenaBasic() { return cenaBasic; }
        public int getCenaFamily() {return cenaFamily;}
        public int getCenaPremium() {return cenaPremium;}
}
