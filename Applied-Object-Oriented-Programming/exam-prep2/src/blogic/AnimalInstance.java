package blogic;

public class AnimalInstance {
    private final String INSTANCE_ID;
    private static int counter;
    private int animalKey;
    private String animalName;
    private int animalAge;

    public AnimalInstance(int animalAge, int animalKey, String animalName) {
        setAnimalAge(animalAge);
        setAnimalKey(animalKey);
        setAnimalName(animalName);
        INSTANCE_ID = String.format("%s %03d", animalName, counter++);
    }

    public String getINSTANCE_ID() {
        return INSTANCE_ID;
    }

    public int getAnimalKey() {
        return animalKey;
    }

    public void setAnimalKey(int animalKey) {
        if (animalKey >= 0) {
            this.animalKey = animalKey;
        }
        else {
            this.animalKey = 0;
        }
    }

    public String getAnimalName() {
        return animalName;
    }

    public void setAnimalName(String animalName) {
        if (animalName != null) {
            this.animalName = animalName;
        }
        else {
            this.animalName = "unknown";
        }
    }

    public int getAnimalAge() {
        return animalAge;
    }

    public void setAnimalAge(int animalAge) {
        if (animalAge > 0) {
            this.animalAge = animalAge;
        }
        else {
            this.animalAge = 0;
        }
    }

    @Override
    public String toString() {
        return String.format("%s, Възраст: %d", INSTANCE_ID, animalAge);
    }
}
