import com.jfoenix.controls.JFXButton;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.chart.BubbleChart;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseButton;
import javafx.scene.text.Text;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

public class GuiController implements Initializable {
    @FXML
    private Button dystrybutorButton;
    @FXML
    private Button exitButton;
    @FXML
    private Button usunButton;
    @FXML
    private TableView<Produkt> produktyTable = new TableView<>();
    @FXML
    private TableView<Klient> klienciTable = new TableView<>();
    @FXML
    private TableView<Dystrybutor> dystrybutorzyTable = new TableView<>();
    @FXML
    private TextField searchField;
    @FXML
    private Text dzienText;
    @FXML
    private Text saldoText;
    @FXML
    private LineChart<Number, Number> wykres = new LineChart<>(new NumberAxis(), new NumberAxis());
    @FXML
    private Produkt kliknietyProdukt;
    private Klient kliknietyKlient;
    private Dystrybutor kliknietyDystrybutor;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        dystrybutorButton.setStyle("-fx-background-color: green");
        usunButton.setStyle("-fx-background-color: yellow");
        exitButton.setStyle("-fx-background-color: crimson");
        searchField.setPromptText("Search");
        dzienText.textProperty().bind(Serwer.instance.dzienStr);
        saldoText.textProperty().bind(Serwer.instance.saldoStr);

        //Produkty:
        TableColumn<Produkt, String> ProdNazwaCol = new TableColumn<>("Nazwa");
        ProdNazwaCol.setCellValueFactory(new PropertyValueFactory<>("nazwa"));
        ProdNazwaCol.setMinWidth(300);

        TableColumn<Produkt, Integer> czasTrwaniaCol = new TableColumn<>("Czas Trwania");
        czasTrwaniaCol.setCellValueFactory(new PropertyValueFactory<>("czasTrwania"));
        czasTrwaniaCol.setPrefWidth(90);

        TableColumn<Produkt, Integer> cenaCol = new TableColumn<>("Cena");
        cenaCol.setCellValueFactory(new PropertyValueFactory<>("cena"));
        cenaCol.setPrefWidth(60);

        TableColumn<Produkt, Dystrybutor> dystrybutorCol = new TableColumn<>("Dystrybutor");
        dystrybutorCol.setCellValueFactory(new PropertyValueFactory<>("dystrybutor"));
        dystrybutorCol.setMinWidth(110);

        TableColumn<Produkt, String> aktorzyCol = new TableColumn<>("Aktorzy");
        aktorzyCol.setCellValueFactory(new PropertyValueFactory<>("aktorzy"));
        aktorzyCol.setMinWidth(150);

        TableColumn<Produkt, String> typCol = new TableColumn<>("Typ");
        typCol.setCellValueFactory(new PropertyValueFactory<>("typ"));
        typCol.setPrefWidth(50);

        TableColumn<Produkt, Integer> ocenaCol = new TableColumn<>("Ocena");
        ocenaCol.setCellValueFactory(new PropertyValueFactory("ocenaUzytkownikow"));
        ocenaCol.setPrefWidth(60);
        //        TableColumn<Produkt, String> firstAktorCol = new TableColumn<>("Gwiazda");
        //        TableColumn<Produkt, String> lastAktorCol = new TableColumn<>("Poboczny");
        //        aktorzyCol.getColumns().addAll(firstAktorCol, lastAktorCol);
        produktyTable.setItems(Serwer.instance.getProdukty());
        produktyTable.getColumns().addAll(ProdNazwaCol, typCol, czasTrwaniaCol, cenaCol, dystrybutorCol, ocenaCol, aktorzyCol);
        produktyTable.setRowFactory(tv -> {
            TableRow<Produkt> row = new TableRow<>();
            row.setOnMouseClicked(event -> {
                if(!row.isEmpty() && event.getButton() == MouseButton.PRIMARY){
                    Produkt clickedRow = row.getItem();
                    kliknietyProdukt = clickedRow;
                    kliknietyDystrybutor = null;
                    kliknietyKlient = null;
                }
                if(!row.isEmpty() && event.getButton() == MouseButton.PRIMARY && event.getClickCount() == 2){
                    Produkt clickedRow = row.getItem();
                    XYChart.Series series = new XYChart.Series();
                    series.setName("Oglądalność Produktu");
                    for (int i = 0; i < clickedRow.getOgladalnosc().size(); i++) {
                        series.getData().add(new XYChart.Data(i * 10, clickedRow.getOgladalnosc().get(i)));
                    }
                    wykres.getData().add(series);
                    wykres.toFront();
                }
            });
            return row;
        });
        //Klienci:
        TableColumn<Klient, String> klientNazwaCol = new TableColumn<>("Imię i nazwisko");
        klientNazwaCol.setCellValueFactory(new PropertyValueFactory<>("nazwa"));
        klientNazwaCol.setMinWidth(150);

        TableColumn<Klient, String> dataUrodzeniaCol = new TableColumn<>("Data Urodzenia");
        dataUrodzeniaCol.setCellValueFactory(new PropertyValueFactory<>("dataUrodzenia"));

        TableColumn<Klient, String> emailCol = new TableColumn<>("Email");
        emailCol.setCellValueFactory(new PropertyValueFactory<>("email"));

        TableColumn<Klient, Integer> numerKartyCol = new TableColumn<>("Numer Karty");
        numerKartyCol.setCellValueFactory(new PropertyValueFactory<>("numerKarty"));

        TableColumn<Klient, ArrayList<Produkt>> wykupioneCol = new TableColumn<>("Wykupione");
        wykupioneCol.setCellValueFactory(new PropertyValueFactory<>("wykupioneStr"));
        wykupioneCol.setMinWidth(250);

