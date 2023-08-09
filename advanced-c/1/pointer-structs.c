#include <stdio.h>

typedef struct {
    int x;
    int y;
} Position;

enum Faction { alliance, horde };

typedef struct {
    char username[50];
    enum Faction faction;
    Position* respawn;
} Player;

void changeRespawn(Position* respawn, Position new) {
    respawn->x = new.x;
    respawn->y = new.y;
}

int main() {
    char factions[][9] = {"alliance", "horde"};

    Position location = {5, 10};
    Player user = {"Calcur", alliance, &location};

    printf("%s (%s) respawned at %i %i\n", user.username,
           factions[user.faction], user.respawn->x, user.respawn->y);

    Player* p = &user;
    printf("%i\n", p->respawn->x);
    changeRespawn(user.respawn, (Position){400, 700});

    printf("%s (%s) respawned at %i %i\n", user.username,
           factions[user.faction], user.respawn->x, user.respawn->y);

    return 0;
}