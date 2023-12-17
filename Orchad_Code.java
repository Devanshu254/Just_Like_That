import java.util.Scanner;

public class Orchad_Code {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ashok = sc.nextLine();
        String anand = sc.nextLine();
        char as[] = ashok.toCharArray();
        char an[] = anand.toCharArray();
        int variable_as = combination(as, as.length);
        int variable_an = combination(an, an.length);
        if (variable_as == 0 && variable_an == 0)
            System.out.print("Invalid input");
        if (variable_as > variable_an)
            System.out.print("Ashok");
        else if (variable_an > variable_as)
            System.out.print("Anand");
        else
            System.out.print("Draw");
    }

    static int combination(char arr[], int n) {
        int count = 0;
        String s = "";
        for (int i = 0; i < n; i++) {
            s = "" + arr[i];
            for (int j = i + 1; j < n; j++) {
                s += arr[j];
                if (s.charAt(0) != arr[j]) {
                    for (int k = j + 1; k < n; k++) {
                        if (s.charAt(1) != arr[k])
                            count++;
                    }
                }
                s = "" + arr[i];
            }
        }
        return count;
    }
}
