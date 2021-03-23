import java.util.Random;
import static java.lang.Math.round;
public class Enemy {
    private int attack,defense,exp,gold,health,
            min_damage;
    private String e_name;
    private Random randGen = new Random();
    //Public accessor methods
    public int getAttack() {
        return attack;
    }
    public int getDefense() {
        return defense;
    }
    public String getE_name() {
        return e_name;
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
    public int getMin_damage() {
        return min_damage;
    }
    //Public mutator methods
    public void setHealth(int health) {
        this.health = health;
    }
    public Enemy(String enemy_n,int exp_val, int gol_val, int att_val, int hel_val, int def_val){
        exp = exp_val;
        health = hel_val;
        defense = def_val;
        attack = att_val;
        gold = gol_val;
        e_name = enemy_n;
        min_damage = round(attack / 5);
    }
}