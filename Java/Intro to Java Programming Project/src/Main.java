import java.util.Random;
import java.util.Scanner;

public class Main {
    public static Player player = new Player();
    public static Location[][] gameMap = new Location[3][3];
    public static Item[] Shop_Items = new Item[3];
    public static String introduction =
            "Welcome to the Grave Adventure Game!\n" +
                    "The objective of this game is simple: Locate the boss and defeat it!\n" +
                    "But be warned, this is not as simple as it sounds.\n" +
                    "You have only me as your eyes and ears.\n" +
                    "Type what actions you wish to take, and I will respond accordingly.\n" +
                    "You must fight enemies, collect items, and gain exp in order to succeed.\n" +
                    "Good luck, and have fun!";
    public static String[] commands = {"look",
            "north", "south", "east", "west", "enter"};
    public static Scanner scnr = new Scanner(System.in);
    public static Random randGen = new Random();
    public static boolean exit = false;
    public static void SetDescriptions(){
        gameMap[0][0].setDescription("You are in a forest.\nEast of you is a beach.\nNorth of you is a lake.");
        gameMap[0][1].setDescription("You are at a lake.\nSouth of you is a forest.\nNorth of you is a graveyard.\nEast of you is a cave.");
        gameMap[0][2].setDescription("You are at the gate of the graveyard. The gate is locked.\nEast of you is a meadow.\nSouth of you is a lake.\n");
        gameMap[1][1].setDescription("You are at a cave.\nEast of you is a swamp.\nSouth of you is a beach.\nNorth of you is a meadow.\nWest of you is a lake.");
        gameMap[2][1].setDescription("You are at a swamp.\nWest of you is a cave.\nSouth of you is a shop.\nNorth of you is a stone statue.");
        gameMap[1][0].setDescription("You are at a beach.\nWest of you is a forest.\nNorth of you is a cave.\nEast of you is a shop.");
        gameMap[2][0].setDescription("You are at a shop.\nWest of you is a beach.\nNorth of you is a swamp.");
        gameMap[1][2].setDescription("You are in a meadow.\nWest of you is a graveyard.\nEast of you is a stone statue.\nSouth of you is a cave.");
        gameMap[2][2].setDescription("You are at a stone statue.\nSouth of you is a swamp.\nWest of you is a meadow.");
    }
    public static boolean AttackOrFlee(Enemy enemy) {
         int p_att = (int)Math.ceil(Math.pow(randGen.nextInt(player.getAttack()) + player.getMin_damage(),2) / (player.getAttack()+enemy.getDefense()));
         int e_att = (int)Math.ceil(Math.pow(randGen.nextInt(enemy.getAttack()) + enemy.getMin_damage(),2) / (enemy.getAttack()+player.getDefense()));
         System.out.println("Attack, Heal, or Flee?");
         String input = scnr.next();
         if(input.equalsIgnoreCase("attack")) {
             enemy.setHealth(enemy.getHealth() - p_att);
             System.out.println("You did " + p_att + " damage to " + enemy.getE_name());
             if (enemy.getHealth() <= 0) {
                 System.out.println("You have slain the enemy!");
                 player.setExp(player.getExp() + enemy.getExp());
                 player.setGold(player.getGold() + enemy.getGold());
                 System.out.println("Gained " + enemy.getExp() + " exp.");
                 System.out.println("Got " + enemy.getGold() + " gold.");
                 while (player.expLevel[player.getLevel() + 1] <= player.getExp()) {
                     if (player.expLevel[player.getLevel() + 1] <= player.getExp()) {
                         player.LevelUp(3);
                     }
                 }
                 return true;
             }

             System.out.println(enemy.getE_name() + "'s health: " + enemy.getHealth());
         }
         else if(input.equalsIgnoreCase("heal")){
             player.usePotion();
             return false;
         }
        else if(input.equalsIgnoreCase("flee")) {
            System.out.println("You fled from the battle");
            System.out.println("Your health: " + player.getHealth());
            return true;
        }
        else{
             System.out.println("Unknown command.");
             return false;
         }
                 player.setHealth(player.getHealth() - e_att);
                 System.out.println("You took " + e_att + " damage from " + enemy.getE_name());
                 if (player.getHealth() <= 0) {
                     System.out.println("You have been slain. Game Over!");
                     exit = true;
                     return true;
                 }
                System.out.println("Your health: " + player.getHealth());
         return false;
     }
     public static void randEncounter() {
         int enemy_no = randGen.nextInt(3);
         Enemy enemy;
         if(randGen.nextInt(3) == 1){
             switch (enemy_no) {
                 case 0:
                     enemy = new Enemy("Goblin", 1, 2, 6, 6, 6);
                     System.out.println(enemy.getE_name() + " appears!");
                     while (!AttackOrFlee(enemy)) ;
                     if(exit){return;}
                     break;
                 case 1:
                     enemy = new Enemy("Ogre", 2, 4, 7, 7, 7);
                     System.out.println(enemy.getE_name() + " appears!");
                     while (!AttackOrFlee(enemy)) ;
                     if(exit){return;}
                     break;
                 case 2:
                     enemy = new Enemy("Giant", 3, 6, 8, 8, 8);
                     System.out.println(enemy.getE_name() + " appears!");
                     while (!AttackOrFlee(enemy)) ;
                     if(exit){return;}
                     break;
             }
         }
         else{
             System.out.println("No enemies appeared");
         }
     }
    public static void FunctionRun(int commNo) {
        switch (commNo) {
            case 0:
                //Run look function
                if(player.getX() == 2 && player.getY() == 2 && !player.isHasKey()){
                    System.out.println("At the bottom of the statue's feet, you find a key.");
                    System.out.println("You got the graveyard key.");
                    player.setHasKey(true);
                }
                break;
            case 1:
                //Run north function

                if (player.getY() < 2) {
                    player.setY(player.getY() + 1);
                    randEncounter();
                }
                if(exit){return;}
                System.out.println(gameMap[player.getX()][player.getY()].getDescription());
                break;
            case 2:
                //Run south function

                if (player.getY() > 0) {
                    player.setY(player.getY() - 1);
                    randEncounter();
                }
                if(exit){return;}
                System.out.println(gameMap[player.getX()][player.getY()].getDescription());
                break;
            case 3:
                //Run east function

                if (player.getX() < 2) {
                    player.setX(player.getX() + 1);
                    randEncounter();
                }
                if(exit){return;}
                System.out.println(gameMap[player.getX()][player.getY()].getDescription());
                break;
            case 4:
                //Run west function
                if(exit){return;}
                if (player.getX() > 0) {
                    player.setX(player.getX() - 1);
                    randEncounter();
                }
                System.out.println(gameMap[player.getX()][player.getY()].getDescription());
                break;
            case 5:
                //Run enter function
                if(exit){return;}
                if(player.getX() == 2 && player.getY() == 0){
                    Shop();
                }
                else if(player.getX() == 0 && player.getY() == 2 && player.isHasKey()){
                    System.out.println("You unlocked the gate and entered the graveyard.");
                    System.out.println("Suddenly, a giant Skeleton rises from the ground and attacks you!");
                    Enemy boss = new Enemy("Skeleton",0,0,15,20,15);
                    while(!bossFight(boss));
                    exit = true;
                    return;
                }
                System.out.println(gameMap[player.getX()][player.getY()].getDescription());
                break;
        }
    }
    public static void InitializeVars(){
        Shop_Items[2] = new Item(10,"Shield");
        Shop_Items[1] = new Item(10,"Sword");
        Shop_Items[0] = new Item(5,"Potion");
        player.setLevelExp();
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                gameMap[a][b] = new Location(a, b, "");
                gameMap[a][b].setX(a);
                gameMap[a][b].setY(b);
            } }
        SetDescriptions();
    }
    public static void PlayerBools(Item item){
        if(player.getGold() >= item.getPrice()) {
            if (item.getName().equalsIgnoreCase("Potion")) {
                player.addPotion();
                player.setGold(player.getGold() - item.getPrice());
                System.out.println("You bought " + item.getName());
                System.out.println("Your gold: " + player.getGold());
            }
            else if (!item.isBought()) {
                item.setBought(true);
                player.setGold(player.getGold() - item.getPrice());
                System.out.println("You bought " + item.getName());
                System.out.println("Your gold: " + player.getGold());
                if (item.getName().equalsIgnoreCase("Shield")) {
                    player.setDefense(player.getDefense() + 10);
                    player.setHasShield(true);
                } else if (item.getName().equalsIgnoreCase("Sword")) {
                    player.setAttack(player.getAttack() + 10);
                    player.setHasSword(true);
                }
            } else {
                System.out.println("Item already bought.");
            }
        }
        else {
            System.out.println("Not enough gold.");
        }
    }
    public static void Shop(){
        System.out.println("Welcome to the Shop!");
        System.out.println("Your gold: " + player.getGold());
        System.out.println("Items available:");
        for (int i = 0; i < Shop_Items.length; ++i){
            System.out.println(Shop_Items[i].getName() + ": " + Shop_Items[i].getPrice() + " gold");
        }
        String input = scnr.next();
        while(!input.equalsIgnoreCase("exit")) {
            for (int i = 0; i < Shop_Items.length; ++i) {
                if (Shop_Items[i].getName().equalsIgnoreCase(input)) {
                    PlayerBools(Shop_Items[i]);
                }
            }
            input = scnr.next();
        }
    }
    public static boolean bossFight(Enemy boss){
        int p_att = (int)Math.ceil(Math.pow(randGen.nextInt(player.getAttack()) + player.getMin_damage(),2) / (player.getAttack()+boss.getDefense()));
        int boss_att = (int)Math.ceil(Math.pow(randGen.nextInt(boss.getAttack()) + boss.getMin_damage(),2) / (boss.getAttack()+player.getDefense()));
        System.out.println("Attack or heal?");
        String input = scnr.next();
        if(input.equalsIgnoreCase("attack")) {
            boss.setHealth(boss.getHealth() - p_att);
            System.out.println("You did " + p_att + " damage to " + boss.getE_name());
            if (boss.getHealth() <= 0) {
                System.out.println("Congratulations! You win!");
                return true;
            }

            System.out.println(boss.getE_name() + "'s health: " + boss.getHealth());
        }
        else if(input.equalsIgnoreCase("heal")){
            player.usePotion();
            return false;
        }
        player.setHealth(player.getHealth() - boss_att);
        System.out.println("You took " + boss_att + " damage from " + boss.getE_name());
        if (player.getHealth() <= 0) {
            System.out.println("You have been slain. Game Over!");
            return true;
        }
        System.out.println("Your health: " + player.getHealth());
        return false;
    }
    public static void funcTest1() {
    InitializeVars();
        boolean valid = false;
        System.out.println(introduction);
        while (!exit) {
            String input = scnr.next();
            for (int i = 0; i < commands.length; ++i) {
                if (commands[i].equalsIgnoreCase(input)) {
                    FunctionRun(i);
                    valid = true;
                    break;
                }
                else {
                    valid = false;
                }
            }
            if(!valid)
                System.out.println("Unknown command");
        }

    }

    public static void main(String[] args) {
    funcTest1();
    }
}
