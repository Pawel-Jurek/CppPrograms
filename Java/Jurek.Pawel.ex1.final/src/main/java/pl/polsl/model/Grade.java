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
public class Grade {
     private float value;      // grade value
     
    /*Contructor creating Grade
    The exception is being thrown when the value is out of the range 1-6*/
     public Grade(float value) throws InvalidGradeException{
        if (value >= 1 && value <= 6) {
            this.value = value;
        } else {
            throw new InvalidGradeException("Error: Grade must be between 1 and 6");
        } 
    }
     
    /*Grade value getter*/
    public float getValue(){
        return this.value;
    }
    
    /*Grade value setter*/
    public void setValue(float value){
        this.value = value;
    }
}
