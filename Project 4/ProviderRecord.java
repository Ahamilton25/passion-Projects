package project4;
import java.util.Vector;
import java.util.Scanner;

/**
 * ProviderRecord class. Contains information about a provider and a vector of ProviderForms.
 * @author Kimberly Lim
 */
public class ProviderRecord extends Record {
	private Vector<ProviderForm> forms;
	private Scanner input = new Scanner(System.in);
	
	/**
	 * Prompts user for provider information and sets the corresponding variables.
	 */
	public ProviderRecord() {
		forms = new Vector<ProviderForm>();
		System.out.println("\nEnter provider name (25 characters): ");
		setName(input.nextLine());
		while (getName().length() > 25) {
			System.out.println("\nName exceeds 25 characters. Please enter a name less than 25 characters.");
			System.out.println("\nEnter provider name (25 characters): ");
			setName(input.nextLine());
		}

		System.out.println("\nEnter provider number (9 digits):");
		setNumber(Integer.valueOf(input.nextLine()));
		while (String.valueOf(getNumber()).length() != 9) {
			System.out.println("\nInvalid provider number. Please enter a 9-digit number.");
			System.out.println("\nEnter provider number (9 digits): ");
			setNumber(Integer.valueOf(input.nextLine()));
		}

		System.out.println("\nEnter provider street address (25 characters): ");
		setStreetAddress(input.nextLine());
		while (getStreetAddress().length() > 25) {
			System.out.println("\nAddress exceeds 25 characters. Please enter an address less than 25 characters.");
			System.out.println("\nEnter provider street address (25 characters): ");
			setStreetAddress(input.nextLine());
		}

		System.out.println("\nEnter provider city (14 characters): ");
		setCity(input.nextLine());
		while (getCity().length() > 14) {
			System.out.println("\nCity exceeds 14 characters. Please enter a city less than 14 characters.");
			System.out.println("Enter provider city (14 characters): ");
			setCity(input.nextLine());
		}

		System.out.println("\nEnter provider state (2 characters): ");
		setState(input.nextLine());
		while (getState().length() > 2) {
			System.out.println("\nState exceeds 2 characters. Please enter a state less than 2 characters.");
			System.out.println("\nEnter provider state (2 characters): ");
			setState(input.nextLine());
		}

		System.out.println("\nEnter provider postal zip code (5 digits):");
		setZip(Integer.valueOf(input.nextLine()));
		while (String.valueOf(getZip()).length() != 5) {
			System.out.println("\nInvalid ZIP code. Please enter a 5-digit number.");
			System.out.println("\nEnter provider postal zip code (5 digits): ");
			setZip(Integer.valueOf(input.nextLine()));
		}
	}
	/**
	 * Appends given ProviderForm to forms vector.
	 * @param pf
	 */
	public void addInfo(ProviderForm pf) {
		this.forms.add(pf);
	}
	/**
	 * Clears all ProviderForms from the forms vector.
	 * @param pf
	 * @return
	 */
	public void deleteInfo() {
		forms.clear();
	}

	/**
	 * Deletes a specific ProviderForm from the forms vector.
	 * @param formNumber
	 */
	public void deleteAForm(int formNumber) {
		if (searchInfo(formNumber) != -1) {
			forms.remove(searchInfo(formNumber));
		}
		else {
			System.out.println("Form does not exist.");
		}
	}

	/**
	 * Searches for a specific ProviderForm in the forms vector.
	 * @param formNumber
	 * @return
	 */
	private int searchInfo(int formNumber) {
		for (int i = 0; i < forms.size(); i++) {
			if (forms.elementAt(i).getServiceCode() == formNumber) {
				return i;
			}
		}
		return -1;
	}

	/**
	 * Retrieves the specified ProviderForm from the forms vector.
	 * @param i
	 * @return
	 */
	public ProviderForm getForm(int i) {
		return forms.get(i);
	}
	
	
	public ProviderForm returnInfo(int formNumber) {
		return this.forms.elementAt(formNumber);
	}

	/**
	 * Retrieves the number of ProviderForms in the forms vector.
	 * @return
	 */
	public int size() {
		return forms.size();
	}

	public Vector<ProviderForm> returnForms() {
		return this.forms;
	}
}