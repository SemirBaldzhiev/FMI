package javafx;

import interfaces.Cipherable;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import models.CipherGenerator;
import models.Result;
import models.Wrapper;

import javafx.event.ActionEvent;
import java.util.Arrays;

public class Controller {
    @FXML private TextField txtSeed;
    @FXML private TextField txtSize;

    private Alert alertMessage;
    private Alert alertErrorMessage;
    private Wrapper wrapper;
    private Result result;

    @FXML private void btnActionGenerateRandom(ActionEvent handler){
        validateInput();
        this.wrapper = new Wrapper(Integer.parseInt(txtSize.getText()));
        generate(wrapper.makeFixedRandom());

        this.alertMessage.setTitle("Generate random subset A-Z");
        showMessage();
    }

    @FXML private void btnActionRandomSubset(ActionEvent handler){
        validateInput();
        this.wrapper = new Wrapper(Integer.parseInt(txtSize.getText()));
        generate(this.wrapper.makeFixedSelection());

        this.alertMessage.setTitle("Random subsequence of letters A-Z");
        showMessage();
    }

    @FXML private void btnActionQuit(ActionEvent handler){
        System.exit(0);
    }

    @FXML private void initialize(){
        this.alertMessage = new Alert(Alert.AlertType.INFORMATION);
        this.alertErrorMessage = new Alert(Alert.AlertType.ERROR);
    }

    private void generate(Cipherable cipher){
        int seed = Integer.parseInt(txtSeed.getText());
        this.result = CipherGenerator.countDistinct(cipher, seed);
    }

    private void showMessage(){
        this.alertMessage.setHeaderText(String.format("Count distinct characters out of %s", this.txtSize.getText()));
        this.alertMessage.setContentText(String.format("Chars: %s \n Result: %d",
                Arrays.toString(result.getChars()), result.getData()));
        this.alertMessage.showAndWait();
    }

    private void validateInput(){
        if (this.txtSeed.getText().equals("") || this.txtSize.getText().equals("")){
            this.alertErrorMessage.setHeaderText("ERROR");
            this.alertErrorMessage.setContentText("Both fields must be filled!");
            this.alertErrorMessage.showAndWait();
            throw new IllegalArgumentException("Empty Fields");
        }
    }
}