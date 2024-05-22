package project4;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;

/**
 * ManageRecords class. Contains Vector of MemberRecords and ProviderRecords. 
 * Contains methods to add, delete, and search records.
 * @author Gowtham Prasad
 */

public class ManageRecords {
	private Vector<MemberRecord> memberRecords = new Vector<MemberRecord>();
	private Vector<ProviderRecord> providerRecords = new Vector<ProviderRecord>();
	private Vector<Pair<Integer, String>> serviceDirectory = new Vector<Pair<Integer, String>>();
	private Vector<Pair<Integer, Double>> serviceFeeDirectory = new Vector<Pair<Integer, Double>>();
	
	/**
	 * Constructor method. Reads in member records, provider records, and service directory.
	 * @throws IOException
	 */
	public ManageRecords() throws IOException {
		readServiceDirectory();
	}

	private void readServiceDirectory() throws FileNotFoundException, IOException {
		//look up the service code in the provider directory
		//and return the service name
		FileReader serviceCodeFile = new FileReader("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\University of Alabama\\UA Year 2\\Fall 2023\\CS 200\\Projects\\Project 4\\project4\\ServiceCodeDirectory.txt");
		FileReader serviceNameFile = new FileReader("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\University of Alabama\\UA Year 2\\Fall 2023\\CS 200\\Projects\\Project 4\\project4\\ServiceNameDirectory.txt");
		FileReader serviceFeeFile = new FileReader("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\University of Alabama\\UA Year 2\\Fall 2023\\CS 200\\Projects\\Project 4\\project4\\ServiceFeeDirectory.txt");

		BufferedReader scannerInt = new BufferedReader(serviceCodeFile);
		BufferedReader scannerStr = new BufferedReader(serviceNameFile);
		BufferedReader scannerFee = new BufferedReader(serviceFeeFile);

		int serviceCode = Integer.valueOf(scannerInt.readLine());
		String serviceName = scannerStr.readLine();
		double serviceFee = Double.valueOf(scannerFee.readLine());

		while (serviceCode != -1 && serviceName != null && serviceFee != -1.00) {
			serviceDirectory.add(new Pair<Integer, String>(serviceCode, serviceName));
			serviceFeeDirectory.add(new Pair<Integer, Double>(serviceCode, serviceFee));
			serviceCode = Integer.valueOf(scannerInt.readLine());
			serviceName = scannerStr.readLine();
			serviceFee = Double.valueOf(scannerFee.readLine());
		}

		scannerInt.close();
		scannerStr.close();
		scannerFee.close();
		serviceCodeFile.close();
		serviceNameFile.close();
		serviceFeeFile.close();
	}

	public String lookUpServiceName(int sCode) throws IOException {
		for (int i = 0; i < serviceDirectory.size(); i++) {
			if (serviceDirectory.elementAt(i).getKey() == sCode) {
				return serviceDirectory.elementAt(i).getValue();
			}
		}
		return "Invalid Service Code";
	}

	public double lookUpFee(int sCode) {
		for (int i = 0; i < serviceFeeDirectory.size(); i++) {
			if (serviceFeeDirectory.elementAt(i).getKey() == sCode) {
				return serviceFeeDirectory.elementAt(i).getValue();
			}
		}
		return -1;
	}

	public int lookUpCode(int sCode) {
		for (int i = 0; i < serviceDirectory.size(); i++) {
			if (serviceDirectory.elementAt(i).getKey().equals(sCode)) {
				return serviceDirectory.elementAt(i).getKey();
			}
		}
		return -1;
	}

	public Vector<Pair<Integer, String>> returnServiceDirectory() {
		return this.serviceDirectory;
	}

	public Vector<Pair<Integer, Double>> returnServiceFeeDirectory() {
		return this.serviceFeeDirectory;
	}
	
	/**
	 * Overloaded function. Add a member record.
	 * @param record
	 */
	public void addMember(MemberRecord member) {
		this.memberRecords.add(member);
	}
	
	/**
	 * Overloaded function. Add a provider record.
	 * @param record
	 */
	public void addProvider(ProviderRecord provider) {
		this.providerRecords.add(provider);
	}
	
	/**
	 * Delete a member given their member number.
	 * @param number
	 */
	public void deleteMember(int number) {
		if (searchMember(number) == -1) {
			System.out.println("Member number" + number + "does not exist.");
			return;
		}
		this.memberRecords.remove(searchMember(number));
	}
	
	/**
	 * Delete a provider given their provider number.
	 * @param number
	 */
	public void deleteProvider(int number) {
		if(searchProvider(number) == -1) {
			System.out.println("Provider number" + number + "does not exist.");
			return;
		}
		this.providerRecords.remove(searchProvider(number));
	}
	
	/**
	 * Returns member record corresponding to member number. Returns null if member number does not exist.
	 * @param number
	 * @return
	 */
	public MemberRecord returnMemberRecord(int number) {
		if (searchMember(number) == -1) {
			System.out.println("Member number" + number + "does not exist.");
			return null;
		}
		return this.memberRecords.get(searchMember(number));
	}

	/**
	 * Returns size of memberRecords Vector.
	 * @return
	 */
	public int returnMemberRecordSize() {
		return this.memberRecords.size();
	}

	/**
	 * Returns size of providerRecords Vector.
	 * @return
	 */
	public int returnProviderRecordSize() {
		return this.providerRecords.size();
	}
	
	/**
	 * Returns provider record corresponding to provider number. Returns null if provider number does not exist.
	 * @param number
	 * @return
	 */
	public ProviderRecord returnProviderRecord(int number) {
		if (searchProvider(number) == -1) {
			System.out.println("Provider number " + number + " does not exist.");
			return null;
		}
		return this.providerRecords.get(searchProvider(number));
	}

	/**
	 * Returns Vector of provider records.
	 * @return
	 */
	public Vector<ProviderRecord> returnProviderRecords() {
		return this.providerRecords;
	}

	/**
	 * Returns Vector of member records.
	 * @return
	 */
	public Vector<MemberRecord> returnMemberRecords() {
		return this.memberRecords;
	}
	
	/**
	 * Search of member records given a member number. Returns index in memberRecords Vector or -1 if number does not exist.
	 * @param number
	 * @return
	 */
	private int searchMember(int number) {
		for (int i = 0; i < this.memberRecords.size(); i++) {
			if (number == this.memberRecords.get(i).getNumber()) {
				return i;
			}
		}
		return -1;
	}
	
	/** 
	 * Search of provider records given a provider number. Returns index in providerRecords Vector or -1 if number does not exist.
	 * @param number
	 * @return
	 */
	private int searchProvider(int number) {
		for (int i = 0; i < this.providerRecords.size(); i++) {
			if (number == this.providerRecords.get(i).getNumber()) {
				return i;
			}
		}
		return -1;
	}
}
