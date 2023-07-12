package test;


import geometry.Line;
import geometry.Point;
import geometry.Rectangle;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.Random;

public class GeometryTest extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        Group group = new Group();
        Scene scene = new Scene(group, 300, 250);

        Random random = new Random();

        Point p1 = new Point(new double[] {
                random.nextInt(1,20_001) / 100.0, random.nextInt(1,20_001)/100.0
        });

        Point p2 = new Point(new double[] {
                random.nextInt(1,20_001) / 100.0, random.nextInt(1,20_001)/100.0
        });

        double width = random.nextInt(1,10_001)/100.0;
        double height = random.nextInt(1,5_001)/100.0;

        Rectangle r1 = new Rectangle(p1, width, height);

        Line d1 = new Line(p1, new Point(new double[] {
                p1.getCoords()[0] + width, p1.getCoords()[1] + height
        }));

        Line d2 = new Line(
                new Point(new double[] {
                        p1.getCoords()[0] + width, p1.getCoords()[1]
                }),
                new Point(new double[] {
                        p1.getCoords()[0], p1.getCoords()[1]+height
                })
        );

        width = random.nextInt(1,10_001)/100.0;
        height = random.nextInt(1,5_001)/100.0;

        Rectangle r2 = new Rectangle(p2, width, height);

        r1.draw(group);
        r2.draw(group);

        d1.draw(group);
        d2.draw(group);

        stage.setTitle("geometry");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();

    }
}
