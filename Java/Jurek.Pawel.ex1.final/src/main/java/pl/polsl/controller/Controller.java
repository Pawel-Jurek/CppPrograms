/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package pl.polsl.controller;

import pl.polsl.view.View;
import pl.polsl.model.StudentGradebook;
import pl.polsl.model.InvalidGradeException;
import pl.polsl.model.Subject;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author SuperStudent.PL
 */

/* Controller class. It's main tasks are:
- operations on objects
- menu operation */
public class Controller {
    private final View view;  // view class to display messages in the console and communicate with the user
    private boolean exceptions;  // founded exceptions
    private final StudentGradebook studentGradebook;   // student gradebook contains final grade and subjects with partial grades
    
    /* Controller constructor */
    public Controller() throws InvalidGradeException{
        view = new View();
        exceptions = false;
        studentGradebook = new StudentGradebook();
        
    }

    /* This method takes the name of the grade file, then imports data from it and finally opens the menu */
    public void runProgram(String[] args)throws InvalidGradeException { 
        String fileName = getGradesFileName(args);
        importSubjects(fileName);
        menu();   
    }
    
    /*Method returns file name. 
    If args are given function reads it. 
    In other case it asks user to provide file name*/
    public String getGradesFileName(String[] args){
        if(args.length > 0){
            return args[0];
        }

        return view.askForFilename();
    }
    
    /*Method returns string with first uppercase letter and rest lowercase letters to ensure uniformity of names*/
    public static String formatSubjectName(String name) {
        return name.substring(0, 1).toUpperCase() + name.substring(1).toLowerCase();
    }
    
    /*Method imports subjects with grades from given file name to studentGradebook field*/
    public void importSubjects(String fileName) throws InvalidGradeException{
        try {
            File file = new File(fileName);
            Scanner fileScanner = new Scanner(file);

            while (fileScanner.hasNextLine()) {
                //Loading the next line from a file
                String line = fileScanner.nextLine();
                
                //Dividing it into subject and grades
                String[] parts = line.split(": ");
                String subjectName = parts[0];
                subjectName = formatSubjectName(subjectName);
                
                //Dividing the all grades into individual grades
                String[] gradesStr = parts[1].split(", ");
                Subject subject = new Subject(subjectName);
                for (String gradeStr : gradesStr) {
                    //Dividing each grade into value and weight
                    String[] grade = gradeStr.split("-");               
                    // Checking format of grades [value, weight]
                    if (grade.length == 2) {
                        String valueStr = grade[0];
                        String weightStr = grade[1];

                        try {
                            float value = Float.parseFloat(valueStr);
                            int weight = Integer.parseInt(weightStr);
                            subject.addPartialGrade(value, weight);

                        } catch (NumberFormatException | InvalidGradeException e) {
                            view.showException(e.getMessage());
                            exceptions = true;
                        }
                    } else {
                        view.wrongGradeFormat();
                        exceptions = true;
                        break;
                    }
                }
                studentGradebook.addSubject(subject);
            }

            fileScanner.close();
        } catch (FileNotFoundException e) {
            view.notFoundError("file");
            exceptions = true;
        }
    }
    /* Menu method with options:
    1 - display grades
    2 - display average
    3 - display subjects
    4 - display final grade
    5 - exit
    
    If exceptions were found, the menu is not displaying */
    public void menu(){
        int option = 0;      
        if(exceptions == false)
        {
            do {
                
                try{
                    // Getting chosen option in menu by the user
                    option = view.displayMenuAndGetOption();
                    
                    // Checking if option will need to provide subject name
                    if (option == 1 || option == 2) {
                        
                        String searchedSubjectName = formatSubjectName(view.askForSubject()); 
                        Subject foundSubject = studentGradebook.getSubject(searchedSubjectName);
 
                        if (foundSubject != null) {
                            if(option == 2){
                                view.displayGradesAverage(searchedSubjectName, foundSubject.calculateAverage());
                            } else {
                                view.displayGrades(foundSubject);
                            }     
                        } else {
                            view.notFoundError("subject");
                        }

                    }
                    else if(option == 3){
                        view.displaySubjects(studentGradebook.getSubjects());
                    }
                    else if(option == 4){
                        view.displayFinalGrade(studentGradebook.calculateFinalGrade());
                    } 
                    else if (option != 5){
                        view.wrongMenuOption();
                    }
                }catch (java.util.InputMismatchException e) {
                    view.invalidValueError();
                    
                }

            } while(option != 5);
        }
    }
}

