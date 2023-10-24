/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.view;

import pl.polsl.model.Subject;
import java.text.DecimalFormat;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author pawel
 */

/*View class including printing and user communication methods */
public class View {
    private final DecimalFormat decimalFormat = new DecimalFormat("#.##"); // decimal format field with pattern: '#.##'
    private static final Scanner scanner = new Scanner(System.in);    // scanner for getting data from user
    
    /*Method is asking for filename*/
    public String askForFilename(){
        System.out.println("Write filename with grades. For example \"grades.txt\". ");
        return scanner.next();
    }
    /*Method is asking for subject name*/
    public String askForSubject(){
        System.out.println("Write subject name: ");
        return scanner.next();
    }
    /*Method is diplaying grades average from given subject*/
    public void displayGradesAverage(String subject, double average){
        String formattedAverage = decimalFormat.format(average);
        System.out.println(subject + " grades average: " + formattedAverage);
    }
    /*Method is displaying grades with weight from given subject*/
    public void displayGrades(Subject subject) {
        System.out.println(subject);
    }
    /*Method is displaying menu and getting option from user*/
    public int displayMenuAndGetOption(){
        System.out.println("-----------------------");
        System.out.println("What do you want to do?");
        System.out.println("1 - Show all grades from choosen subject");
        System.out.println("2 - Show average from grades froms choosen subject");
        System.out.println("3 - Show your subjects");
        System.out.println("4 - Show your final grade");
        System.out.println("5 - Exit");
        return scanner.nextInt();
    }
    /*Method showing info about wrong type of data*/
    public void invalidValueError(){
         System.err.println("Error: You need to provide an integer");
         scanner.next();
    }
    /*Method showing info about not founding object*/
    public void notFoundError(String obj){
         System.err.println("Error: The " + obj + " not found");
    }
    /*Method showing all subjects*/
    public void displaySubjects(List<Subject> subjects) {
        System.out.print("Subjects: ");
        int size = subjects.size();
        for (int i = 0; i < size; i++) {
            System.out.print(subjects.get(i).getName());
            if (i < size - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();
    }
    /*Method showing exception message*/
    public void showException(String message){
        System.err.println(message);
    }
    /*Method showing info about wrong grade format*/
    public void wrongGradeFormat(){
        System.out.println("Error: Wrong grades format. Correct one:");
        System.out.println("Subject: grade1 value1, grade2 value2...");
    }
    
    /*Method showing final grade with communicate about passing*/
    public void displayFinalGrade(float grade){
        if(grade >= 2){
            System.out.println("You are passing this semester with grade: " + grade);
        } else{
            System.out.println("You are not passing this semester. Your grade: " + grade);
        }
        
    }
    
    /*Method displaying communicate about wrong menu option*/
    public void wrongMenuOption(){
        System.out.println("Incorrent option, try number in from range 1-5");
    }
    
    
}
