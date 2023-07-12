package problem1;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.time.LocalDate;

public class Calendar extends Application {
    private Scene scene;
    private TextInputDialog inputDlg;
    private LocalDate date;
    private VBox vbox;

    private void readInput()
    {
        int year;
        int month;
        inputDlg.setTitle("Input data");
        inputDlg.setHeaderText(null);
        inputDlg.setContentText("Enter year: ");
        do {
            year = Integer.parseInt(inputDlg.showAndWait().get());
        }while (year < 0);

        inputDlg.setContentText("Enter month (1-12): ");
        do {
            month = Integer.parseInt(inputDlg.showAndWait().get());
        }while (month < 0 || month > 12);

        date = LocalDate.of(year, month, 1);
    }

    private boolean isLeap(int year)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return true;
        return false;
    }

    private void daysLabels()
    {
        HBox header = new HBox(7);
        String[] dayNames = { "MON", "TUE", "WED", " THU", "FRI", "SAT", "SUN" };
        for (int i = 0; i < 7; i++)
        {
            Label dayLabel = new Label(dayNames[i]);
            dayLabel.setStyle("-fx-font-weight: bold");
            header.getChildren().add(dayLabel);
        }
        vbox.getChildren().add(header);
    }

    private void drawCalendar()
    {
        LocalDate today = LocalDate.now();
        int daysInMonth = date.getMonth().length(isLeap(date.getYear()));
        int startDay = date.getDayOfWeek().getValue() -1;
        int currDay = 1;
        daysLabels();

        for (int i = 0; i < 6; i++)
        {
            HBox datesLine = new HBox(20);
            for (int j = 0; j< 7; j++ )
            {
                if (currDay > daysInMonth)
                {
                    break;
                }
                if (j != startDay)
                {
                    datesLine.getChildren().add(new Label("    "));
                }
                else
                {
                    String labelToAdd = String.format("%d",currDay);
                    if (currDay < 10)
                    {
                        labelToAdd = String.format("%d  ", currDay);
                    }
                    Label day = new Label(labelToAdd);
                    if (currDay == today.getDayOfMonth() && date.getMonth().getValue() == today.getMonth().getValue())
                    {
                        day.setTextFill(Color.RED);
                    }
                    day.setStyle("-fx-font-weight: bold");
                    datesLine.getChildren().add(day);
                    currDay++;
                    if (startDay != 6)
                    {
                        startDay++;
                    }
                }
            }
            startDay = 0;
            vbox.getChildren().add(datesLine);
        }
    }

    @Override
    public void start(Stage stage) throws Exception {
        inputDlg = new TextInputDialog();
        vbox = new VBox();

        readInput();
        drawCalendar();

        vbox.setSpacing(5);
        vbox.setPadding(new Insets(25,35,25,35));
        scene = new Scene(vbox, 350, 200);

        stage.setTitle(String.format("Calendar for %s %d", date.getMonth(), date.getYear()));
        stage.setScene(scene);
        stage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}