package exam.logic;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class InventoryManagement {

    private RandomCategorySupplier supplier;
    private List<Inventory> inventories;

    public InventoryManagement() {
        supplier = ArrayList::new;
        inventories = supplier.getRandomData(4, 120, 300);

    }

    public String showInventory() {
        return inventories.stream().map(i -> i.toString()).collect(Collectors.joining("\n"));
    }

    public double averagePrice() {
        return inventories.stream().mapToDouble(i -> i.getPrice()).average().orElse(0.0);
    }

    public List<Inventory> sortInventoryTypeAndID() {
        return inventories.stream().sorted(Comparator.comparing(Inventory::getCategory).thenComparing(i -> i.ID, Comparator.reverseOrder())).collect(Collectors.toList());
    }

    public String findTotalPricePerCategory() {

        return inventories.stream().collect(Collectors.groupingBy(Inventory::getCategory, Collectors.summingDouble(Inventory::getPrice)))
                .entrySet().stream().sorted(Comparator.comparing(Map.Entry::getKey))
                .map(x -> String.format("%s - %f", x.getKey().name(), x.getValue())).collect(Collectors.joining("\n"));
    }
}
