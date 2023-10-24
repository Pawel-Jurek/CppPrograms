/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.main;

import pl.polsl.controller.Controller;
import pl.polsl.model.InvalidGradeException;

/**
 *
 * @author pawel
 */


/**
* Main class
* You can provide a filename in the project run arguments, for example "grades.txt"
* Schema in file looks like:
* "(string)subject name": "(float)grade value"-"grade weight",...
* example: "Maths: 2-1, 4-2, 6-3, 2-1"
*/
public class Main {
    static Controller controller; // controller reference
    
    /*The main method activates the controller and thus starts the program*/
    public static void main(String[] args) throws InvalidGradeException {
        controller = new Controller();
        controller.runProgram(args);
    }
}
