import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import static java.lang.Math.round;

public class Player {
    private int attack,defense,exp,gold,health,level,max_health,
            min_damage,potions,x,y;
    private Random randGen = new Random();
    private boolean hasSword = false; // Sword increases attack. Bought at store.
    private boolean hasShield = false; // Shield increases defense. Bought at store.
    private boolean hasKey = false; // Key grants access to boss. Location is random.
    public int p_max_level = 10;
    public int [] expLevel = new int[p_max_level + 1];
    void setLevelExp() {
        for (int i = 0; i <= p_max_level; i++) {
            expLevel[i] = (int) java.lang.Math.pow(3.0 / 2.0, i) - 1;
        }
    }
    public Player(){
    x = 1;
    y = 1;
    level = 1;
    exp = 0;
    attack = 10;
    defense = 10;
    max_health = 10;
    health = max_health;
    min_damage = round(attack / 5);
    }
    public void usePotion(){
        if(potions > 0) {
            health = max_health;
            potions--;
            System.out.println("You used a potion. Health restored");
            System.out.println("Potions left: " + potions);
            System.out.println("Health: " + health);
        }
        else{
            System.out.println("You do not have any potions");
        }
    }
    //Public accessor methods
    public int getAttack() {
        return attack;
    }
    public int getDefense() {
        return defense;
    }
    public int getExp() {
        return exp;
    }
    public int getGold() {
        return gold;
    }
    public int getHealth(){
        return health;
    }
    public int getLevel(){
        return level;
    }
    public int getMin_damage() {
        return min_damage;
    }
    public int getX(){
        return x;
    }
    public int getY(){
        return y;
    }
    public boolean isHasKey() {
        return hasKey;
    }
    //Public mutator methods
    public void setExp(int exp) {
        this.exp = exp;
    }
    public void setGold(int gold) {
        this.gold = gold;
    }
    public void setHealth(int health) {
        this.health = health;
    }
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    public void setAttack(int attack) {
        this.attack = attack;
    }
    public void setDefense(int defense) {
        this.defense = defense;
    }
    public void addPotion() {
        this.potions++;
    }
    public void setHasKey(boolean hasKey) {
        this.hasKey = hasKey;
    }
    public void setHasShield(boolean hasShield) {
        this.hasShield = hasShield;
    }
    public void setHasSword(boolean hasSword) {
        this.hasSword = hasSword;
    }
    //Other public methods
    public void LevelUp(int rand_limit) {
        level++;
        int attack_rand = randGen.nextInt(rand_limit) + 1;
        int defense_rand = randGen.nextInt(rand_limit) + 1;
        int health_rand = randGen.nextInt(rand_limit) + 1;
        attack += attack_rand;
        defense += defense_rand;
        max_health += health_rand;
        health = max_health;
        min_damage = round(attack / 5);
        System.out.println("Level Up!");
        System.out.println("Attack raised by: " + attack_rand);
        System.out.println("Defense raised by: " + defense_rand);
        System.out.println("Health raised by: " + health_rand);
        System.out.println("Attack: " + attack);
        System.out.println("Defense: " + defense);
        System.out.println("Health: " + max_health);
        System.out.println("Level: " + level);
    }
}
