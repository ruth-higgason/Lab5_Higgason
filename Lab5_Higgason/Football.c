#include <stdio.h>
#include <stdbool.h>

//function to find all possible score combinations
void find_combinations(int score) {
  //variables
  int plays[5] = {8, 7, 6, 3, 2};
  char *play_names[5] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Saftey"};
  int combinations[5] = {0, 0, 0, 0, 0};
  int num_combinations = 0;

  int truef = 1;
  while (truef == 1) {
    num_combinations = 0;
    //checks if the current combination is greater than or equal the score
    for (int i = 0; i < 5; i++){
      num_combinations += (combinations[i] * plays[i]);
    }
    int remainder = score - num_combinations;
    //checks if remainder is even or odd
    if ((remainder % 2 != 0) && (remainder <= score)){
      combinations [3] += 1;
      remainder -= plays[3];
    }
    combinations[4] = remainder / plays[4];
    int total = 0;
    //find total value of the current combination
    for (int i = 0; i < 5; i++){
      total += (combinations[i] * plays[i]);
    }
    //if current combination is equal to score, print
    if (total == score) {
      for (int i = 0; i < 5; i++){
        printf("%d %s, ", combinations[i], play_names[i]);
      }
      printf("\n");
    }
    //if current combination is greater than score, reduce the value of the current combination
    if (total > score){
      num_combinations = 0;
      for (int i = 0; i < 5; i++){
        num_combinations += (combinations[i] * plays[i]);
        if (num_combinations > score){
          combinations[i] -= 1;
          break;
        }
      }
    }
    //changes to a new combination to check
    combinations[4] = 0;
    for (int i = 3; i > -1; i--) {
      num_combinations = 0;
      for (int j = 0; j < 5; j++){
        num_combinations += (combinations[j] * plays[j]);
      }
      num_combinations += plays[i];
      if ((num_combinations < score) && (score - num_combinations > 1)){
        combinations[i] += 1;
        i = -1;
      }
      else{
        if (i == 0){
          truef = 0;
          break;
        }
        combinations[i] = 0;
      }
    }
  }
}

//main
int main() {
  int score;

  //while score is greater than one
  while (1) {
    printf("Enter a score (<= 1 to exit): ");
    scanf("%d", &score);
    if (score <= 1)
      break;
    else {
      //find score combination
      find_combinations(score);
    }
  }

  return 0;
}