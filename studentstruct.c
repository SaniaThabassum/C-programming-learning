#include <stdio.h>
#include <string.h>

struct Player {
    int id;
    char name[50];
    int score;
    char skill[20];
};

int main() {
    int N, i, j;
    printf("Enter number of players: ");
    scanf("%d", &N);

    struct Player players[N];
    int total = 0;

    // Input player details
    for (i = 0; i < N; i++) {
        printf("Enter ID, Name (use _ for spaces), and Score: ");
        scanf("%d %s %d", &players[i].id, players[i].name, &players[i].score);
        total += players[i].score;

        // Assign skill level
        if (players[i].score >= 80)
            strcpy(players[i].skill, "Elite");
        else if (players[i].score >= 60)
            strcpy(players[i].skill, "Advanced");
        else if (players[i].score >= 40)
            strcpy(players[i].skill, "Intermediate");
        else
            strcpy(players[i].skill, "Beginner");
    }

    float avg = (float) total / N;
    printf("\nOverall Average Score = %.2f\n", avg);

    // Count categories
    int elite = 0, adv = 0, inter = 0, beg = 0;
    for (i = 0; i < N; i++) {
        if (strcmp(players[i].skill, "Elite") == 0) elite++;
        else if (strcmp(players[i].skill, "Advanced") == 0) adv++;
        else if (strcmp(players[i].skill, "Intermediate") == 0) inter++;
        else beg++;
    }

    printf("Elite: %d, Advanced: %d, Intermediate: %d, Beginner: %d\n",
           elite, adv, inter, beg);

    // Display all players
    printf("\nPlayer Details:\n");
    for (i = 0; i < N; i++) {
        printf("ID: %d, Name: %s, Score: %d, Skill: %s\n",
               players[i].id, players[i].name, players[i].score, players[i].skill);
    }

    // Sort players by score (descending)
    struct Player temp;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (players[j].score > players[i].score) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Display top 3 performers
    printf("\nTop Performers:\n");
    for (i = 0; i < N && i < 3; i++) {
        printf("%s with Score: %d\n", players[i].name, players[i].score);
    }

    return 0;
}
