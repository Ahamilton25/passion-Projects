package project4;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;


/**
 * MemberReport class. Generates member report.
 * @author Vishak Vikranth
 */
public class MemberReport {
	private LocalDate now = LocalDate.now();
	
	public void print(MemberRecord memberRecord) throws IOException {
		File report = new File(memberRecord.getName() + "_" + DateTimeFormatter.ofPattern("MM-DD-YYYY").format(now) + ".txt");
		if (report.exists()) report.delete();
		report.createNewFile();
		FileWriter writer = new FileWriter(report);

		writer.append("Name: " + memberRecord.getName() + "\n");
		writer.flush();

		writer.append("Number: " + memberRecord.getNumber() + "\n");
		writer.flush();

		writer.append("Address: " + memberRecord.getStreetAddress() + ", " + memberRecord.getCity() + ", " + memberRecord.getState() + ", " + memberRecord.getZip() + "\n");
		writer.flush();

		writer.append("Status: " + memberRecord.returnStatus() + "\n");

		writer.append("Service Records: \n");
		writer.flush();

		for (int i = 0; i < memberRecord.returnServices().size(); i++) {
			ServiceRecord serviceRecord = memberRecord.returnServices().get(i);
			writer.append("\tService Date: " + serviceRecord.getServiceDate() + "\n");
			writer.flush();

			writer.append("\tProvider Name: " + serviceRecord.getProviderName() + "\n");
			writer.flush();

			writer.append("\tService Name: " + serviceRecord.getServiceName() + "\n");
			writer.flush();
		}

		writer.close();
	}
}
