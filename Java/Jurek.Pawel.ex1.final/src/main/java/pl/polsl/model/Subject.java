/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.model;

/**
 *
 * @author pawel
 */
import java.util.ArrayList;
import java.util.List;

/*Subject class*/
public class Subject {
    private final String name; //name of the subject
    private final List<PartialGrade> partialGrades; //list of partial grades
    
    /*Constructor that creates empty a list of grades and 
      setting the name field with the given parameter*/
    public Subject(String name){
        this.name = name;
        this.partialGrades = new ArrayList<>();
    }

    /*Method adds grade to list grade by creating new Grade object
    InvalidGradeException appears when grade value is out of range 1-6*/
    public void addPartialGrade(float value, int weight) throws InvalidGradeException {
        partialGrades.add(new PartialGrade(value, weight));
    }

    /*Method calculates weighted average of grades*/
    public float calculateAverage() {
        if (partialGrades.isEmpty()) {
            return (float) 0.0;
        }

        float sum = 0;
        int totalWeight = 0;
        for (PartialGrade grade : partialGrades) {
            sum += grade.getWeightedGrade();
            totalWeight += grade.getWeight();
        }
        return sum / totalWeight;
    }

    /*Partial grades getter*/
    public List<PartialGrade> getGrades() {
        return partialGrades;
    }

    /*Subject name getter*/
    public String getName() {
        return name;
    }
    
    /*Overridden method to simpler and nicer displaying subject*/
    @Override
    public String toString(){
        String representation ="------\n" + name + " grades\n";
        for(Grade grade: partialGrades){
            representation += (grade + "\n");
        }
        return representation;
    }
}

