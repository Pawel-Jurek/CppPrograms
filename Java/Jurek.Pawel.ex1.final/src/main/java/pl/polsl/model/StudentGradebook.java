/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.model;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author pawel
 */

/*Student gradebook with final grade and all subjects with partial grades*/
public class StudentGradebook {
    private final List<Subject> subjects;
    private final FinalGrade finalGrade;
    
    /*Creating empty gradebook
    The exception is being thrown when the value is out of the range 1-6*/
    public StudentGradebook() throws InvalidGradeException{
        this.subjects = new ArrayList<>();
        this.finalGrade = new FinalGrade(1);
    }
    
    /*Method for adding new subject*/
    public void addSubject(Subject subject){
        this.subjects.add(subject);
    }
    
    /*Subjects getter*/
    public List<Subject> getSubjects(){
        return this.subjects;
    }
    
    /*Final grade getter */
    public FinalGrade getFinalGrade(){
        return this.finalGrade;
    }
    
    /*Final grade setter */
    public void setFinalGrade(float value){
        this.finalGrade.setValue(value);
    }
    
    /*Subject getter chosen by name of the subject */
    public Subject getSubject(String searchedSubjectName){
        for (Subject subject : this.subjects) {
            if (subject.getName().equals(searchedSubjectName)) {
                return subject;
            }
        }
        return null;
    }
    
    /*Method calculate average from all subjects convert it and set to final grade in the set method*/
    public float calculateFinalGrade(){
        float sum = 0;
        for(Subject subject: this.subjects){
            sum += subject.calculateAverage();
        }
        this.finalGrade.setValue(sum / this.subjects.size());
        return this.finalGrade.getValue();
    }
}