        TableColumn<Klient, pakiet> abonamentCol = new TableColumn<>("Abonament");
        abonamentCol.setCellValueFactory(new PropertyValueFactory<>("wersja"));

        klienciTable.setItems(Serwer.instance.getKlienci());
        klienciTable.getColumns().addAll(klientNazwaCol, dataUrodzeniaCol, emailCol, numerKartyCol, wykupioneCol, abonamentCol);
        klienciTable.setRowFactory(tv -> {
            TableRow<Klient> row = new TableRow<>();
            row.setOnMouseClicked(event -> {
                if(!row.isEmpty() && event.getButton() == MouseButton.PRIMARY){
                    Klient clickedRow = row.getItem();
                    kliknietyKlient = clickedRow;
                    kliknietyDystrybutor = null;
                    kliknietyProdukt = null;
                }
            });
            return row;
        });
        //Dystrybutorzy:
        TableColumn<Dystrybutor, String> dystNazwaCol = new TableColumn<>("Imię i nazwisko");
        dystNazwaCol.setCellValueFactory(new PropertyValueFactory<>("nazwa"));
        dystNazwaCol.setMinWidth(300);

        TableColumn<Dystrybutor, Integer> zaOdtworzenieCol = new TableColumn<>("Za odtworzenie");
        zaOdtworzenieCol.setCellValueFactory(new PropertyValueFactory<>("zaOdtworzenie"));

        TableColumn<Dystrybutor, Integer> pensjaCol = new TableColumn<>("Miesięcznie");
        pensjaCol.setCellValueFactory(new PropertyValueFactory<>("pensja"));

        TableColumn<Dystrybutor, Integer> portfelCol = new TableColumn<>("Portfel");
        portfelCol.setCellValueFactory(new PropertyValueFactory<>("portfel"));

        dystrybutorzyTable.setItems(Serwer.instance.getDystrybutorzy());
        dystrybutorzyTable.getColumns().addAll(dystNazwaCol, zaOdtworzenieCol, pensjaCol, portfelCol);
        dystrybutorzyTable.setRowFactory(tv -> {
            TableRow<Dystrybutor> row = new TableRow<>();
            row.setOnMouseClicked(event -> {
                if(!row.isEmpty() && event.getButton() == MouseButton.PRIMARY){
                    Dystrybutor clickedRow = row.getItem();
                    kliknietyDystrybutor = clickedRow;
                    kliknietyKlient = null;
                    kliknietyProdukt = null;
                }
            });
            return row;
        });
    }

    public void filtruj(){
        ObservableList<Produkt> produktyFiltered = FXCollections.observableArrayList(new ArrayList<>());
        produktyFiltered.addAll(Serwer.instance.getProdukty());
        produktyFiltered.removeIf(p -> !p.getNazwa().contains(searchField.getText()));
        produktyTable.setItems(produktyFiltered);

        ObservableList<Klient> klienciFiltered = FXCollections.observableArrayList(new ArrayList<>());
        klienciFiltered.addAll(Serwer.instance.getKlienci());
        klienciFiltered.removeIf(p -> !p.getNazwa().contains(searchField.getText()));
        klienciTable.setItems(klienciFiltered);

        ObservableList<Dystrybutor> dystrybutorzyFiltered = FXCollections.observableArrayList(new ArrayList<>());
        dystrybutorzyFiltered.addAll(Serwer.instance.getDystrybutorzy());
        dystrybutorzyFiltered.removeIf(p -> !p.getNazwa().contains(searchField.getText()));
        dystrybutorzyTable.setItems(dystrybutorzyFiltered);
    }
    @FXML
    private void nowyDystrybutor(){
        Serwer.instance.dodajDystrybutora();
    }
    @FXML
    private void switchToKlienci(){ klienciTable.toFront(); }
    @FXML
    private void switchToProdukty() { produktyTable.toFront(); }
    @FXML
    private void switchToDystrybutorzy() { dystrybutorzyTable.toFront(); }
    @FXML
    private void usun(){
        if(kliknietyKlient != null){
            kliknietyKlient.setDoUsuniecia(true);
            int tmp = Serwer.instance.getKlienci().indexOf(kliknietyKlient) - 1;
            if(tmp == -1) tmp++;
            Serwer.instance.getKlienci().remove(kliknietyKlient);
            if(Serwer.instance.getKlienci().size() > 0){
                kliknietyKlient = Serwer.instance.getKlienci().get(tmp);
            }
            else kliknietyKlient = null;
        }
        else if(kliknietyDystrybutor != null){
            kliknietyDystrybutor.setDoUsuniecia(true);
            int tmp = Serwer.instance.getDystrybutorzy().indexOf(kliknietyDystrybutor) - 1;
            if(tmp == -1) tmp++;
            Serwer.instance.getDystrybutorzy().remove(kliknietyDystrybutor);
            if(Serwer.instance.getDystrybutorzy().size() > 0){
                kliknietyDystrybutor = Serwer.instance.getDystrybutorzy().get(tmp);
            }
            else kliknietyDystrybutor = null;
        }
        else if(kliknietyProdukt != null){
            int tmp = Serwer.instance.getProdukty().indexOf(kliknietyProdukt) - 1;
            if(tmp == -1) tmp++;
            Serwer.instance.getProdukty().remove(kliknietyProdukt);
            for(Klient k : Serwer.instance.getKlienci()){
                k.getWykupione().remove(kliknietyProdukt);
            }
            if(Serwer.instance.getProdukty().size() > 1){
                kliknietyProdukt = Serwer.instance.getProdukty().get(tmp);
            }
            else kliknietyProdukt = null;
        }

    }
    @FXML
    private void exit(){
        System.exit(0);
    }
}
