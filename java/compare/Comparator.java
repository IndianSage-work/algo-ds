//https://www.hackerrank.com/challenges/java-comparator/problem

import java.util.*;

class Checker implements Comparator<Player>{
    public int compare(Player a, Player b){
        //while comparing, just think of the number line. If left element larger, -1, if right element larger, 1.
        //see Priority Queue folder for Comparable
        if(a.score==b.score){
            int compare = a.name.compareTo(b.name);
            if(compare<0){
                return -1;
            }
            else if(compare>0){
                return 1;
            }
        }else if(a.score>b.score){
            return -1;
        }else{
            return 1;
        }
        return 0;
    }
}
// Write your Checker class here

class Player{
    String name;
    int score;
    
    Player(String name, int score){
        this.name = name;
        this.score = score;
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Player[] player = new Player[n];
        Checker checker = new Checker();
        
        for(int i = 0; i < n; i++){
            player[i] = new Player(scan.next(), scan.nextInt());
        }
        scan.close();

        Arrays.sort(player, checker);
        for(int i = 0; i < player.length; i++){
            System.out.printf("%s %s\n", player[i].name, player[i].score);
        }
    }
}