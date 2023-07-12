package exam.logic;

import java.util.ArrayList;
import java.util.List;

public enum Category {
    A(0, new ArrayList<String>()),
    B(0, new ArrayList<String>()),
    C(0, new ArrayList<String>()),
    D(0, new ArrayList<String>());

    private int reorderQty;
    private List<String> suppliers;

    Category(int reorderQty, List<String> suppliers) {
        setReorderQty(reorderQty);
        setSuppliers(suppliers);
    }

    public int getReorderQty() {
        return reorderQty;
    }

    public void setReorderQty(int reorderQty) {
        this.reorderQty = reorderQty;
    }

    public List<String> getSuppliers() {
        return suppliers;
    }

    public void setSuppliers(List<String> suppliers) {
        this.suppliers = suppliers;
    }


}
