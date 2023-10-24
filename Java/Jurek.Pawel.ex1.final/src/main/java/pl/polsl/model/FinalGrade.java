/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.model;

/**
 *
 * @author pawel
 */

/*The final grade is class for the final grade calculated for all subjects*/
public class FinalGrade extends Grade {
    /*Constructor setting value of value field
    The exception is being thrown when the value is out of the range 1-6*/
    public FinalGrade(float value) throws InvalidGradeException {
        super(value);
    }
    
    /*Method calculates value of the grade
    Grade value is a number in the range 1-6 with a step of 0.5*/
    public void calculateValue(){
        if(this.getValue() > 6){
            super.setValue(6);
        } else {
            float value = this.getValue();
            int beforeDecimal = (int) value;
            float afterDecimal = value - beforeDecimal;
            
            if(afterDecimal >= 0.75){
                super.setValue(beforeDecimal + 1);
            } else if(afterDecimal >= 0.25){
                super.setValue((float) (beforeDecimal + 0.5));
            } else {
                super.setValue(beforeDecimal);
            }
        }
    }
    
    /*Overridden method built to setting value for final grade in schema (1-6 with 0.5 step)*/
    @Override
    public void setValue(float value){
        super.setValue(value);
        this.calculateValue();      
    }
    
}
