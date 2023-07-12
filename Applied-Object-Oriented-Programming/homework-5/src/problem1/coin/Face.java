package problem1.coin;

public enum Face {
    HEADS(1),
    TAILS(2);

    private final int value;
    private Face(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
