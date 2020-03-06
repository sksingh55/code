import java.util.*;
import java.io.*;

class Machine{
    ArrayList<String> ip= new ArrayList<>();
    int currentIndex=-1;
    int count = 0;
    String lastIp="";
}

public class Main{

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    Map<String,Integer> machineStatus = new HashMap<>();
    Map<String,ArrayList<String>> ans = new HashMap<>();
    Map<String,Machine> urlToMachineMapping = new HashMap<>();
    String[] inp1;
    void addMachineToUrl(String url,String ip){
        Machine machine = new Machine();
        if(!urlToMachineMapping.containsKey(url)){
            machine.count++;
            machine.currentIndex = -1;
            machine.ip.add(ip);
            machineStatus.put(ip,0);
            urlToMachineMapping.put(url,machine);
        }
        else{
            machine = urlToMachineMapping.get(url);
            machine.ip.add(ip);
            machine.count++;
            machineStatus.put(ip,machine.count-1);
        }
        urlToMachineMapping.put(url,machine);
    }

    void getMachine(FastReader sc){
        int n = sc.nextInt();
        inp1 = sc.nextLine().split(" ");
        for(String ip : inp1){
            machineStatus.put(ip,-1);
            ans.put(ip,new ArrayList<>());
        }
    }
    void getMachineMapping(FastReader sc){
        int n = sc.nextInt();
        while(n-- > 0){
            String url = sc.nextLine();
            int k = sc.nextInt();
            String[] inp2 = sc.nextLine().split(" ");
            for(String ip:inp2){
                addMachineToUrl(url,ip);
            }
        }
    }
    String getNextMachine(String url){
        if(!urlToMachineMapping.containsKey(url)){
            return "";
        }
        Machine machine = urlToMachineMapping.get(url);
        int count = machine.ip.size();
        if(count == 0){
            return "";
        }
        int curr = machine.currentIndex%count;
        if(curr !=-1 && machine.ip.get(curr) != machine.lastIp ){
            machine.lastIp = machine.ip.get(curr);
            urlToMachineMapping.put(url,machine);
            return machine.ip.get(curr);
        }
        while(count-- > 0){
            curr = (curr+1)%machine.count;
            machine.currentIndex = curr;
            machine.lastIp = machine.ip.get(curr);
            urlToMachineMapping.put(url,machine);
            return machine.ip.get(curr);
        }
        return "";
    }
    void addToAns(String url,String fullurl){
        String ip = getNextMachine(url);
        // cout<<ip<<"\n";
        if(ip==""){
            return;
        }
        else{
            if(!ans.containsKey(ip)){
                return;
            }
            ArrayList<String> sol = ans.get(ip);
            sol.add(fullurl);
            ans.put(ip,sol);
        }
    }
    void removeMachine(String url,String ip){
        if(!machineStatus.containsKey(ip)||machineStatus.get(ip)==-1){
            return;
        }
        if(!urlToMachineMapping.containsKey(url)){
            return;
        }
        Machine machine = urlToMachineMapping.get(url);
        if(!machineStatus.containsKey(ip)){
            return;
        }
        int index = machineStatus.get(ip);
        machine.ip.remove(index);
        machine.count--;
        urlToMachineMapping.put(url,machine);
        machineStatus.put(ip,-1);
    }
    void updateMachineStatus(String url,String ip,boolean status){
        if(status){
            addMachineToUrl(url,ip);
        }
        else{
            removeMachine(url,ip);
        }
    }
    void compileUrl(String fullUrl){
        String[] line = fullUrl.split("/");
        if(line.length==1){
            addToAns(line[0],fullUrl);
        }
        else{
            String[] params = line[1].split("\\?");
            if(params.length==1){
                addToAns(line[0], fullUrl);
                return;
            }
            if(params[0].equals("machine_down")){
                String[] par = params[1].split("=");
                if(par.length!=2){
                    addToAns(line[0], fullUrl);
                    return;
                }
                String ip = par[1];
                updateMachineStatus(line[0], ip, false);
            }
            else if(params[0].equals("machine_up")){
                String[] par = params[1].split("=");
                if(par.length!=2){
                    addToAns(line[0], fullUrl);
                    return;
                }
                String ip = par[1];
                updateMachineStatus(line[0], ip, true);
            }
            else{
                addToAns(line[0], fullUrl);
            }
        }
    }

    void query(FastReader sc){
        int n = sc.nextInt();
        while(n-- > 0){
            String fullurl = sc.nextLine();
            compileUrl(fullurl);
        }
        print(new PrintWriter(System.out));
    }

    void print(PrintWriter out){
        for(String s:inp1){
            out.println(s);
            for(String a : ans.get(s)){
                out.println(a);
            }
        }
        out.close();
    }

    void printMapping(){
        PrintWriter out = new PrintWriter(System.out);
        for(String url:urlToMachineMapping.keySet()){
            out.println(url);
            for(String a : urlToMachineMapping.get(url).ip){
                out.println(a);
            }
        }
        out.close();
    }

    public static void main (String[] args){
        FastReader sc = new FastReader();
        Main main= new Main();
        main.getMachine(sc);
        main.getMachineMapping(sc);
        main.query(sc);
    }
}