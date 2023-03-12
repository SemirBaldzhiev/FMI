package problem1;

public class StockTest {
    public static void main(String[] args) {
        Stock s = new Stock("ST", "new stock");
        s.setCurrentPrice(1.6);
        s.setPreviousClosingPrice(1.5);

        System.out.printf("Current Price: %.2f%n", s.getCurrentPrice());
        System.out.printf("Old Price: %.2f%n", s.getPreviousClosingPrice());

        // Set default values for these fields when passed values are incorrect
        s.setCurrentPrice(-1.8);
        s.setPreviousClosingPrice(-2.9);


        System.out.printf("Current Price: %.2f%n", s.getCurrentPrice());
        System.out.printf("Old Price: %.2f%n", s.getPreviousClosingPrice());

        System.out.printf("Stock: %s%nStock Symbol: %s%nChange Percentage: %.2f%%", s.getName(), s.getSymbol(), s.changePercent());


    }
}
