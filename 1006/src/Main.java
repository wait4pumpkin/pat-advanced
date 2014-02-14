import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Created by pumpkin on 1/27/14.
 */
public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            int nWorker = Integer.parseInt(reader.readLine());
            List<Worker> workers = new ArrayList<Worker>();
            for (int i = 0; i < nWorker; ++i) {
                workers.add(new Worker(reader.readLine()));
            }

            Collections.sort(workers, new Comparator<Worker>() {
                @Override
                public int compare(Worker o1, Worker o2) {
                    if (o1.start < o2.start) {
                        return -1;
                    } else if (o1.start > o2.start) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            });
            System.out.print(workers.get(0).id + " ");

            Collections.sort(workers, new Comparator<Worker>() {
                @Override
                public int compare(Worker o1, Worker o2) {
                    if (o1.end < o2.end) {
                        return 1;
                    } else if (o1.end > o2.end) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            });
            System.out.print(workers.get(0).id);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Worker {
    Worker(String line) {
        String[] data = line.split(" ");
        id = data[0];
        start = parseTime(data[1]);
        end = parseTime(data[2]);
    }

    private int parseTime(String str) {
        String[] time = str.split(":");
        return Integer.parseInt(time[2]) + 60 * Integer.parseInt(time[1]) + 3600 * Integer.parseInt(time[0]);
    }

    public String id;
    public int start;
    public int end;
}
