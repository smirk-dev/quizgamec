#include <stdio.h>
struct Question {
    char question[256];
    char options[4][50];
    char correctOption;
};
int askQuestion(struct Question q) 
{
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) 
    {
        printf("%c. %s\n", 'A' + i, q.options[i]);
    }
    char answer;
    printf("Enter your answer (A, B, C, D): ");
    scanf(" %c", &answer);
    if (answer == q.correctOption) 
    {
        printf("Correct!\n\n");
        return 1;
    } else 
    {
        printf("Wrong! Correct answer is %c\n\n", q.correctOption);
        return 0;
    }
}
void startQuiz() 
{
    struct Question questions[5] = 
    {
        {"Which country has the highest life expectancy?", {"Paris", "Hong Kong", "Rome", "Berlin"}, 'B'},
        {"What is the most common surname in the United States?", {"Shakespeare", "Dickens", "Smith", "Tolkien"}, 'C'},
        {"What is the chemical symbol for water?", {"CO2", "H2O", "NaCl", "O2"}, 'B'},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 'B'},
        {"Who painted the Mona Lisa?", {"Van Gogh", "Picasso", "Da Vinci", "Monet"}, 'C'}
    };
    int score = 0;
    printf("Welcome to the Quiz!\n");
    printf("---------------------\n");
    for (int i = 0; i < 5; i++) 
    {
        score += askQuestion(questions[i]);
    }
    printf("You completed the quiz!\n");
    printf("Your final score is: %d/5\n", score);
}
int main() 
{
    startQuiz();
    return 0;
}