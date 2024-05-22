package project4;

import java.io.IOException;
import java.util.Scanner;

/**
 * MainProgram class. Generates menu for user to select user type.
 * @version 1.0
 * @author Gowtham Prasad
 */

public class Program {
    
    Scanner input = new Scanner(System.in);

    /**
     * Main method. Generates menu for user to select user type.
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
    	ManageRecords records = new ManageRecords();
        while (true) {
           new Program().executeTerminal(records);
           new Timer(records);
        }
    }

    /**
     * Constructor method. Generates menu for user to select user type.
     * @param record
     * @throws IOException
     */
    public void executeTerminal(ManageRecords record) throws IOException {
        System.out.println("\nSelect user terminal or exit.");
		System.out.println("\n\t" + "(1) Manager Terminal");
		System.out.println("\n\t" + "(2) Operator Terminal");
		System.out.println("\n\t" + "(3) Provider Terminal");
		System.out.println("\n\t" + "(4) Exit");
        int userType = Integer.valueOf(input.nextLine());

        switch (userType) {
            case 1:
                new ManagerTerminal(record);
                break;
            case 2:
                new OperatorTerminal(record);
                break;
            case 3:
                new ProviderTerminal(record);
                break;
            case 4:
                System.out.println("\n" + "Exiting...");
                System.exit(0);
            default:
                System.out.println("\nInvalid selection. Please try again.");
            }
    }
}
