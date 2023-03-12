package problem1;

public class Stock {
    private String symbol;
    private String name;
    private double previousClosingPrice;
    private double currentPrice;

    public Stock(String symbol, String name) {
        this.symbol = symbol;
        this.name = name;
    }

    public String getSymbol() {
        return symbol;
    }

    public String getName() {
        return name;
    }

    public double getPreviousClosingPrice() {
        return previousClosingPrice;
    }

    public void setPreviousClosingPrice(double previousClosingPrice) {
        if (previousClosingPrice > 0) {
            this.previousClosingPrice = previousClosingPrice;
        }
        else {
            this.previousClosingPrice = 1.0;
        }
    }

    public double getCurrentPrice() {
        return currentPrice;
    }

    public void setCurrentPrice(double currentPrice) {
        if (currentPrice > 0) {
            this.currentPrice = currentPrice;
        }
        else {
            this.currentPrice = 2.0;
        }
    }

    public double changePercent() {
        return (this.currentPrice - this.previousClosingPrice) / this.previousClosingPrice * 100;
    }
}
