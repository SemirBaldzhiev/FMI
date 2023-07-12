package problem1;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class Controller {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnDecrypt;

    @FXML
    private Button btnEncrypt;

    @FXML
    private Button btnQuit;

    @FXML
    private TextArea txaInput;

    @FXML
    private TextArea txaOutput;

    @FXML
    private TextField txtCipherKey;

    private RouteCipher rc;

    @FXML
    void btnDecryptOnClick(ActionEvent event) {
        int key = Integer.parseInt(txtCipherKey.getText());
        rc = new RouteCipher(key);
        String decText = txaOutput.getText();

        String result = rc.decrypt(decText);

        txaInput.setText(result);
    }

    @FXML
    void btnEncryptOnClick(ActionEvent event) {
        int key = Integer.parseInt(txtCipherKey.getText());
        rc = new RouteCipher(key);
        String plainText = txaInput.getText();

        String result = rc.encrypt(plainText);

        txaOutput.setText(result);
    }

    @FXML
    void btnQuitOnClick(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void initialize() {
        assert btnDecrypt != null : "fx:id=\"btnDecrypt\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        assert btnEncrypt != null : "fx:id=\"btnEncrypt\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        assert txaInput != null : "fx:id=\"txaInput\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        assert txaOutput != null : "fx:id=\"txaOutput\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        assert txtCipherKey != null : "fx:id=\"txtCipherKey\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
    }

}
