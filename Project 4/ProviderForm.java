package project4;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.format.ResolverStyle;
import java.util.Calendar;
import java.util.Locale;
import java.util.Scanner;

/**
 * ServiceRecord class. Stores information about a service provided by a provider to a member.
 * @author Dylan Melnick
 */
public class ProviderForm {
	private String serviceDate = new String();
	private String dateTimeReceived = new String();
	private int memberNumber = 0;
	private String serviceName = new String();
	private String memberName = new String();
	private int serviceCode = 0;
	private double serviceFee = 0;
	private int providerNumber = 0;
	private Scanner input = new Scanner(System.in);
	
	
	/**
	 * Constructor method. Prompts user for information and sets corresponding variables.
	 * @param records
	 * @param serviceCode
	 * @param memberNumber
	 * @param memberName
	 * @throws IOException
	 */
	public ProviderForm(ManageRecords records, int serviceCode, int memberNumber, String memberName, int providerNumber) throws IOException {
		System.out.println("\nPROVIDER FORM");
		memberName = records.returnMemberRecord(memberNumber).getName();

		System.out.println("\nEnter Date service was provided (MM-DD-YYYY): ");
		serviceDate = input.nextLine();
		while (!dateValidator(serviceDate)) {
			System.out.println("Invalid date format. Please enter date in MM-DD-YYYY format and ensure date is valid: ");
			serviceDate = input.nextLine();
		}

		this.providerNumber = providerNumber;

		this.memberNumber = memberNumber;
		this.memberName = memberName;

		this.serviceCode = serviceCode;
		serviceFee = records.lookUpFee(serviceCode);
		serviceName = records.lookUpServiceName(serviceCode);

		dateTimeReceived = new SimpleDateFormat("MM-DD-YYYY HH:MM:SS").format(Calendar.getInstance().getTime());
	}

	/**
	 * Validates date format.
	 * @param date
	 * @return
	 */
	private boolean dateValidator(String date) {
		DateTimeFormatter day = DateTimeFormatter.ofPattern("MM-DD-YYYY", Locale.US).withResolverStyle(ResolverStyle.STRICT);
		try {
			day.parse(date);
		} 
		catch (DateTimeParseException e) {
			return false;
		}
		return true;
	}
	
	/**
	 * Returns service date entered by provider.
	 * @return
	 */
	public String getServiceDate() {
		return serviceDate;
	}
	
	/**
	 * Returns date-time form was received by computer.
	 * @return
	 */
	public String getDateTimeReceived() {
		return dateTimeReceived;
	}
	
	/**
	 * Returns member number.
	 * @return
	 */
	public int getMemberNumber() {
		return memberNumber;
	}
	
	/**
	 * Returns member name.
	 * @return
	 */
	public String getMemberName() {
		return memberName;
	}
	
	/**
	 * Returns service code.
	 * @return
	 */
	public int getServiceCode() {
		return serviceCode;
	}
	
	/**
	 * Returns seervice fee.
	 * @return
	 */
	public double getServiceFee() {
		return serviceFee;
	}

	/**
	 * Returns service name.
	 * @return
	 */
	public String getServiceName() {
		return serviceName;
	}

	/**
	 * Returns provider number.
	 * @return
	 */
	public int getProviderNumber() {
		return providerNumber;
	}
}
