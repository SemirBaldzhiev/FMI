package problem1;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Calendar extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();
        Scene scene = new Scene(group, 600, 550);

        VBox vbox = new VBox();

        HBox hbox  = new HBox(5);
        String[] dayTexts = new String[] {"MON", "TUE", "WED", "THR", "FRI", "SAT", "SUN"};

        for (int i = 0; i < dayTexts.length; i++) {
            Label l = new Label(dayTexts[i]);
            l.setStyle("-fx-font-weight: bold");
            hbox.getChildren().add(l);
        }
        hbox.setPadding(new Insets(25, 25, 25, 25));
        group.getChildren().add(hbox);





        stage.setTitle("Drawing scene");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }
}
