#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Assignment {
    public:
        int lowRange;
        int highRange;
        int totalAssignments;
        int * scores;
        float assignmentWeight;
        Assignment(int num1, int num2, float weight)
        {
            lowRange = num1;
            highRange = num2;
            assignmentWeight = weight;
        }
        int getLowRange(){
            return lowRange;
        }
        void setLowRange(int newLow){
            lowRange = newLow;
        }
        int getHighRange(){
            return highRange;
        }
        void setHighRange(int newHigh){
            highRange = newHigh;
        }
        int getAssignmentWeight(){
            return assignmentWeight;
        }
        void setAssignmentWeight(int newWeight){
            assignmentWeight = newWeight;
        }
        int getTotalAssignments(){
            return totalAssignments;
        }
        void setTotalAssignments(int newTotal){
            totalAssignments = newTotal;
        }
        void addAssignment(){
            totalAssignments++;
        }
        int * getScores(){
            return scores;
        }
        int * addScores(int newScore){
            scores = append(scores, newScore);
        }
        
};


int tester(Assignment work)
{
    float numCorrect;
    int divisor = 1;
    int num1 = rand() % work.getHighRange();
    int num2 = rand() % work.getHighRange();
    for(int i = 0; i < 10; i++){
        string input;
        cout << (i + 1);
        cout << num1;
        cout << " + ";
        cout << num2 << endl;
        printf ("Answer: ");
        scanf ("%c",&input);
        if(math(num1, num2, divisor) = input){
            numCorrect++;
        }
    }
    return (numCorrect / 10);
}

int math(int num1,int num2, int divisor){
    if(divisor == 1){
        return num1 + num2;
    }
        if(divisor == 2){
        return num1 - num2;
    }
        if(divisor == 3){
        return num1 * num2;
    }
    return 0;
}

int results(Assignment assignment){
        int scoreTotal;   
        for(int i = 0; i < assignment.getTotalAssignments(); i++){
            scoreTotal = assignment.getScores()[i] + scoreTotal;
        }
        
        scoreTotal = scoreTotal / assignment.getTotalAssignments();

        return (scoreTotal * assignment.getAssignmentWeight());
}

int * append(int array[], int newNum){
    int size = (sizeof(array)/sizeof(array[0]));
    int newArray [size + 1]= {};
    for(int i = 0; i < size; i++){
        newArray[i] = array[i];
    }
    newArray[size] = newNum;

    return newArray;
}

int main()
{
    Assignment test = Assignment(0,20,0.4);
    Assignment hw = Assignment(0,10,0.6);
    string choice = "h";
    while(choice == "h" || choice == "t"){
        printf ("Take a test or do homework (Enter t or h) ");
        scanf ("%c",&choice);
        if(choice == "h"){
            test.addScores(tester(hw));
        }else{
            hw.addScores(tester(test));
        }
    }
    int finalScore = results(hw) + results(test);
    cout << finalScore;
}