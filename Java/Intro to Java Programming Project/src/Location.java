public class Location {
    private int x, y;
    private String description;
    //Public access methods
    public Location(int i, int j,String desc ){
        x = i;
        y = j;
        description = desc;
    }
    public String getDescription() {
        return description;
    }
    //Public mutator methods
    public void setDescription(String description) {
        this.description = description;
    }
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }

}
