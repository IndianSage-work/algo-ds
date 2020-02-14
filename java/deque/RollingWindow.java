 //https://www.hackerrank.com/challenges/java-dequeue/problem   
    import java.util.*;
    public class test {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            Deque<Integer> deque = new ArrayDeque<>();
            HashMap<Integer,Integer> hm = new HashMap<>();
            int n = in.nextInt();
            int m = in.nextInt();
            int uniq = 0;
            int i = 0;
            for (; i < m; i++) {
                int num = in.nextInt();
                deque.addFirst(num);
                int mapVal = -1;
                if(hm.containsKey(num)){
                    mapVal = hm.get(num);
                }    
                else{
                    mapVal = 0;
                }
                if(mapVal==0){
                    uniq++;
                    hm.put(num,1);
                }else{
                    hm.put(num,mapVal+1);
                }
            }
            int maxUniq = uniq;
            while(i<n){
                int last = deque.removeLast();
                int mapVal = hm.get(last);
                if(mapVal==1){
                    uniq--;
                }
                hm.put(last,mapVal-1);
                int num = in.nextInt();
                deque.addFirst(num);
                if(hm.containsKey(num)){
                    mapVal = hm.get(num);
                }    
                else{
                    mapVal = 0;
                }
                if(mapVal==0){
                    uniq++;
                    hm.put(num,1);
                }else{
                    hm.put(num,mapVal+1);
                }
                if(uniq>maxUniq){
                    maxUniq=uniq;
                }
                i++;
            }
            System.out.println(maxUniq);
        }
    }



