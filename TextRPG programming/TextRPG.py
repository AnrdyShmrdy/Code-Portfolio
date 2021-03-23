import random
enemy_health = 0
p_max_level = 5
expLevel = [0, 0, 1, 2, 4, 7]
no = False
flee = False
p_max = 10  # this is the maximum attack the player can deal
p_min = 1  # this is the base attack stat. Note that this is the minimum attack the player can deal
p_health_max = 50  # max health for player at current level
p_health = 50
p_exp = 0
p_level = 1
e1_name = "Enemy1"
e2_name = "Enemy2"
e3_name = "Enemy3"
max_e1_health = 15
max_e2_health = 30
max_e3_health = 45


def level_up(rand_limit):
    global p_health_max
    global p_min
    global p_max
    global p_level
    global p_exp
    global p_health
    rand_stat1 = random.randint(0, rand_limit)
    rand_stat2 = random.randint(0, rand_limit)
    p_health_max += rand_stat1
    p_min += rand_stat2
    p_max += rand_stat2
    p_level += 1
    p_health = p_health_max
    print("Level Up!")
    print("Attack raised by: " + str(rand_stat2))
    print("Health raised by: " + str(rand_stat1))
    print("Attack: " + str(p_min))
    print("Health: " + str(p_health))
    print("Level: " + str(p_level))


def attack_or_flee(e_max, e_min, e_name):
    global flee
    global enemy_health
    global p_exp
    global p_health
    global p_level
    global expLevel
    flee = False
    input_char = ''
    r1 = 0
    r2 = 0
    input_char = input("Attack(a)		or		Flee(f)?\n")[0]
    if input_char == 'a':
        r1 = random.randint(0, p_max) + p_min
        enemy_health -= r1
        print("You did " + str(r1) + " damage to " + e_name)
        if enemy_health <= 0:
            print("You have slain the enemy!")
            if e_name[5] == '1':
                p_exp += 1
                print("Gained 1 exp.")
                print("Your exp: " + str(p_exp))
            elif e_name[5] == '2':
                p_exp += 2
                print("Gained 2 exp.")
                print("Your exp: " + str(p_exp))
            elif e_name[5] == '3':
                p_exp += 3
                print("Gained 3 exp.")
                print("Your exp: " + str(p_exp))
            while expLevel[p_level+1] <= p_exp:
                if expLevel[p_level+1] <= p_exp:
                    level_up(3)
                    # This loop allows the player
                    # to go up more than one level after defeating
                    # an enemy, provided the player gains enough exp
                    return
                else:
                    return
            return
        print(e_name + "'s health: " + str(enemy_health))
        r2 = random.randint(0, e_max) + e_min
        p_health -= r2
        print("You took " + str(r2) + " damage from " + e_name)
        print("Your health: " + str(p_health))
        if p_health <= 0:
            print("You have been slain. Game Over!")
            return
    elif input_char == 'f':
        flee = True
        print("You fled from the battle")
        return


def yes_or_no():
    global flee
    global no
    global enemy_health
    char_input = ''
    flee = False
    r1 = 0
    e1_health = max_e1_health
    e2_health = max_e2_health
    e3_health = max_e3_health
    print("Continue?")
    char_input = input("Yes(y)		or		No(n)?\n")
    if char_input == 'y':
        r1 = random.randint(0,3) + 1
        if r1 == 1:
            enemy_health = max_e1_health
            print(e1_name + " appears!")
            while flee == False and enemy_health > 0 and p_health > 0:
                attack_or_flee(6, 1, e1_name)
        elif r1 == 2:
            enemy_health = max_e2_health
            print(e2_name + " appears!")
            while flee == False and enemy_health > 0 and p_health > 0:
                attack_or_flee(7, 2, e2_name)
        elif r1 == 3:
            enemy_health = max_e3_health
            print(e3_name + " appears!")
            while flee == False and enemy_health > 0 and p_health > 0:
                attack_or_flee(8, 3, e3_name)
        elif r1 == 4:
            print("No enemies appeared")
    elif char_input == 'n':
        no = True


while no == False and p_health > 0:
    yes_or_no()