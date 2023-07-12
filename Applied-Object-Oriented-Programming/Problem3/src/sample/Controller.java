package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

public class Controller {
    private Alert messageBox;

    @FXML
    private TextField formName;

    @FXML
    private TextField formPhoneNumber;

    @FXML
    private TextField formEmailAddress;

    @FXML
    private TextField formPassword;

    @FXML
    private TextField formConfirmPassword;

    @FXML
    private void buttonValidateOnAction(ActionEvent event){
        boolean validated = validate();
        if (validated)
            register();
    }

    private boolean validate(){
        boolean validated = true;

        if (formName.getText().equals("")
                || formPhoneNumber.getText().equals("")
                || formEmailAddress.getText().equals("")
                || formPhoneNumber.getText().equals("")
                || formConfirmPassword.getText().equals("")) {
            showMessage("Please fill all fields");
            validated = false;
        }
        else if (!formName.getText().matches("[A-Za-z]+") || formName.getText().length() < 2){
            showMessage("Invalid name!");
            validated = false;
        }
        else if (!formPhoneNumber.getText().matches("[(]\\d{4}[)] [(]\\d{7}[)]")) {
            showMessage("Invalid phone number!");
            validated = false;
        }
        else if (!formEmailAddress.getText()
                .matches("(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|\"(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21\\x23-\\x5b\\x5d-\\x7f]|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])*\")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21-\\x5a\\x53-\\x7f]|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])+)\\])")) { //RFC5332
            showMessage("Invalid email adress");
            validated = false;
        }
        else if (!formPassword.getText().equals(formConfirmPassword.getText())) {
            showMessage("Password and confirm password fields must be identical");
            validated = false;
        }

        return validated;
    }

    private void register(){
        showMessage("Successfully registered!");
    }

    private void showMessage(String contentText) {
        messageBox.setContentText(contentText);
        messageBox.setHeaderText(null);
        messageBox.showAndWait();
    }

    @FXML
    void initialize() {
        // create an instance of Alert dialog MessageBox
        messageBox = new Alert(Alert.AlertType.INFORMATION);
    }
}