//https://www.hackerrank.com/challenges/java-stack/problem

import java.util.*;

class Solution{

	public static void main(String []arg)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			String input=sc.next();
            
            ArrayDeque<Character> a = new ArrayDeque<Character>();
            for(int i=0;i<input.length();i++){
                
                char top = '\u0000';
                if(a.peek()!=null){
                    top = a.peek();
                }
                //System.out.println(top);
                char match = input.charAt(i);
                
                    if(top=='[' && match==']'){
                        a.pop();
                        //System.out.println("a");
                    }
                    else if(top=='{' && match=='}'){
                        a.pop();
                        //System.out.println("b");
                    }
                    else if(top=='(' && match==')'){
                        a.pop();
                        //System.out.println("c");
                    }
                
                else{
                    a.push(match);
                    //System.out.println("d");
                }
            }
            if(a.size()==0){
                System.out.println("true");
            }
            else{
                System.out.println("false");
            }
                
        }
	}
		
}




