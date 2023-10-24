/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.model;



/**
 *
 * @author pawel
 */

/*Grade class*/
public class PartialGrade extends Grade{
    private final int weight;     // grade weight
    
    /*Contructor creating PartialGrade
    The exception is being thrown when the value is out of the range 1-6*/
    public PartialGrade(float value, int weight) throws InvalidGradeException {
        super(value);
        this.weight = weight; 
    }
    /*grade weight getter*/
    public int getWeight(){
        return this.weight;
    }

    /*Method returns weighted grade*/
    public float getWeightedGrade(){
        return this.getValue() * this.weight;
    }
    
    /*Overridden method to simpler and nicer displaying partial grade*/
    @Override
    public String toString(){
        return "grade: " + this.getValue() + "   weight: " + weight;
    }
}
