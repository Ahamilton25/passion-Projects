package project4;

import java.io.IOException;
import java.util.Scanner;


public class OperatorTerminal {
	private Scanner input = new Scanner(System.in);
	private int attempts = 3;
	
	/**
	 * Verifies operator password. Returns true if password is correct, false otherwise.
	 * @return
	 */
	public boolean verifyOperator() {
		System.out.println("Enter Operator Password:");
		String password = input.nextLine();
		if (password.equals("team17")) {
			System.out.println("Password Verified");
			return true;
		}
		else {
			System.out.println("Password Incorrect");
			attempts--;
			if (attempts == 0) {
				System.out.println("Too many incorrect attempts. Exiting program.");
				return false;
			}
			System.out.println("You have " + attempts + " attempts remaining.");
			return verifyOperator();
		}
	}

	/**
	 * Constructor method. Generates menu for user to perform action on records.
	 * @param records
	 * @throws IOException
	 */
	public OperatorTerminal(ManageRecords records) throws IOException {
		if (!verifyOperator()) {
			return;
		}
		System.out.println("\nSelect user type.");
		System.out.println("\n\t" + "(1) Member");
		System.out.println("\n\t" + "(2) Provider");
		System.out.println("\n\t" + "(3) View member directory");
		System.out.println("\n\t" + "(4) View provider directory");
		System.out.println("\n\t" + "(5) Exit");
		int selection = Integer.valueOf(input.nextLine());
		String userType = new String();

		switch (selection) {
		case 1:
			userType = "Member";
			break;
		case 2:
			userType = "Provider";
			break;
		case 3:
			System.out.println("\nMember Name\t\tMember Number");
			for (int i = 0; i < records.returnMemberRecordSize(); i++) {
				System.out.println(records.returnMemberRecords().get(i).getName() + "\t\t" + records.returnMemberRecords().get(i).getNumber());
			}
		case 4:
			System.out.println("\nProvider Name\t\tProvider Number");
			for (int i = 0; i < records.returnProviderRecordSize(); i++) {
				System.out.println(records.returnProviderRecords().get(i).getName() + "\t\t" + records.returnProviderRecords().get(i).getNumber());
			}
		case 5:
			return;
		default:
			System.out.println("Invalid selection.");
		}

		System.out.println("\nSelect action.");
		System.out.println("\n\t" + "(1) Add " + userType);
		System.out.println("\n\t" + "(2) Modify " + userType);
		System.out.println("\n\t" + "(3) Delete " + userType);
		System.out.println("\n\t" + "(4) Exit");
		selection = Integer.valueOf(input.nextLine());

		switch (selection) {
		case 1:
			add(userType, records);
			break;
		case 2:
			System.out.println("Enter " + userType + " Number:");
			modify(userType, Integer.valueOf(input.nextLine()), records);
			break;
		case 3:
			System.out.println("Enter " + userType + " Number:");
			delete(userType, Integer.valueOf(input.nextLine()), records);
			break;
		case 4:
			return;
		default:
			System.out.println("Invalid selection.");
		}
	}
	
	/**
	 * Adds record to records. Record userType is specified in userType parameter.
	 * @param userType
	 * @param records
	 * @throws IOException
	 */
	private void add(String userType, ManageRecords records) {
		switch (userType) {
		case "Member":
			records.addMember(new MemberRecord());
			break;
		case "Provider":
			records.addProvider(new ProviderRecord());
			break;
		}
	}
	
	/**
	 * Generates menu for user to modify a specific aspect of a record in records. 
	 * Record userType is specified in the userType parameter. 
	 * The number parameter corresponds to the specific member/provider number.
	 * @param userType
	 * @param number
	 * @param records
	 */
	private void modify(String userType, int number, ManageRecords records) {
		System.out.println("\nSelect attribute to modify.");
		System.out.println("\n\t" + "Name");
		System.out.println("\n\t" + "Address");
		String selection;
		switch (userType) {
		case "Member":
			System.out.println("\n\t" + "Status");
			System.out.println("\n\t" + "Exit");
			selection = input.nextLine();
			// MemberRecord updatedMember = records.returnMemberRecord(number);
			switch (selection) {
			case "Name":
				System.out.println("Enter new name.");
				records.returnMemberRecord(number).setName(input.nextLine());
				break;
			case "Address":
				System.out.println("Enter new street.");
				records.returnMemberRecord(number).setStreetAddress(input.nextLine());
				System.out.println("Enter new city.");
				records.returnMemberRecord(number).setCity(input.nextLine());
				System.out.println("Enter new state.");
				records.returnMemberRecord(number).setState(input.nextLine());
				System.out.println("Enter new ZIP.");
				records.returnMemberRecord(number).setZip(Integer.valueOf(input.nextLine()));
				break;
			case "Status":
				records.returnMemberRecord(number).modifyStatus();
				break;
			case "Exit":
				return;
			default:
				System.out.println("Invalid selection.");
			}
			//records.deleteMember(number);
			//records.addMember(updatedMember);
			break;
		case "Provider":
			System.out.println("\n\t" + "Exit");
			selection = input.nextLine();
			//ProviderRecord updatedProvider = records.returnProviderRecord(number);
			switch (selection) {
			case "Name":
				System.out.println("Enter new name.");
				records.returnProviderRecord(number).setName(input.nextLine());
				break;
			case "Address":
				System.out.println("Enter new street.");
				records.returnProviderRecord(number).setStreetAddress(input.nextLine());
				System.out.println("Enter new city.");
				records.returnProviderRecord(number).setCity(input.nextLine());
				System.out.println("Enter new state.");
				records.returnProviderRecord(number).setState(input.nextLine());
				System.out.println("Enter new ZIP.");
				records.returnProviderRecord(number).setZip(Integer.valueOf(input.nextLine()));
			case "Exit":
				return;
			default:
				System.out.println("Invalid selection.");
			}
			//records.deleteMember(number);
			//records.addProvider(updatedProvider);
		}
	}
	
	/**
	 * Deletes record from records. The record userType is specified by the userType parameter. 
	 * The number parameter corresponds to the specific member/provider number.
	 * @param userType
	 * @param number
	 * @param records
	 */
	private void delete(String userType, int number, ManageRecords records) {
		switch (userType) {
		case "Member":
			records.deleteMember(number);
			break;
		case "Provider":
			records.deleteProvider(number);
			break;
		}
	}
}
