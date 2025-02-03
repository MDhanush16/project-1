#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 11  // Fixed 11 players per team
#define NAME_LENGTH 50  // Maximum length of names

// Function to input team details
void inputTeamDetails(char teamName[], char captainName[], char playerNames[MAX_PLAYERS][NAME_LENGTH], int runs[MAX_PLAYERS]) {
    printf("Enter Team Name: ");
    fgets(teamName, NAME_LENGTH, stdin);
    teamName[strcspn(teamName, "\n")] = '\0';  // Remove newline

    printf("Enter Captain's Name: ");
    fgets(captainName, NAME_LENGTH, stdin);
    captainName[strcspn(captainName, "\n")] = '\0';  // Remove newline

    // Input player names and their runs
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter Player %d Name: ", i + 1);
        fgets(playerNames[i], NAME_LENGTH, stdin);
        playerNames[i][strcspn(playerNames[i], "\n")] = '\0';  // Remove newline

        printf("Enter runs scored by %s: ", playerNames[i]);
        scanf("%d", &runs[i]);
        getchar();  // Consume newline
    }
}

// Function to display the scoreboard
void displayScoreboard(char teamName[], char captainName[], char playerNames[MAX_PLAYERS][NAME_LENGTH], int runs[MAX_PLAYERS]) {
    int totalRuns = 0;
    
    printf("\n=====================================\n");
    printf("          CRICKET SCOREBOARD        \n");
    printf("=====================================\n");
    printf("Team: %s\n", teamName);
    printf("Captain: %s\n", captainName);
    printf("-------------------------------------\n");
    printf("Player Name          Runs Scored\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%-20s %d\n", playerNames[i], runs[i]);
        totalRuns += runs[i];
    }

    printf("-------------------------------------\n");
    printf("Total Runs: %d\n", totalRuns);
    printf("=====================================\n");
}

// Function to decide the winner
void decideWinner(int totalRuns1, char team1[], int totalRuns2, char team2[]) {
    printf("\n========= MATCH RESULT =========\n");
    if (totalRuns1 > totalRuns2) {
        printf("🏆 %s Wins the Match! 🎉\n", team1);
    } else if (totalRuns2 > totalRuns1) {
        printf("🏆 %s Wins the Match! 🎉\n", team2);
    } else {
        printf("It's a Tie! 🤝\n");
    }
    printf("===============================\n");
}

int main() {
    char team1[NAME_LENGTH], team2[NAME_LENGTH];
    char captain1[NAME_LENGTH], captain2[NAME_LENGTH];
    char playerNames1[MAX_PLAYERS][NAME_LENGTH], playerNames2[MAX_PLAYERS][NAME_LENGTH];
    int runs1[MAX_PLAYERS], runs2[MAX_PLAYERS];
    int totalRuns1 = 0, totalRuns2 = 0;

    // Input details for Team 1
    printf("\n=== Enter Details for Team 1 ===\n");
    inputTeamDetails(team1, captain1, playerNames1, runs1);

    // Input details for Team 2
    printf("\n=== Enter Details for Team 2 (Opponent) ===\n");
    inputTeamDetails(team2, captain2, playerNames2, runs2);

    // Calculate total runs for Team 1
    for (int i = 0; i < MAX_PLAYERS; i++) {
        totalRuns1 += runs1[i];
    }

    // Calculate total runs for Team 2
    for (int i = 0; i < MAX_PLAYERS; i++) {
        totalRuns2 += runs2[i];
    }

    // Display Scoreboard for Team 1
    displayScoreboard(team1, captain1, playerNames1, runs1);

    // Display Scoreboard for Team 2
    displayScoreboard(team2, captain2, playerNames2, runs2);

    // Decide Winner
    decideWinner(totalRuns1, team1, totalRuns2, team2);

    return 0;
}
