//https://www.hackerrank.com/challenges/java-priority-queue/problem

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Comparator;
/*
 * Create the Student and Priorities classes here.
 */
class Student implements Comparable<Student>{
    private int id;
    private double cgpa;
    private String name;

    Student(int id, String name, double cgpa){
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }

    public int getID() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public double getCGPA() {
        return this.cgpa;
    }

    public int compareTo(Student student){
        if(this.cgpa==student.cgpa){
            int compareName = this.name.compareTo(student.name);
            if(compareName>0){
                return 1;
            }else if(compareName<0){
                return -1;
            }else{
                return (this.id>student.id)?(1):(-1);
            }
            
        }
        else if(this.cgpa>student.cgpa){
            return -1;
        }
        else{
            return 1;
        }
    }
}

class Priorities {
    List<Student> getStudents(List<String> events){
        
        PriorityQueue<Student> pQ = new PriorityQueue<Student>();
        for(String event:events){
            if(event.charAt(0)=='E'){
                String[] sDetails = event.split(" ");
                Student student = new Student(Integer.parseInt(sDetails[3]),sDetails[1],Double.parseDouble(sDetails[2]));
                pQ.add(student);
            }
            else{
                pQ.poll();
            }
        }
        List<Student> answer = new ArrayList<Student>();
        Student first = pQ.poll();
        if (first == null) {
            return answer;
        } else {
            while (first != null) {
                answer.add(first);
                first = pQ.poll();
            }
            return answer;
        }
    }
}


public class Solution {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();
    
    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());    
        List<String> events = new ArrayList<>();
        
        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }
        
        List<Student> students = priorities.getStudents(events);
        
        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}