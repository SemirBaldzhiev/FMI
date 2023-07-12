package blogic;

public class Animal {

    private String name;
    private AnimalType animalType;
    private boolean predator;
    private String region;
    private boolean endangered;

    public static final String[] REGIONS = {"Africa", "Asia", "Australia", "Europe", "America"};

    public Animal(String name, AnimalType animalType, boolean predator, String region, boolean endangered) {
        setName(name);
        setAnimalType(animalType);
        setPredator(predator);
        setRegion(region);
        setEndangered(endangered);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {

        if (name != null) {
            this.name = name;
        }
        else {
            this.name = "unknown";
        }
    }

    public AnimalType getAnimalType() {
        return animalType;
    }

    public void setAnimalType(AnimalType animalType) {
        if (animalType != null) {
            this.animalType = animalType;
        }
        else {
            this.animalType = AnimalType.BIRD;
        }
    }

    public boolean isPredator() {
        return predator;
    }

    public void setPredator(boolean predator) {
        this.predator = predator;
    }

    public String getRegion() {
        return region;
    }

    public void setRegion(String region) {

        for (int i = 0; i < REGIONS.length; i++) {
            if (region != null && region.equals(REGIONS[i])) {
                this.region = region;
                return;
            }
        }
        this.region = "Unknown";
    }

    public boolean isEndangered() {
        return endangered;
    }

    public void setEndangered(boolean endangered) {
        this.endangered = endangered;
    }

    @Override
    public String toString() {
        String pred = predator ? "Да":"Не";
        String end = endangered ? "Да":"Не";

        return "Животно{ " +
                name + ", тип= " + animalType +
                ", хищник= " + pred +
                ", рейон= " + region  +
                ", застрашен= " + end +
                "}\n";
    }
}
