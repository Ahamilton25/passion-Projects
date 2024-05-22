package project4;

import java.io.IOException;

/** 
 * Prints both a provider and member reports. 
 * @author Rajiv Yalamanchili
 */
public class Summary {
    
    public void printProviderReport(ProviderRecord providerRecord) throws IOException {
        new ProviderReport().print(providerRecord);
    }

    public void printMemberReport(MemberRecord memberRecord) throws IOException {
        new MemberReport().print(memberRecord);
    }
}