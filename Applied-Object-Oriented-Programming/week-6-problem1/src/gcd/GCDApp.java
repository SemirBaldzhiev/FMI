package gcd;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


public class GCDApp extends javafx.application.Application {

    @Override
    public void start(javafx.stage.Stage stage) throws java.lang.Exception {
        javafx.scene.Parent root
                = javafx.fxml.FXMLLoader.load(getClass().getResource("gcdScene.fxml"));

        javafx.scene.Scene scene = new javafx.scene.Scene(root);

        // Set the Window title
        stage.setTitle("GCD");
        stage.sizeToScene();
        stage.resizableProperty().setValue(java.lang.Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(java.lang.String[] args) {
        launch(args);
    }
}

