package exam.logic;

import java.util.Arrays;

public class Inventory {
    public final String ID;

    private static int cnt;
    private Category category;
    private double price;
    private final String description;

    public Inventory(Category category, double price) {
        cnt++;
        ID = String.valueOf(cnt);
        this.category = category;
        this.price = price;
        this.description = String.format("Product-%s", ID);
    }

    public Category getCategory() {
        return category;
    }

    public void setCategory(Category category) {
        this.category = category;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public String toString() {
        return String.format("%s%ncategory: %s%nprice: %f%nsuppliers: %s%n",
                description, category.name(), price, Arrays.toString(category.getSuppliers().toArray()));

    }
}
