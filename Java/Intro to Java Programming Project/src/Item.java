public class Item {
    private int price;
    private String name;
    private boolean bought = false;
    Item(int price, String name){
        this.name = name;
        this.price = price;
    }
    public void setBought(boolean bought) {
        this.bought = bought;
    }
    public boolean isBought() {
        return bought;
    }
    public String getName() {
        return name;
    }
    public int getPrice() {
        return price;
    }
}
