import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Serwer.instance = new Serwer();
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("LocalFlix");
        primaryStage.setScene(new Scene(root, 950, 700));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
