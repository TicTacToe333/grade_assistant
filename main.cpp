#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Assignment {
    public:
        int lowRange;
        int highRange;
        int totalAssignments;
        int scores;
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
        float getAssignmentWeight(){
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
        int getScores(){
            return scores;
        }
        void addScores(int newScore){
            scores = scores + newScore;
        }
        float results(){
            float scoreTotal = scores / (totalAssignments * 10);
            return float(scoreTotal * assignmentWeight);
        }
};

int math(int num1,int num2, int divisor){
    switch(divisor){
        case 0:
            return num1 + num2;
        case 1:
            return num1 - num2;
        case 2:
            return num1 * num2;
        default:
            return 0;
    }
    return 0;
}

int tester(Assignment work)
{
    float numCorrect;
    int divisor = 0;
    for(int i = 0; i < 10; i++){
        int input;
        int num1 = rand() % work.getHighRange();
        int num2 = rand() % work.getHighRange();
        cout << (i + 1) << ". " << num1 << " + " << num2 << endl;
        cout << ("Answer: ");
        cin >> input;
        int answer = math(num1, num2, divisor);
        if(answer == input){
            cout << "Correct!" << endl;
            numCorrect++;
        }else{
            cout <<"The correct answer was: " << answer << endl;
        }
        cout << " " << endl;
    }
    return numCorrect;
}



int main()
{
    Assignment test = Assignment(0,20,0.4);
    Assignment hw = Assignment(0,10,0.6);
    string choice = "h";
    while(choice == "h" || choice == "t"){
        cout << "Take a test or do homework (Enter t or h) " << endl;
        cout << "Enter r to see your final grade. ";
        cin >> choice;
        if(choice == "t"){
            test.addScores(tester(test));
        }else if(choice == "h"){
            hw.addScores(tester(hw));
        }
    }
    float finalScore =  test.results() * 10;
    cout << finalScore;
    return 0;
}