package exam.logic;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.function.Supplier;

public interface RandomCategorySupplier extends Supplier<List<Inventory>> {
    final Random RANDOM = new Random();
    private void updateType(Category type) {
        type.getSuppliers().clear();
        int count = RANDOM.nextInt(1, 6);

        for (int i = 0; i < count; i++) {
            type.getSuppliers().add(String.format("%s Supplier No. %d", type.name(), i+1));
        }

        type.setReorderQty(RANDOM.nextInt(1, 10*type.getSuppliers().size()+1));
    }

    default List<Inventory> getRandomData(int howMany, int a, int b) {

        Supplier<List<Inventory>> suppliers = ArrayList::new;
        List<Inventory> inventories = suppliers.get();

        for (int i = 0; i < howMany; i++) {
            double price = a + (b - a) * RANDOM.nextDouble();
            Category c = Category.B;
            updateType(c);
            inventories.add(new Inventory(c, price));
        }

        return inventories;
    }
}
