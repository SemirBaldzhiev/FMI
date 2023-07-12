import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;


public class DB2Test {

    private Connection connection;
    private Statement statement;
    private ResultSet resultSet;


    public void openConnection() {
        try {

            DriverManager.registerDriver(new com.ibm.db2.jcc.DB2Driver());

        }
        catch(Exception cnfex) {

            System.out.println("Problem in loading or registering IBM DB2 JDBC driver");

            cnfex.printStackTrace();
        }

        try {

            connection = DriverManager.getConnection("jdbc:db2://62.44.108.24:50000/SAMPLE", "db2admin", "db2admin");

            statement = connection.createStatement();

        }
        catch(SQLException s){

            s.printStackTrace();

        }

    }

    public void closeConnection(){

        try {

            if(null != connection) {
                resultSet.close();
                statement.close();
                connection.close();
            }
        }
        catch (SQLException s) {
            s.printStackTrace();
        }
    }

    public void select(String stmnt, String[] tokens) {
        try{
            resultSet = statement.executeQuery(stmnt);
            String result = "";

            while(resultSet.next()) {

                for (int i = 0; i < tokens.length; i++) {
                    result += resultSet.getString(tokens[i]);

                    if (i == tokens.length - 1) result += " \n";
                    else             result += ", ";
                }

            }

            System.out.println("Executing query: " + stmnt + "\n");
            System.out.println("Result output \n");
            System.out.println("---------------------------------- \n");
            System.out.println(result);

        }
        catch (SQLException s)
        {
            s.printStackTrace();
        }
    }

    public void insert(String stmnt) {
        try{
            statement.executeUpdate(stmnt);
        }
        catch (SQLException s){
            s.printStackTrace();
        }

        System.out.println("Successfully inserted!");
    }


    public void delete(String stmnt) {

        try{
            statement.executeUpdate(stmnt);
        }
        catch (SQLException s){
            s.printStackTrace();
        }

        System.out.println("Successfully deleted!");
    }

    public static void menu() {
        System.out.println("+----------------------------------------------------+");
        System.out.println("|----------------------COMMANDS----------------------|");
        System.out.println("| > SELECT <TABLE> <COLUMNS>                         |");
        System.out.println("|----------------------------------------------------|");
        System.out.println("| > SELECTWHERE <TABLE> <COLUMNS> WHERE <CONDITION>  |");
        System.out.println("|----------------------------------------------------|");
        System.out.println("| > INSERT <TABLE>                                   |");
        System.out.println("| > <COLUMNS>                                        |");
        System.out.println("| > <VALUES>                                         |");
        System.out.println("|----------------------------------------------------|");
        System.out.println("| > DELETE <TABLE> <CONDITION>                       |");
        System.out.println("|----------------------------------------------------|");
        System.out.println("| > EXIT                                             |");
        System.out.println("+----------------------------------------------------+");

    }

    public static void main(String[] args) {

        menu();
        DB2Test db2Obj = new DB2Test();
        String selectStmnt = "";
        String insertStmnt = "";
        String deleteStmnt = "";

        db2Obj.openConnection();

        Scanner scanner = new Scanner(System.in);

        while(true) {
            System.out.print("> ");
            String command = scanner.nextLine();
            String[] tokens = command.split(" ");

            if (tokens[0].toUpperCase().equals("EXIT")) {
                break;
            }
            else if (tokens[0].toUpperCase().equals("SELECT")) { // SELECT TABLE COLUMNS
                String columns = "";
                for (int i = 2; i < tokens.length; i++) {
                    if (i == tokens.length - 1) {
                        columns += tokens[i].toUpperCase();
                    } else {
                        columns += String.format("%s, ", tokens[i]).toUpperCase();
                    }
                }
                System.out.println(columns);
                String[] columnLables = columns.split(", ");

                selectStmnt = String.format("SELECT %s FROM FN8MI0700024.%s", columns, tokens[1]);

                db2Obj.select(selectStmnt, columnLables);
            }
            else if (tokens[0].toUpperCase().equals("SELECTWHERE")) { // SELECT TABLE COLUMNS CONDITION
                String columnsWhere = "";

                int index = command.indexOf("WHERE");
                String cond = command.substring(index);

                tokens = command.substring(0, index).split(" ");

                for (int i = 2; i < tokens.length; i++) {
                    if (i == tokens.length - 1) {
                        columnsWhere += tokens[i].toUpperCase();
                    } else {
                        columnsWhere += String.format("%s, ", tokens[i]).toUpperCase();
                    }
                }

                String[] columnLables = columnsWhere.split(", ");

                selectStmnt = String.format("SELECT %s FROM FN8MI0700024.%s %s", columnsWhere, tokens[1], cond);

                db2Obj.select(selectStmnt, columnLables);
            }
            else if(tokens[0].toUpperCase().equals("INSERT")) { // insert table columns values

                System.out.print("> ");
                String columns = scanner.nextLine();
                System.out.print("> ");
                String values = scanner.nextLine();
                insertStmnt = String.format("INSERT INTO FN8MI0700024.%s(%s)"
                                 + " VALUES (%s)", tokens[1], columns, values);

                db2Obj.insert(insertStmnt);
            }
            else if (tokens[0].toUpperCase().equals("DELETE")) { // DELETE TABLE CONDITION

                deleteStmnt = String.format("DELETE FROM FN8MI0700024.%s WHERE %s", tokens[1], tokens[2]);
                db2Obj.delete(deleteStmnt);
            }
        }

        db2Obj.closeConnection();

    }

}
   
    
     
   

 