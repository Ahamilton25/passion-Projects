package project4;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Calendar;

/**
 * EFTData class. Generates EFT data file for provider. This class is not used in the current version of the program, but is included for future use.
 * @author Rajiv Yalamanchili
 */
public class EFTData {
	private LocalDate now = LocalDate.now();
	
	/**
	 * Prints formatted .txt EFT data file.
	 * @param name
	 * @param number
	 * @param amount
	 * @throws IOException
	 */
	public void print(ProviderRecord providerRecord) throws IOException {
		File report = new File(providerRecord.getName() + "_" + DateTimeFormatter.ofPattern("MM-DD-YYYY").format(now) + "_EFT.txt");
		if (report.exists()) report.delete();
		report.createNewFile();
		FileWriter writer = new FileWriter(report);
		
		writer.append("Current Date and Time: " + new SimpleDateFormat("MM-DD-YYYY HH:MM:SS").format(Calendar.getInstance().getTime()));
		writer.flush();

		writer.append("\nProvider Number: " + providerRecord.getNumber());
		writer.flush();

		writer.append("\nMember Number: " + providerRecord.returnForms().get(0).getMemberNumber());
		writer.flush();

		writer.append("\nService Code: " + providerRecord.returnForms().get(0).getServiceCode());
		writer.flush();

		writer.close();
	}
}
