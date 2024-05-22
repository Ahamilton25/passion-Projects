package project4;

import java.io.IOException;
import java.util.Scanner;

/**
 * ManagerTerminal class. Generates menu for user to perform action on records.
 * @author Ardise Hamilton
 */
public class ManagerTerminal {
	private int selection;
	private Scanner input = new Scanner(System.in);
	private int memberNum;
	private int providerNum;
	private int attempts = 3;

	/**
	 * Verifies manager password.
	 * 
	 * @return
	 * @throws IOException
	 */
	public boolean verifyManager() throws IOException {
		System.out.println("Enter Manager Password:");
		String password = input.nextLine();
		if (password.equals("team17")) {
			System.out.println("Password Accepted.");
			return true;
		} 
		else {
			System.out.println("Password Incorrect.");
			attempts--;
			if (attempts == 0) {
				System.out.println("Too many incorrect attempts. Exiting program.");
				return false;
			}
			System.out.println("You have " + attempts + " attempts remaining.");
			return verifyManager();
		}
	}

	/**
	 * Constructor method. Generates menu for user to perform action on records.
	 * 
	 * @param records
	 * @throws IOException
	 */
	public ManagerTerminal(ManageRecords records) throws IOException {
		if (!verifyManager())
			return;
		System.out.println("Select Option:");
		System.out.println("\n\t (1) Run Main Accounting Procedure");
		System.out.println("\n\t (2) Print individual report");
		this.selection = Integer.valueOf(input.nextLine());
		switch (selection) {
			case 1:
				printReport(this.selection, 0, records);
				break;
			case 2:
				System.out.println("Select Report Type:");
				System.out.println("\n\t (1) Member Report");
				System.out.println("\n\t (2) Provider Report");
				this.selection = Integer.valueOf(input.nextLine());
				switch (selection) {
					case 1:
						System.out.println("Please enter member number:");
						this.memberNum = Integer.valueOf(input.nextLine());
						while (records.returnMemberRecord(this.memberNum) == null) {
							System.out.println("Member number does not exist. Please try again.");
							this.memberNum = Integer.valueOf(input.nextLine());
						}
						printReport(this.selection, this.memberNum, records);
						break;
					case 2:
						System.out.println("Please enter provider number:");
						this.providerNum = Integer.valueOf(input.nextLine());
						while (records.returnProviderRecord(this.providerNum) == null) {
							System.out.println("Provider number does not exist. Please try again.");
							this.providerNum = Integer.valueOf(input.nextLine());
						}
						printReport(this.selection, this.providerNum, records);
						break;
					default:
						System.out.println("Invalid entry.");
				}
				break;
			default:
				System.out.println("Invalid entry. Please try again.");
		}
	}

	/**
	 * Prints report based on selection.
	 * 
	 * @param s       <-- selection
	 * @param n       <-- ID number
	 * @param records
	 * @throws IOException
	 */
	private void printReport(int s, int n, ManageRecords records) throws IOException {
		if (n == 0) {
			for (int i = 0; i < records.returnMemberRecordSize(); i++) {
				new Summary().printMemberReport(records.returnMemberRecords().get(i));
			}
			for (int i = 0; i < records.returnProviderRecordSize(); i++) {
				new Summary().printProviderReport(records.returnProviderRecords().get(i));
			}
		}
		if (s == 1) {
			for (int i = 0; i < records.returnMemberRecordSize(); i++) {
				new MemberReport().print(records.returnMemberRecords().get(i));
			}
		}
		if (s == 2) {
			for (int i = 0; i < records.returnProviderRecordSize(); i++) {
				new ProviderReport().print(records.returnProviderRecords().get(i));
			}
		}
	}
}
