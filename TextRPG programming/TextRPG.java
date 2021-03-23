import java.util.Scanner;
import java.util.Vector;
import java.util.Random;
public class RPG {
    public static int enemy_health = 0;
    public static int p_max_level = 5;
    public static Vector expLevel = new Vector(p_max_level,1);
    public static Boolean no = false;
    public static Boolean flee = false;
    public static int p_max = 10; // this is the maximum attack the player can deal
    public static int p_min = 1; // this is the base attack stat. Note that this is the minimum attack the player can deal
    public static int p_health_max = 50; // max health for player at current level
    public static int p_health = 50;
    public static int p_exp = 0;
    public static int p_level = 1;
    public static String e1_name = "Enemy1";
    public static String e2_name = "Enemy2";
    public static String e3_name = "Enemy3";
    public static final int max_e1_health = 15;
    public static final int max_e2_health = 30;
    public static final int max_e3_health = 45;
    public static Random randGen = new Random();
    public static Scanner scnr = new Scanner(System.in);
    public static void LevelXPset(double constant, int level_max) {
        for (int i = 0; i <= level_max; i++) {
            int e = (int)java.lang.Math.pow(constant, i) - 1;
            expLevel.add(e);
        }
    }
    public static void LevelUp(int rand_limit) {
        int rand_stat1 = randGen.nextInt(rand_limit);
        int rand_stat2 = randGen.nextInt(rand_limit);
        p_health_max += rand_stat1;
        p_min += rand_stat2;
        p_max += rand_stat2;
        p_level += 1;
        p_health = p_health_max;
        System.out.println("Level Up!");
        System.out.println("Attack raised by: " + rand_stat2);
        System.out.println("Health raised by: " + rand_stat1);
        System.out.println("Attack: " + p_min);
        System.out.println("Health: " + p_health);
        System.out.println("Level: " + p_level);
    }
    public static void AttackOrFlee(int max, int min, String e_name) {
        flee = false;
        char input;
        int r1;
        int r2;
        System.out.println("Attack(a)		or		Flee(f)?");
        input = (scnr.next().charAt(0));
        switch (input) {
            case 'a':
                r1 = randGen.nextInt(p_max) + p_min;
                enemy_health -= r1;
                System.out.println("You did " + r1 + " damage to " + e_name);
                if (enemy_health <= 0) {
                    System.out.println("You have slain the enemy!");
                    switch (e_name.charAt(5)) {
                        case '1':
                            p_exp += 1;
                            System.out.println("Gained 1 exp.");
                            break;
                        case '2':
                            p_exp += 2;
                            System.out.println("Gained 2 exp.");
                            break;
                        case '3':
                            p_exp += 3;
                            System.out.println("Gained 3 exp.");
                            break;
                    }
                    while ((int)expLevel.elementAt(p_level+1) <= p_exp) {
                        if ((int)expLevel.elementAt(p_level + 1) <= p_exp) {
                            LevelUp(3);
                        }
                    }
                    break;
                }
                System.out.println(e_name + "'s health: " + enemy_health);
                r2 = randGen.nextInt(max) + min;
                p_health -= r2;
                System.out.println("You took " + r2 + " damage from " + e_name);
                if (p_health <= 0) {
                    System.out.println("You have been slain. Game Over!");
                    break;
                }
                System.out.println("Your health: " + p_health);
                break;
            case 'f':
                flee = true;
                System.out.println("You fled from the battle");
                break;
        }
    }
    public static void YesOrNo() {
        flee = false;
        char input = ' ';
        int r1;
        int e1_health = max_e1_health;
        int e2_health = max_e2_health;
        int e3_health = max_e3_health;
        System.out.println("Continue?");
        System.out.println("Yes(y)		or		No(n)?");
        input = (scnr.next().charAt(0));
        if (input == 'y') {
            r1 = randGen.nextInt(4) + 1;
            switch (r1) {
                case 1:
                    enemy_health = max_e1_health;
                    System.out.println(e1_name + " appears!");
                    while (flee == false && enemy_health > 0 && p_health > 0) {
                        AttackOrFlee(6, 1, e1_name);
                    }
                    break;
                case 2:
                    enemy_health = max_e2_health;
                    System.out.println(e2_name + " appears!");
                    while (flee == false && enemy_health > 0 && p_health > 0) {
                        AttackOrFlee(7, 2, e2_name);
                    }
                    break;
                case 3:
                    enemy_health = max_e3_health;
                    System.out.println(e3_name + " appears!");
                    while (flee == false && enemy_health > 0 && p_health > 0) {
                        AttackOrFlee(8, 3, e3_name);
                    }
                    break;
                case 4:
                    System.out.println("No enemies appeared");
                    break;
            }
        } else if (input == 'n') {
            no = true;
        }
    }
    public static void main(String[] args) {
    LevelXPset((3.0/2.0),10);
        while(no == false & p_health >0)
        {
        YesOrNo();
        }
    }
}