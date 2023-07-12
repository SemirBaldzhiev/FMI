package vue;

import java.awt.image.SampleModel;
import java.net.URL;
import java.util.Random;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import blogic.*;

public class Controller {

    private AnimalInstance[] samples;
    private Animal[] animals;
    private Random random;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnDistributionByRegions;

    @FXML
    private Button btnQuit;

    @FXML
    private Button btnShowAllSortedByAge;

    @FXML
    private Button btnShowEndangeredByAnimalType;

    @FXML
    private Button btnShuffleSamples;

    @FXML
    private TextArea txaResult;

    @FXML
    void btnDistributionByRegionsOnClick(ActionEvent event) {

        int[] countByRegions = new int[Animal.REGIONS.length];

        for (int  i = 0; i < samples.length; i++) {
            for (int j = 0; j < countByRegions.length; j++) {
                if (animals[samples[i].getAnimalKey()].getRegion().equals(Animal.REGIONS[j])) {
                    countByRegions[j]++;
                }
            }
        }
        txaResult.setText("");
        for (int i = 0; i < countByRegions.length; i++) {
            txaResult.appendText(String.format("%10s\t%d%n", Animal.REGIONS[i], countByRegions[i]));
        }
    }

    @FXML
    void btnQuitOnClick(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void btnShowAllSortedByAgeOnClick(ActionEvent event) {
        for (int i = 0; i < samples.length; i++) {
            for (int j = 0; j < samples.length - i - 1; j++) {
                if (samples[j].getAnimalAge() < samples[j + 1].getAnimalAge()) {
                    AnimalInstance temp = samples[j];
                    samples[j] = samples[j + 1];
                    samples[j + 1] = temp;
                }
            }
        }
        txaResult.setText("");
        for (int i = 0; i < samples.length; i++) {
            txaResult.appendText(samples[i].toString());
            txaResult.appendText("\n");
        }
    }

    @FXML
    void btnShowEndangeredByAnimalTypeOnClick(ActionEvent event) {
        int[] countByEndangered = new int[AnimalType.values().length];

        for (int  i = 0; i < samples.length; i++) {
            for (int j = 0; j < countByEndangered.length; j++) {
                if (animals[samples[i].getAnimalKey()].isEndangered()) {
                    countByEndangered[j]++;
                }
            }
        }
        txaResult.setText("");
        for (int i = 0; i < countByEndangered.length; i++) {
            txaResult.appendText(String.format("%10s\t%d%n", AnimalType.values()[i], countByEndangered[i]));
        }
    }

    @FXML
    void btnShuffleSamplesOnClick(ActionEvent event) {

        int index;
        AnimalInstance temp;
        for (int i = 0; i < samples.length; i++) {
            index = random.nextInt(samples.length);
            temp = samples[i];
            samples[i] = samples[index];
            samples[index] = temp;
        }
        txaResult.setText("");
        for (int i = 0; i < samples.length; i++) {
            txaResult.appendText(samples[i].toString());
            txaResult.appendText("\n");
        }
    }

    @FXML
    void initialize() {
        assert btnDistributionByRegions != null : "fx:id=\"btnDistributionByRegions\" was not injected: check your FXML file 'ZooSurveyScene.fxml'.";
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'ZooSurveyScene.fxml'.";
        assert btnShowAllSortedByAge != null : "fx:id=\"btnShowAllSortedByAge\" was not injected: check your FXML file 'ZooSurveyScene.fxml'.";
        assert btnShowEndangeredByAnimalType != null : "fx:id=\"btnShowEndangeredByAnimalType\" was not injected: check your FXML file 'ZooSurveyScene.fxml'.";
        assert btnShuffleSamples != null : "fx:id=\"btnShuffleSamples\" was not injected: check your FXML file 'ZooSurveyScene.fxml'.";
        assert txaResult != null : "fx:id=\"txaResult\" was not injected: check your FXML file 'ZooSurveyScene.fxml'.";
        animals = new Animal[] {
                new Animal("Тигър", AnimalType.MAMMAL, true, "Asia", true),
                new Animal("Фламинго", AnimalType.BIRD, false, "Africa", true),
                new Animal("Гущер", AnimalType.REPTILE, true, "Australia", true),
                new Animal("Пъстърва", AnimalType.FISH, false, "Europe", false),
                new Animal("Делфин", AnimalType.MAMMAL, false, "Australia", true),
                new Animal("Вълк", AnimalType.MAMMAL, true, "America", false)
        };

        random = new Random();

        samples = new AnimalInstance[20];

        for (int i = 0; i < samples.length; i++) {
            int key = random.nextInt(animals.length);
            samples[i] = new AnimalInstance(random.nextInt(10, 31), key, animals[key].getName());
        }
    }

}
