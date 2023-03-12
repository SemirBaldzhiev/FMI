package com.example.demo;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        Group group = new Group(); // Create a layout Panel
        Scene scene = new Scene(group, 600, 500);// Create the Scene

        // add content to the Layout panel
        double width = scene.getWidth(); // total width of the scene
        double height = scene.getHeight(); // total width of the scene

        double spaceW = width / 20;
        double spaceH = height / 20;
        int cnt = 0;

        double x1 = 0, y1 = 0, x2 = 0, y2 = height;
        while (cnt <= 20) {
            Line line = new Line(y1 / width, y1, x2, y2);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);
            y1+=spaceH;                 //You should modify this if
            x2+=spaceW;                 //it's not an equal square (like 250x250)
            cnt++;
        }
        x1 = y1 = x2 = cnt = 0;
        while (cnt <= 20) {
            Line line = new Line(x2, y1 / height, width, y1);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);
            y1+=spaceH;                 //You should modify this if
            x2+=spaceW;                 //it's not an equal square (like 250x250)
            cnt++;
        }
//
        x1 = y1 = x2 = cnt = 0;
        while (cnt <= 20) {
            Line line = new Line(x2 / width, height-y1, x2, 0);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);
            y1+=spaceH;                 //You should modify this if
            x2+=spaceW;                 //it's not an equal square (like 250x250)
            cnt++;
        }

        x1 = y1 = x2 = cnt = 0;
        while (cnt <= 20) {
            Line line = new Line(x2,height-(y1 / height), width,height-y1);
            line.setStroke(Color.DARKORANGE);
            group.getChildren().add(line);
            y1+=spaceH;                 //You should modify this if
            x2+=spaceW;                 //it's not an equal square (like 250x250)
            cnt++;
        }


        // Set the title of the Stage(the application window)
        stage.setTitle("Drawing shapes");
        // Add the Scene to the Stage
        stage.setScene(scene);
        // Show the Stage (the application window)
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}