package project4;

/**
 * Record class. Contains information about a member or provider
 * @author Kimberly Lim
 */
public class Record {
	private String name;
	private int number;
	private String streetAddress;
	private String city;
	private String state;
	private int zip;
	
	public Record() {
		this.name = new String();
		this.number = 0;
		this.streetAddress = new String();
		this.city = new String();
		this.state = new String();
		this.zip = 0;
	}
	
	/**
	 * Sets the name in the record to the input value.
	 * @param inputName
	 */
	public void setName(String inputName) {
		this.name = inputName;
	}
	/**
	 * Sets the number in the record to the input value.
	 * @param inputNumber
	 */
	public void setNumber(int inputNumber) {
		this.number = inputNumber;
	}
	/**
	 * Sets the street in the record to the input value.
	 * @param inputStreet
	 */
	public void setStreetAddress(String inputStreet) {
		this.streetAddress = inputStreet;
	}
	/**
	 * Sets the city in the record to the input value.
	 * @param inputCity
	 */
	public void setCity(String inputCity) {
		this.city = inputCity;
	}
	/**
	 * Sets the state in the record to the input value.
	 * @param inputState
	 */
	public void setState(String inputState) {
		this.state = inputState;
	}
	/**
	 * Sets the zip in the record to the input value.
	 * @param inputZip
	 */
	public void setZip(int inputZip) {
		this.zip = inputZip;
	}
	
	/**
	 * Retrieves the name contained in the record.
	 * @return name
	 */
	public String getName() {
		return this.name;
	}
	/**
	 * Retrieves the number contained in the record.
	 * @return number
	 */
	public int getNumber() {
		return this.number;
	}
	/**
	 * Retrieves the street contained in the record.
	 * @return street
	 */
	public String getStreetAddress() {
		return this.streetAddress;
	}
	/**
	 * Retrieves the city contained in the record.
	 * @return city
	 */
	public String getCity() {
		return this.city;
	}
	/**
	 * Retrieves the state contained in the record.
	 * @return state
	 */
	public String getState() {
		return this.state;
	}
	/**
	 * Retrieves the zip contained in the record.
	 * @return zip
	 */
	public int getZip() {
		return this.zip;
	}
}