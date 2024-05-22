package project4;

import java.util.Vector;
import java.util.Scanner;

/**
 * MemberRecord class. Contains information about a member and a vector of ServiceRecords.
 * @author Kimberly Lim
 */

public class MemberRecord extends Record {
	private Vector<ServiceRecord> services = new Vector<ServiceRecord>();
	private String status;
	private Scanner input = new Scanner(System.in);
	/**
	 * Prompts user for member information and sets the corresponding variables.
	 */
	public MemberRecord() {
		System.out.println("\nEnter member name (25 characters): ");
		setName(input.nextLine());
		while (getName().length() > 25) {
			System.out.println("\nName exceeds 25 characters. Please enter a name less than 25 characters.");
			System.out.println("\nEnter member name (25 characters): ");
			setName(input.nextLine());
		}

		System.out.println("\nEnter member number (9 digits): ");
		setNumber(Integer.valueOf(input.nextLine()));
		while (String.valueOf(getNumber()).length() != 9) {
			System.out.println("\nInvalid member number. Please enter a 9-digit number.");
			System.out.println("\nEnter member number (9 digits): ");
			setNumber(Integer.valueOf(input.nextLine()));
		}

		System.out.println("\nEnter member street address (25 characters): " );
		String temp = input.nextLine();
		setStreetAddress(temp);
		while (getStreetAddress().length() > 25) {
			System.out.println("\nAddress exceeds 25 characters. Please enter an address less than 25 characters.");
			System.out.println("\nEnter member street address (25 characters): ");
			temp = input.next();
			setStreetAddress(temp);
		}

		System.out.println("\nEnter member city (14 characters): ");
		setCity(input.nextLine());
		while (getCity().length() > 14) {
			System.out.println("\nCity exceeds 14 characters. Please enter a city less than 14 characters.");
			System.out.println("\nEnter member city (14 characters): ");
			setCity(input.nextLine());
		}

		System.out.println("\nEnter member state (2 characters): ");
		setState(input.nextLine());
		while (getState().length() > 2) {
			System.out.println("\nState exceeds 2 characters. Please enter a state less than 2 characters.");
			System.out.println("\nEnter member state (2 characters): ");
			setState(input.nextLine());
		}

		System.out.println("\nEnter member postal zip code (5 digits): ");
		setZip(Integer.valueOf(input.nextLine()));
		while (String.valueOf(getZip()).length() != 5) {
			System.out.println("\nInvalid ZIP code. Please enter a 5-digit number.");
			System.out.println("\nEnter member postal zip code (5 digits): ");
			setZip(Integer.valueOf(input.nextLine()));
		}

		this.status = "Active";
	}
	/**
	 * Appends given ServiceRecord to services vector.
	 * @param sr
	 */
	public void addService(ServiceRecord sr) {
		this.services.add(sr);
	}

	/**
	 * Clears all ServiceRecords from the services vector.
	 */
	public void deleteServices() {
		this.services.clear();
	}

	/**
	 * Deletes a specific ServiceRecord from the services vector.
	 * @param serviceNumber
	 */
	public void deleteService(int serviceNumber) {
		if (searchServices(serviceNumber) != -1) {
			services.remove(searchServices(serviceNumber));
		}
		else {
			System.out.println("Service number " + serviceNumber + " does not exist.");
		}
	}

	/**
	 * Searches for a ServiceRecord in the services vector.
	 * @param serviceNumber
	 * @return
	 */
	public int searchServices(int serviceNumber) {
		for (int i = 0; i < services.size(); i++) {
			if (services.elementAt(i).getServiceCode() == serviceNumber) {
				return i;
			}
		}
		return -1;
	}

	/**
	 * Modifies the status of the record.
	 */
	public void modifyStatus() {
		System.out.println("\nCurrent status: " + this.status);
		System.out.println("\nHow would you like to modify the status? Change status to: ");
		System.out.println("\n\t(1) Active");
		System.out.println("\n\t(2) Suspended");
		System.out.println("\n\t(3) Cancelled");

		switch (Integer.valueOf(input.nextLine())) {
			case 1:
				this.status = "Active";
				break;
			case 2:
				this.status = "Suspended";
				break;
			case 3:
				this.status = "Cancelled";
				break;
			default:
				System.out.println("\nInvalid input. Please choose from the following options:");
				modifyStatus();
				break;
		}
	}

	/**
	 * Retrieves the specified ServiceRecord.
	 * @param serviceNumber
	 * @return ServiceRecord
	 */
	public ServiceRecord returnService(int serviceNumber) {
		return this.services.elementAt(serviceNumber);
	}

	/**
	 * Retrieves the services vector.
	 * @return services
	 */
	public Vector<ServiceRecord> returnServices() {
		return this.services;
	}

	/**
	 * Retrieves the status of the record.
	 * @return status
	 */
	public String returnStatus() {
		return this.status;
	}	

	/**
	 * Retrieves the number of ServiceRecords in the services vector.
	 * @return
	 */
	public int getSize() {
		return services.size();
	} 
}