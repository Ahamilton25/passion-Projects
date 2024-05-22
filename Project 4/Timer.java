package project4;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.file.Path;
import java.text.DecimalFormat;
import java.time.DayOfWeek;
import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.TemporalAdjusters;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

/**
 * Timer class. Generates weekly summary.
 * @author Ardise Hamilton
 */
public class Timer {

    private ManageRecords records;
    private static DecimalFormat df = new DecimalFormat("$0.00");
    private LocalDate now = LocalDate.now();
    private int totalConsultations = 0;
    private double totalFee = 0;

    public Timer(ManageRecords records) {
        this.records = records;
        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);

        // Get the current date and time
        LocalDateTime now = LocalDateTime.now();

        // Calculate the delay until the next Friday at midnight
        LocalDateTime nextFriday = getNextFriday(now);
        long initialDelay = Duration.between(now, nextFriday).toMillis();

        // Schedule the task to run every week on Friday at midnight
        scheduler.scheduleAtFixedRate(new Summary(), initialDelay, 7, TimeUnit.DAYS);
    }

    private static LocalDateTime getNextFriday(LocalDateTime currentDateTime) {
        return currentDateTime.with(TemporalAdjusters.next(DayOfWeek.FRIDAY)).withHour(0).withMinute(0).withSecond(0);
    }

    private class Summary implements Runnable {
        /**
         * Generates weekly summary.
         */
        @Override
        public void run() {
            System.out.println("Generating weekly summary...");
            Path folder = Paths.get("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\Summary Reports");
            try {
                if (!Files.exists(folder))
                    Files.createDirectory(folder);
                for (int i = 0; i < records.returnMemberRecordSize(); i++) {
                    printMemberReport(records.returnMemberRecords().get(i));
                }
                for (int i = 0; i < records.returnProviderRecordSize(); i++) {
                    printProviderReport(records.returnProviderRecords().get(i));
                }
            } catch (Exception e) {
                System.out.println("Error generating weekly summary.");
            }
        }

        /**
         * Prints member report.
         * @param memberRecord
         * @throws IOException
         */
        private void printMemberReport(MemberRecord memberRecord) throws IOException {
            Path folder = Paths.get("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\Summary Reports\\Member Reports");
            if (!Files.exists(folder))
                Files.createDirectory(folder);

            File report = new File(memberRecord.getName() + "_" + DateTimeFormatter.ofPattern("MM-DD-YYYY").format(now) + "_Report.txt");
            Path filePath = Paths.get("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\Summary Reports\\Member Reports", report.getName());
            if (!Files.exists(filePath))
                Files.createFile(filePath);
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

        /**
         * Prints provider report.
         * @param providerRecord
         * @throws IOException
         */
        private void printProviderReport(ProviderRecord providerRecord) throws IOException {
            Path folder = Paths.get("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\Summary Reports\\Provider Reports");
            if (!Files.exists(folder))
                Files.createDirectory(folder);

            File report = new File(providerRecord.getName() + "_" + DateTimeFormatter.ofPattern("MM-DD-YYYY").format(now) + "_Report.txt");
            Path filePath = Paths.get("C:\\Users\\prasa\\OneDrive - The University of Alabama\\Documents\\Summary Reports\\Provider Reports", report.getName());
            if (!Files.exists(filePath))
                Files.createFile(filePath);
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

                writer.append("Fee to be paid: " + df.format(providerForm.getServiceFee()) + "\n");
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
}
