package problem2;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class DrawingLines extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group(); // Create a layout Panel
        Scene scene = new Scene(group, 600, 500);// Create the Scene

        // add content to the Layout panel
        double width = scene.getWidth(); // total width of the scene
        double height = scene.getHeight(); // total height of the scene

        double spaceW = width / 20;
        double spaceH = height / 20;
        int cnt = 0;
        double y = 0;
        double x = 0;

        while (cnt <= 60) {

            Line line = new Line(y / width, y, x, height);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);

            line = new Line(x, y / height, width, y);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);

            line = new Line(x / width, height-y, x, 0);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);

            line = new Line(x,height-(y / height), width,height-y);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);

            x+=spaceW;
            y+=spaceH;
            cnt++;
        }

        stage.setTitle("Drawing lines");
        stage.setScene(scene);
        stage.show();

    }
}
