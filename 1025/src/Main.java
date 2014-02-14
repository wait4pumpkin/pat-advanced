import java.util.*;

/**
 * Created by pumpkin on 1/28/14.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Testee> database = new ArrayList<Testee>();
        int nLocation = scanner.nextInt();
        for (int idxLoc = 1; idxLoc <= nLocation; ++idxLoc) {
            int nTestee = scanner.nextInt();
            scanner.nextLine();
            List<Testee> testees = new ArrayList<Testee>();
            for (int i = 0; i < nTestee; ++i) {
                testees.add(new Testee(scanner.nextLine(), idxLoc));
            }

            Collections.sort(testees, new Comparator<Testee>() {
                @Override
                public int compare(Testee o1, Testee o2) {
                    if (o1.score < o2.score) {
                        return 1;
                    } else if (o1.score > o2.score) {
                        return -1;
                    } else if (o1.id < o2.id) {
                        return -1;
                    } else if (o1.id > o2.id) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            });
            int score = -1;
            int rank = 1;
            for (int k = 0; k < testees.size(); ++k) {
                if (testees.get(k).score != score) {
                    score = testees.get(k).score;
                    rank = k + 1;
                }
                testees.get(k).localRank = rank;
            }

            database.addAll(testees);
        }

        System.out.println(database.size());
        Collections.sort(database, new Comparator<Testee>() {
            @Override
            public int compare(Testee o1, Testee o2) {
                if (o1.score < o2.score) {
                    return 1;
                } else if (o1.score > o2.score) {
                    return -1;
                } else if (o1.id < o2.id) {
                    return -1;
                } else if (o1.id > o2.id) {
                    return 1;
                } else {
                    return 0;
                }
            }
        });
        int score = -1;
        int rank = 1;
        for (int k = 0; k < database.size(); ++k) {
            Testee ins = database.get(k);
            if (ins.score != score) {
                score = ins.score;
                rank = k + 1;
            }
            ins.globalRank = rank;

            System.out.println(ins.idStr + " " + ins.globalRank + " " + ins.loc + " " + ins.localRank);
        }
    }
}

class Testee {
    Testee(String line, int loc) {
        String[] data = line.split(" ");
        idStr = data[0];
        id = Long.parseLong(idStr);
        this.loc = loc;
        score = Integer.parseInt(data[1]);
    }

    String idStr;
    long id;
    int loc;
    int score;
    int localRank, globalRank;
}
