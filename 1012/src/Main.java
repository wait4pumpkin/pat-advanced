import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.*;
/**
 * Created by pumpkin on 1/27/14.
 */
public class Main {
    public static void main(String[] args) {
        try {
            String sample = "4 6\n" +
                            "310101 98 85 88 90\n" +
                            "310102 70 95 88 84\n" +
                            "310103 82 87 94 88\n" +
                            "310104 91 91 91 91\n" +
                            "310101\n" +
                            "310102\n" +
                            "310103\n" +
                            "310104\n" +
                            "310105\n" +
                            "999999";
            BufferedReader reader = new BufferedReader(new StringReader(sample));
            Scanner scanner = new Scanner(reader.readLine());
            int nStudent = scanner.nextInt();
            int nQuery = scanner.nextInt();

            Map<Integer, Student> database = new HashMap<Integer, Student>();
            for (int i = 0; i < nStudent; ++i) {
                Student s = new Student(reader.readLine());
                database.put(s.id, s);
            }

            List<Student> students = new ArrayList<Student>(database.values());
            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    if (o1.avg < o2.avg) {
                        return 1;
                    } else if (o1.avg > o2.avg) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            });
            for (int i = 0; i < nStudent; ++i) {
                students.get(i).avgRank = i + 1;
            }

            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    if (o1.code < o2.code) {
                        return 1;
                    } else if (o1.code > o2.code) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            });
            for (int i = 0; i < nStudent; ++i) {
                students.get(i).codeRank = i + 1;
            }

            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    if (o1.math < o2.math) {
                        return 1;
                    } else if (o1.math > o2.math) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            });
            for (int i = 0; i < nStudent; ++i) {
                students.get(i).mathRank = i + 1;
            }

            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    if (o1.eng < o2.eng) {
                        return 1;
                    } else if (o1.eng > o2.eng) {
                        return -1;
                    } else {
                        return 0;
                    }
                }
            });
            for (int i = 0; i < nStudent; ++i) {
                students.get(i).engRank = i + 1;
            }

            for (int i = 0; i < nQuery; ++i) {
                int query = Integer.parseInt(reader.readLine());
                Student s = database.get(query);
                if (s != null) {
                    System.out.println(s.bestRankInfo());
                } else {
                    System.out.println("N/A");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Student {
    Student(String line) {
        String[] data = line.split(" ");
        id = Integer.parseInt(data[0]);
        code = Integer.parseInt(data[1]);
        math = Integer.parseInt(data[2]);
        eng = Integer.parseInt(data[3]);
        avg = (code + math + eng) / 3.;
    }

    String bestRankInfo() {
        if (avgRank <= codeRank && avgRank <= mathRank && avgRank <= engRank) {
            return avgRank + " A";
        } else if (codeRank <= mathRank && codeRank <= engRank) {
            return codeRank + " C";
        } else if (mathRank <= engRank) {
            return mathRank + " M";
        } else {
            return engRank + " E";
        }
    }

    int id, code, math, eng;
    double avg;
    int avgRank, codeRank, mathRank, engRank;
}
