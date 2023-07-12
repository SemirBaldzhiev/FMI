package problem2;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class SquareSpiral extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();
        Scene scene = new Scene(group, 600, 600);

        double width = scene.getWidth();
        double height = scene.getHeight();

        double centerX = width / 2;
        double centerY = height / 2;

        double lineLen = centerX / 6;

        for (int i = 1; i < 6; i++) {
            Line line1 = new Line(centerX + (lineLen * i),centerY - (lineLen * i),centerX + (lineLen * i), centerY + lineLen + (lineLen * i));
            Line line2 = new Line(centerX + (lineLen * i),centerY + lineLen + (lineLen * i),centerX - lineLen - (lineLen * i), centerY + lineLen + (lineLen * i));
            Line line3 = new Line(centerX - lineLen - (lineLen * i),centerY + lineLen + (lineLen * i),centerX - lineLen - (lineLen * i),centerY - lineLen - (lineLen * i));
            Line line4 = new Line(centerX - lineLen - (lineLen * i),centerY - lineLen - (lineLen * i),centerX + lineLen + (lineLen * i),centerY - lineLen - (lineLen * i));

            line1.setStroke(Color.RED);
            line2.setStroke(Color.RED);
            line3.setStroke(Color.RED);
            line4.setStroke(Color.RED);


            group.getChildren().add(line1);
            group.getChildren().add(line2);
            group.getChildren().add(line3);
            group.getChildren().add(line4);
        }



        stage.setTitle("Drawing scene");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }
}
