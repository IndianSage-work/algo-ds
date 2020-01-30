/* https://www.hackerrank.com/challenges/ctci-ransom-note/problem */

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the checkMagazine function below.
    static void checkMagazine(String[] magazine, String[] note) {
        HashMap<String, Integer> magMap = new HashMap<String, Integer>();
        boolean valid = true;
        //put all the words in a hashmap
        for(String s:magazine){
            Integer i = magMap.get(s);
            if (i == null) {
                magMap.put(s, 1);
            } else {
                magMap.put(s, i + 1);
            }
        }
        for(String s:note){
            Integer i = magMap.get(s);
            if (i == null||magMap.get(s)==0) {
                valid = false;
                break;
            } else {
                magMap.put(s,i-1);
            }
        }
        if(valid)
            System.out.println("Yes");
        else
            System.out.println("No");
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] mn = scanner.nextLine().split(" ");

        int m = Integer.parseInt(mn[0]);

        int n = Integer.parseInt(mn[1]);

        String[] magazine = new String[m];

        String[] magazineItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            String magazineItem = magazineItems[i];
            magazine[i] = magazineItem;
        }

        String[] note = new String[n];

        String[] noteItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            String noteItem = noteItems[i];
            note[i] = noteItem;
        }

        checkMagazine(magazine, note);

        scanner.close();
    }
}
