import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * Created by pumpkin on 1/28/14.
 */
public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            Scanner scanner = new Scanner(reader.readLine());
            int nStudent = scanner.nextInt();
            int query = scanner.nextInt();

            List<Student> database = new ArrayList<Student>();
            for (int i = 0; i < nStudent; ++i) {
                database.add(new Student(reader.readLine()));
            }

            switch (query) {
                case 1:
                    Collections.sort(database, new Comparator<Student>() {
                        @Override
                        public int compare(Student o1, Student o2) {
                            if (o1.id < o2.id) {
                                return -1;
                            } else if (o1.id > o2.id) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    });
                    break;

                case 2:
                    Collections.sort(database, new Comparator<Student>() {
                        @Override
                        public int compare(Student o1, Student o2) {
                            int result = o1.name.compareTo(o2.name);
                            if (result == 0) {
                                if (o1.id < o2.id) {
                                    return -1;
                                } else if (o1.id > o2.id) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                            return result;
                        }
                    });
                    break;

                case 3:
                    Collections.sort(database, new Comparator<Student>() {
                        @Override
                        public int compare(Student o1, Student o2) {
                            if (o1.grade < o2.grade) {
                                return -1;
                            } else if (o1.grade > o2.grade) {
                                return 1;
                            } else {
                                if (o1.id < o2.id) {
                                    return -1;
                                } else if (o1.id > o2.id) {
                                    return 1;
                                } else {
                                    return 0;
                                }
                            }
                        }
                    });
                    break;

                default:
                    break;
            }

            for (int i = 0; i < nStudent; ++i) {
                System.out.println(database.get(i).info());
                System.out.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Student {
    Student(String line) {
        String[] data = line.split(" ");
        idStr = data[0];
        id = Integer.parseInt(data[0]);
        name = data[1];
        grade = Integer.parseInt(data[2]);
    }

    String info() {
        return idStr + " " + name + " " + grade;
    }

    String idStr;
    int id;
    String name;
    int grade;
}
