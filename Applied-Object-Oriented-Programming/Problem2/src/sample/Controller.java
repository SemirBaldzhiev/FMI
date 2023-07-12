package sample;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

public class Controller {
    private Double result;

    @FXML
    private Button btnDecimal;

    @FXML
    private Button btnEquals;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnOne;

    @FXML
    private Button btnTwo;

    @FXML
    private Button btnThree;

    @FXML
    private Button btnFour;

    @FXML
    private Button btnFive;

    @FXML
    private Button btnSix;

    @FXML
    private Button btnSeven;

    @FXML
    private Button btnEight;

    @FXML
    private Button btnNine;

    @FXML
    private Button btnZero;

    @FXML
    private Button btnSum;

    @FXML
    private Button btnSubstract;

    @FXML
    private Text resultText;

    @FXML
    private Button btnMultiply;

    @FXML
    private Button btnDevide;

    @FXML
    private Button btnClear;

    @FXML
    private Button btnClearAll;

    @FXML
    private Button btnOff;

    @FXML
    private TextField displayText;

    @FXML
    void btnDecimalOnAction(ActionEvent event) {
        if(!resultText.getText().substring(resultText.getText().length() - 1).equals(".")){
            displayText.appendText(".");
        }
    }
    @FXML
    public void btnEqualsOnAction(ActionEvent event) {
        if(displayText.getText().equals("")){
            return;
        }
        calculate();
        resultText.setText(String.format("%s%s=%.2f", resultText.getText(), displayText.getText(), result));
        displayText.setText("");
        result = null;
    }

    private void calculate(){
        String action = resultText.getText().substring(resultText.getText().length() - 1);
        switch (action){
            case "+":
                result += Double.parseDouble(displayText.getText());
                break;
            case "-":
                result -= Double.parseDouble(displayText.getText());
                break;
            case "*":
                result *= Double.parseDouble(displayText.getText());
                break;
            case "/":
                result /= Double.parseDouble(displayText.getText());
                break;
        }
    }

    @FXML
    void btnClearAllOnAction(ActionEvent event) {
        displayText.setText("");
        resultText.setText("");
        result = null;
    }

    @FXML
    void btnClearOnAction(ActionEvent event) {
        if(displayText.getText().equals("")){
            btnClearAllOnAction(event);
        }
        else {
            displayText.setText(displayText.getText().substring(0, displayText.getText().length() - 1));
        }
    }

    @FXML
    void btnDevideOnAction(ActionEvent event) {
        if(displayText.getText().equals("")){
            return;
        }
        if(result == null){
            result = Double.parseDouble(displayText.getText());
        }
        else {
            calculate();
        }
        resultText.setText(result + "/");
        displayText.setText("");
    }


    @FXML
    void btnEightOnAction(ActionEvent event) {
        displayText.appendText("8");
    }

    @FXML
    void btnFiveOnAction(ActionEvent event) {
        displayText.appendText("5");
    }

    @FXML
    void btnFourOnAction(ActionEvent event) {
        displayText.appendText("4");
    }

    @FXML
    void btnMultiplyOnAction(ActionEvent event) {
        if(displayText.getText().equals("")){
            return;
        }
        if(result == null){
            result = Double.parseDouble(displayText.getText());
        }
        else {
            calculate();
        }
        resultText.setText(result + "*");
        displayText.setText("");
    }

    @FXML
    void btnNineOnAction(ActionEvent event) {
        displayText.appendText("9");
    }

    @FXML
    void btnOffOnAction(ActionEvent event) {
        System.exit(0);
    }

    @FXML
    void btnOneOnAction(ActionEvent event) {
        displayText.appendText("1");
    }

    @FXML
    void btnSevenOnAction(ActionEvent event) {
        displayText.appendText("7");
    }

    @FXML
    void btnSixOnAction(ActionEvent event) {
        displayText.appendText("6");
    }

    @FXML
    void btnSubstractOnAction(ActionEvent event) {
        if(displayText.getText().equals("")){
            return;
        }
        if(result == null){
            result = Double.parseDouble(displayText.getText());
        }
        else {
            calculate();
        }
        resultText.setText(result + "-");
        displayText.setText("");
    }


    @FXML
    void btnSumOnAction(ActionEvent event) {
        if (displayText.getText().equals("")){
            return;
        }
        if(result == null){
            result = Double.parseDouble(displayText.getText());
        }
        else {
            calculate();
        }
        resultText.setText(result + "+");
        displayText.setText("");
    }

    @FXML
    void btnThreeOnAction(ActionEvent event) {
        displayText.appendText("3");
    }

    @FXML
    void btnTwoOnAction(ActionEvent event) {
        displayText.appendText("2");
    }

    @FXML
    void btnZeroOnAction(ActionEvent event) {
        displayText.appendText("0");
    }

    @FXML
    void initialize() {
        assert btnOne != null : "fx:id=\"btnOne\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnTwo != null : "fx:id=\"btnTwo\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnThree != null : "fx:id=\"btnThree\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnFour != null : "fx:id=\"btnFour\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnFive != null : "fx:id=\"btnFive\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnSix != null : "fx:id=\"btnSix\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnSeven != null : "fx:id=\"btnSeven\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnEight != null : "fx:id=\"btnEight\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnNine != null : "fx:id=\"btnNine\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnZero != null : "fx:id=\"btnZero\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnSum != null : "fx:id=\"btnSum\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnSubstract != null : "fx:id=\"btnSubstract\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnMultiply != null : "fx:id=\"btnMultiply\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnDevide != null : "fx:id=\"btnDevide\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnClear != null : "fx:id=\"btnClear\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnClearAll != null : "fx:id=\"btnClearAll\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnOff != null : "fx:id=\"btnOff\" was not injected: check your FXML file 'sample.fxml'.";
        assert displayText != null : "fx:id=\"displayText\" was not injected: check your FXML file 'sample.fxml'.";
        assert resultText != null : "fx:id=\"resultText\" was not injected: check your FXML file 'sample.fxml'.";

        this.result = null;
    }
}