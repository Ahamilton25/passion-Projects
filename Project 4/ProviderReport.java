package project4;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

/**
 * ProviderReport class. Generates provider report and EFT data file for provider.
 * @author Vishak Vikranth
 */
public class ProviderReport {
	private static DecimalFormat df = new DecimalFormat("$0.00");
	private LocalDate now = LocalDate.now();
	private int totalConsultations = 0;
	private double totalFee = 0;
	
	public void print(ProviderRecord providerRecord) throws IOException {
		File report = new File(providerRecord.getName() + " " + DateTimeFormatter.ofPattern("MM-dd-yyyy").format(now) + ".txt");
		if (report.exists()) report.delete();
		report.createNewFile();
		FileWriter writer = new FileWriter(report);
		
		writer.append("Name: " + providerRecord.getName() + "\n");
		writer.flush();

		writer.append("Number: " + providerRecord.getNumber() + "\n");
		writer.flush();

		writer.append("Address: " + providerRecord.getStreetAddress() + ", " + providerRecord.getCity() + ", " + providerRecord.getState() + ", " + providerRecord.getZip() + "\n");
		writer.flush();

		for (int i = 0; i < providerRecord.returnForms().size(); i++) {
			ProviderForm providerForm = providerRecord.returnForms().get(i);
			writer.append("Consultation Date: " + providerForm.getServiceDate() + "\n");
			writer.flush();

			writer.append("Member Name: " + providerForm.getMemberName() + "\n");
			writer.flush();

			writer.append("Service Name: " + providerForm.getServiceName() + "\n");
			writer.flush();

			writer.append("Service Code: " + providerForm.getServiceCode() + "\n");
			writer.flush();

			writer.append("Fee to be paid: " + df.format(providerForm.getServiceFee()) + "\n\n");
			writer.flush();

			totalFee += providerForm.getServiceFee();
			totalConsultations++;
		}

		writer.append("Total number of consultations: " + totalConsultations + "\n");
		writer.flush();

		writer.append("Total fees for the week of " + DateTimeFormatter.ofPattern("MM-dd-yyyy").format(now) + ": " + df.format(totalFee) + "\n");
		writer.flush();

		writer.close();

		EFTData eftData = new EFTData();
		eftData.print(providerRecord);
	}
}
